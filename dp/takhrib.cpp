#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e2+10, mod = 1e9+7;
int a[maxn], dp[maxn][maxn*maxn];

int binary_search(int n, int x) {
    int begin = 0, end = n-1;
    while (begin <= end) {
        int mid = (begin+end)/2;
        if (a[mid] <= x)
            begin = mid + 1;
        else 
            end = mid - 1;
    }
    
    return end;
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin>>n>>q;
    int sum=0;
    for (int i=0; i<n; i++) {
        cin>>a[i];
        sum += a[i];
    }

    sort(a, a+n);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= a[i-1]) 
                dp[i][j] = (dp[i][j] + dp[i-1][j-a[i-1]] + 1) % mod;
            
        }
    }


    while (q--) {
        int k, d;
        cin>>k>>d;
        int i = binary_search(n, d)+1, j = k*d;
        if (j > sum) 
            j = sum;
        cout<<(dp[i][j])<<'\n';
    }
    
}