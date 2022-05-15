#include <bits/stdc++.h>

using namespace std;

int n, m, q, u, v, s;
int lst[100001];
bool visited[100001];
int ans[100001];

void bfs(int start, vector<vector<int>> &nodes){
  vector<int> checked;
  checked.clear();
  int ssuk = 0, chung = 0;
  queue<int> q;

  q.push(start);
  visited[start] = true;

  if (lst[start] == 1) chung++;
  else if (lst[start] == 0) ssuk++;

  while(!q.empty()){
    int now = q.front();
    q.pop();

    for (int j=0; j<nodes[now].size(); j++){
      int next = nodes[now][j];
      if (!visited[next]){
        if (lst[next] == 1) chung++;
        if (lst[next] == 0) ssuk++;
        q.push(next);
        visited[next] = true;
        checked.push_back(next);
      }
    }
  }
  if (chung > ssuk){
    ans[start] = 1;
    for (int k=0; k<checked.size(); k++){
      ans[checked[k]] = 1;
    }
  }
  else{
    ans[start] = 0;
    for (int k=0; k<checked.size(); k++){
      ans[checked[k]] = 0;
    }
  }
}

int main(void){
  fill(ans, ans + 100001, -1);

  scanf("%d %d %d", &n, &m, &q);
  for (int i=1; i<=n; i++){
    scanf("%d", &lst[i]);
  }
  vector<vector<int>> nodes(n + 1, vector<int> ());
  for (int i=0; i<m; i++){
    scanf("%d %d", &u, &v);
    if (find(nodes[u].begin(), nodes[u].end(), v) == nodes[u].end()){
      nodes[u].push_back(v);
      nodes[v].push_back(u);
    }
  }

  for (int i=0; i<q; i++){
    scanf("%d", &s);
    if (ans[s] != -1) printf("%d\n", ans[s]);
    else {
      memset(visited, false, sizeof(visited));
      bfs(s, nodes);
      printf("%d\n", ans[s]);
    }
  }

  return 0;
}