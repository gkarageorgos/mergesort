#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printArray(int A[], int size);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

int main(){
    int n; // Size of the array
    int max_value; // Maximum possible element in the array

    printf("Enter the size of the array:");
    scanf("%d", &n);

    printf("Enter the maximum possible element in the array:");
    scanf("%d", &max_value);

    // Set the seed for the rand() function based on the current time
    srand(time(0));

    // Create and generate random integers for the array
    int array[n];
    for (int i = 0; i < n; i++) {
        array[i] = rand() % max_value; // Generate a random number in the range [0, max_value-1]
    }

    printf("Random integer array:\n");
    printArray(array,n);

    mergeSort(array, 0, n - 1);

    printf("Sorted array:\n");
    printArray(array, n);


    return 0;
}


void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void merge(int arr[], int l, int m, int r) {
    int sizeA = m - l + 1;
    int sizeB = r - m;

    int A[sizeA];
    int B[sizeB];

    // Copy data to temporary arrays A and B
    for (int i = 0; i < sizeA; i++) {
        A[i] = arr[l + i];
    }
    for (int i = 0; i < sizeB; i++) {
        B[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    // Merge the two arrays A and B into C (in the original array arr)
    while (i < sizeA && j < sizeB) {
        if (A[i] < B[j]) {
            arr[k] = A[i];
            i++;
        } else {
            arr[k] = B[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from A and B to the original array arr
    while (i < sizeA) {
        arr[k] = A[i];
        i++;
        k++;
    }

    while (j < sizeB) {
        arr[k] = B[j];
        j++;
        k++;
    }
}


void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}