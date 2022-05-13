#include <bits/stdc++.h>

using namespace std;

int f, s, g, u, d;
bool visited[1000001];

void bfs(){
  int ans = 0;
  queue<pair<int, int>> q; // 탐색깊이, 층
  q.push({0, s});
  visited[s] = true;

  while(!q.empty()){
    int depth = q.front().first;
    int now = q.front().second;
    q.pop();

    for (auto i : {u, -d}){
      int next = now + i;
      if (next <= 0 || next > f) continue;
      if (next == g) ans = depth + 1;
      else if (!visited[next]){
        q.push({depth + 1, next});
        visited[next] = true;
      }
    }
  }
  if (ans > 0) cout << ans;
  else if (s == g) cout << 0;
  else cout << "use the stairs";
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  cin >> f >> s >> g >> u >> d;
  bfs();
}