#include <bits/stdc++.h>

using namespace std;

int a, b, n, m, ans = INT_MAX;
bool visited[100001];

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  cin >> a >> b >> n >> m;

  queue<pair<int, int>> q; // 깊이, 좌표
  q.push({0, n});
  visited[n] = true;

  while(!q.empty()){
    int depth = q.front().first;
    int now = q.front().second;
    q.pop();

    for (auto i : {now + 1, now - 1, now + a, now - a, now + b, now - b, now * a, now * b}){
      if (i < 0 || i > 100000) continue;
      if (i == m) ans = min(ans, depth + 1);
      else if (!visited[i]){
        q.push({depth + 1, i});
        visited[i] = true;
      }
    }
  }
  cout << ans;
}