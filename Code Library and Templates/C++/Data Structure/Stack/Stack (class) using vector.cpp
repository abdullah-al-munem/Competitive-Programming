#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack{

private:
	vector<T> data;

public:
	bool Empty(); //checks if stack is empty
	void push(T item); //adds item to stack
	T top(); //returns item at top of stack
	void pop(); //removes item at top of stack
	friend ostream& operator<<(ostream&out, const Stack &s); //overloaded output operator
	void printStack();

};

template <class T>
bool Stack<T>::Empty() //checks if stack is empty
{
	return data.empty();
}

template <class T>
void Stack<T>::push(T item) //adds item to stack
{
	data.push_back(item);

}

template <class T>
T Stack<T>::top() //returns item at top of stack
{
	if(data.back()>-1)
	return data.back();

	else
		cerr<<"Stack is empty\n";
}

template <class T>
void Stack<T>::pop() //removes item at top of stack
{
	data.pop_back();
}

template <class T>
ostream & operator<<(ostream&out, const Stack<T> &s) //overloaded output operator
{
	while(!s.Empty())
	{
	out<<s.Top();
	s.Pop();
	}return out;
}

template <class T>
void Stack<T>::printStack() //removes item at top of stack
{
	for(T i = 0; i<data.size(); i++)
        cout << data[i] << " ";
    cout << endl;
}


int main(){

    Stack<int> sta;
    sta.push(2);
    sta.push(3);
    sta.push(4);
    sta.printStack();
    return 0;
}

