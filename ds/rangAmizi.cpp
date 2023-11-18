#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

const int maxn = 1e5 + 10;
set<pii> segment[4 * maxn], lazy[4 * maxn];

int n, ans, ans1;

void update(int l, int r, int t, int val, int begin = 1, int end = n,
            int id = 1) {
  if (l > end || r < begin)
    return;

  if (begin >= l && end <= r) {
    segment[id].insert({t, val});
    return;
  }
  int mid = (begin + end) / 2;
  update(l, r, t, val, begin, mid, id << 1 | 0);
  update(l, r, t, val, mid + 1, end, id << 1 | 1);
}

int get(int index, int t, int begin = 1, int end = n, int id = 1) {
  auto it = segment[id].upper_bound({t, 0});
  it--;
  pii u = *it;
  if (abs(u.first - t) < abs(ans - t)) {
    ans1 = u.second;
    ans = u.first;
  }
  if (begin == end)
    return ans1;
  int mid = (begin + end) / 2;
  if (index >= begin && index <= mid)
    return get(index, t, begin, mid, id << 1 | 0);
  return get(index, t, mid + 1, end, id << 1 | 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int q, t, l, r, x, c;
  char type;
  cin >> n >> q;

  for (int i = 0; i < 4 * maxn; i++)
    segment[i].insert({0, 0});

  while (q--) {
    cin >> type;
    if (type == '~') {
      cin >> t >> l >> r >> c;
      update(l, r, t, c);
    } else {
      cin >> t >> x;
      ans = 2e9, ans1 = 2e9;
      cout << get(x, t) << '\n';
    }
  }
}
