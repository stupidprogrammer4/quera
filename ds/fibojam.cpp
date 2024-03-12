// be happy in your life :)
#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define F first
#define S second

const int maxn=3e5+10, mod=1e9+7;
int a[maxn], fib[maxn], n;
int seg[4*maxn];
pii lazy[4*maxn];

// build segment tree
void build(int begin=0, int end=n-1, int id=1) {
    if (begin == end) {
        seg[id] = a[begin];
        return;
    }
    int mid=(begin+end)>>1;
    build(begin, mid, id<<1|0);
    build(mid+1, end, id<<1|1);

    seg[id] = (seg[id<<1|0] + seg[id<<1|1])%mod;
}

// calculate h[k] where h is a fibonacci-like sequence
inline int cal(int a, int b, int k) {
    if (k == 1) return a;
    if (k == 2) return b;
    return ((1LL*a*fib[k-2])%mod + (1LL*b*fib[k-1])%mod)%mod;
}

// sum of h[i] where 1<=i<=k
inline int get_sum(int a, int b, int k) {
    if (k == 1) return a;
    if (k == 2) return (a+b)%mod;
    return ((cal(a, b, k+2) - b)%mod+mod)%mod;
}

// modify node
inline void modify(int id, int begin, int end, int a, int b) {
    lazy[id].F = (lazy[id].F + a) % mod;
    lazy[id].S = (lazy[id].S + b) % mod;
    seg[id] = (seg[id] + get_sum(a, b, end-begin+1)) % mod;
}

inline void propagate_lazy(int id, int begin, int end) {
    if (!lazy[id].F) return;
    int mid=(begin+end)>>1;
    int al = lazy[id].F, bl = lazy[id].S;
    int ar = cal(al, bl, mid-begin+2), br = cal(al, bl, mid-begin+3);
    modify(id<<1|0, begin, mid, al, bl);
    modify(id<<1|1, mid+1, end, ar, br);
    lazy[id].F = lazy[id].S = 0;
}

void update(int l, int r, int a, int b, 
        int begin=0, int end=n-1, int id=1) {
    if (begin > r || end < l) return;

    if (begin >= l && end <= r) {
        modify(id, begin, end, cal(a, b, begin-l+1), cal(a, b, begin-l+2));
        return;
    }
    propagate_lazy(id, begin, end);
    int mid=(begin+end)>>1;
    update(l, r, a, b, begin, mid, id<<1|0);
    update(l, r, a, b, mid+1, end, id<<1|1);

    seg[id] = (seg[id<<1|0] + seg[id<<1|1])%mod;
}

int query(int index, int begin=0, int end=n-1, int id=1) {
    if (begin == end) return seg[id];
    propagate_lazy(id, begin, end);
    int mid = (begin+end)>>1;
    int sum = 0;
    if (index <= mid)
        sum = (sum + query(index, begin, mid, id<<1|0))%mod;
    else 
        sum = (sum + query(index, mid+1, end, id<<1|1))%mod;
    
    return sum;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fib[1] = fib[2] = 1;
    for (int i=3; i<maxn; i++) fib[i] = (fib[i-1] + fib[i-2]) % mod;

    int q, l, r;
    cin>>n>>q;
    for (int i=0; i<n; i++) cin>>a[i];
    build();
    while (q--) {
        cin>>l>>r;
        l--, r--;
        update(l, r, fib[1], fib[2]);
    }
    for (int i=0; i<n; i++) cout<<query(i)<<' ';
    cout<<'\n';
}
