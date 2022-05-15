#include <bits/stdc++.h>

using namespace std;

int n, lst[1001];
bool visited[1001];

int bfs(){
  queue<pair<int, int>> q; // 깊이, 좌표
  q.push({0, 0});
  visited[0] = true;

  if (n == 1) return 0;

  while(!q.empty()){
    int depth = q.front().first;
    int now = q.front().second;
    q.pop();

    for (int i=1; i<=lst[now]; i++){
      int next = now + i;
      if (next >= n) continue;
      if (next == n - 1) return depth + 1;
      if (!visited[next]){
        q.push({depth + 1, next});
        visited[next] = true;
      }
    }
  }
  return -1;
}

int main(void){
  ios_base::sync_with_stdio(false); // scanf 사용시 아래 두 문장 삭제
  cin.tie(nullptr);

  cin >> n;
  for (int i=0; i<n; i++){
    cin >> lst[i];
  }

  cout << bfs();
}