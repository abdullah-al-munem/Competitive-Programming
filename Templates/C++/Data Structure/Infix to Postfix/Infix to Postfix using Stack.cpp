#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack* sp);
int isEmpty(struct stack *ptr);
int isFull(struct stack *ptr);
void push(struct stack* ptr, char val);
char pop(struct stack* ptr);
int precedence(char ch);
int isOperator(char ch);
char* infixToPostfix(char* infix, int len);

int main()
{
    char * infix = "x-y/z-k*d";
    int len = strlen(infix);
    //cout << len << endl;
    printf("postfix is %s\n", infixToPostfix(infix, len+1));

    return 0;
}


int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2;
    else
        return 0;
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/')
        return 1;
    else
        return 0;
}


char* infixToPostfix(char* infix, int len){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = len;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;


}

