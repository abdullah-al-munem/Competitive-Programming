#include<iostream>
using namespace std;

///Iterative
int factorial_1(int n)
{
    unsigned int factorial;
    if (n < 0){
        cout << "Error! Factorial of a negative number doesn't exist.";
        return 0;
    }
    else {
        for(int i = 1; i <=n; ++i) {
            factorial *= i;
        }
        return factorial;
    }

}

///recursive
int factorial_2(int n)
{
    if(n > 1)
        return n * factorial_2(n - 1);
    else
        return 1;
}

// Factorial of a big number
#define MAX 500

int multiply(int x, int res[], int res_size);
void factorial(int n)
{
    int res[MAX];

    // Initialize result
    res[0] = 1;
    int res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);

    cout << "Factorial of given number is \n";
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
}


int main()
{
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    //cout << "Factorial of " << n << " = " << factorial(n);
    factorial(n);

    return 0;
}


int multiply(int x, int res[], int res_size)
{
    int carry = 0;  // Initialize carry

    // One by one multiply n with individual digits of res[]
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry  = prod/10;
    }

    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

