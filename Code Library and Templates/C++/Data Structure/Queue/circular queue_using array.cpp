#include<stdio.h>
int queue[100], choice, n, head, tail, x, i, starting_point = 0;
void createEmptyQueue();
void enQueue(int a);
void deQueue();
void display();
int main()
{
    createEmptyQueue();
    printf("\n Enter the size of Queue[MAX=100]: ");
    scanf("%d",&n);
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
            display();
            break;
        case 4:
            printf("\nExit...");
            break;
        }
    }while(choice>0 && choice<4);
    return 0;
}

void createEmptyQueue(){
    head = -1;
    tail = -1;
}

void enQueue(int a){
    //if(tail == head && head != -1 && head != 0){
    if((tail+1)%n == head){
        printf("\n\t Queue is Full\n");
        return;
    }
    if(head == -1){
        head = starting_point;
        tail = head;
        //printf(" Enter a value to be enqueued: ");
        //scanf("%d",&x);
        queue[tail] = a;

    }
    else{
        //printf(" Enter a value to be enqueued: ");
        //scanf("%d",&x);
        tail = (tail+1)%n;
        queue[tail] = a;

        //printf("\n Tail else2: %d\n",tail);
        //printf("\n Head else2: %d\n",head);
    }
}
void deQueue(){

    if(head <=-1){
        printf("\n\t Queue is empty\n");
        return;
    }
    if(head == tail){
        head = -1;
        tail = -1;
    }
    else{
        printf("\n\t The dequeued elements is %d",queue[head]);
        head = (head+1)%n;
    }


}
void display(){
    //printf("\n %d",queue[1]);
    //printf("\n head = %d\n",head);
    //printf("\n tail = %d\n",tail);


    if(head == -1)
        printf("\n The Queue is empty\n");
    else{
        printf("\n The elements in Queue \n");
        if(head > tail){
            for(i = head; i< n ; i++)
                printf("\n %d",queue[i]);
            for(i = starting_point; i<= tail ; i++)
                printf("\n %d",queue[i]);
        }
        else if(tail >= head){
            for(i = head; i<=tail; i++)
                printf("\n %d",queue[i]);
        }
        printf("\n\n Press Next Choice\n");

    }

}

