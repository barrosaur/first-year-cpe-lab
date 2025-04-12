#include <stdio.h>
#include "../tree.h"

int calculateTreeHeight(NODE *root) {
    if(root == NULL) {
        return 0;
    } else {
        int leftTreeHeight = calculateTreeHeight(root->left);
        int rightTreeHeight = calculateTreeHeight(root->right);

        return (leftTreeHeight > rightTreeHeight) ? (leftTreeHeight + 1) : (rightTreeHeight + 1);
    }
}