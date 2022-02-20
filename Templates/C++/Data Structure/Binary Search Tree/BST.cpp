#include<stdio.h>
#include <stdlib.h>

typedef struct BST{
    int data;
    struct BST *left;
    struct BST *right;

}node;

node *create();
void insert_node(node *root, node *tmp);
unsigned int getLeafCount(node* node);
node *search_node(node *root, int x);
node *find_min(node *root);
node *find_max(node *root);
node *delete_node(node *root, int x);
void preOrder(node* root);
void inOrder(node* root);
void postOrder(node* root);

int main(){
    char ch;
    node *root = NULL, *tmp;

    do{

        tmp = create();
        if(root == NULL)
            root = tmp;
        else
            insert_node(root, tmp);
        printf("Do you want to enter more(y/n)? - ");
        getchar();
        scanf("%c",&ch);
        if(!(ch=='y'||ch=='Y'||ch=='n'||ch=='N'))
        {
            printf("Invalid Option\n");
            printf("Continue: (y/n)");
            scanf("%c",&ch);
        }
    }while(ch == 'y' || ch == 'Y');

    printf("inOrder Traversal: ");
    //preOrder(root);
    inOrder(root);
    printf("\n");

    node *maxValue = find_max(root);
    printf("The max value: %d\n",maxValue->data);

    node *minValue = find_min(root);
    printf("The min value: %d\n",minValue->data);

    printf("Enter the value that you want to search: ");
    int x;
    scanf("%d",&x);
    node *searchValue = search_node(root,x);
    if(searchValue!= NULL)
        printf("%d is Found.\n",searchValue->data);


    printf("Enter the value that you want to delete: ");
    int y;
    scanf("%d",&y);
    delete_node(root,y);

    printf("inOrder Traversal: ");
    inOrder(root);
    printf("\n");

    return 0;
}

node *create(){
    node *tmp;
    printf("Enter data: ");
    tmp = (node*)malloc(sizeof(node));
    scanf("%d",&tmp->data);
    tmp->left = tmp->right = NULL;
    return tmp;
}

void insert_node(node *root, node *tmp){
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

}

unsigned int getLeafCount(node* node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    else
        return getLeafCount(node->left)+
            getLeafCount(node->right);

}

node* search_node(node *root, int x){

    if(root==NULL){
        printf("Not Found!!\n");
        return NULL;
    }
    if(root->data==x)
        return root;
    else if(x>root->data)
        search_node(root->right, x);
    else
        search_node(root->left,x);

}

node* find_min(node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left != NULL)
        return find_min(root->left);
    return root;
}

node* find_max(node *root){
     if(root == NULL)
        return NULL;
    else if(root->right != NULL)
        return find_max(root->right);
    return root;
}

node *delete_node(node *root, int x){

    int c =0;

    if(root==NULL)
        return NULL;
    if (x > root->data)
        root->right = delete_node(root->right, x);
    else if(x < root->data)
        root->left = delete_node(root->left, x);
    else
    {

        c++;
        //printf("x %d = %d\n",c,x);

        //No Children
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left==NULL || root->right==NULL)
        {
            node *tmp;
            if(root->left==NULL)
                tmp = root->right;
            else
                tmp = root->left;
            free(root);
            return tmp;
        }

        //Two Children
        else
        {
            node *tmp = find_min(root->right); //for finding Successor Node
            root->data = tmp->data;
            root->right = delete_node(root->right, tmp->data); //delete Successor Node
        }
    }
    // x is not in BST
    if(c == 0 && root->right == NULL && root->left == NULL){
        printf("%d is not in this BST\n",x);
    }

    return root;
}


void preOrder(node* root){

    if(root != NULL){

        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }

}

void postOrder(node* root){

    if(root != NULL){

        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }

}

void inOrder(node* root){

    if(root != NULL){

        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }

}

