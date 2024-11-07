#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char str[50];
    int vowelCount = 0, consonantCount = 0;
    int i, j, strLength;
    char vowels[50] = "", consonants[50] = "";
    char vowelList[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

    printf("Enter a string: ");
    gets(str);

    strLength = strlen(str);

    for(i = 0; i < strLength; i++) {
        char ch = str[i];
        bool isVowel = false;

        for(j = 0; j < 10; j++) {
            if(ch == vowelList[j]) {
                isVowel = true;
                break;  
            }
        }

        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (isVowel) {
                vowels[vowelCount++] = ch;
            } else {
                vowels[consonantCount++] = ch;
            }
        }
    }

    vowels[vowelCount++] = '\0';
    consonants[consonantCount++] = '\0';

    printf("\n=================================================================\n");

    printf("Vowels                  : %s\n", vowels);
    printf("Number of vowels        : %d\n", vowelCount);
    printf("Consonants              : %s\n", consonants);
    printf("Number of consonants    : %d\n", consonantCount);

    return 0;
}