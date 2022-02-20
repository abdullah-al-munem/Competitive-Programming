#include <bits/stdc++.h>
using namespace std;

void printSubArrays(vector<int> arr, int start, int endx)
{

	if (endx == arr.size())
		return;

	else if (start > endx)
		printSubArrays(arr, 0, endx + 1);


	else
	{
		cout << "[";
		for (int i = start; i < endx; i++){
			cout << arr[i] << ", ";
		}

		cout << arr[endx] << "]" << endl;
		printSubArrays(arr, start + 1, endx);
	}

	return;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    printSubArrays(arr, 0, 0);

    /*
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=i; k<=j; k++)
                cout << v[k] << " ";
            cout << endl;
        }
    }
    */
    return 0;
}

