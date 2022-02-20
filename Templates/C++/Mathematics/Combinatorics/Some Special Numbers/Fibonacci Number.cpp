#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

//Use recursion
// O(n)
int fib_1(int n);

//print using loop
// O(n)
void printFib(int n);

// using formula -> F(n) = {[( sqrt(5) + 1)/2] ^ n} / sqrt(5)
// O(1)
int fib_2(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));

}

int main ()
{
    int n = 9;
    cout << fib_2(n)<<endl;
    printFib(n+1);
    //getchar();
    return 0;
}

int fib_1(int n)
{
    if (n <= 1)
        return n;
    return fib_1(n-1) + fib_1(n-2);
}

void printFib(int n){
    int first = 0, second = 1, next, c;

    printf("First %d terms of Fibonacci series are : \n",n);

    for ( c = 0 ; c < n ; c++ )
    {
        if ( c <= 1 )
            next = c;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ",next);
    }
    cout << endl;

}

