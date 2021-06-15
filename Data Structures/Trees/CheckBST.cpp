/*
Binary Tree
    - H = height of the tree
        - root  = 0
        -       = 1
    - max # of nodes at a level "l" is 2^l
        - max number of nodes --> 2^(H + 1) - 1
*/
bool checkBST(NOde * n, int min, int max) {
    // Empty tree is a valid BST
    if (n == NULL) return true;
    // Must satisfy min/max constraints
    if (n->data < min || n->data > max) {
        return false;
    }
    // Check subtree and tighten constraints
    return checkBST(n->left, min, n->data - 1) &&
            checkBST(n->right, n->data + 1, max);
}