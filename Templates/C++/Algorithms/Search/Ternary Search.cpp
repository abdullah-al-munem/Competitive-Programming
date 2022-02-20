#include <stdio.h>
int n;
int ternarySearch(int arr[], int x, int first, int last);

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
    int p = ternarySearch(arr,search,first,last);
    if(p == -1)
        printf("Not found! %d isn't present in the list.\n", search);
    else
        printf("%d found at location %d.\n", search, p+1);

    return 0;
}

int ternarySearch(int arr[], int key, int first, int last){

    if (last - first > 0) {

        int mid1 = first + (last - first) / 3;
        int mid2 = mid1 + (last - first) / 3;

        if (arr[mid1] == key) {
            return mid1;
        }
        if (arr[mid2] == key) {
            return mid2;
        }
        if (key < arr[mid1]) {

            return ternarySearch(arr, key, first, mid1);
        }
        else if (key > arr[mid2]) {

            return ternarySearch(arr, key, mid2 + 1, last);
        }
        else {

            return ternarySearch(arr, key, mid1, mid2);
        }
    }

    return -1;


}


