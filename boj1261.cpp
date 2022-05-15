#include <bits/stdc++.h>

using namespace std;

int n, m, ans = INT_MAX;
int field[101][101];
bool visited[101][101][10001]; // y,  x, 벽뚫은횟수
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

int bfs(){
  queue<tuple<int, int, int>> q; // 벽뚫은횟수, y, x
  q.push({0, 0, 0});
  visited[0][0][0] == true;

  while(!q.empty()){
    int limit = get<0>(q.front());
    int y = get<1>(q.front());
    int x = get<2>(q.front());
    q.pop();

    for (int i=0; i<4; i++){
      int newlimit = limit;
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
      if (newy == n - 1 && newx == m - 1) ans = min(ans, limit);
      if (field[newy][newx] == 1) newlimit++;
      if (!visited[newy][newx][newlimit] && newlimit <= 200){
        q.push({newlimit, newy, newx});
        visited[newy][newx][newlimit] = true;
      }
    }
  }
  return ans;
}

int main(void){
  scanf("%d %d", &m, &n);
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      scanf("%1d", &field[i][j]);
    }
  }
  if (n == 1 && m == 1){
    if (field[0][0] == 0) cout << 0;
    else cout << 1;
  }
  else cout << bfs();
}