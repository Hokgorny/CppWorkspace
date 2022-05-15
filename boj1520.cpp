#include <bits/stdc++.h>

using namespace std;

int m, n;
int field[501][501];
bool visited[501][501];
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

int bfs(){
  int ans = 0;
  queue<pair<int, int>> q;
  q.push({0, 0});
  
  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i=0; i<4; i++){
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (newy < 0 || newy >= m || newx < 0 || newx >= n) continue;
      if (newy == m - 1 && newx == n - 1 && field[newy][newx] < field[y][x]) ans++;
      if (field[newy][newx] < field[y][x]){
        q.push({newy, newx});
        // visited[newy][newx] = true;
      }
    }
  }
  return ans;
}

int main(void){
  ios_base::sync_with_stdio(false); // scanf 사용시 아래 두 문장 삭제
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  cin >> m >> n; // 세로 가로
  for (int i=0; i<m; i++){
    for (int j=0; j<n; j++){
      cin >> field[i][j];
    }
  }
  cout << bfs();
}