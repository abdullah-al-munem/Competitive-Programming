#include<stdio.h>
int stack[100], choice, n, top, x, i;
void push();
void pop();
void display();
int main()
{

    top = -1;
    printf("\n Enter the size of Stack[MAX=100]: ");
    scanf("%d",&n);
    printf("\n\t 1. Push\n\t 2. Pop\n\t 3. Display\n\t 4. Exit");
    do{

        printf("\nEnter You Choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            for(i=0; i<n; i++)
                push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExit...");

        }
    }while(choice>0 && choice<4);
    return 0;
}

void push(){

    if(top>=n-1){
        printf("\n\tStack is over flow");
    }
    else{
        printf(" Enter a value to be pushed: ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop(){

    if(top<=-1)
        printf("\n\t Stack is under flow");
    else{
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }


}
void display(){
    if(top>=0){
        printf("\n The elements in Stack \n");
        for(i = top; i>=0; i--)
            printf("\n %d",stack[i]);
        printf("\n\n Press Next Choice");
    }
    else
        printf("\n The Stack is empty");
}
