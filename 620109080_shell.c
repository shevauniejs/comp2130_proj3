#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void showme(char file[]); //done
void junk(char file[]); //done
void createf(char file[]); //done
void lstdir(); //done
void countlines(char file[]); //done
int exists(FILE * ptr, char file[]); //necessary
void parse_log(char fileI[], char fileO []);

void main(int argc, char * filename[]){
    parse_log(filename[1], filename[2]);
}


void showme(char file[]){ //works
    FILE * fpt = NULL;
    char c;
    fpt= fopen(file,"r");
    if(exists(fpt, file)==0){
        printf("\nFile not found %s", file);
        }
        else{
            while((c=fgetc(fpt))!=EOF){
                printf("%c", c);
                }
            }
}

void junk(char file[]){ //works
    FILE * fpt= NULL;
    int rem;
    fpt = fopen(file, "r");
    if((exists(fpt, file))==0){
    printf("\nFile not found, failed to junk %s", file);
    }else{
        rem = remove(file);
        printf("\nRemoved: %s", file);
    }
}

void countlines(char file[]){ //works
    //if char == \n, count++
    char c;
    int line_c, word_c, char_c =0;
    FILE * fpt =NULL;
    fpt = fopen(file, "r");
    if(exists(fpt, file)==0){
        printf("\nFile not found %s", file);
    }else{
        while((c = fgetc(fpt))!=EOF){
            if(c=='\n' || c== ' '){
                word_c++;
            }
            if(c=='\n'){
                line_c++;
            }
            char_c++;
        }
    }
    printf("\nLines: %d", line_c);
    printf("\nWords: %d", word_c);
    printf("\nCharacters: %d", char_c);
    }

void createf(char file[]){ //works
    FILE * fpt = NULL;
    if(fpt==NULL){
        fpt = fopen(file, "w");
        printf("\nCreated %s", file);
        fclose(fpt);
    }
}

void lstdir(){ //works
    int e;
    char program [] ="ls";
    e = execvp(program,NULL);
    printf("\nFailed to list the directory contents");
}

void parse_log(char fileI[], char fileO []){
    int e;
    char * args [2];
    char program[] = "./parse_log";

    args[0] = "parse_log";
    args[1] = fileI;
    args[2] =fileO;

    e = execvp(program, args);
    printf("\nError executing parse_log command");
}

int exists(FILE * ptr, char file[]){ //needed
    ptr = fopen(file, "r");
    if(ptr == NULL ){
    return 0;
    }
    else{
        fclose(ptr);
    return 1;
    }
}


