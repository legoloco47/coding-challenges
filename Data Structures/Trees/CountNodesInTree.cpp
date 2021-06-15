/*
This will count the number of nodes in a tree via 
    1. Recursion (DFS)
    2. A Queue (BFS)
*/

int countNodes_rec(Node * n) {
    if (n == NULL) return 0;
    int count = 0;
    if (n->left && n->right) {
        count = count + 1;
    }
    count += countNodes_rec(n->left);
    count += countNodes_rec(n->right);
    return count;
}

int countNodes(Node * n) {
    if (n == NULL) return 0;
    queue<Node *> q;
    int count = 0;
    q.push(n);
    while (!q.empty()) {
        struct Node * temp = q.front();
        q.pop();
        if (temp->left && temp->right) count++;
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    return count;
}