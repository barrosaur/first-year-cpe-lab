#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

#define CONSOLE_WIDTH 80
#define CONSOLE_HEIGHT 25
#define ALPHABET_SIZE 26
 
typedef struct {
    char **words;
    int size;
} INPUT;

typedef struct node {
    struct node *children[ALPHABET_SIZE];
    bool isEndOfWord;
    char character;
} NODE;

// utility.c
INPUT inputModule();
void inputHandle(char *words[], int wordCount, NODE **root);
void waitForSpaceBar(const char *msg);
void clearInputBuffer();
int calculateTrieHeight(NODE *root);
void printWord(char *prefix, int length);
void printTrie(NODE *root, char *buffer[], int height, int level, int col, int width, char *prefix, int prefixLen);
void displayTrie(NODE *root);

// node functions
NODE *createNode();
bool insertTrie(NODE *root, const char *key);
bool searchTrie(NODE *root, const char *key);
void freeTrie(NODE *root);
NODE *removeKey(NODE *root, const char *key, int depth);
bool isEmpty(NODE *node);

// module
void insertWordModule(NODE **root);
void searchWordModule(NODE *root);
void deleteWordModule(NODE **root);

#endif