// C++ implementation of doubly linked list
#include<bits/stdc++.h>
#include <stdio.h>
#include <iostream>
using namespace std;

// data structure for Node
// data -> the actual value
// next -> address of the next node
struct Node {
    int data;
    Node *next;
    Node *prev;
};

typedef Node *NodePtr;

class DoublyLinkedList{
    private:
    NodePtr head;
    NodePtr tail;

    public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;

    }

    int lengthOfList(){
        int count = 0;
        NodePtr tmp = head;
        while(tmp != NULL){
            count++;
            tmp = tmp->next;
        }
        return count;
    }

    void insert(int value) {

        if (isEmpty()) {
            NodePtr node = new Node;
            node->data = value;
            node->next = nullptr;
            node->prev = nullptr;
            head = node;
            tail = node;
        }
        else
        {
            NodePtr newnode = new Node();
            newnode->data = value;
            newnode->next = NULL;
            newnode->prev = tail;
            tail->next = newnode; //add the new node after tail node
            tail = tail->next; //move tail pointer forward
        }

    }

    // Insert 'value' at the front of the list
    void insertAtFront(int value) {
        NodePtr node = new Node;
        node->data = value;
        node->next = nullptr;
        node->prev = nullptr;

        if (isEmpty()) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    // insert value at the back of the linked list
    void insertAtEnd(int value) {
        NodePtr node = new Node;
        node->data = value;
        node->next = nullptr;

        if (isEmpty()) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    // inserts value after key
    void insertAfter(int key, int value) {
        NodePtr node = new Node;
        node->data = value;
        node->next = nullptr;

        // find the position of key
        NodePtr currPtr = head;
        while (currPtr != nullptr && currPtr->data != key) {
            currPtr = currPtr->next;
        }

        // if key is not there, raise error
        if (currPtr == nullptr) {
            cout<<"key not found";
        } else if (currPtr->next == nullptr) {
            // if key is the last node, insert right after it
            currPtr->next = node;
            node->prev = currPtr;
            tail = node;
        } else {
            // insert between key and item next to key
            NodePtr nextPtr = currPtr->next;
            currPtr->next = node;
            node->prev = currPtr;
            node->next = nextPtr;
            nextPtr->prev = node;
        }
    }

    void insertNodeAtMiddle(int num, int pos)
    {
        int i;
        NodePtr newnode, tmp;
        if(tail == NULL)
        {
        printf(" No data found in the list!\n");
        }
        else
        {
            tmp = head;
            i=1;
            while(i<pos-1 && tmp!=NULL)
            {
                tmp = tmp->next;
                i++;
            }
            if(tmp!=NULL)
            {
                newnode->data = num;
                //next address of new node is linking with the next address of temp node
                newnode->next = tmp->next;
                // previous address of new node is linking with the tmp node
                newnode->prev = tmp;
                if(tmp->next != NULL)
                {
                    tmp->next->prev = newnode; // n+1th node is linking with new node
                }
                tmp->next = newnode; // n-1th node is linking with new node
            }
            else
            {
                printf(" The position you entered, is invalid.\n");
            }
        }
    }

    // returns the data at first node
    int topFront() {
        if (isEmpty()) {
            cout<<"List is empty"<<endl;
        } else {
            return head->data;
        }
    }

    // returns the data at last node
    int topBack() {
        if (isEmpty()) {
            cout<<"List is empty"<<endl;
        } else if (head->next == nullptr) {
            return head->data;
        } else {
            NodePtr currPtr = head;
            while (currPtr->next != nullptr) {
                currPtr = currPtr->next;
            }
            return currPtr->data;
        }
    }

    // removes the item at front of the linked list and return
    void popFront() {
        int item;
        if (isEmpty()) {
            cout<<"List is empty"<<endl;
            //return -99999;
            return;
        } else {
            NodePtr nextPtr = head->next;
            if (nextPtr->next != nullptr) {
                nextPtr->prev = nullptr;
            }
            item = head->data;
            // remove head
            delete head;

            // make nextptr head
            head = nextPtr;
        }

        //return item;
    }

    // remove the item at the list of the linked list and return
    void popBack() {
        int item;
        if (isEmpty()) {
            cout<<"List if empty"<<endl;
            //return -99999;
            return;
        } else {
            item = tail->data;
            NodePtr prev = tail->prev;
            if (prev != nullptr) {
                prev->next = nullptr;
            }

            tail->prev = nullptr;
            delete tail;
            tail = prev;
        }

        //return item;
    }

    // removes an item with value 'key'
    void remove(int key) {
        if (isEmpty()) {
            cout<<"list is empty"<<endl;
            return;
        }

        // get to the position of key
        NodePtr currPtr = head;
        while(currPtr != nullptr && currPtr->data != key) {
            currPtr = currPtr->next;
        }

        if (currPtr == nullptr) {
            cout<<"Key is not found in the list"<<endl;
            return;
        }

        if (currPtr->prev == nullptr) {
            // this is the first item
            popFront();

        } else if (currPtr->next == nullptr) {
            // this is the last item
            popBack();
        } else {
            // anywhere in between first and last
            NodePtr nextPtr = currPtr->next;
            NodePtr prevPtr = currPtr->prev;
            nextPtr->prev = prevPtr;
            prevPtr->next = nextPtr;

            currPtr->next = nullptr;
            currPtr->prev = nullptr;
            delete currPtr;
            currPtr = nullptr;
        }
    }

    void removeNodeByPositiono(int pos)
    {
        NodePtr curNode;
        int i;
        int len = lengthOfList();
        curNode = head;
        for(i=1; i<pos && curNode!=NULL; i++)
        {
            curNode = curNode->next;
        }

        if(pos == 1)
        {
            popFront();
        }
        else if(pos == len || curNode == tail)
        {
            popBack();
        }
        else if(curNode != NULL)
        {
            curNode->prev->next = curNode->next;
            curNode->next->prev = curNode->prev;

            free(curNode); //Delete the n node
        }
        else
        {
            printf(" The given position is invalid!\n");
        }
    }


    // print the linked list
    void print() {
        NodePtr currPtr = head;
        while (currPtr != nullptr) {
            cout<<currPtr->data<<" ";
            currPtr = currPtr->next;
        }
        cout<<endl;
    }

    void printReverse() {
        NodePtr currPtr = tail;
        while (currPtr != nullptr) {
            cout<<currPtr->data<<" ";
            currPtr = currPtr->prev;
        }
        cout<<endl;
    }

    // check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // check if a key is in the list
    bool find(int key) {
        if (isEmpty()) {
            return false;
        }

        NodePtr currPtr = head;
        while (currPtr != nullptr && currPtr->data != key) {
            currPtr = currPtr->next;
        }

        if (currPtr == nullptr) {
            return false;
        }

        return true;
    }

};

int main() {
    DoublyLinkedList list;
    list.insertAtFront(1);
    list.insertAtFront(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.printReverse();
    list.insert(34);
    list.insert(44);
    list.insert(52);
    list.insert(22);
    list.print();
    list.printReverse();
    list.insertAfter(22, 33);
    list.insertAfter(52, 100);
    list.print();
    cout<<list.topFront()<<endl;
    list.print();
    cout<<list.topBack()<<endl;
    list.print();
    list.remove(100);
    list.printReverse();
    // operations
    return 0;
}
