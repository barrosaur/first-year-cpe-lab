#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

NODE *deleteMinHeap(NODE *root, bool *stepMode) {
    if (root == NULL) {
        printf("Min Heap is empty, nothing to delete.\n");
        return NULL;
    }
    
    int removedValue = root->value;
    
    if (root->left == NULL && root->right == NULL) {
        free(root);
        printf("Removed last node with value %d from Min Heap.\n", removedValue);
        return NULL;
    }
    
    NODE *lastNode = NULL;
    NODE *parentOfLastNode = NULL;
    
    NODE *queue[1000];
    NODE *parentQueue[1000]; 
    int front = 0, rear = 0;
    
    queue[rear] = root;
    parentQueue[rear] = NULL; 
    rear++;
    
    while (front < rear) {
        NODE *current = queue[front];
        NODE *parent = parentQueue[front];
        front++;
        
        lastNode = current;
        parentOfLastNode = parent;
        
        if (current->left) {
            queue[rear] = current->left;
            parentQueue[rear] = current;
            rear++;
        }
        
        if (current->right) {
            queue[rear] = current->right;
            parentQueue[rear] = current;
            rear++;
        }
    }
    
    if (*stepMode) {
        displayTree(root);
        printf("Deleting root %d, replacing with %d, press SPACE BAR to continue...\n", 
               root->value, lastNode->value);
        waitForSpaceBar("");
    }
    
    root->value = lastNode->value;
    
    if (parentOfLastNode) {
        if (parentOfLastNode->right == lastNode) {
            free(parentOfLastNode->right);
            parentOfLastNode->right = NULL;
        } else if (parentOfLastNode->left == lastNode) {
            free(parentOfLastNode->left);
            parentOfLastNode->left = NULL;
        }
    }
    
    if (root->left || root->right) {
        NODE *current = root;
        
        while (1) {
            NODE *smallest = current;
            NODE *left = current->left;
            NODE *right = current->right;
            
            if (left && left->value < smallest->value) {
                smallest = left;
            }
            
            if (right && right->value < smallest->value) {
                smallest = right;
            }
            
            if (smallest == current) {
                break;
            }
            
            if (*stepMode) {
                displayTree(root);
                printf("Heapifying %d in Min Heap, press SPACE BAR to continue...\n", current->value);
                waitForSpaceBar("");
            }
            
            int temp = current->value;
            current->value = smallest->value;
            smallest->value = temp;
            
            current = smallest;
        }
    }
    
    printf("Successfully removed %d from Min Heap.\n", removedValue);
    return root;
}