#include <stdio.h>
int n;
void linearSearch(int arr[], int search);
void linearSearch2(int arr[], int search);
int checkElement(int arr[], int search);

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
    linearSearch(arr,search);

    return 0;
}

void linearSearch(int arr[], int search){
    int i=0, c, count = 0;
    for (c = 0; c < n; c++) {
        if (arr[c] == search) {
            printf("%d is present at location %d.\n", search, c+1);
            count++;
        }
    }
    if (count == 0)
       printf("%d isn't present in the array.\n", search);
    else
        printf("%d is present %d times in the array.\n", search, count);

}

int checkElement(int arr[], int search){
    int first = 0;
    int last = n - 1;
    int middle = first+(last-first)/2;

    while (first <= last) {
        if (arr[middle] < search)
            first = middle + 1;
        else if (arr[middle] == search) {
            return 1;
            break;
        }
        else
            last = middle - 1;

        middle = (first + last)/2;
    }
    if (first > last)
        return 0;

}

void linearSearch2(int arr[], int search){
    int i=0, c, count = 0, location[100], p, q;
    for (c = 0; c < n; c++) {
        if (arr[c] == search) {
            p = c+1;
            //printf("%d is present at location %d.\n", search, c+1);
            count++;
        }
        q = checkElement(location, p);
        if(count!=0 && q!=1){
            location[i] = p;
            i++;
        }
    }
    if (count == 0)
       printf("%d isn't present in the array.\n", search);
    else{
        printf("%d is present %d times in the array at location: ", search, count);
        for(c=0; c<i; c++){
            printf("%d ",location[c]);
        }
        printf("\n");
    }

}


