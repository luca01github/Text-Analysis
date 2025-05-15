//Writes on the output file the cleaned version of the text, without sentences between brackets [] 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    FILE *fPtr = fopen("romeo-and-juliet_TXT_FolgerShakespeare.txt", "r");
    FILE *foutput = fopen("Romeostep1.txt", "w");
    
    if(fPtr == NULL || foutput == NULL){
        perror("Error while opening the file\n");
        return 1;
    }

    char ch;
    bool inside_br = false;

    while((ch = fgetc(fPtr)) != EOF){
        if(ch == '['){
            inside_br = true;
        }
        else if(ch == ']'){
            inside_br = false;
        }
        else if(!inside_br){
            fputc(ch, foutput);
        }
    }
    
    fclose(fPtr);
    fclose(foutput);
}
