#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isword(char *word, char *upperbound, char *lowerbound, FILE *thewordsfile);
void generateWords(int number[], char word[], int index, FILE *thewordsfile);

int main()
{

    return 0;
}

int isword(char *word, char *upperbound, char *lowerbound, FILE *thewordsfile)
{
    char line[8];
    if (!(thewordsfile))
    {
        thewordsfile = ("sevenletterword.txt", "r");
        if (!(thewordsfile))
        {
            printf("Error opening word alpha file \n");
            return 1;
        }
    }
    do
    {
        fscanf(thewordsfile, "%s", line);
    } while (strcmp(upperbound, line) > 0);
    if (strcmp(word, line) == 0)
    {
        return 1;
    }
    while (fscanf(thewordsfile, "%s", line) != EOF)
    {
        if (strcmp(word, line) == 0)
        {
            return 1;
        }
        if (strcmp(lowerbound, line) < 0)
        {
            return 0;
        }
    }
}
void generateWords(int number[], char word[], int index, FILE *file)
{
    if (index == 7)
    {
        fprintf(file, "%s\n", word);
        return;
    }

    int digit = number[index];
    char letters[4];
    int count = 0;

    switch (digit)
    {
    case 2:
        letters[0] = 'a';
        letters[1] = 'b';
        letters[2] = 'c';
        count = 3;
        break;
    case 3:
        letters[0] = 'd';
        letters[1] = 'e';
        letters[2] = 'f';
        count = 3;
        break;
    case 4:
        letters[0] = 'g';
        letters[1] = 'h';
        letters[2] = 'i';
        count = 3;
        break;
    case 5:
        letters[0] = 'j';
        letters[1] = 'k';
        letters[2] = 'l';
        count = 3;
        break;
    case 6:
        letters[0] = 'm';
        letters[1] = 'n';
        letters[2] = 'o';
        count = 3;
        break;
    case 7:
        letters[0] = 'p';
        letters[1] = 'r';
        letters[2] = 's';
        count = 3;
        break;
    case 8:
        letters[0] = 't';
        letters[1] = 'u';
        letters[2] = 'v';
        count = 3;
        break;
    case 9:
        letters[0] = 'w';
        letters[1] = 'x';
        letters[2] = 'y';
        count = 3;
        break;
    }

    for (int i = 0; i < count; i++)
    {
        word[index] = letters[i];
        generateWords(number, word, index + 1, file);
    }
}
void getlower(char lower[], int number[])
{
    int digit = 0;
    int i = 0;
    for (i = 0; i < 7; i++)
        digit = number[i];
    {
        switch (digit)
        {
        case 2 lower[i] = 'a';
            break;
            case 3:
            lower[i] = 'd';
            break;
        case 4:
            lower[i] = 'g';
            break;
        case 5:
            lower[i] = 'j';
            break;
        case 6:
            lower[i] = 'm';
            break;
        case 7:
            lower[i] = 'p';
            break;
        case 8:
            lower[i] = 't';
            break;
        case 9:
            lower[i] = 'w';
        default:
            break;
        }
    }
    return;
}
void getupper(char upper[], int number[])
{
    int digit = 0;
    int i = 0;
    for (i = 0; i < 7; i++)
        digit = number[i];
    {
        switch (digit)
        {
        case 2 upper[i] = 'c';
            break;
            case 3:
            upper[i] = 'f';
            break;
        case 4:
            upper[i] = 'i';
            break;
        case 5:
            upper[i] = 'l';
            break;
        case 6:
            upper[i] = 'o';
            break;
        case 7:
            upper[i] = 's';
            break;
        case 8:
            upper[i] = 'v';
            break;
        case 9:
            upper[i] = 'y';
        default:
            break;
        }
    }
    return;
}