#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define in insert
#define X first
#define Y second

const int MAXN = 2e5 + 69, MOD = 1e9 + 7;

int n, q, arr[MAXN], seg[MAXN << 2], mark[MAXN << 2], lazy[MAXN << 2];

int mod(int val) {
  if (val < 0)
    val += MOD;
  return val % MOD;
}
int sum(int l, int r) {
  l++, r++;
  int R = mod(r * (r - 1) >> 1LL);
  int L = mod(l * (l - 1) >> 1LL);
  return mod(R - L);
}
void build(int l = 0, int r = n, int id = 1) {
  if (r - l == 1) {
    seg[id] = mod(arr[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, id << 1 | 0);
  build(mid, r, id << 1 | 1);
  seg[id] = mod(seg[id << 1 | 0] + seg[id << 1 | 1]);
}
void bang(int l, int r, int id) {
  int mid = (l + r) >> 1;

  seg[id << 1 | 0] = mod(seg[id << 1 | 0] + mod((mid - l) * lazy[id]));
  seg[id << 1 | 1] = mod(seg[id << 1 | 1] + mod((r - mid) * lazy[id]));
  lazy[id << 1 | 0] = mod(lazy[id << 1 | 0] + lazy[id]);
  lazy[id << 1 | 1] = mod(lazy[id << 1 | 1] + lazy[id]);
  lazy[id] = 0;

  seg[id << 1 | 0] = mod(seg[id << 1 | 0] + mod(mark[id] * sum(l, mid)));
  seg[id << 1 | 1] = mod(seg[id << 1 | 1] + mod(mark[id] * sum(mid, r)));
  mark[id << 1 | 0] = mod(mark[id << 1 | 0] + mark[id]);
  mark[id << 1 | 1] = mod(mark[id << 1 | 1] + mark[id]);
  mark[id] = 0;

  return;
}
void update(int st, int en, int val, int l = 0, int r = n, int id = 1) {
  if (l >= en or r <= st)
    return;
  if (l >= st and r <= en) {
    seg[id] = mod(seg[id] + mod((r - l) * val));
    lazy[id] = mod(lazy[id] + val);

    seg[id] = mod(seg[id] + sum(l, r));
    mark[id] = mod(mark[id] + 1);

    return;
  }
  int mid = (l + r) >> 1;
  bang(l, r, id);
  update(st, en, val, l, mid, id << 1 | 0);
  update(st, en, val, mid, r, id << 1 | 1);
  seg[id] = mod(seg[id << 1 | 0] + seg[id << 1 | 1]);
}
int get(int st, int en, int l = 0, int r = n, int id = 1) {
  if (l >= en or r <= st)
    return 0;
  if (l >= st and r <= en)
    return seg[id];
  int mid = (l + r) >> 1;
  bang(l, r, id);
  return mod(get(st, en, l, mid, id << 1 | 0) +
             get(st, en, mid, r, id << 1 | 1));
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  build();
  string type;
  int l, r;
  for (int it = 1; it <= q; it++) {
    cin >> type >> l >> r;
    if (type == "add")
      update(l - 1, r, mod(-l + 1));
    else
      cout << get(l - 1, r) << "\n";
  }
}
