//Simple implementation of a fixed sized Queue using an array
//the head and tail of the queue is circulated across the array

#include <iostream>
#include <cmath>
#include <cstdlib>
#include<stdio.h>

template <typename T>
class Queue{
private:
    //head tail position, enqueue limit, and current number of elements in the queue
    int head, tail, elementCount, queueInitSize = 2;
    int enqLmit = queueInitSize;
    T* data;

public:
    Queue(){
        queueInitSize = 2;
        enqLmit = queueInitSize;
        data = new T[enqLmit];
        elementCount= 0; // length
        head= 0;
        tail= 0;
    }

    T& front(){
        if(empty()){
            std::cerr<<"Error: Attempt to take data form empty Queue!"<<std::endl;
            exit(1);
        }

        return data[head];
    }

    T& back(void){
        if(empty()){
            std::cerr<<"Error: Attempt to take data form empty Queue!"<<std::endl;
            exit(1);
        }

        return data[tail];
    }

    bool empty(void){
        return (elementCount == 0);
    }

    bool full(void){
        return (elementCount == enqLmit);
    }

    int size(void){
        return elementCount;
    }

    int capacity(void){
        return enqLmit;
    }
    /*
    void enqueue(const T& obj){
        if(full()){
            std::cerr<< "Queue overflow error!" <<std::endl;
            return;
        }

        tail = (tail+1)%enqLmit;
        data[tail]= obj;
        elementCount++;
    }
    */

    void enqueue(const T& item){

        if (elementCount == enqLmit)
        {
            T * tempData ;
            //allocate new memory space for tempList
            enqLmit = 2 * enqLmit ;
            tempData = new T[enqLmit] ;
            int i, j;
            j = 0;
            for( i = head; i < elementCount ; i++ )
            {
                tempData[j++] = data[i] ; //copy items from rear
            }
            for( i = 0; i < head ; i++ )
            {
                tempData[j++] = data[i] ; //copy items before rear
            }
            head = 0 ;
            tail = elementCount;
            delete[] data ; //free the memory allocated before
            data = tempData ; //make list to point to new memory
        }

        data[tail] = item ; //store new item
        tail = (tail + 1) % enqLmit ;
        elementCount++ ;
    }

    void dequeue(void){
        if(empty()){
            std::cerr<< "Queue underflow error!" <<std::endl;
            return;
        }

        head = (head+1)%enqLmit;
        elementCount--;
    }

    void printQueue(){
        for(int i=0; i<elementCount; i++)
            printf("%d ",data[i]);
        printf("\n");

    }

};

int main(void)
{
    using std::cout;
    using std::endl;

    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
//    q.enqueue(7);     //Expect overflow

    cout<< "is the queue full: " << q.full() <<endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
//    q.dequeue();      //Expect underflow

    cout<< q.front() <<endl;
    cout<< q.back() <<endl;

    Queue<int> q2;
    q2.enqueue(2);
    q2.enqueue(3);
    q2.enqueue(4);
    q2.printQueue();
    return 0;
}
