#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e2+10, mod = 1e9 + 7;
int a[maxn], dp[maxn][maxn], c[maxn][maxn];

int main() {
	for (int i = 0; i < maxn; i++) 
		for (int j = 0; j <= i; j++) {
			if (j == i or j == 0) 
				c[i][j] = 1;
			else 
				c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;
		}
	
	int n;
	cin>>n;
	for (int i = 0; i < n; i++) cin>>a[i];

	for (int i = 1; i <= n + 1; i++)
		dp[i][i-1] = 1;
	
	for (int r = 1; r <= n; r++) 
		for (int l = r-1; l >= 1; l-=2) 
			for (int i = l+1; i <= r; i+=2) 
				if (a[i-1] < a[l-1])
					dp[l][r] = (dp[l][r] + 1LL * ((1LL * dp[l+1][i-1] * dp[i+1][r]) % mod) * c[(r-l+1)/2][(i-l+1)/2]) % mod;
	
	cout<<dp[1][n];
}   	 

