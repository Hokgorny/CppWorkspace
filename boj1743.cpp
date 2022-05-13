#include <bits/stdc++.h>

using namespace std;

int n, m, k, ans = 1;
int field[101][101];
bool visited[101][101];
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};
vector<pair<int, int>> trash;

int bfs(pair<int, int> start){
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
      if (newy <= 0 || newy > n || newx <= 0 || newx > m) continue;
      else if (!visited[newy][newx] && field[newy][newx] == 1){
        q.push({newy, newx});
        visited[newy][newx] = true;
        cnt++;
      }
    }
  }
  return cnt;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  cin >> n >> m >> k;
  for (int i=0; i<k; i++){
    int r, c;
    cin >> r >> c;
    field[r][c] = 1;
    trash.push_back({r, c});
  }
  for (int i=0; i<trash.size(); i++){
    if (!visited[trash[i].first][trash[i].second]) ans = max(ans, bfs(trash[i]));
  }
  cout << ans;
}