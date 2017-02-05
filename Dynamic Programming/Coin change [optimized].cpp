#include <bits/stdc++.h>
using namespace std;
int count(int s[], int m, int n){
    int table[n + 1] = {0};
    table[0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = s[i]; j <= n; j++){
            table[j] = table[j] + table[j - s[i]];
        }
    }
    return table[n];
}
int main(){
    int ammnt, coins[] = {50, 25, 10, 5, 1};
    int sz = sizeof(coins) / sizeof(int);
    while(scanf("%d", &ammnt) == 1)
        printf("%d\n", count(coins, sz, ammnt));
    return 0;
}
