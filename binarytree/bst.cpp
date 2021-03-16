#include <iostream>

using namespace std;

struct Node{
public:
    Node* right;
    Node* left;
    int value;

    Node(int value){
        this -> value = value;
        right = NULL;
        left = NULL;
    }
};

Node* addNode(Node* root, int value){
    if (root == NULL){
        return new Node(value);
    }
    else if (root->value > value){
        root->left = addNode(root->left, value);
    } else{
        root->right = addNode(root->right, value);
    }
    return root;
}

Node* search(Node* root, int key){
    if (root == NULL || root->value == key){
        return root;
    }
    else if (root->value > key){
        search(root->left, key);
    }
    else{
        search(root->right, key);
    }
}

Node* minBST(Node* node){
    if(node->left == NULL){
        return node;
    }
    minBST(node->left);
}

int maxBST(Node* node){
    if(node->right == NULL){
        return node->value;
    }
    maxBST(node->right);
}

struct Node* deleteNode(Node* node, int key){
    if (node == NULL){
        return node;
    }

    if (node->value > key){
        node->left = deleteNode(node->left, key);
    } else if (node->value < key) {
        node->right = deleteNode(node->right, key);
    } else{
        // node with one child or no child
        if (node->right == NULL){
            Node* temp = node->left;
            free(node);
            return temp;
        }else if (node->left == NULL){
            Node* temp = node->right;
            free(node);
            return temp;
        }
        // node with two children
        Node* temp = minBST(node->right); // finding de successor
        node->value = temp->value;
        node->right = deleteNode(node->right, temp->value);
    }
    return node;
}

void printBST(Node* node){
    if (node == NULL){
        return;
    }
    printBST(node->left);
    cout << node->value << " ";
    printBST(node->right);
}

int main(){
    Node *node = new Node(15);
    addNode(node, 8);
    addNode(node, 35);
    addNode(node, 57);
    addNode(node, 20);
    addNode(node, 26);
    addNode(node, 6);
    addNode(node, 12);
    addNode(node, 2);
    addNode(node, 48);
    addNode(node, 46);
    printBST(node);
    node = deleteNode(node, 15);
    cout << endl;
    printBST(node);


    return 0;
}