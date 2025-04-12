#include <stdio.h>
#include "../tree.h"

NODE *insertMinHeap(NODE *root, int value, bool *stepMode) {
    if (root == NULL) {
        return createNode(value);
    }
    
    NODE *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        NODE *current = queue[front++];
        
        if (!current->left) {
            current->left = createNode(value);
            
            NODE *child = current->left;
            while (child != root && child->value < current->value) {
                if (*stepMode) {
                    displayTree(root);
                    printf("Heapifying %d in Min Heap, press SPACE BAR to continue...\n\n", child->value);
                    waitForSpaceBar("");
                }
                
                int temp = child->value;
                child->value = current->value;
                current->value = temp;
                
                child = current;
                
                NODE *parent = NULL;
                NODE *traversal = root;
                NODE *queue2[1000];
                int front2 = 0, rear2 = 0;
                queue2[rear2++] = traversal;
                
                while (front2 < rear2) {
                    NODE *node = queue2[front2++];
                    if (node->left == child || node->right == child) {
                        parent = node;
                        break;
                    }
                    if (node->left) queue2[rear2++] = node->left;
                    if (node->right) queue2[rear2++] = node->right;
                }
                
                if (parent) {
                    current = parent;
                } else {
                    break; 
                }
            }
            
            return root;
        }

        else if (!current->right) {
            current->right = createNode(value);
            
            NODE *child = current->right;
            while (child != root && child->value < current->value) {
                if (*stepMode) {
                    displayTree(root);
                    printf("Heapifying %d in Min Heap, press SPACE BAR to continue...\n\n", child->value);
                    waitForSpaceBar("");
                }
                
                int temp = child->value;
                child->value = current->value;
                current->value = temp;
                
                child = current;
                
                NODE *parent = NULL;
                NODE *traversal = root;
                NODE *queue2[1000];
                int front2 = 0, rear2 = 0;
                queue2[rear2++] = traversal;
                
                while (front2 < rear2) {
                    NODE *node = queue2[front2++];
                    if (node->left == child || node->right == child) {
                        parent = node;
                        break;
                    }
                    if (node->left) queue2[rear2++] = node->left;
                    if (node->right) queue2[rear2++] = node->right;
                }
                
                if (parent) {
                    current = parent;
                } else {
                    break; 
                }
            }
            
            return root;
        }
        
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
    
    printf("Error: Could not find insertion point in the heap.\n\n");
    return root;
}