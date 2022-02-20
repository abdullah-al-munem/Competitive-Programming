#include "iostream"
#include "math.h"
using namespace std;

#define MAXN 10000
#define SQRSIZE 100

int arr[MAXN];			 // original array
int segment[SQRSIZE];		 // decomposed array
int segment_size;					 // segment size

// Time Complexity : O(1)
void update(int idx, int val)
{
	int segmentNumber = idx / segment_size;
	segment[segmentNumber] += val - arr[idx];
	arr[idx] = val;
}

// Time Complexity : O(sqrt(n))
int query(int l, int r)
{
	int sum = 0;
	while (l<r and l%segment_size!=0 and l!=0)
	{
		sum += arr[l];
		l++;
	}
	while (l+segment_size <= r)
	{
		sum += segment[l/segment_size];
		l += segment_size;
	}
	while (l<=r)
	{
		sum += arr[l];
		l++;
	}
	return sum;
}

void preprocess(int input[], int n)
{
	int current_segment = -1;

	segment_size = sqrt(n);

	for (int i=0; i<n; i++)
	{
		arr[i] = input[i];
		if (i%segment_size == 0)
		{
			current_segment++;
		}
		segment[current_segment] += arr[i];
	}
}


int main()
{

	//int input[] = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
	int input[] = {1,4,2,2,1,1,2,1,3,5,1,2,7};
	int n = sizeof(input)/sizeof(input[0]);

	preprocess(input, n);

	cout << "query(1,10) : " << query(1, 10) << endl;
	cout << "query(3,8) : " << query(3, 8) << endl;
	cout << "query(1,6) : " << query(1, 6) << endl;
	update(8, 0);
	cout << "query(8,8) : " << query(8, 8) << endl;
	return 0;
}
