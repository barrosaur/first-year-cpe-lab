#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

NODE *createNode(int value) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if(newNode == NULL) return NULL;

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

NODE *findParent(NODE *root, int height, int nodeCount) {
    if (root == NULL || height <= 1) return root;
    
    int parentIndex = (nodeCount - 1) / 2;
    int currentIndex = 1; 
    NODE *current = root;
    
    NODE *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        NODE *node = queue[front++];
        currentIndex++;
        
        if (currentIndex > parentIndex) {
            return node;
        }
        
        if (node->left) queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }
    
    return root; 
}

int countNodes(NODE *root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

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
            
            // heapify up
            NODE *child = current->left;
            while (child != root && child->value < current->value) {
                if (*stepMode) {
                    displayTree(root);
                    printf("Heapifying %d in Min Heap, press SPACE BAR to continue...\n", child->value);
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
                    break; // We've reached the root
                }
            }
            
            return root;
        }
        // If right child is empty, insert here
        else if (!current->right) {
            current->right = createNode(value);
            
            // Heapify up
            NODE *child = current->right;
            while (child != root && child->value < current->value) {
                // Display step if in step mode
                if (*stepMode) {
                    displayTree(root);
                    printf("Heapifying %d in Min Heap, press SPACE BAR to continue...\n", child->value);
                    waitForSpaceBar("");
                }
                
                // Swap values
                int temp = child->value;
                child->value = current->value;
                current->value = temp;
                
                // Find the parent of current node to continue heapify up
                child = current;
                
                // Find parent through tree traversal
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
                    break; // We've reached the root
                }
            }
            
            return root;
        }
        
        // Continue with level order traversal
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
    
    // This should not happen for a properly maintained heap
    printf("Error: Could not find insertion point in the heap.\n");
    return root;
}

NODE *insertMaxHeap(NODE *root, int value, bool *stepMode) {
    // If tree is empty, create root
    if (root == NULL) {
        return createNode(value);
    }
    
    // Use level-order traversal to find the first empty spot
    NODE *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        NODE *current = queue[front++];
        
        // If left child is empty, insert here
        if (!current->left) {
            current->left = createNode(value);
            
            // Heapify up
            NODE *child = current->left;
            while (child != root && child->value > current->value) {
                // Display step if in step mode
                if (*stepMode) {
                    displayTree(root);
                    printf("Heapifying %d in Max Heap, press SPACE BAR to continue...\n", child->value);
                    waitForSpaceBar("");
                }
                
                // Swap values
                int temp = child->value;
                child->value = current->value;
                current->value = temp;
                
                // Find the parent of current node to continue heapify up
                child = current;
                
                // Find parent through tree traversal
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
                    break; // We've reached the root
                }
            }
            
            return root;
        }
        // If right child is empty, insert here
        else if (!current->right) {
            current->right = createNode(value);
            
            // Heapify up
            NODE *child = current->right;
            while (child != root && child->value > current->value) {
                // Display step if in step mode
                if (*stepMode) {
                    displayTree(root);
                    printf("Heapifying %d in Max Heap, press SPACE BAR to continue...\n", child->value);
                    waitForSpaceBar("");
                }
                
                // Swap values
                int temp = child->value;
                child->value = current->value;
                current->value = temp;
                
                // Find the parent of current node to continue heapify up
                child = current;
                
                // Find parent through tree traversal
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
                    break; // We've reached the root
                }
            }
            
            return root;
        }
        
        // Continue with level order traversal
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
    
    // This should not happen for a properly maintained heap
    printf("Error: Could not find insertion point in the heap.\n");
    return root;
}

NODE *findLastNode(NODE *root) {
    if (root == NULL) return NULL;

    int nodeCount = countNodes(root);

    NODE *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    // BFS to find the last node
    int count = 0;
    while (front < rear) {
        NODE *node = queue[front++];
        count++;

        if (count == nodeCount) {
            return node;
        }

        if (node->left) queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }

    return NULL;
}

NODE *findParentOfLastNode(NODE *root) {
    if (root == NULL) return NULL;

    int nodeCount = countNodes(root);
    if (nodeCount <= 1) return NULL;

    NODE *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int count = 0;
    while (front < rear) {
        NODE *node = queue[front++];
        count++;

        if (node->right && count + 1 == nodeCount) {
            return node;
        }
        if (node->left && !node->right && count == nodeCount - 1) {
            return node;
        }

        if (node->left) queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }

    return NULL;
}
