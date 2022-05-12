#include <bits/stdc++.h>

using namespace std;

int n, cnt;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int field[26][26] = {};
bool visited[26][26] = {};
vector<pair<int, int>> lst; // y, x
vector<int> danji;

void bfs(pair<int, int> p){
  cnt = 1;
  queue<pair<int, int>> q;
  q.push({p.first, p.second});
  visited[p.first][p.second] = true;

  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i=0; i<4; i++){
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (newy < 0 || newy >= n || newx < 0 || newx >= n) continue;
      if (field[newy][newx] == 0) continue;
      if (!visited[newy][newx]){
        q.push({newy, newx});
        visited[newy][newx] = true;
        cnt++;
      }
    }
  }
  danji.push_back(cnt);
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  scanf("%d\n", &n);
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      scanf("%1d", &field[i][j]);
      if (field[i][j] == 1) lst.push_back({i, j}); // y, x
    }
  }
  for (int ii=0; ii<lst.size(); ii++){
    if (!visited[lst[ii].first][lst[ii].second] && field[lst[ii].first][lst[ii].second] == 1) bfs({lst[ii].first, lst[ii].second});
  }
  
  sort(danji.begin(), danji.end());
  cout << danji.size() << "\n";
  for (int i=0; i<danji.size(); i++){
    cout << danji[i] << "\n";
  }
}