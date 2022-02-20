#include <stdio.h>
#include <stdlib.h>
int choice,n, x, i, c=0;
struct stack
{
    int item;
    struct stack *next;
}*top;
typedef struct stack st;

int isEmpty();
int isFull();
int lengthOfList();
void push(int newitem);
void pop();
void display();

int main()
{
    printf("\n Enter the size of Stack: ");
    scanf("%d",&n);

    //s = (st *)malloc(sizeof(st));
    //createEmptyStack(s);
    printf("\n\t 1. Insert data/ push stack\n\t 2. Print stack\n\t 3. Pop stack\n\t 4. Exit");
    do{

        printf("\nEnter You Choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:


            for(i=0; i<n; i++){
                printf("Input Item %d: ",i+1);
                scanf("%d",&x);
                push(x); /// push(value)
            }
            printf("Pushed");


            break;
        case 2:
            display();
            break;
        case 3:
            pop();
            break;

        case 4:
            printf("\nExit...");

        }
    }while(choice>0 && choice<4);

    return 0;
}

void push(int newitem){


    st *fnNode, *tmp;
    int num, i;
    //top = (st*)malloc(sizeof(st));

    if(isFull())
    {
        printf("Stack Full\n");
    }
    else
    {
        if(top == NULL){
            top = (st *)malloc(sizeof(st));
            top->item = newitem;
            top->next = NULL;
            c++;

        }
        else{
            fnNode = (st *)malloc(sizeof(st));
            fnNode->item = newitem;
            fnNode->next = NULL;
            st* tmp = (st *)malloc(sizeof(st));
            tmp = top;
            while(tmp->next != NULL){
                tmp = tmp->next;
            }
            tmp->next = fnNode;
            c++;
        }

    }
    //return s;
}

int lengthOfList(){
    int count = 0;
    st *tmp;
    tmp = top;
    while(tmp != NULL){
        count++;
        tmp = tmp->next;
    }
    return count;
}

int isFull(){
    //int len = lengthOfList();
    if(c == n)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if(top == NULL)
        return 1;
    else
        return 0;
}

void pop(){

    st* tmp = (st*)malloc(sizeof(st));
    if(isEmpty())
        printf("Stack Empty\n");
    /*else if(tmp == NULL){
        printf(" Memory can not be allocated.");
    }*/
    else{
        tmp = top;
        int l, i;
        l = lengthOfList();
        st* tmp2 = NULL;
        for(i = 1; i<=l; i++){
            if(i == l){
                tmp2->next = tmp->next;
                break;
            }

            tmp2 = tmp;
            tmp = tmp->next;
        }
        printf("\n item of Stack %d which is being Pooped is: %d\n", l,tmp->item);
        free(tmp);
        c--;
    }
}

void display()
{
    st *tmp;
    if(top == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        tmp = top;
        while(tmp != NULL)
        {
            printf(" item = %d\n", tmp->item);
            tmp = tmp->next;
        }
    }
}
