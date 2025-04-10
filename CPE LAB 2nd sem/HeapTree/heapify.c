#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void heapifyDownMin(NODE *root, NODE *node, bool *stepMode) {
    if (node == NULL) return;

    NODE *smallest = node;
    NODE *left = node->left;
    NODE *right = node->right;

    if (left && left->value < smallest->value) {
        smallest = left;
    }

    if (right && right->value < smallest->value) {
        smallest = right;
    }

    if (smallest != node) {
        if (*stepMode) {
            displayTree(root);
            printf("Heapifying %d in Min Heap, press SPACE BAR to continue...\n", node->value);
            waitForSpaceBar("");
        }

        // Swap values
        int temp = node->value;
        node->value = smallest->value;
        smallest->value = temp;

        // Recursively heapify the affected subtree
        heapifyDownMin(root, smallest, stepMode);
    }
}

void heapifyDownMax(NODE *root, NODE *node, bool *stepMode) {
    if (node == NULL) return;

    NODE *largest = node;
    NODE *left = node->left;
    NODE *right = node->right;

    if (left && left->value > largest->value) {
        largest = left;
    }

    if (right && right->value > largest->value) {
        largest = right;
    }

    if (largest != node) {
        if (*stepMode) {
            displayTree(root);
            printf("Heapifying %d in Max Heap, press SPACE BAR to continue...\n", node->value);
            waitForSpaceBar("");
        }

        // Swap values
        int temp = node->value;
        node->value = largest->value;
        largest->value = temp;

        // Recursively heapify the affected subtree
        heapifyDownMax(root, largest, stepMode);
    }
}

NODE *deleteMinHeap(NODE *root, bool *stepMode) {
    if (root == NULL) {
        printf("Min Heap is empty, nothing to delete.\n");
        return NULL;
    }
    
    // Store the value being removed for display purposes
    int removedValue = root->value;
    
    // If root is the only node
    if (root->left == NULL && root->right == NULL) {
        free(root);
        printf("Removed last node with value %d from Min Heap.\n", removedValue);
        return NULL;
    }
    
    // Find the last node using level-order traversal
    NODE *lastNode = NULL;
    NODE *parentOfLastNode = NULL;
    
    // Use queue for level-order traversal
    NODE *queue[1000];
    NODE *parentQueue[1000]; // Track parent nodes
    int front = 0, rear = 0;
    
    queue[rear] = root;
    parentQueue[rear] = NULL; // Root has no parent
    rear++;
    
    // Find the last node in level order
    while (front < rear) {
        NODE *current = queue[front];
        NODE *parent = parentQueue[front];
        front++;
        
        // Update last node and its parent
        lastNode = current;
        parentOfLastNode = parent;
        
        // Add children to queue
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
    
    // Now lastNode contains the last node in level order
    if (*stepMode) {
        displayTree(root);
        printf("Deleting root %d, replacing with %d, press SPACE BAR to continue...\n", 
               root->value, lastNode->value);
        waitForSpaceBar("");
    }
    
    // Replace root value with last node's value
    root->value = lastNode->value;
    
    // Remove the last node
    if (parentOfLastNode) {
        if (parentOfLastNode->right == lastNode) {
            free(parentOfLastNode->right);
            parentOfLastNode->right = NULL;
        } else if (parentOfLastNode->left == lastNode) {
            free(parentOfLastNode->left);
            parentOfLastNode->left = NULL;
        }
    }
    
    // Only proceed with heapify if we still have nodes
    if (root->left || root->right) {
        // Start heapify down from root
        NODE *current = root;
        
        while (1) {
            NODE *smallest = current;
            NODE *left = current->left;
            NODE *right = current->right;
            
            // Find the smallest of current, left child, and right child
            if (left && left->value < smallest->value) {
                smallest = left;
            }
            
            if (right && right->value < smallest->value) {
                smallest = right;
            }
            
            // If current is already the smallest, stop heapify
            if (smallest == current) {
                break;
            }
            
            // Display step if in step mode
            if (*stepMode) {
                displayTree(root);
                printf("Heapifying %d in Min Heap, press SPACE BAR to continue...\n", current->value);
                waitForSpaceBar("");
            }
            
            // Swap values with the smallest child
            int temp = current->value;
            current->value = smallest->value;
            smallest->value = temp;
            
            // Move down to the child we swapped with
            current = smallest;
        }
    }
    
    printf("Successfully removed %d from Min Heap.\n", removedValue);
    return root;
}

NODE *deleteMaxHeap(NODE *root, bool *stepMode) {
    if (root == NULL) {
        printf("Max Heap is empty, nothing to delete.\n");
        return NULL;
    }
    
    // Store the value being removed for display purposes
    int removedValue = root->value;
    
    // If root is the only node
    if (root->left == NULL && root->right == NULL) {
        free(root);
        printf("Removed last node with value %d from Max Heap.\n", removedValue);
        return NULL;
    }
    
    // Find the last node using level-order traversal
    NODE *lastNode = NULL;
    NODE *parentOfLastNode = NULL;
    
    // Use queue for level-order traversal
    NODE *queue[1000];
    NODE *parentQueue[1000]; // Track parent nodes
    int front = 0, rear = 0;
    
    queue[rear] = root;
    parentQueue[rear] = NULL; // Root has no parent
    rear++;
    
    // Find the last node in level order
    while (front < rear) {
        NODE *current = queue[front];
        NODE *parent = parentQueue[front];
        front++;
        
        // Update last node and its parent
        lastNode = current;
        parentOfLastNode = parent;
        
        // Add children to queue
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
    
    // Now lastNode contains the last node in level order
    if (*stepMode) {
        displayTree(root);
        printf("Deleting root %d, replacing with %d, press SPACE BAR to continue...\n", 
               root->value, lastNode->value);
        waitForSpaceBar("");
    }
    
    // Replace root value with last node's value
    root->value = lastNode->value;
    
    // Remove the last node
    if (parentOfLastNode) {
        if (parentOfLastNode->right == lastNode) {
            free(parentOfLastNode->right);
            parentOfLastNode->right = NULL;
        } else if (parentOfLastNode->left == lastNode) {
            free(parentOfLastNode->left);
            parentOfLastNode->left = NULL;
        }
    }
    
    // Only proceed with heapify if we still have nodes
    if (root->left || root->right) {
        // Start heapify down from root
        NODE *current = root;
        
        while (1) {
            NODE *largest = current;
            NODE *left = current->left;
            NODE *right = current->right;
            
            // Find the largest of current, left child, and right child
            if (left && left->value > largest->value) {
                largest = left;
            }
            
            if (right && right->value > largest->value) {
                largest = right;
            }
            
            // If current is already the largest, stop heapify
            if (largest == current) {
                break;
            }
            
            // Display step if in step mode
            if (*stepMode) {
                displayTree(root);
                printf("Heapifying %d in Max Heap, press SPACE BAR to continue...\n", current->value);
                waitForSpaceBar("");
            }
            
            // Swap values with the largest child
            int temp = current->value;
            current->value = largest->value;
            largest->value = temp;
            
            // Move down to the child we swapped with
            current = largest;
        }
    }
    
    printf("Successfully removed %d from Max Heap.\n", removedValue);
    return root;
}

void freeTree(NODE *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
