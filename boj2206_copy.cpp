#include <bits/stdc++.h>

using namespace std;

int n, m, ans = INT_MAX;
int field[1001][1001];
bool visited[1001][1001];
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

int bfs(){
  queue<tuple<int, int, int, int>> q;
  q.push({0, 0, 0, 1}); // 깊이, y좌표, x좌표, 지나간 1 수
  visited[0][0] = true;

  while(!q.empty()){
    int y = get<1>(q.front());
    int x = get<2>(q.front());
    int depth = get<3>(q.front());
    int limit = get<0>(q.front());
    q.pop();
    visited[y][x] = true;
    if (y < 0 || y >= n || x < 0 || x >= m) continue;
    if (y == n - 1 && x == m - 1){
      if (limit <= 1) ans = min(ans, depth);
    }

    for (int i=0; i<4; i++){
      int newy = y + dy[i];
      int newx = x + dx[i];
      int newlimit = limit;
      if (!visited[newy][newx]){
        if (field[newy][newx] == 1) newlimit++;
        q.push({newlimit, newy, newx, depth + 1});
      }
    }
  }
  if (ans == INT_MAX) return -1;
  else return ans;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  scanf("%d %d", &n, &m);
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      scanf("%1d", &field[i][j]);
    }
  }
  if (n == 1 && m == 1) cout << 1;
  else cout << bfs();
}