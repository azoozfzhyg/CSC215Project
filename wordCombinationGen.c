#include <stdio.h>

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

void generateNumbers(int digits[], int index, int length , FILE *file ,char word[]) {
    if (index == length) {
        // Send the generated number to generateWords function
        generateWords(digits , word, 0, file);
        return;
    }

    for (int i = 2; i <= 9; i++) {
        digits[index] = i;
        generateNumbers(digits, index + 1, length , file , word);
    }
}

int main() {
    // Initialize the digits array
    int digits[7];
    char word[8];
    // Open the file for writing
    FILE *file = fopen("wordCombination.txt", "w");

    // Call the generateNumbers function
    generateNumbers(digits, 0, 7 , file , word);

    // Close the file
    fclose(file);

    return 0;
}