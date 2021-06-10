#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Tree {
    Node *root;
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }



    // pre order means print, then search left, then search right
    void preOrder(Node *root) {
        // Preorder (Root, Left, Right)
        if (root == NULL) 
            return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
        
    }

    // postorder = start at the bottom of the tree
    void postOrder(Node *root) {
        // Postorder (Left, Right, Root)
        if (root == NULL) 
            return;

        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
    
    void inOrder(Node *root) {
        // Inorder (Left, Root, Right)
        if (root == NULL) 
            return;

        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }


}; //End of Tree

// From Hackerrank
int main() {
  
    Tree myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.preOrder(root);
    return 0;
}
