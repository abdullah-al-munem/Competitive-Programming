// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
#include <bits/stdc++.h>
using namespace std;

struct Activitiy{
	int start, finish;
};

bool activityCompare(Activitiy s1, Activitiy s2){

	return (s1.finish < s2.finish);
}

void printMaxActivities(Activitiy arr[], int n){

	sort(arr, arr+n, activityCompare);

	cout << "Following activities are selected n: ";

	int i = 0;
	cout << "(" << arr[i].start << ", " << arr[i].finish << ")";

	for (int j = 1; j < n; j++){
        if (arr[j].start >= arr[i].finish){
            cout << ", (" << arr[j].start << ", " << arr[j].finish << ")";
            i = j;
        }
	}
	cout << endl;
}

int main()
{
	Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
	int n = sizeof(arr)/sizeof(arr[0]);
	printMaxActivities(arr, n);


    //int n;
    cin >> n;
    Activitiy arr2[n];
    for(int i=0; i<n; i++){
        int s, f;
        cin >> s >> f;
        arr2[i].start = s;
        arr2[i].finish = f;
    }
    printMaxActivities(arr2, n);

	return 0;
}
