#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  cin >> n >> q;
  vector<long long> sum(1), idx(n, 1), result;
  sum[0] = 0;
  for (int cnt = 0; cnt < q; cnt++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      sum.push_back(sum[sum.size() - 1] + x);
    } else if (type == 2) {
      int i, j;
      cin >> i >> j;
      int st = idx[i - 1], en = st + j - 1;
      long long ans = sum[en] - sum[st - 1];
      idx[i - 1] = en + 1;
      result.push_back(ans);
    }
  }
  for (auto &i : result)
    cout << i << '\n';
  return 0;
}
