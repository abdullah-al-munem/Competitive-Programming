#include <stdio.h>
int n;
void insertionSort(int arr[]);
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

    insertionSort(arr);

    printf("After sorting...\n");
    printArray(arr);
    return 0;
}

void insertionSort(int arr[]){
    int i,j,tmp,flag=0;
    for(i=1; i<=n-1;i++){
        tmp = arr[i];
        for(j=i-1; j>=0; j--){
            if(arr[j] > tmp){
                arr[j+1] = arr[j];
                flag = 1;
            }
            else
                break;
        }
        if(flag)
            arr[j+1] = tmp;
    }
}

void printArray(int arr[])
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

