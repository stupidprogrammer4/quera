#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  stack<int> st;
  int i = 0, maxArea = 0;
  while (i < n) {
    if (st.empty() or a[st.top()] <= a[i]) {
      st.push(i++);
      continue;
    }
    int height = a[st.top()], width;
    st.pop();
    width = st.empty() ? i : i - st.top() - 1;
    maxArea = max(maxArea, height * width);
  }
  while (!st.empty()) {
    int height = a[st.top()], width;
    st.pop();
    width = st.empty() ? i : i - st.top() - 1;
    maxArea = max(maxArea, height * width);
  }
  cout << maxArea;
  return 0;
}
