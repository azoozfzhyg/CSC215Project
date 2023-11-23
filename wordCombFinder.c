#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isword(char* word,char* upperbound,char* lowerbound , FILE *thewordsfile);
void generateWords(int number[], char word[], int index, FILE *thewordsfile);

int main(){

    return 0;
}

int isword(char* word,char* upperbound,char* lowerbound , FILE *thewordsfile){
    char line[8];
    if(!(thewordsfile)){
        thewordsfile = ("sevenletterword.txt", "r");
        if(!(thewordsfile)){
            printf("Error opening word alpha file \n");
            return 1;
        }
    }
    do{
        fscanf(thewordsfile, "%s" , line);
    }while(strcmp(upperbound,line) > 0);
    if(strcmp(word,line) == 0){
        return 1;
    }
    while(fscanf(thewordsfile, "%s" , line) != EOF){
        if(strcmp(word,line) == 0){
            return 1;
        }
        if(strcmp(lowerbound,line) < 0){
            return 0;
        }
    }
}
void generateWords(int number[], char word[], int index, FILE *file) {
    if (index == 7) {
        fprintf(file, "%s\n", word);
        return;
    }

    int digit = number[index];
    char letters[4];
    int count = 0;

    switch (digit) {
        case 2:
            letters[0] = 'A';
            letters[1] = 'B';
            letters[2] = 'C';
            count = 3;
            break;
        case 3:
            letters[0] = 'D';
            letters[1] = 'E';
            letters[2] = 'F';
            count = 3;
            break;
        case 4:
            letters[0] = 'G';
            letters[1] = 'H';
            letters[2] = 'I';
            count = 3;
            break;
        case 5:
            letters[0] = 'J';
            letters[1] = 'K';
            letters[2] = 'L';
            count = 3;
            break;
        case 6:
            letters[0] = 'M';
            letters[1] = 'N';
            letters[2] = 'O';
            count = 3;
            break;
        case 7:
            letters[0] = 'P';
            letters[1] = 'R';
            letters[2] = 'S';
            count = 3;
            break;
        case 8:
            letters[0] = 'T';
            letters[1] = 'U';
            letters[2] = 'V';
            count = 3;
            break;
        case 9:
            letters[0] = 'W';
            letters[1] = 'X';
            letters[2] = 'Y';
            count = 3;
            break;
    }

    for (int i = 0; i < count; i++) {
        word[index] = letters[i];
        generateWords(number, word, index + 1, file);
    }
}