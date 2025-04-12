#include <stdio.h>
#include "../tree.h"

int countNodes(NODE *root) {
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}