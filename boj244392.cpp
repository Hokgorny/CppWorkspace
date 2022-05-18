#include <bits/stdc++.h>

using namespace std;

int n, m, ans = INT_MAX;
int ofield[1001][1001], field[1001][1001];
vector<tuple<int, int, int>> visited; // y, x, d
vector<pair<int, int>> v0, vy, vx;
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

int bfs(){
  queue<tuple<int, int, int>> q; // depth, y, x
  q.push({0, 0, 0});
  visited[0][0] = true;

  while(!q.empty()){
    int depth = get<0>(q.front());
    int y = get<1>(q.front());
    int x = get<2>(q.front());
    q.pop();

    for (int i=0; i<4; i++){
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
      if (newy == n - 1 && newx == m - 1) return depth + 1;
      if (!visited[newy][newx] && field[newy][newx] == 0){
        q.push({depth + 1, newy, newx});
        visited[newy][newx] = true;
      }
    }
  }
  return -1;
}

int obfs(){
  queue<tuple<int, int, int>> q; // depth, y, x
  q.push({0, 0, 0});
  visited[0][0] = true;
  v0.push_back({0, 0});

  while(!q.empty()){
    int depth = get<0>(q.front());
    int y = get<1>(q.front());
    int x = get<2>(q.front());
    q.pop();

    for (int i=0; i<4; i++){
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
      if (newy == n - 1 && newx == m - 1) return depth + 1;
      if (!visited[newy][newx] && ofield[newy][newx] == 0){
        q.push({depth + 1, newy, newx});
        visited[newy][newx] = true;
        v0.push_back({newy, newx});
      }
    }
  }
  return -1;
}

int main(){
  scanf("%d %d", &n, &m);

  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      scanf("%1d", &ofield[i][j]);
    }
  }

  reset();
  obfs();

  for (int i=0; i<v0.size(); i++){ // 뚫을 지점 찾기
    int cy = v0[i].first;
    int cx = v0[i].second;
    if (ofield[cy + 1][cx] == 1) vy.push_back({cy, cx});
    if (ofield[cy][cx + 1] == 1) vx.push_back({cy, cx});
  }

  for (int i=0; i<vy.size(); i++){
    reset();
    int ccy = vy[i].first;
    int ccx = vy[i].second;
    for (int j=ccy; j<n; j++){
      field[j][ccx] = 0;
    }
    int res = bfs();
    ans = (res != -1) ? min(ans, res) : ans;
  }
  for (int i=0; i<vx.size(); i++){
    reset();
    int ccy = vx[i].first;
    int ccx = vx[i].second;
    for (int j=ccx; j<m; j++){
      field[ccy][j] = 0;
    }
    int res = bfs();
    ans = (res != -1) ? min(ans, res) : ans;
  }
  if (ans == INT_MAX) cout << -1;
  else cout << ans;

  return 0;
}