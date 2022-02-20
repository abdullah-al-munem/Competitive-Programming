#include <cstdio>

#include <algorithm>

using namespace std;

#define FOR(i, n) for (int i = 0; i < n; ++i)

int even[1000001];

int odd[1000001];

void mergeSort(int arr[], int first, int last);

void merge(int arr[], int first, int middle, int last);

int main()

{

    int n, xe = 0, xo = 0, a;

    scanf("%d", &n);

    FOR(i, n)

    {

        scanf("%d", &a);

        if(a % 2 == 0){

            even[xe] = a;

            xe++;

        }else{

            odd[xo] = a;

            xo++;

        }

    }

    int first1 = 0;
    int last1 = xe - 1;

    int first2 = 0;
    int last2 = xo - 1;

    mergeSort(even,first1,last1);
    mergeSort(odd,first2,last2);


    FOR(i, xe){
        printf("%i\n", even[i]);
    }

    FOR(i, xo){
        printf("%i\n", odd[xo - i - 1]);
    }


    return 0;

}


void mergeSort(int arr[], int first, int last){
    if(first>=last)
        return;
    int m = first+(last-first)/2;
    mergeSort(arr, first, m);
    mergeSort(arr, m + 1, last);

    merge(arr, first, m, last);

}

void merge(int arr[], int first, int middle, int last){
    int i, j, k;
	int x = middle - first + 1;
	int y = last - middle;

	int L[x], R[y];

	for (i = 0; i < x; i++)
		L[i] = arr[first + i];
	for (j = 0; j < y; j++)
		R[j] = arr[middle + 1 + j];

    i = 0;
	j = 0;
	k = first;
	while (i < x && j < y) {
		if (L[i] < R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < x) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < y) {
		arr[k] = R[j];
		j++;
		k++;
	}

}


