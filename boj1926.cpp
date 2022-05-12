#include <bits/stdc++.h>

using namespace std;

int n, m, cnt = 0, max_p = 0;
int field[501][501];
bool visited[501][501];
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};
vector<pair<int, int>> lst;

void bfs(pair<int, int> start){
  int p = 1;
  max_p = max(max_p, p);
  
  queue<tuple<int, int, int>> q;
  q.push({0, start.first, start.second});
  visited[start.first][start.second] = true;

  while(!q.empty()){
    int depth = get<0>(q.front());
    int y = get<1>(q.front());
    int x = get<2>(q.front());
    q.pop();
    visited[y][x] = true;

    for (int ii=0; ii<4; ii++){
      int newy = y + dy[ii];
      int newx = x + dx[ii];
      if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
      if (!visited[newy][newx] && field[newy][newx] == 1){
        q.push({depth + 1, newy, newx});
        visited[newy][newx] = true;
        p++;
        max_p = max(max_p, p);
      }
    }
  }
}

int main(void){
  int count = 0;
  vector<int> ans;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  cin >> n >> m;
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      cin >> field[i][j];
      if (field[i][j] == 1) lst.push_back({i, j});
    }
  }
  
  for (int i=0; i<lst.size(); i++){
    if (!visited[lst[i].first][lst[i].second]){
      bfs(lst[i]);
      cnt++;
    }
  }
  cout << cnt << "\n" << max_p;
}