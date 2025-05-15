//eliminating upper words using the function
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LENGTH 1024

//Filters uppercase words, numbers and "scene"
int is_all_upper(const char *word){
    if(strcmp(word, "Scene") == 0){
        return 1;
    }
    int upper_count = 0;
    int count_digit = 0;
    while(*word){
        if(isalpha(*word)){
            if(!isupper(*word))
            {return 0;}
            upper_count++;
        }
        else if(isdigit(*word)){
            count_digit++;
        }
        word++;
    }
    return (upper_count >= 2) || (count_digit>0);
}

int main(){
    FILE *fPtr = fopen("Romeostep1.txt", "r");
    FILE *foutput = fopen("RomeoAndJuliet-cleaned.txt", "w");

    if(fPtr == NULL || foutput == NULL){
        perror("Error while opening the files\n");
        return 1;
    }
    
    char line[MAX_LENGTH];
    //Analizing every line of the file
    while(fgets(line, MAX_LENGTH, fPtr) != NULL){
        char *tokenPtr = strtok(line, "\n\t ,.!?:;=");  //First token with strtok
        while(tokenPtr != NULL){
            if(!is_all_upper(tokenPtr)){
                fprintf(foutput, "%s ", tokenPtr);
            }
            else{
                printf("Upper word: %s\n", tokenPtr);  //used as an output control of the function
            }
            tokenPtr = strtok(NULL, "\n\t ,.!?:;=");  //Following tokens with strtok
        }
    }
    
    fclose(fPtr);
    fclose(foutput);
}
