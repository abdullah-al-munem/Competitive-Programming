/*

AVL tree
=========

balance factor = height of left subtree - height of right subtree
bf = h(l) - h(r) = {-1, 0, 1} -> balanced

we have to found bf for each and every nodes.

Imbalance tree:
1. Left-Left (LL) imbalanced -> bf = 2
2. Left-Right (LR) imbalanced -> bf = 2
3. Right-Right (RR) imbalanced -> bf = -2
4. Right-Left (RL) imbalanced -> bf = -2

AVL Rotation: (to make tree balanced)
1. LL: rotate the root node at right.

2. LR: rotate the left node at left to convert the root to LL from LR.
       then, rotate the root node at right.

3. RR: rotate the root node at left.

4. RL: rotate the right node at right to convert the root to RR from RL.
       then, rotate the root node at left.

*/

#include<stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left,*right;
	int ht;
}node;

node *insert(node *,int);
node *Delete(node *,int);
void preorder(node *);
void inorder(node *);
int height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);

int main()
{
	node *root=NULL;
	int x,n,i,op;

	do
	{
		printf("\n1)Create:");
		printf("\n2)Insert:");
		printf("\n3)Delete:");
		printf("\n4)Print:");
		printf("\n5)Quit:");
		printf("\n\nEnter Your Choice:");
		scanf("%d",&op);

		switch(op)
		{
			case 1: printf("\nEnter no. of elements:");
					scanf("%d",&n);
					printf("\nEnter tree data: \n");
					root=NULL;
					for(i=0;i<n;i++)
					{
						scanf("%d",&x);
						root=insert(root,x);
					}
					break;

			case 2: printf("\nEnter a data: ");
					scanf("%d",&x);
					root=insert(root,x);
					break;

			case 3: printf("\nEnter a data: ");
					scanf("%d",&x);
					root=Delete(root,x);
					break;

			case 4: printf("\nPreorder sequence:\n");
					preorder(root);
					printf("\n\nInorder sequence:\n");
					inorder(root);
					printf("\n");
					break;
		}
	}while(op!=5);

	return 0;
}

node * insert(node *root,int x)
{
	if(root==NULL)
	{
		root=(node*)malloc(sizeof(node));
		root->data=x;
		root->left=NULL;
		root->right=NULL;
	}
	else
		if(x > root->data)		// insert in right subtree
		{
			root->right = insert(root->right,x);
			if(BF(root)==-2)
				if(x > root->right->data)
					root=RR(root);
				else
					root=RL(root);
		}
		else
			if(x < root->data)
			{
				root->left = insert(root->left,x);
				if(BF(root)==2)
					if(x < root->left->data)
						root=LL(root);
					else
						root=LR(root);
			}

		root->ht=height(root);

		return(root);
}

node * Delete(node *root,int x)
{
	node *tmp;

	if(root==NULL)
	{
		return NULL;
	}
	else
		if(x > root->data)		// insert in right subtree
		{
			root->right=Delete(root->right,x);
			if(BF(root)==2)
				if(BF(root->left)>=0)
					root = LL(root);
				else
					root = LR(root);
		}
		else
			if(x < root->data)
			{
				root->left=Delete(root->left,x);
				if(BF(root)==-2)	//Rebalance during windup
					if(BF(root->right)<=0)
						root = RR(root);
					else
						root=RL(root);
			}
			else
			{
				//data to be deleted is found
				if(root->right!=NULL)
				{	//delete its inorder succesor
					tmp=root->right;

					while(tmp->left!= NULL)
						tmp=tmp->left;

					root->data=tmp->data;
					root->right=Delete(root->right,tmp->data);

					if(BF(root)==2)//Rebalance during windup
						if(BF(root->left)>=0)
							root=LL(root);
						else
							root=LR(root);\
				}
				else
					return(root->left);
			}
	root->ht=height(root);
	return(root);
}

int height(node *root)
{
	int lh,rh;
	if(root==NULL)
		return(0);

	if(root->left==NULL)
		lh=0;
	else
		lh=1+root->left->ht;

	if(root->right==NULL)
		rh=0;
	else
		rh=1+root->right->ht;

	if(lh>rh)
		return(lh);

	return(rh);
}

node * rotateright(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right; //y->right == null if x have only two nodes
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}

node * rotateleft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left; // y->left == null if x have only two nodes
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);

	return(y);
}

node * RR(node *root)
{
	root=rotateleft(root);
	return(root);
}

node * LL(node *root)
{
	root=rotateright(root);
	return(root);
}

node * LR(node *root)
{
    // it will convert the root to LL from LR
	root->left=rotateleft(root->left);
	root=rotateright(root);

	return(root);
}

node * RL(node *root)
{
    // it will convert the root to RR from RL
	root->right=rotateright(root->right);
	root=rotateleft(root);
	return(root);
}

int BF(node *root)
{
	int lh,rh;
	if(root==NULL)
		return(0);

	if(root->left==NULL)
		lh=0;
	else
		lh=1+root->left->ht;

	if(root->right==NULL)
		rh=0;
	else
		rh=1+root->right->ht;

	return(lh-rh);
}

void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d(Bf=%d) ",root->data,BF(root));
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d(Bf=%d) ",root->data,BF(root));
		inorder(root->right);
	}
}
