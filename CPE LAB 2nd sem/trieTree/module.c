#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "tree.h"

void insertWordModule(NODE **root) {
    char word[100];
    printf("=== INSERT WORD ===\n");
    
    printf("Enter word (lowercase letters only): ");
    scanf("%99s", word);
    clearInputBuffer();
    
    for(int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
    
    printf("Inserting word \"%s\"...\n", word);
    
    if(insertTrie(*root, word)) {
        printf("SUCCESS: Word added to trie!\n");
        displayTrie(*root);
    } else {
        printf("ERROR: Failed to insert word.\n");
    }
    
    printf("Press any key to return to MAIN MENU...\n");
    getch();
    return;
}

void searchWordModule(NODE *root) {
    char word[100];
    printf("=== SEARCH WORD ===\n");
    
    printf("Enter word to search: ");
    scanf("%99s", word);
    clearInputBuffer();
    
    for(int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
    
    printf("Searching for \"%s\"...\n", word);
    
    if(searchTrie(root, word)) {
        printf("SUCCESS: Word found in trie!\n");
    } else {
        printf("Word not found in trie.\n");
    }
    
    printf("Press any key to return to MAIN MENU...\n");
    getch();
    return;
}

void deleteWordModule(NODE **root) {
    char word[100];
    printf("=== DELETE WORD ===\n");
    
    printf("Enter word to delete: ");
    scanf("%99s", word);
    clearInputBuffer();
    
    for(int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
    
    printf("Deleting \"%s\"...\n", word);
    
    if(searchTrie(*root, word)) {
        *root = removeKey(*root, word, 0);
        printf("SUCCESS: Word deleted from trie!\n");
        displayTrie(*root);
    } else {
        printf("Word not found in trie. Nothing to delete.\n");
    }
    
    printf("Press any key to return to MAIN MENU...\n");
    getch();
    return;
}