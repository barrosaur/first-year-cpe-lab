#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

NODE *createNode() {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if(newNode == NULL) return NULL;

    newNode->isEndOfWord = false;
    newNode->character = '\0';  // Add this line to initialize the character
    
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = NULL;
    }
    
    return newNode;
}

bool insertTrie(NODE *root, const char *key) {
    if(root == NULL) return false;
    
    NODE *current = root;
    int length = strlen(key);
    
    for(int i = 0; i < length; i++) {
        int index = key[i] - 'a';
        
        if(index < 0 || index >= ALPHABET_SIZE) {
            printf("ERROR: Invalid character '%c' in key. Only lowercase letters allowed.\n", key[i]);
            return false;
        }
        
        if(current->children[index] == NULL) {
            current->children[index] = createNode();
            if(current->children[index] == NULL) {
                printf("ERROR: Memory allocation failed for new node.\n");
                return false;
            }
            current->children[index]->character = key[i];
        }
        
        current = current->children[index];
    }
    
    current->isEndOfWord = true;
    return true;
}

bool searchTrie(NODE *root, const char *key) {
    if(root == NULL) return false;
    
    NODE *current = root;
    int length = strlen(key);
    
    for(int i = 0; i < length; i++) {
        int index = key[i] - 'a';
        
        if(index < 0 || index >= ALPHABET_SIZE) {
            return false;
        }
        
        if(current->children[index] == NULL) {
            return false;
        }
        
        current = current->children[index];
    }
    
    return (current != NULL && current->isEndOfWord);
}

bool isEmpty(NODE *node) {
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(node->children[i] != NULL) {
            return false;
        }
    }
    return true;
}

NODE *removeKey(NODE *root, const char *key, int depth) {
    if(root == NULL) return NULL;
    
    if(depth == strlen(key)) {
        if(root->isEndOfWord) {
            root->isEndOfWord = false;
        }
        
        if(isEmpty(root)) {
            free(root);
            root = NULL;
        }
        
        return root;
    }
    
    int index = key[depth] - 'a';
    root->children[index] = removeKey(root->children[index], key, depth + 1);
    
    if(isEmpty(root) && root->isEndOfWord == false) {
        free(root);
        root = NULL;
    }
    
    return root;
}

void freeTrie(NODE *root) {
    if(root != NULL) {
        for(int i = 0; i < ALPHABET_SIZE; i++) {
            if(root->children[i] != NULL) {
                freeTrie(root->children[i]);
            }
        }
        free(root);
    }
}