#include <bits/stdc++.h>

using namespace std;

int a, b, n, m;
bool visited[10001];

int bfs(vector<vector<int>> &lst){
  queue<pair<int, int>> q;
  q.push({0, a});
  visited[0] = true;

  while(!q.empty()){
    int depth = q.front().first;
    int now = q.front().second;
    q.pop();

    for (int i=0; i<lst[now].size(); i++){
      if (lst[now][i] == b) return depth + 1;
      else if (!visited[lst[now][i]]){
        q.push({depth + 1, lst[now][i]});
        visited[lst[now][i]] = true;
      }
    }
  }
  return -1;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> a >> b >> n >> m;
  vector<vector<int>> lst(n + 1, vector<int> ());
  for (int i=0; i<m; i++){
    int u, v;
    cin >> u >> v;
    lst[u].push_back(v);
    lst[v].push_back(u);
  }
  if (a == b) cout << 0;
  else cout << bfs(lst);
}