#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int field[101][101];
bool visited[101][101];
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};
vector<int> ans;

void bfs(pair<int, int> start){
  int cnt = 1;
  queue<pair<int, int>> q;
  q.push(start);
  visited[start.first][start.second] = true;

  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int ii=0; ii<4; ii++){
      int newy = y + dy[ii];
      int newx = x + dx[ii];
      if (newy < 0 || newy >= m || newx < 0 || newx >= n) continue;
      else if (!visited[newy][newx] && field[newy][newx] == 0){
        q.push({newy, newx});
        visited[newy][newx] = true;
        cnt++;
      }
    }
  }
  ans.push_back(cnt);
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  cin >> m >> n >> k; // 끝칸은 세로 : m - 1, 가로 : n - 1
  for(int i=0; i<k; i++){
    int sx, sy, lx, ly;
    cin >> sx >> sy >> lx >> ly;
    for (int j=sy; j<ly; j++){
      for (int k=sx; k<lx; k++){
        field[j][k] = 1;
      }
    }
  }

  for (int i=0; i<m; i++){
    for (int j=0; j<n; j++){
      if (field[i][j] == 0 && !visited[i][j]) bfs({i, j});
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (int i=0; i<ans.size(); i++){
    cout << ans[i] << ' ';
  }
}