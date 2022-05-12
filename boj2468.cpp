#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0, ans = 0;
int field[101][101];
bool visited[101][101];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void bfs(int wl, pair<int, int> start){
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
      if (newy < 0 || newy >= n || newx < 0 || newx >= n) continue;
      if (field[newy][newx] <= wl) continue;
      if (!visited[newy][newx]){
        q.push({newy, newx});
        visited[newy][newx] = true;
      }
    }
  }
  cnt++;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  cin >> n;
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      cin >> field[i][j];
    }
  }
  for (int wl=0; wl<=100; wl++){
    cnt = 0;
    memset(visited, false, sizeof(visited));
    vector<pair<int, int>> v;
    v.clear();

    for (int ii=0; ii<n; ii++){ // 육지 찾기
      for (int jj=0; jj<n; jj++){
        if (field[ii][jj] > wl) v.push_back({ii, jj});
      }
    }

    for (int j=0; j<v.size(); j++){
      if (!visited[v[j].first][v[j].second]) bfs(wl, v[j]);
    }
    ans = max(ans, cnt);
  }
  cout << ans;
}