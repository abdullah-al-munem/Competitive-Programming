#include<stdio.h>
#include <string.h>
int choice, n = 100, top, i, c = 0;
char stack[100], x;
void initialize();
void push(char a);
void pop();
void check(char a[]);
void display();
int main()
{
    char arr[100];
    initialize();
    printf("Enter a string of paranthesis: ");
    gets(arr);
    check(arr);
    return 0;
}
void initialize() {
 top = -1;
}
void push(char a){

    if(top>=n-1){
        printf("\n\tStack is over flow");
    }
    else{
        //printf(" Enter a value to be pushed: ");
        //scanf("%c",&x);
        top++;
        stack[top]=a;
    }
}
void pop(){

    if(top<=-1)
        printf("\n\t Stack is under flow");
    else{
        //Sprintf("\n\t The popped elements is %c\n",stack[top]);
        top--;
    }


}

void check(char a[]){
    int i;
    for(i=0; a[i]!='\0';i++){
        if(a[i] == '(')
            push(a[i]);
        //else if(a[i] == ')' || a[i] == '}' || a[i] == ']'){
        else if(a[i] == ')'){
            if(top == -1){
                printf("\nclosing parentheses is used without opening parentheses\n");
                push(a[i]);
            }

            else
                pop();
        }
    }
    //display();
    if(top<=-1)
        printf("\nValid Paranthesis Expression\n");
    else{
        if(stack[top] == '(')
            printf("\nOpening parentheses not end\n");
        else if(stack[top] == ')')
            printf("\nClosing parentheses not matched\n");
    }


}


void display(){
    if(top>=0){
        printf("\n The elements in Stack \n");
        for(i = top; i>=0; i--)
            printf("\n %c",stack[i]);
        //printf("\n\n Press Next Choice");
         printf("\n");
    }
    else
        printf("\n The Stack is empty");
}
