#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int> 
#define F first 
#define S second 

const int maxn=1e6+10, oo=1e9;
int a[maxn], seg[4*maxn], lazy[4*maxn], n;

void build(int st=0, int en=n-1, int id=1) {
  lazy[id] = 0;
  if (st == en) {
    seg[id] = a[st];
    return;
  }
  int mid=(st+en)>>1;
  build(st, mid, id<<1|0);
  build(mid+1, en, id<<1|1);
  seg[id] = min(seg[id<<1|0], seg[id<<1|1]);
}

void update(int l, int r, int val, int st=0, int en=n-1, int id=1) {
  if (lazy[id]) {
    seg[id] += lazy[id];
    if (st != en) {
      lazy[id<<1|0] += lazy[id];
      lazy[id<<1|1] += lazy[id];
    }
    lazy[id] = 0;
  }
  if ((st > en) || (st > r || en < l)) return;

  if (st >= l && en <= r) {
    seg[id] += val;
    if (st != en) {
      lazy[id<<1|0] += val;
      lazy[id<<1|1] += val;
    }
    return;
  }
  int mid=(st+en)>>1;
  update(l, r, val, st, mid, id<<1|0);
  update(l, r, val, mid+1, en, id<<1|1);
  seg[id] = min(seg[id<<1|0], seg[id<<1|1]);
}

int query(int l, int r, int st=0, int en=n-1, int id=1) {
  if ((st > en) || (st > r || en < l)) return oo;
  if (lazy[id]) {
    seg[id] += lazy[id];
    if (st != en) {
      lazy[id<<1|0] += lazy[id];
      lazy[id<<1|1] += lazy[id];
    }
    lazy[id] = 0;
  }
  if (st >= l && en <= r) return seg[id];

  int mid = (st+en)>>1;
  int m1 = query(l, r, st, mid, id<<1|0);
  int m2 = query(l, r, mid+1, en, id<<1|1);
  return min(m1, m2);
}

inline bool cal(int n, int k, int ps) {
  build();
  
  int sum=0;
  for (int i=n-k-1; i>=0; i--) {
    int val = query(i+1, i+k);
    update(i+1, i+k, -val);
    sum += (val*k);
  }
  int val = query(0, k-1);
  sum += (val*k);

  return sum == ps;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t, k;
  cin>>t;
  while (t--) {
    cin>>n>>k;
    int ps=0;
    for (int i=0; i<n; i++) cin>>a[i], ps+=a[i];

    if (cal(n, k, ps))
      cout<<"Cake\n";
    else 
      cout<<"Fake\n";
  }
}
