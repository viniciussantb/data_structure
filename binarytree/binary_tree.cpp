#include <iostream>

using namespace std;

struct Node{
public:
    Node* left, *right;
    int value;
    Node(int value){
        this -> value = value;
    }
};

void preorder(Node* node){
    // (Root, Left, Right)
    if(node == NULL) {
        return;
    };
    cout << node->value << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node){
    // (Left, Right, Root)
    if (node == NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->value << " ";
}

void inorder(Node* node){
    // (Left, Root, Right)

    if (node == NULL){
        return;
    }
    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}

int main(){
    struct Node *root = new Node(12);
    root->left = new Node(18);
    root->right = new Node(16);
    root->left->left = new Node(9);
    root->left->right = new Node(15);
    root->right->right = new Node(27);
    inorder(root);
    return 0;
}
