#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define vi vector<int>

const int maxn = 1e5 + 10;
int a[maxn], b[maxn], d[maxn], ps[maxn], tmp[maxn];
int ans = 0;

int merge(int begin, int mid, int end) {
  int i = begin, j = mid + 1, k = end, inv_count = 0, st = begin;
  while (i <= mid && j <= end) {
    if (b[j] >= b[i]) {
      tmp[st++] = b[i++];
    } else {
      tmp[st++] = b[j++];
      inv_count = inv_count + (mid - i + 1);
    }
  }

  while (i <= mid)
    tmp[st++] = b[i++];

  while (j <= end)
    tmp[st++] = b[j++];

  for (i = begin; i <= end; i++)
    b[i] = tmp[i];

  return inv_count;
}

int merge_sort(int begin, int end) {
  if (begin >= end)
    return 0;

  int mid = (begin + end) / 2, inv_count = 0;
  inv_count += merge_sort(begin, mid);
  inv_count += merge_sort(mid + 1, end);
  inv_count += merge(begin, mid, end);
  return inv_count;
}

void solve(string &s, char c) {
  int n = 0;
  for (char ch : s) {
    if (ch == c)
      a[n++] = 1;
    else
      a[n++] = 0;
  }

  ps[0] = 0;
  for (int i = 1; i <= n; i++) {
    ps[i] = ps[i - 1] + a[i - 1];
  }
  for (int i = 0; i <= n; i++)
    b[i] = 2 * ps[i] - i;

  int total = ((n + 1) * n) / 2;
  int t = merge_sort(0, n);
  ans = ans + (total - t);
}

void cal(string &s, int c1, int c2) {
  int i = 0, n = s.size(), sum = 0, k = 0;
  for (char c : s) {
    if (c == c1 + 97)
      d[i++] = 1;
    else if (c == c2 + 97)
      d[i++] = -1;
    else
      d[i++] = 0;
  }
  unordered_map<int, int> mp[maxn];
  for (i = 0; i < n; i++) {
    if (d[i] == 0) {
      k++;
      sum = 0;
      continue;
    }

    sum += d[i];

    if (sum == 0)
      ans--;

    if (mp[k].find(sum) != mp[k].end())
      ans -= mp[k][sum];

    mp[k][sum]++;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for (int i = 0; i < 26; i++) {
    char c = 'a' + i;
    solve(s, c);
  }

  for (int i = 0; i < 26; i++)
    for (int j = i + 1; j < 26; j++)
      cal(s, i, j);

  cout << ans << '\n';
}
