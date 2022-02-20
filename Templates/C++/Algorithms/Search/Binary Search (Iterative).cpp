#include <stdio.h>
int n;
void binarySearch(int arr[], int search);

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

    binarySearch(arr,search);

    return 0;
}

void binarySearch(int arr[], int search){

    int first = 0;
    int last = n - 1;
    int middle = first+(last-first)/2;

    while (first <= last) {
        if (arr[middle] < search)
            first = middle + 1;
        else if (arr[middle] == search) {
            printf("%d found at location %d.\n", search, middle+1);
            break;
        }
        else
            last = middle - 1;

        middle = (first + last)/2;
    }
    if (first > last)
        printf("Not found! %d isn't present in the list.\n", search);

}

