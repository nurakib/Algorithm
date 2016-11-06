#include <bits/stdc++.h>
using namespace std;
int maxSubArraySum(int a[], int size){
    int max_so_far = a[0], max_ending_here = a[0];
    for(int i = 1; i < size; i++){
        max_ending_here = max(a[i], max_ending_here + a[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}
int main(){
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum << endl;
    return 0;
}

#another approch to find Largest Sum Contiguous Subarray


int maxSubArraySum(int a[], int size){
    int max_so_far = 0, max_ending_here = 0;
    for(int i = 0; i < size; i++){
        max_ending_here = max_ending_here + a[i];
        if(max_ending_here < 0)
            max_ending_here = 0;
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}


