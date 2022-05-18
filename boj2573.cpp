#include <bits/stdc++.h>

using namespace std;

int n, m, cnt = 0, t = 0;
int oldfield[301][301], newfield[301][301];
bool visited[301][301], landchecked[301][301];
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};
vector<pair<int, int>> land;

bool bfs(pair<int, int> start){
  vector<pair<int, int>> checked; // 이번 bfs에서 지나간 land들
  checked.clear();
  queue<pair<int, int>> q;
  q.push(start);
  checked.push_back({start});
  visited[start.first][start.second] = true;

  while (!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i=0; i<4; i++){
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
      if (oldfield[newy][newx] <= 0) newfield[y][x]--;
      if (oldfield[newy][newx] > 0 && !visited[newy][newx]){
        q.push({newy, newx});
        checked.push_back({newy, newx});
        visited[newy][newx] = true;
      }
    }
  }
  if ((int) checked.size() != (int) land.size()) return true;
  else return false;
}

int main(){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);

  cin >> n >> m;
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      cin >> newfield[i][j];
    }
  }

  while (true){ // while의 한 주기는 1년이다.

    cnt = 0;
    copy(&newfield[0][0], &newfield[0][0] + 90601, &oldfield[0][0]);
    memset(visited, false, sizeof(visited));
    land.clear();

    for (int i=0; i<n; i++){ // 매년마다 육지를 파악한다.
      for (int j=0; j<m; j++){
        if (newfield[i][j] > 0) land.push_back({i, j});
      }
    }
    int c = land.size();
    if (c == 1 || c == 0){ // 육지의 크기가 1이라면 즉시 탈출한다.
      t = 0;
      break;
    }

    for (int k=0; k<c; k++){ // 모든 육지에 대해서 탐색
      if (!visited[land[k].first][land[k].second]){
        bfs(land[k]);
        cnt++;
      }
    }
    if (cnt >= 2) break; // 탐색 횟수가 2번 이상이면 탈출
    t++;
  }
  
  cout << t;
  return 0;
}