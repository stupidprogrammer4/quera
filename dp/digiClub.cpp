#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int u64;

const u64 maxn=1e5+10, mod=1e9+7;
u64 a[maxn];

inline u64 sum(u64 l, u64 r) {
    u64 s0 = (l*(l+1))/((u64)2),
    s1 = (r*(r+1))/((u64)2);

    u64 s = (s1 - s0);
    s %= mod;

    return s;
}


map<u64, u64> mp;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    u64 n, k;
    cin>>n;

    for (u64 i=0; i<n; i++) {
        cin>>a[i];
        mp[a[i]] += 1LL;
    }
    cin>>k;

    sort(a, a+n);
    u64 m = distance(a, unique(a, a+n));

    u64 ans = 0, cnt, l, x;
    for (int i=m-1; i>=0; i--) {
        if (k == 0)
            break;
        l = i == 0 ? 0 : a[i-1];
        cnt = mp[a[i]];
        u64 diff_cnt = (a[i]-l)*cnt,
        poss_cnt = (k/cnt)*cnt;

        if (poss_cnt >= diff_cnt) {
            if (i > 0)
                mp[a[i-1]] += cnt;
            cnt = (cnt*sum(l, a[i])) % mod;
            ans = (ans + cnt) % mod;
            k -= diff_cnt;
        }
        else {
            l = a[i]-(k/cnt), x = k%cnt;
            ans = (ans + cnt*sum(l, a[i])) % mod;
            l = (l*x) % mod;
            ans = (ans + l) % mod;
            k=0;
        }
        ans %= mod;
    }

    cout<<ans<<'\n';     
      
}
