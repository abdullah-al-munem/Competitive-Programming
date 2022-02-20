#include <stdio.h>
int n;
void mergeSort(int arr[], int first, int last);
void mergeAll(int arr[], int first, int middle, int last);
void printArray(int arr[]);

int main()
{
    int i;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers: ", n);

    for (i = 0; i < n; i++)
       scanf("%d", &arr[i]);
    printArray(arr);

    int first = 0;
    int last = n - 1;
    mergeSort(arr,first,last);

    printf("After sorting...\n");
    printArray(arr);
    return 0;
}

void mergeSort(int arr[], int first, int last){
    if(first>=last)
        return;
    int m = first+(last-first)/2;
    mergeSort(arr, first, m);
    mergeSort(arr, m + 1, last);

    mergeAll(arr, first, m, last);

}

void mergeAll(int arr[], int first, int middle, int last){
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

void printArray(int arr[])
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


