#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void fileProcess(char fileI[], char fileO[]);

void main(int argc, char * files[]){
	if(argc<3){
		printf("Please specify an input and output file.\nFORMAT: ./program_name input_file.txt output_file.txt.\n");
		exit(0);
	}
	fileProcess(files[1], files[2]);
}

void fileProcess(char fileI[], char fileO[]){
    FILE * iPtr; //input file pointer
    FILE * oPtr; //output file pointer
    char aLine[300];

    iPtr = fopen(fileI, "r"); //init reading

    if (iPtr == NULL) {
        //if the file doesn't exist, out a message
        perror("File not found bro...");
    }else{
        /*of the file exist:
        1- grab the entire line and check if its empty, if it is not.(35)
        2- check if the line has the words "error" or  "failed login".(36)
        3- if it does, open the stream to the output file to add text.(37)
        4- Add the line to the text file.(38)
        5- close the output file's stream.(39)
        6- close the input file's stream.(43)
        */
        while (fgets(aLine, 300, iPtr) != NULL) {
            if (strstr(aLine,"error")!=NULL|| strstr(aLine,"failed login")!=NULL) {
                oPtr = fopen(fileO, "a");
                fprintf(oPtr,"%s", aLine);
                fclose(oPtr);
                }
            }
        }
    fclose(iPtr);
}

