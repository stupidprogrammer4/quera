#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)

map<string, string> ans;

string get_state(string state) {
  char b[3][3];
  forn(i, 3) forn(j, 3) b[i][j] = state[3 * i + j];

  int x_cnt, o_cnt;
  forn(i, 3) {
    x_cnt = 0;
    o_cnt = 0;
    forn(j, 3) {
      if (b[i][j] == 'O')
        o_cnt++;
      if (b[i][j] == 'X')
        x_cnt++;
    }
    if (x_cnt == 3)
      return "X";
    if (o_cnt == 3)
      return "O";
  }

  forn(i, 3) {
    x_cnt = 0;
    o_cnt = 0;
    forn(j, 3) {
      if (b[j][i] == 'O')
        o_cnt++;
      if (b[j][i] == 'X')
        x_cnt++;
    }
    if (x_cnt == 3)
      return "X";
    if (o_cnt == 3)
      return "O";
  }

  x_cnt = 0;
  o_cnt = 0;
  forn(i, 3) {
    if (b[i][i] == 'O')
      o_cnt++;
    if (b[i][i] == 'X')
      x_cnt++;
  }
  if (x_cnt == 3)
    return "X";
  if (o_cnt == 3)
    return "O";

  x_cnt = 0;
  o_cnt = 0;
  forn(i, 3) {
    if (b[i][2 - i] == 'O')
      o_cnt++;
    if (b[i][2 - i] == 'X')
      x_cnt++;
  }
  if (x_cnt == 3)
    return "X";
  if (o_cnt == 3)
    return "O";

  int q_cnt = 0;
  for (auto ch : state)
    if (ch == '?')
      q_cnt++;

  if (q_cnt == 0)
    return "Draw";
  return "Unfinished";
}

void generate_all(string state, char turn) {
  ans[state] = get_state(state);
  if (ans[state] != "Unfinished")
    return;

  for (int i = 0; i < 9; i++) {
    if (state[i] == '?') {
      state[i] = turn;
      generate_all(state, (turn == 'X' ? 'O' : 'X'));
      state[i] = '?';
    }
  }
}

int main() {
  generate_all("?????????", 'X');

  string state = "", s;
  forn(i, 3) {
    cin >> s;
    state += s;
  }

  if (ans.find(state) == ans.end()) {
    cout << "Invalid\n";
    exit(0);
  }
  cout << ans[state] << '\n';
}
