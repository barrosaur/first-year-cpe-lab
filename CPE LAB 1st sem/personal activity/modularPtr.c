// Goal:
//     display each letter and their numbers
//     find the letter with the most number of occurences

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

void countOccurrences(char *str, int *frequency);
void displayOccurences(int *frequency);
char findMaxOccurrences(int *frequency);

int main() {
    char input[MAX_LEN];
    int frequency[26] = {0}; //store every occurence of each letter

    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin);

    countOccurrences(input, frequency);

    displayOccurences(frequency);

    char maxLetter = findMaxOccurrences(frequency);
    if(maxLetter != '\0') {
        printf("Most occuring letter is %c", maxLetter);
    } else {
        printf("Wala");
    }

    return 0;
}

void countOccurrences(char *str, int *frequency) {
    while(*str) {
        if(isalpha(*str)) {
            char lowerCase = tolower(*str);
            frequency[lowerCase - 'a']++;
        }
        str++;
    }

    //what it does
    //1. checks if the string exists
    //2. check if si str kay naa uppercase letters
    //3. if naa uppercase, str is converted to lowercase (Hello => hello)
    //4. a, b => a:1, b:5
}

void displayOccurences(int *frequency) {
    for(int i = 0; i < 26; i++) {
        if(frequency[i] > 0) {
            printf("%c: %d\n", 'a' + i, frequency[i]);
        }
    }
}

char findMaxOccurrences(int *frequency) {
    int max = 0;
    char maxLetter = '\0';

    for(int i = 0; i < 26; i++) {
        if(frequency[i] > max) {
            max = frequency[i];
            maxLetter = 'a' + i;
        }
    }

    return maxLetter;
}