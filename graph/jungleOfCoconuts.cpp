#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int, int>
#define pB push_back
#define mP make_pair
#define X first
#define Y second

const int maxn = 2 * 100000 + 10, MOD = 1000 * 1000 * 1000 + 7,
          INF = 1000 * 1000 * 1000;

pii dir[] = {pii(0, 1), pii(1, 0), pii(0, -1), pii(-1, 0)};

string board[500];
int color[555][555];
int curcolor;
int n, m;

bool inRange(pii cur) {
  return (cur.X >= 0 && cur.X < n && cur.Y >= 0 && cur.Y < m);
}

bool canGo(pii cur) {
  if (inRange(cur)) {
    char ch = board[cur.X][cur.Y];
    if (ch == 'M' || ch == '.' || ch == 'L' || ch == 'O')
      return true;
  }
  return false;
}

pii operator+(const pii a, const pii b) { return pii(a.X + b.X, a.Y + b.Y); }

vector<pair<pii, int>> BFS(pii start, bool Mehrdad) {
  queue<pair<pii, int>> Q;
  Q.push(mP(start, 0));
  curcolor++;
  vector<pair<pii, int>> candid;
  while (!Q.empty()) {
    pair<pii, int> temp = Q.front();
    Q.pop();
    if (board[temp.X.X][temp.X.Y] == 'O')
      candid.pB(temp);
    for (int i = 0; i < 4; i++) {
      pii nx(temp.X + dir[i]);
      int delta = 0;
      if (inRange(nx) && board[nx.X][nx.Y] == '+' && !Mehrdad) {
        nx = nx + dir[i];
        delta++;
      }
      if (canGo(nx) && color[nx.X][nx.Y] != curcolor) {
        color[nx.X][nx.Y] = curcolor;
        Q.push(mP(nx, temp.Y + 1 + delta));
      }
    }
  }
  return candid;
}

pii getTunnel(vector<pair<pii, int>> M, vector<pair<pii, int>> L) {
  pii ans(INF, INF);
  for (int i = 0; i < M.size(); i++) {
    bool flag = false;
    for (int j = 0; j < L.size(); j++) {
      if (M[i].X == L[j].X) {
        flag = true;
        if (M[i].Y < L[j].Y && M[i].X < ans)
          ans = M[i].X;
        break;
      }
    }
    if (!flag && M[i].X < ans)
      ans = M[i].X;
  }
  return ans;
}

int main() {
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      cin >> board[i];
    pii M, L;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (board[i][j] == 'M')
          M = pii(i, j);
        else if (board[i][j] == 'L')
          L = pii(i, j);
    vector<pair<pii, int>> me, li;
    me = BFS(M, true);
    li = BFS(L, false);
    pii ans = getTunnel(me, li);
    cout << "Case " << tt++ << ": ";
    if (ans.X != INF)
      cout << ans.X + 1 << ' ' << ans.Y + 1 << endl;
    else
      cout << "good bye my dear good friend :(" << endl;
  }
  return 0;
}
