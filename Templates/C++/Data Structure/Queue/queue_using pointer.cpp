#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct node {
    int data;
    struct node *link;
}*head, *tail;
typedef struct node que;

void createEmptyQueue();
void insert();
void del();
void queueSize();
void check();
void firstElement();
void displayQueue();

int main()
{
    int choice, value;

   printf("\n\t 1. Create an empty queue\n\t 2. Insert element\n\t 3. Dequeue\n\t 4. Check if empty\n\t 5. First element\n\t 6. Len of queue\n\t 7. Display Queue\n\t 8. Exit");
    do{

        printf("\nEnter You Choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            createEmptyQueue();

            break;
        case 2:
            insert();
            break;
        case 3:
            del();
            break;
        case 4:
            check();
            break;
        case 5:
            firstElement();
            break;
        case 6:
            queueSize();
            break;
        case 7:
            displayQueue();
            break;
        case 8:
            printf("\nExit...");
            break;
        default:
            printf("wrong choice\n");
            break;
        }
    }while(choice>0 && choice<8);
    return 0;
}
void createEmptyQueue(){
    printf("Empty queue is created with a capacity of %d\n", MAX);

}
void insert(){
    que *tmp;

    tmp = (que *)malloc(sizeof(que));
    printf("Enter value to be inserted \n");
    scanf("%d", &tmp->data);
    tmp->link = NULL;
    if(tail == NULL){
        head = (que *)malloc(sizeof(que));
        tail = (que *)malloc(sizeof(que));
        head = tail = tmp;
    }

    else{

        tail->link = tmp;
        tail = tmp;
    }
}
void del(){
    que *tmp;

    tmp = (que *)malloc(sizeof(que));
    tmp = head;
    if(head == NULL){
        printf("Queue is empty.\n");
        head = tail = NULL;
    }
    else{

        printf("Deleted element is %d\n", head->data);
        head = head->link;
        free(tmp);
    }

}
void check(){
    if(head == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
        printf("Not empty.\n");
}
void queueSize(){
    int count = 0;
    que *tmp = (que *)malloc(sizeof(que));
    tmp = head;
    //tmp = head;
    while(tmp != NULL){
        count++;
        tmp = tmp->link;
    }
    printf("The size of queue is %d\n",count);
}
void firstElement(){
    printf("The first element is %d\n",head->data);
}
void displayQueue()
{
    que *tmp = (que *)malloc(sizeof(que));
    if(head == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        tmp = head;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->link);
            tmp = tmp->link;
        }
    }
}
