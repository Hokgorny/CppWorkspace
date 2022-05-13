#include <bits/stdc++.h>

using namespace std;

int n, m;
bool visited[501];
vector<vector<int>> v;

int bfs(){
  int cnt = 0;
  queue<pair<int, int>> q;
  q.push({0, 1});
  visited[1] = true;

  while(!q.empty()){
    int depth = q.front().first;
    int now = q.front().second;
    q.pop();

    for (int i=0; i<v[now].size(); i++){
      int next = v[now][i];

      if (!visited[next] && depth + 1 <= 2){
        q.push({depth + 1, next});
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
  v = vector<vector<int>> (n + 1, vector<int> ());
  for (int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  cout << bfs();
}