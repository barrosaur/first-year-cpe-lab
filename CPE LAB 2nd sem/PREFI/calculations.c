#include <stdio.h>
#include "tree.h"

int calculateTreeHeight(NODE *root) {
    if (root == NULL) return -1; // Empty tree has height -1
    
    int leftHeight = calculateTreeHeight(root->left);
    int rightHeight = calculateTreeHeight(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Height of left subtree (excluding root)
int calculateLeftSubtreeHeight(NODE *root) {
    if (root == NULL) return -1;
    return calculateTreeHeight(root->left);
}

// Height of right subtree (excluding root)
int calculateRightSubtreeHeight(NODE *root) {
    if (root == NULL) return -1;
    return calculateTreeHeight(root->right);
}
