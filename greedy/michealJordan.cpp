#include <bits/stdc++.h>

using namespace std;
stack<char> st;

int main() {
  string s;
  cin >> s;
  stack<char> st;
  deque<char> dq;
  for (char c : s)
    dq.push_back(c);
  bool back = 1;
  while (dq.size()) {
    char v;
    if (back) {
      v = dq.back();
      dq.pop_back();
    } else {
      v = dq.front();
      dq.pop_front();
    }
    if (v == 'x')
      back = !back;
    st.push(v);
  }
  while (st.size()) {
    char c = st.top();
    st.pop();
    cout << c;
  }
  cout << '\n';
  return 0;
}
