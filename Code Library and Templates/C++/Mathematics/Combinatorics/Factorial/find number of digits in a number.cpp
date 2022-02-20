#include <iostream>
#include <cmath>
using namespace std;

// normal approach
int count_digit_1(int number) {
    int count = 0;
    while(number != 0) {
        number = number / 10;
        count++;
    }
    return count;
}

// find using log10()
int count_digit(int number) {
    int count = (log10(number) + 1);
    return count;
}

int main() {
    cout << "Number of digits in 1245: " << count_digit(1245) << endl;

    return 0;
}
