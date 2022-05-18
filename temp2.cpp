#include <bits/stdc++.h>

using namespace std;

int n, m, ans = INT_MAX;
int ofield[1001][1001], field[1001][1001];
bool visited[1001][1001];
vector<tuple<int, int, int>> v0, vy, vx; // tuple : depth, y, x
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

void reset(){
  memset(visited, false, sizeof(visited));
  copy(&ofield[0][0], &ofield[0][0] + 1002001, &field[0][0]);
}

int bfs(tuple<int, int, int> start){
  queue<tuple<int, int, int>> q; // depth, y, x
  q.push(start);
  visited[get<1>(start)][get<2>(start)] = true;

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
  v0.push_back({0, 0, 0});

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
        v0.push_back({depth + 1, newy, newx});
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
  int temp = obfs();

  for (int i=0; i<v0.size(); i++){ // 뚫을 지점 찾기
    int cdepth = get<0>(v0[i]);
    int cy = get<1>(v0[i]);
    int cx = get<2>(v0[i]);
    if (ofield[cy + 1][cx] == 1) vy.push_back({cdepth, cy, cx});
    if (ofield[cy][cx + 1] == 1) vx.push_back({cdepth, cy, cx});
  }

  for (int i=0; i<vy.size(); i++){
    reset();
    int ccy = get<1>(vy[i]);
    int ccx = get<2>(vy[i]);
    for (int j=ccy; j<n; j++){
      field[j][ccx] = 0;
    }
    int res = bfs(vy[i]);
    ans = (res != -1) ? min(ans, res) : ans;
  }
  for (int i=0; i<vx.size(); i++){
    reset();
    int ccy = get<1>(vx[i]);
    int ccx = get<2>(vx[i]);
    for (int j=ccx; j<m; j++){
      field[ccy][j] = 0;
    }
    int res = bfs(vx[i]);
    ans = (res != -1) ? min(ans, res) : ans;
  }

  if (n == 1 && m == 1) cout << 0;
  else if ((int) vy.size() + (int) vx.size() == 0) cout << temp;
  else if (ans == INT_MAX) cout << -1;
  else cout << ans;

  return 0;
}