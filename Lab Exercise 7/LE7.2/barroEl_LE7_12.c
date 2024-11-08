#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int checkCharacter(char ch);

int main() {
    char str[100];
    int i, length, result;
    int vowelCount = 0, consonantCount = 0;
    
    printf("Enter a string: ");
    gets(str);

    length = strlen(str);

    for(i = 0; i < length; i++) {
        result = checkCharacter(str[i]);

        if(result == 1) {
            vowelCount++;
        } else if (result == 2) {
            consonantCount++;
        }
    }

    printf("Vowel count: %d\n", vowelCount);
    printf("Consonant count: %d\n", consonantCount);

    return 0;
}

int checkCharacter(char ch) {
    int flag;
    bool isVowel = (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U');
    bool isLetter = ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));

    if(isVowel) {
        flag = 1;
    } else if (isLetter) {
        flag = 2;
    } else {
        flag = 0;
    }

    return flag;
}