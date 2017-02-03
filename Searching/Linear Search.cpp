#include <bits/stdc++.h>
using namespace std;
int linear_search(int arr[], int n, int x){
    int i;
    for(i = 0; i < n; i++){
        if(arr[i] == x)
            return i;
    }
    return -1;
}
int main(){
    int x, fl, arr[] = {1, 4, 5, 6, 7, 8, 2};
    cin >> x;
    fl = linear_search(arr, sizeof(arr) / sizeof(int), x);
    if(fl != -1) cout << x << " found on " << fl << " position" << endl;
    else cout << x << " is not found in the array!" << endl;
}
