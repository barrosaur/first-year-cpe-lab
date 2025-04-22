#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

INPUT inputModule() {
    char buffer[100];
    char **words = NULL;
    int wordCount = 0;
    INPUT input;

    printf("Enter words: ");
    while(1) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(strchr(buffer, '!')) {
            break;
        }

        char *token = strtok(buffer, " \t");
        while(token != NULL) {
            char *word = strdup(token);

            for(int i = 0; word[i]; i++) {
                word[i] = tolower(word[i]);
            }

            char **temp = realloc(words, (wordCount + 1) * sizeof(char*));
            if(!temp) {
                printf("ERROR: memory allocation failed!\n\n");
                input.words = NULL;
                input.size = 0;
                free(temp);
                return input;
            }

            words = temp;
            words[wordCount++] = word;

            token = strtok(NULL, " \t");
        }
    }

    input.words = words;
    input.size = wordCount;
    
    return input;
}

void inputHandle(char *words[], int wordCount, NODE **root) {
    if(words != NULL && wordCount > 0) {
        printf("=== Building initial trie tree ===\n");
        printf("Inserting words: ");
        for(int i = 0; i < wordCount; i++) {
            printf("%s", words[i]);
            if(i < wordCount - 1) printf(", ");
        }
        printf("\n\n");

        for(int i = 0; i < wordCount; i++) {
            printf("Inserting \"%s\"...\n", words[i]);
            insertTrie(*root, words[i]);
        }
        
        displayTrie(*root);
        printf("Tree done!\n");
        printf("Press SPACE BAR to continue...\n\n");
        getchar();
    }
}

void waitForSpaceBar(const char *msg) {
    if(strlen(msg) > 0) {
        printf("%s", msg);
    }

    while(1) {
        int key = getchar();

        if(key == ' ') {
            break;
        }
    }
}

void clearInputBuffer() {
    while(getchar() != '\n');
}

int calculateTrieHeight(NODE *root) {
    if(root == NULL) return 0;

    int maxHeight = 0;

    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(root->children[i] != NULL) {
            int height = calculateTrieHeight(root->children[i]);

            if(height > maxHeight) {
                maxHeight = height;
            }
        }
    }

    return maxHeight + 1;
}

void printWord(char *prefix, int length) {
    for(int i = 0; i < length; i++) {
        printf("%c", prefix[i]);
    }
}

void printTrie(NODE *root, char *buffer[], int height, int level, int col, int width, char *prefix, int prefixLen) {
    if(root == NULL) return;

    if(level > height * 2) return;

    if(level > 0) {
        char nodeStr[2] = {root->character, '\0'};
        int position = col - 1;

        if(position < 0) position = 0;
        if(position >= CONSOLE_WIDTH - 1) position = CONSOLE_WIDTH - 2;

        buffer[level][position] = root->character;

        prefix[prefixLen - 1] = root->character;
    }

    int childrenCount = 0;
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(root->children[i] != NULL) {
            childrenCount++;
        }
    }

    if(childrenCount == 0) return;

    int spacing = width / (childrenCount + 1);
    if(spacing < 2) spacing = 2;

    int childPos = col - (spacing * (childrenCount - 1) / 2);

    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(root->children[i] != NULL) {
            if(level + 1 < height * 2) buffer[level+1][col] = '|';

            char newPrefix[100];
            memcpy(newPrefix, prefix, prefixLen);
            printTrie(root->children[i], buffer, height, level + 2, childPos, spacing, newPrefix, prefixLen + 1);

            childPos += spacing;
        }
    }
}

void displayTrie(NODE *root) {
    if(root == NULL) {
        printf("Trie is empty!\n\n");
        return;
    }
    
    int height = calculateTrieHeight(root);
    int bufferHeight = height * 2;
    
    if(bufferHeight > CONSOLE_HEIGHT - 5) {
        bufferHeight = CONSOLE_HEIGHT - 5;
    }
    
    char *buffer[bufferHeight];
    for(int i = 0; i < bufferHeight; i++) {
        buffer[i] = (char*)malloc(sizeof(char) * (CONSOLE_WIDTH + 1));
        if(buffer[i] == NULL) {
            printf("ERROR: Memory allocation failed for display buffer!\n\n");
            
            for(int j = 0; j < i; j++) {
                free(buffer[j]);
            }
            return;
        }
        
        memset(buffer[i], ' ', CONSOLE_WIDTH);
        buffer[i][CONSOLE_WIDTH] = '\0';
    }
    
    char prefix[100] = {0}; 
    printTrie(root, buffer, height, 0, CONSOLE_WIDTH / 2, CONSOLE_WIDTH / 3, prefix, 0);
    
    printf("\n=== TRIE STRUCTURE ===\n");
    for(int i = 0; i < bufferHeight; i++) {
        printf("%s\n", buffer[i]);
    }
    printf("\n");
    
    for(int i = 0; i < bufferHeight; i++) {
        free(buffer[i]);
    }
}