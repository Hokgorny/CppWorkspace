#include <bits/stdc++.h>

using namespace std;

int n, m, cnt = 0;

vector<bool> visited(1001, false);

void bfs(int node, vector<vector<int>> &nd){
  queue<int> q;
  q.push(node);
  visited[node] = true;

  while(!q.empty()){
    int now = q.front();
    q.pop();

    for (int j=0; j<nd[now].size(); j++){
      if (!visited[nd[now][j]]){
        q.push(nd[now][j]);
        visited[nd[now][j]] = true;
      }
    }
  }
  cnt++;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  cin >> n >> m;
  vector<vector<int>> nd(1001, vector<int> ());
  int u, v;
  for (int i=0; i<m; i++){
    cin >> u >> v;
    nd[u].push_back(v);
    nd[v].push_back(u);
  }

  for (int i=1; i<=n; i++){
    if (!visited[i]) bfs(i, nd);
  }

  cout << cnt;
}