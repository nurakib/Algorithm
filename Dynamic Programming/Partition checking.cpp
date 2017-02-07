#include <bits/stdc++.h>
using namespace std;
bool findPartition(int arr[], int n){
    int i, j, sum = 0;
    for(int i = 0; i < n; i++) //calculate sum of all elements
        sum += arr[i];
    if(sum % 2) //checking for odd number
        return false;
    bool part[sum / 2 + 1][n + 1];
    for(i = 0; i <= n; i++)  //initialize top row as true
        part[0][i] = true;
    for(i = 1; i <= sum / 2; i++)
        part[i][0] = false;
    //Fill the partition table in bottom up manner
    for(i = 1; i <= sum / 2; i++){
        for(j = 1; j <= n; j++){
            part[i][j] = part[i][j - 1];
            if(i >= arr[j - 1])
                part[i][j] = part[i][j] || part[i - arr[j - 1]][j - 1];
        }
    }
    return part[sum / 2][n];
}
int main(){
    int arr[] = {2, 3, 5};
    int n = 3; //arr[] size
    if(findPartition(arr, n) == true) cout << "Can be divided into two subsets of equal sum" << endl;
    else cout << "Can not be divided into two subsets of equal sum" << endl;
    return 0;
}
