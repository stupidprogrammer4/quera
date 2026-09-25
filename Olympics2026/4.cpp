#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int maxn=3e5+10;
ll a[maxn], pre[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=2; i<=n; i++) {
        cin>>a[i];
        pre[i] = pre[i-1]+a[i];
    }

    if (n == 1) {
        cout<<1<<'\n';
        return 0;
    }

    ll ans=a[2], pw=1;
    for (int i=3; i<=n; i++) {
        int r1 = min((ll)n, i+pw-1);
        ll sum1 = pre[r1]-pre[i-1];
        ans = max(ans, sum1-pre[i-1]+1);

        ll pw2 = min((ll)n, pw*2);
        int r2 = min((ll)n, i+pw2-1);
        ll sum2 = pre[r2]-pre[i-1];
        ans = max(ans, sum2-pre[i-1]);

        pw = pw2;
    }

    cout<<ans<<'\n';
}
