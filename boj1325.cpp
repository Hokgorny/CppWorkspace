#include <bits/stdc++.h>

using namespace std;

int n, m;
bool visited[10001];
vector<int> ans;

int bfs(int start, vector<vector<int>> &nodes){
  int cnt = 1;
  memset(visited, false, sizeof(visited));
  queue<int> q;
  q.push(start);
  visited[start] = true;

  while(!q.empty()){
    int pos = q.front();
    q.pop();

    for (int ii=0; ii<nodes[pos].size(); ii++){
      int next = nodes[pos][ii];
      if (!visited[next]){
        q.push(next);
        visited[next] = true;
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

  cin >> n >> m;
  vector<vector<int>> nodes(n + 1, vector<int> ());
  for (int i=0; i<m; i++){
    int u, v;
    cin >> u >> v;
    nodes[v].push_back(u);
  }

  int max_hc = 0;
  for (int i=1; i<=n; i++){
    int curr_hc = bfs(i, nodes);
    if (curr_hc > max_hc){
      ans.clear();
      ans.push_back(i);
    }
    else if (max_hc == curr_hc) ans.push_back(i);
    max_hc = max(max_hc, curr_hc);
  }
  for (int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
  }
}