#include <stdio.h>
int n;
int binarySearch(int arr[], int x, int first, int last);

int main()
{
    int search, i;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers: ", n);

    for (i = 0; i < n; i++)
       scanf("%d", &arr[i]);

    printf("Enter a number to search: ");
    scanf("%d", &search);

    int first = 0;
    int last = n - 1;
    int p = binarySearch(arr,search,first,last);
    if(p == -1)
        printf("Not found! %d isn't present in the list.\n", search);
    else
        printf("%d found at location %d.\n", search, p+1);

    return 0;
}

int binarySearch(int arr[], int x, int first, int last){

    int middle = first+(last-first)/2;

    if (last >= first)
    {
        int middle = first + (last - first)/2;

        if (arr[middle] == x)
            return middle;

        if (arr[middle] > x)
            return binarySearch(arr, x, first, middle-1);

        return binarySearch(arr, x, middle+1, last);
    }

    return -1;


}


