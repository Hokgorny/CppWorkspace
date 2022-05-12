#include <bits/stdc++.h>

using namespace std;

int t, m, n, k, cnt = 0;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void bfs(int b, int a, int field[][51], bool visited[][51]){
  queue<pair<int, int>> q;
  q.push({b, a});
  visited[b][a] = true;

  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int j=0; j<4; j++){
      int newy = y + dy[j];
      int newx = x + dx[j];
      if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
      if (field[newy][newx] == 0) continue;
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

  cin >> t;
  while(t--){
    cnt = 0;
    int field[51][51] = {};
    vector<pair<int, int>> lst;
    bool visited[51][51] = {};

    cin >> m >> n >> k; // m이 가로(x), n이 세로(y)
    for(int i=0; i<k; i++){
      int u, v; // u가 x, v가 y
      cin >> u >> v;
      field[v][u] = 1;
      lst.push_back({v, u});
    }
    for (int i=0; i<lst.size(); i++){
      int b, a; // b가 y, a가 x
      b = lst[i].first;
      a = lst[i].second;
      if (!visited[b][a] && field[b][a] == 1) bfs(b, a, field, visited);
    }
    cout << cnt << "\n";
  }
}