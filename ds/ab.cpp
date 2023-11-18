#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;
int a[maxn], pre_max[maxn];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  pre_max[n] = a[n - 1];
  for (int i = n - 1; i >= 1; i--)
    pre_max[i] = max(pre_max[i + 1], a[i - 1]);

  int before_max = 0, after_max = pre_max[1], result = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i - 1] > before_max)
      before_max = a[i - 1];
    after_max = pre_max[i];
    int r = min(after_max, before_max) - a[i - 1];
    result += r;
  }
  cout << result << '\n';
  return 0;
}
