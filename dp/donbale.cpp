#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
const int maxn = 1e5 + 5, maxk = 100;
ll prefix_sum[maxn][maxk];
int a[maxn];
int main() {
    int n, q;
    cin>>n;
    int T = sqrt(n);
    int y = min(T, maxk);
    for (int i = 1; i <= n; i++) cin>>a[i];
    for (int k = 1; k <= y; k++) {
        for (int i = 1; i <= n; i++) {
            if (i >= k) 
                prefix_sum[i][k] = prefix_sum[i-k][k]+a[i];
            else
                prefix_sum[i][k] = a[i];
        }
    } 
    cin>>q;
    for (int i = 0; i < q; i++) {
        int s, k; 
        ll ans = 0;
        cin>>s>>k;
        if (k <= y) {
            int end = s + ((n - s)/k)*k;
            ans = prefix_sum[end][k] - prefix_sum[s][k] + (ll)a[s];
        }
        else {
            for (int j = 0; j <= (n - s)/k; j++)
                ans += a[s + j*k]; 
        }
        cout<<ans<<'\n';
    }
    return 0;
}