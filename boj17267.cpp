#include <bits/stdc++.h>

using namespace std;

int n, m, l, r, ans = 0;
int field[1001][1001];
bool visited[1001][1001];
pair<int, int> start;
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

void bfs(int sy, int sx){
  queue<tuple<int, int, int, int>> q; // 남은 l, 남은 r, y좌표, x좌표
  q.push({l, r, sy, sx});
  visited[sy][sx] = true;

  while (!q.empty()){
    int remainl = get<0>(q.front());
    int remainr = get<1>(q.front());
    int y = get<2>(q.front());
    int x = get<3>(q.front());
    q.pop();

    for (int i=0; i<4; i++){
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
      if (i == 2 && remainr >= 1){ // 오른쪽으로 갈 때
        if (!visited[newy][newx] && field[newy][newx] != 1){
          q.push({remainl, remainr - 1, newy, newx});
          visited[newy][newx] = true;
        }
      }
      if (i == 3 && remainl >= 1){ // 왼쪽으로 갈 때
        if (!visited[newy][newx] && field[newy][newx] != 1){
          q.push({remainl - 1, remainr, newy, newx});
          visited[newy][newx] = true;
        }
      }
      else if (i == 0){ // 아래로 갈 때
        for (int j=y; j<n; j++){
          newy = j;
          newx = x;
          if (!visited[newy][newx] && field[newy][newx] != 1){
            q.push({remainl, remainr, newy, newx});
            visited[newy][newx] = true;
          }
          if (field[newy][newx] == 1) break;
        }
      }
      else if (i == 1){ // 위로 갈 때
        for (int j=y; j>=0; j--){
          newy = j;
          newx = x;
          if (!visited[newy][newx] && field[newy][newx] != 1){
            q.push({remainl, remainr, newy, newx});
            visited[newy][newx] = true;
          }
          if (field[newy][newx] == 1) break;
        }
      }
    }
  }
}

int main(){
  scanf("%d %d %d %d", &n, &m, &l, &r);

  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      scanf("%1d", &field[i][j]);
      if (field[i][j] == 2) start = {i, j};
    }
  }
  bfs(start.first, start.second);
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      if (visited[i][j] == true) ans++;
    }
  }
  cout << ans;
  return 0;
}