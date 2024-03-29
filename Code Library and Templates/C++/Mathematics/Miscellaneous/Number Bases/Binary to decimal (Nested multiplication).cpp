//Converts Binary (bit string) to decimal (long long) using nested multiplication

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

//converts string object
long long binaryToDecimal(const std::string& bin){
    long long res= bin[0] - '0';
    for(int i= 1; bin[i] !='\0'; i++){
        res *= 2;
        res += bin[i] - '0';
    }

    return res;
}

//converts C string / char array
long long binaryToDecimal(const char* bin){
    long long res= bin[0] - '0';
    for(int i= 1; bin[i] !='\0'; i++){
        res *= 2;
        res += bin[i] - '0';
    }

    return res;
}

int main(void)
{

    string bin = "11111111110000010110101011010";
    //Using string object:
    cout<< "Binary: " << bin<< "\nDecimal: " << binaryToDecimal(bin)  <<endl;
    //Using c string:
    cout<< "\nBinary: " << bin<< "\nDecimal: " << binaryToDecimal(bin.c_str())  <<endl;


    return 0;
}
