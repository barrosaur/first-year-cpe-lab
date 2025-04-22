#include <stdio.h>
#include "tree.h"

int calculateTreeHeight(NODE *root) {
    if (root == NULL) return -1; 
    
    int leftHeight = calculateTreeHeight(root->prev);  
    int rightHeight = calculateTreeHeight(root->next); 
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int calculateLeftSubtreeHeight(NODE *root) {
    if (root == NULL || root->prev == NULL) return -1;  
    return calculateTreeHeight(root->prev);  
}

int calculateRightSubtreeHeight(NODE *root) {
    if (root == NULL || root->next == NULL) return -1;  
    return calculateTreeHeight(root->next);  
}