#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
int dp[MAX][MAX];
int lcslenght(string a, string b, int m, int n){
	for(int i = 0; i <= m; i++) dp[i][0] = 0;
	for(int j = 0; j <= n; j++) dp[0][j] = 0;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else 
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[m][n];
}
int main(){
	int m, n, ans;
	string a, b;
	while(getline(cin, a)){
		getline(cin, b);
		ans = lcslenght(a, b, a.size(), b.size());
		cout << ans << endl;
	}
	return 0;
}
