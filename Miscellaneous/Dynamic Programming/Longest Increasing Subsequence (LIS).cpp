#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20
#define EMPTY_VALUE -1

int mem[MAX_N];
int next_index[MAX_N];

int countLIS(int i, vector<int> &A) {
    if (mem[i] != EMPTY_VALUE) {
        return mem[i];
    }

    int ans = 0;
    for (int j = i + 1;j < A.size();j++) {
        if (A[j] > A[i]) {
            int subResult = countLIS(j, A);
            if (subResult > ans) {
                ans = subResult;
                next_index[i] = j;
            }
        }
    }

    mem[i] = ans + 1;
    return mem[i];
}

// O(n^2)
vector<int> findLIS(vector<int> A){
    int ans = 0;

    for(int i = 0;i<A.size();i++) {
        mem[i] = EMPTY_VALUE;
        next_index[i] = EMPTY_VALUE;
    }

    int start_index = -1;

    for(int i = 0;i<A.size();i++) {
        int result = countLIS(i, A);
        if (result > ans) {
            ans = result;
            start_index = i;
        }
    }

    vector<int> lis;
    while(start_index != -1) {
        lis.push_back(A[start_index]);
        start_index = next_index[start_index];
    }
    cout << "Length of LIS is: " << ans << endl;
    return lis;
}

int main(){

    vector<int> arr;

    arr.push_back(5);
    arr.push_back(0);
    arr.push_back(9);
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(4);

    arr = findLIS(arr);

    cout << "Subsequences Are: ";
    for(int elm : arr)
        cout << elm << " ";

    cout << endl;

    return 0;
}


