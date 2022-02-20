// C++ implementation of Dynamic Array
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define NULL_VALUE -999999
using namespace std;

template <class T>
class DynamicArray {
private:
    T *list;
    int max_size;
    int length;
public:
    DynamicArray() {
        // initially allocate a single memory block
        max_size = 1;
        list = new T[max_size];
        length = 0;
    }

    // insert a new item to the end of the list
    void add(T item) {
        if (isFull()) {
            // create temporary list with double size
            max_size = 2 * max_size;
            T *temp_list = new T[2* max_size];

            // move all the elements to the temporary list
            for (int i = 0; i < length; i++) {
                temp_list[i] = list[i];
            }

            // delete the old list
            delete [] list;

            // rename temp list
            list = temp_list;
        }

        // add the new item at the end of the list
        list[length] = item;
        length++;
    }

    int searchItem(T item)
    {
        int i = 0;
        for (i = 0; i < length; i++)
        {
            if( list[i] == item ) return i;
        }
        return NULL_VALUE;
    }

    void removeItemAt(int position) //do not preserve order of items
    {
        if ( position < 0 || position >= length ) return ; //nothing to remove
        list[position] = list[length-1] ;
        length-- ;
    }

    void remove(T item)
    {
        int position;
        position = searchItem(item) ;
        if ( position == NULL_VALUE ) return ; //nothing to remove
        removeItemAt(position) ;
    }

    void printList() {
        for (int i = 0; i < length; i++) {
            cout<<list[i]<<' ';
        }
        cout<<endl;
    }

    T getItem(int position)
    {
        if(position < 0 || position >= length) return NULL_VALUE ;
        return list[position] ;
    }
    int getLength()
    {
        return length ;
    }
    // check if the list is full
    bool isFull() {
        return length == max_size;
    }

    ~DynamicArray() {
        delete [] list;
    }


};

int main() {
    DynamicArray<char> list;
    list.add('1');
    list.add('2');
    list.add('3');
    list.add('4');
    list.add('5');
    list.add('6');
    list.add('7');
    list.add('8');
    list.add('9');
    list.remove('9');
    list.printList();
    return 0;
}


