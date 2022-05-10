#include <bits/stdc++.h>

using namespace std;

int n, m;

int bfs(vector<vector<int>> &l){
  queue<int> q;
  vector<bool> visited(n + 1, false);
  q.push(1);
  
  while(!q.empty()){
    int x = q.front();
    q.pop();
    visited[x] = true;

    for (int i=0; i<l[x].size(); i++){
      if (!visited[l[x][i]]) q.push(l[x][i]);
    }
  }
  return count(visited.begin(), visited.end(), true) - 1;
}

int main(void){
  freopen("input.txt", "r", stdin);
  
  cin >> n >> m;

  int a, b;
  vector<vector<int>> l(n + 1, vector<int> (0, 0));

  for (int i=0; i<m; i++){
    cin >> a >> b;
    l[a].push_back(b);
    l[b].push_back(a);
  }
  cout << bfs(l);
}