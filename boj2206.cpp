#include <bits/stdc++.h>

using namespace std;

int n, m;
int field[1001][1001];
bool visited[1001][1001][2];
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

int bfs(){
  queue<tuple<int, int, int, int>> q;
  q.push({1, 0, 0, 0}); // 깊이, y좌표, x좌표, 지나간 1 수
  visited[0][0][0] = true;

  while(!q.empty()){
    int y = get<1>(q.front());
    int x = get<2>(q.front());
    int depth = get<0>(q.front());
    int limit = get<3>(q.front());
    q.pop();

    for (int i=0; i<4; i++){
      int newy = y + dy[i];
      int newx = x + dx[i];
      int newlimit = limit;
      if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
      if (newy == n - 1 && newx == m - 1) return depth + 1;
      else if (!visited[newy][newx][newlimit]){
        if (field[newy][newx] == 1) newlimit++;
        if (newlimit <= 1){
          q.push({depth + 1, newy, newx, newlimit});
          visited[newy][newx][newlimit] = true;
        }
      }
    }
  }
  return -1;
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
  if (n == 1 & m == 1) cout << 1;
  else cout << bfs();
}