#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

const int maxn = 5e5 + 10;

pii d[maxn];
int a[maxn];

bool compare(const pii &p1, const pii &p2) {
  if (p1.first == p2.first)
    return p1.second > p2.second;
  return p1.first < p2.first;
}

int findLIS(int n) {
  if (n == 0)
    return 0;

  vector<int> tail(n, 0);
  int length = 1;

  tail[0] = a[1];

  for (int i = 2; i <= n; i++) {

    auto b = tail.begin(), e = tail.begin() + length;
    auto it = lower_bound(b, e, a[i]);

    if (it == tail.begin() + length)
      tail[length++] = a[i];
    else
      *it = a[i];
  }

  return length;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> d[i].first;
    d[i].second = i + 1;
  }
  sort(d, d + n, compare);
  int k = 1;
  for (int i = 0; i < n; i++) {
    a[d[i].second] = k++;
  }
  for (int i = 1; i <= n; i++)
    a[i] *= -1;
  cout << findLIS(n) << '\n';
  for (int i = 1; i <= n; i++) {
    cout << a[i] * -1 << ' ';
  }
}
