#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int count = 0;

struct stack
{
    int items[MAX];
    int top;
};
typedef struct stack st;

void createEmptyStack(st *s){
    s->top = -1;
}

int isFull(st *s){
    if(s->top == MAX-1)
        return 1;
    else
        return 0;
}
int isEmpty(st *s){
    if(s->top == -1)
        return 1;
    else
        return 0;
}
void push(st *s, int newitem){

    if(isFull(s)){
        printf("Stack Full");
    }
    else{
        s->top++;
        s->items[s->top]=newitem;
    }
    count++;
}
void pop(st *s){

    if(isEmpty(s)){
        printf("Stack Empty");
    }
    else{
        printf("Item popped: %d",s->items[s->top]);
        s->top--;
    }
    count--;
    printf("\n");
}
void printStack(st *s){
    printf("Stack: ");
    int i;
    for(i = 0; i<count; i++)
        printf("%d ",s->items[i]);
    printf("\n");
}

int main(){

    int ch;
    st *s = (st *)malloc(sizeof(st));
    createEmptyStack(s);

    push(s, 1); /// push(stack, value)
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    printf("After popping out\n");
    printStack(s);

    return 0;
}
