#include <stdio.h>
#include <stdlib.h>

int n, c = 0, x, choice;

struct queue {
    int data;
    struct queue *next;
}*head, *tail;
typedef struct queue que;

void createEmptyQueue();
void enQueue(int a);
void deQueue();
int lengthOfList();
int isFull();
int isEmpty();
void displayQueue();

int main()
{
    createEmptyQueue();
    printf(" Input the number of Queue node: ");
    scanf("%d", &n);

   printf("\n\t 1. Enqueue\n\t 2. Dequeue\n\t 3. Display\n\t 4. Exit");
    do{

        printf("\nEnter You Choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf(" Enter a value to be enqueued: ");
            scanf("%d",&x);
            enQueue(x);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            displayQueue();
            break;
        case 4:
            printf("\nExit...");
            break;
        }
    }while(choice>0 && choice<4);
    return 0;
}

void createEmptyQueue()
{
    head = NULL;
    tail = NULL;
}


void enQueue(int a){

    que *fnNode, *tmp;
    int num, i;

    if(isFull()){
        printf("\n\t Queue is Full\n");
        return;
    }
    if(head == NULL){
        head = (que *)malloc(sizeof(que));
        head->data = a;
        head->next = NULL;
        tail = head;
        c++;
    }
    else{

        fnNode = (que *)malloc(sizeof(que));
        fnNode->data = a;
        fnNode->next = NULL;
        tmp = (que *)malloc(sizeof(que));
        tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = fnNode;
        tail = fnNode;
        c++;
    }

}

void deQueue(){
    que* tmp = (que*)malloc(sizeof(que));
    if(isEmpty()){
        printf("Queue is empty.\n");
    }
    else{
        tmp = head;
        head = tmp->next;
        printf("\n item of Queue which is being Dequeued is: %d\n", tmp->data);
        free(tmp);
        c--;
    }
}

int lengthOfList(){
    int count = 0;
    que *tmp = head;
    //tmp = head;
    while(tmp != NULL){
        count++;
        tmp = tmp->next;
    }
    return count;
}

int isFull(){
    if(c == n)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if(head == NULL)
        return 1;
    else
        return 0;
}

void displayQueue()
{
    que *tmp;
    if(head == NULL)
    {
        printf("Queue is empty.");
    }
    else
    {
        tmp = head;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->data);
            tmp = tmp->next;
        }
    }
}
