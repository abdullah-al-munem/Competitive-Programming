#include <iostream>
using namespace std;

template <typename T>
int sumDigits(T num){
    int m, sum = 0;
    while(num != 0){
        m = num%10;
        sum = sum + m;
        num /= 10;
    }

    return sum;
}

int main(void)
{

    cout<< sumDigits(64689) <<endl;
    cout<< sumDigits(9999) <<endl;

    return 0;
}
