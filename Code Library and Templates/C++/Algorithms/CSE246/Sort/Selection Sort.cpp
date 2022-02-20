#include <stdio.h>
int n;
void selectionSort(int arr[]);
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
    selectionSort(arr);
    printf("After sorting...\n");
    printArray(arr);
    return 0;
}


void selectionSort(int arr[]){
    int i,j,pos,tmp;
    for(i = 0; i<n-1; i++){
        pos = i;
        for(j=i+1; j<n; j++){
            if(arr[pos]> arr[j])
                pos = j;
        }
        if(pos != i){
            tmp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = tmp;
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
