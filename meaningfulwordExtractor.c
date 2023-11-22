#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void add_Word(char *, FILE *);
void add_number(char *, FILE *);

int main(){
    char meaningfulWord[9], wordCombination[8];
    int i;
    FILE *meaningfulWordsFile;
    FILE *wordalphaFile;
    FILE *wordCombinationFile;
    if(!(meaningfulWordsFile = fopen("meaningfulWords.txt", "w"))){
        printf("Error opening meaningfulWords file \n");
        return 1;
    }
    if(!(wordalphaFile = fopen("words_alpha.txt", "r"))){
        printf("Error opening word alpha file \n");
        return 1;
    }
    if(!(wordCombinationFile = fopen("wordCombination.txt", "r"))){
        printf("Error opening word combination file \n");
        return 1;
    }

    while(!(fscanf(wordalphaFile, "%s", meaningfulWord) == EOF)){
        meaningfulWord[8] = '\0';
        if(strlen(meaningfulWord) != 7 )
            continue;
        while(fscanf(wordCombinationFile, "%s", wordCombination) != EOF){
            wordCombination[7] = '\0';
            if(isdigit(wordCombination[0]))
                add_number(wordCombination, meaningfulWordsFile);
            else if(strcmp(meaningfulWord, wordCombination) == 0){
                add_Word(meaningfulWord, meaningfulWordsFile);
                break;
            }
        }
    }
    printf("Done Extracting\n");
    fclose(meaningfulWordsFile);
    fclose(wordalphaFile);
    fclose(wordCombinationFile);
    return 0;
}

void add_Word(char *word , FILE *fp){
    fprintf(fp, "%s\n", word);
}

void add_number(char *numberCombination, FILE *fp){
    fprintf(fp, "%s\n", numberCombination);
}