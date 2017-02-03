#include <bits/stdc++.h>
using namespace std;
void Swap(int *xp, int *yp){
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}
void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++){
        swapped = false;
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                Swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
