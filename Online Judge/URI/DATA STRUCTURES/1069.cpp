#include<stdio.h>
#include <string.h>
int n = 1001, top;
char stack[1001];
void initialize();
void push(char a);
void pop();
int check(char a[]);

int main()
{
    char arr[1001];
    int N, i;
    int d;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        initialize();
        scanf("%s",&arr);
        d = check(arr);
        printf("%d\n",d);
    }
    return 0;
}
void initialize() {
 top = -1;
}
void push(char a){

    if(top>=n-1){
        return;
    }
    else{
        top++;
        stack[top]=a;
    }
}
void pop(){

    if(top<=-1){
        return;
    }

    else{
        top--;
    }


}

int check(char a[]){
    int i, count=0;
    for(i=0; a[i]!='\0';i++){
        if(a[i] == '<')
            push(a[i]);
        if(a[i] == '>' && top != -1){
            pop();
            count++;
        }
    }
    return count;

}

