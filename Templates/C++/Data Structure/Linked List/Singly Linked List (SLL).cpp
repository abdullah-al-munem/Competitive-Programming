#include<bits/stdc++.h>
#include <stdio.h>
#include <iostream>
using namespace std;


// Making a node struct containing a data int and a pointer
// to another node
struct Node {
    int data;
    Node *next;
};

class LinkedList
{
    // Head pointer
    Node* head;

public:
    // default constructor. Initializing head pointer
    LinkedList()
    {
        head = NULL;
    }

    static void concatenate(Node *a, Node *b)
    {
        if( a != NULL && b!= NULL )
        {
            if (a->next == NULL)
                a->next = b;
            else
                concatenate(a->next,b);
        }
        else
        {
            cout << "Either a or b is NULL\n";
        }
    }

    // inserting elements (At start of the list)
    void insert(int val)
    {
        // make a new node
        Node* new_node = new Node;
        new_node->data = val;
        new_node->next = NULL;

        // If list is empty, make the new node, the head
        if (head == NULL)
            head = new_node;
        // else, make the new_node the head and its next, the previous
        // head
        else
        {
            Node *current_node = head; //make a copy of root node
            while(current_node->next!=NULL) //Find the last node
            {
                current_node=current_node->next; //go to next address
            }
            Node *newnode = new Node(); //create a new node
            newnode->data= val;
            newnode->next = NULL;

            current_node->next=newnode; //link the last node with new node
        }
    }

    void insertBegin(int val){
        Node* fnNode = new Node;
        fnNode->data = val;
        fnNode->next = head;
        head = fnNode;
    }

    void insertEnd(int val){
        Node* fnNode = new Node;
        fnNode->data = val;
        fnNode->next = NULL;
        Node* tmp = new Node;
        tmp = head;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = fnNode;
    }

    void insertMiddle(int val, int p){

        Node* fnNode = new Node;
        fnNode->data = val;
        fnNode->next = NULL;
        Node* tmp = new Node;
        tmp = head;
        int i;
        for(i = 2; i<=p-1; i++){
            tmp = tmp->next;
            if(tmp == NULL)
                break;
        }
        if(tmp != NULL){
            fnNode->next = tmp->next;
            tmp->next = fnNode;
        }
        else
            printf("Insertion is not possible to this position.");

    }

    // loop over the list. return true if element found
    bool search(int val)
    {
        Node* temp = head;
        while(temp != NULL)
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    int lengthOfList(){
        int count = 0;
        Node* tmp = head;
        while(tmp != NULL){
            count++;
            tmp = tmp->next;
        }
        return count;
    }

    int isThere(int n){
        int c = 0;
        Node* tmp = head;
        while(tmp != NULL){
            if(n == tmp->data)
                c++;
            tmp = tmp->next;
        }
        return c;

    }

    void remove(int val)
    {
        // If the head is to be deleted
        if (head->data == val)
        {
            delete head;
            head = head->next;
            return;
        }

        // If there is only one element in the list
        if (head->next == NULL)
        {
            // If the head is to be deleted. Assign null to the head
            if (head->data == val)
            {
                delete head;
                head = NULL;
                return;
            }
            // else print, value not found
            cout << "Value not found!" << endl;
            return;
        }

        // Else loop over the list and search for the node to delete
        Node* temp = head;
        while(temp->next!= NULL)
        {
            // When node is found, delete the node and modify the pointers
            if (temp->next->data == val)
            {
                Node* temp_ptr = temp->next->next;
                delete temp->next;
                temp->next = temp_ptr;
                return;
            }
            temp = temp->next;
        }

        // Else, the value was neve in the list
        cout << "Value not found" << endl;
    }

    void removeFirstNode(){
        Node* tmp = head;
        head = tmp->next;
        printf("Data of node 1 which is being deleted is: %d\n", tmp->data);
        free(tmp);
    }

    void removeLastNode(){
        Node* tmp = head;
        int l, i;
        l = lengthOfList();
        Node* tmp2 = new Node;
        for(i = 1; i<=l; i++){
            if(i == l){
                tmp2->next = tmp->next;
                break;
            }
            tmp2 = tmp;
            tmp = tmp->next;
        }
        printf("Data of node %d which is being deleted is: %d\n", l,tmp->data);
        free(tmp);
    }

    void removeNodeByPosition(int p){

        Node* tmp = head;
        int l, i;
        l = lengthOfList();
        if(p > l){
            printf("Invalid Input\n");
        }
        else{
            Node* tmp2 = new Node;
            for(i = 1; i<=l; i++){
                if(i == p){
                    tmp2->next = tmp->next;
                    break;
                }
                tmp2 = tmp;
                tmp = tmp->next;
            }
            printf("Data of node %d which is being deleted is: %d\n", p,tmp->data);
            free(tmp);
        }
    }

    void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }

    void display()
    {
        Node* temp = head;
        if(head == NULL)
        {
            printf("List is empty.");
        }
        else
        {
            while(temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

    }

};

int main() {

    LinkedList l;
    // inserting elements
    l.insert(6);
    l.insert(9);
    l.insert(1);
    l.insert(3);
    l.insert(7);
    cout << "Current Linked List: ";
    l.display();

    cout << "Deleting 1: ";
    l.remove(1);
    l.display();

    cout << "Deleting 6: ";
    l.remove(6);
    l.display();

    cout << "Deleting 13: ";
    l.remove(13);

    cout << "Searching for 7: ";
    cout << l.search(7) << endl;

    cout << "Searching for 13: ";
    cout << l.search(13) << endl;


    return 0;
}

