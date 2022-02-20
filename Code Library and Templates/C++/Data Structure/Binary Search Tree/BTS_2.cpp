#include<stdio.h>
#include<iostream>

using namespace std;

typedef struct BST{
    int data;
    struct BST *left;
    struct BST *right;

}Node;

Node* addNode(Node *root, int val);
Node *insert_node(Node *root, Node *tmp);
void inOrder(Node* root);

int main(){

    Node *root1 = NULL;

    root1 = addNode(root1, 50);
    root1 = addNode(root1, 40);
    root1 = addNode(root1, 70);
    root1 = addNode(root1, 10);
    root1 = addNode(root1, 90);

    inOrder(root1);
    cout << endl;

    return 0;
}

Node* addNode(Node *root, int val)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = val;
    tmp->left = tmp->right = NULL;

    if(root == NULL){
        root = (Node*)malloc(sizeof(Node));
        root = tmp;
    }
    else{
        root = insert_node(root, tmp);
    }

    return root;
}

Node *insert_node(Node *root, Node *tmp){

    if(tmp->data < root->data){

        if(root->left != NULL)
            insert_node(root->left, tmp);
        else
            root->left = tmp;
    }

    if(tmp->data > root->data){

        if(root->right != NULL)
            insert_node(root->right, tmp);
        else
            root->right = tmp;
    }

    return root;

}
void inOrder(Node* root){

    if(root != NULL){

        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }

}



