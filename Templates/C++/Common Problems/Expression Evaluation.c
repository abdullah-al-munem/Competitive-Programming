#include <stdio.h>
#include <stdlib.h>
int choice,n, x, i, c=0;
struct stack
{
    char item;
    struct stack *next;
}*head;
typedef struct stack st;

int isEmpty();
int isFull();
int lengthOfList();
void push(char newitem);
char pop();
void evaluateEquation(char *str, int len);
void display();

int main()
{
    printf("\n Write down the Equation: ");
    char str[50];
    gets(str);
    puts(str);
    evaluateEquation(str, strlen(str));


    return 0;
}

void evaluateEquation(char *str, int len){
    int i;
    for(i=0; i<len; i++){
        if(str[i]=="")
    }
}

void push(char newitem){


    st *fnNode, *tmp;
    int num, i;
    //head = (st*)malloc(sizeof(st));

    if(isFull())
    {
        printf("Stack Full\n");
    }
    else
    {
        if(head == NULL){
            head = (st *)malloc(sizeof(st));
            head->item = newitem;
            head->next = NULL;
            c++;

        }
        else{
            fnNode = (st *)malloc(sizeof(st));
            fnNode->item = newitem;
            fnNode->next = NULL;
            st* tmp = (st *)malloc(sizeof(st));
            tmp = head;
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
    tmp = head;
    while(tmp != NULL){
        count++;
        tmp = tmp->next;
    }
    return count;
}

int isFull(){
    //int len = lengthOfList();
    /*if(c == n)
        return 1;
    else
        return 0; */
    return 0;
}

int isEmpty(){
    if(head == NULL)
        return 1;
    else
        return 0;
}

char pop(){

    st* tmp = (st*)malloc(sizeof(st));
    if(isEmpty())
        printf("Stack Empty\n");
    /*else if(tmp == NULL){
        printf(" Memory can not be allocated.");
    }*/
    else{
        tmp = head;
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
        //printf("\n item of Stack %d which is being Pooped is: %d\n", l,tmp->item);
        c--;
        char a = tmp->item;
        free(tmp);
        return a;

    }
}





void display()
{
    st *tmp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        tmp = head;
        while(tmp != NULL)
        {
            printf(" item = %c\n", tmp->item);
            tmp = tmp->next;
        }
    }
}

