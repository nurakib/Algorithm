#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2]; //temp arrays to copy data
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    //merge temp arrays back into primary array
    i = 0; j = 0; k = l; //initial index of first, second, merged sub array
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //copy remaining elements of L[] or R[], if there is any
    while(i < n1){
        arr[k] = L[i];
        i++; k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++; k++;
    }
}
void mergesort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2; // (l+r) / 2
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void print_array(int arr[], int arr_size){
    for(int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int arr[] = {4, 5, 2, 1, 34, 5, 6, 7, 0, -1, -5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "Given Array: ";
    print_array(arr, arr_size);
    mergesort(arr, 0, arr_size - 1);
    cout << "Sorted Array: ";
    print_array(arr, arr_size);
    return 0;
}
