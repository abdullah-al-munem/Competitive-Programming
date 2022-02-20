#include <stdio.h>
int n;
void bubbleSort(int arr[]);
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

    bubbleSort(arr);

    printf("After sorting...\n");
    printArray(arr);
    return 0;
}

void bubbleSort(int arr[]){
    int i,j,tmp;
    for(i=0; i<n-1;i++){
        for(j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}


void printArray(int arr[])
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
