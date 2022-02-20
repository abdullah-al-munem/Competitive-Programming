#include<stdio.h>
#include <string.h>
int choice, n = 100, top, i, c = 0;
int stack[100], x;
void initialize();
void push(int a);
void pop();
void d2b(int a);
void display();
int main()
{
    int n;
    printf("Input: ");
    scanf("%d",&n);
    d2b(n);
    return 0;
}
void initialize() {
 top = -1;
}
void push(int a){

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

void d2b(int a){
    int i,r;
    while(a != 0){
        r = a%2;
        a = a/2;
        push(r);
    }
    display();
}

void display(){
    if(top>=0){
        printf("\n After convert into Binary: ");
        for(i = top; i>0; i--)
            printf("%d",stack[i]);
        //printf("\n\n Press Next Choice");
         printf("\n");
    }
    else
        printf("\n The Stack is empty");
}
