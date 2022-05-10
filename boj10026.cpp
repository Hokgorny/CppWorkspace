#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
char field[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void reset(){
  for (int i=0; i<100; i++){
    memset(visited[i], false, sizeof(visited[i]));
    cnt = 0;
  }
}

void bfs(int yy, int xx){
  queue<pair<int, int>> q;
  q.push({yy, xx});
  visited[yy][xx] = true;
  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    
    for (int i=0; i<4; i++){
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (newy < 0 || newy >= n || newx < 0 || newx >= n) continue;
      if (!visited[newy][newx] && field[newy][newx] == field[y][x]){
        q.push({newy, newx});
        visited[newy][newx] = true;
      }
    }
  }
  cnt++;
}

int main(void){
  freopen("input.txt", "r", stdin);

  cin >> n;
  for (int i=0; i<n; i++){
    cin >> field[i];
  }
  for (int ii=0; ii<n; ii++){
    for (int jj=0; jj<n; jj++){
      if (!visited[ii][jj]) bfs(ii, jj);
    }
  }
  cout << cnt << " ";

  reset();

  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (field[i][j] == 'G') field[i][j] = 'R';
    }
  }
  for (int ii=0; ii<n; ii++){
    for (int jj=0; jj<n; jj++){
      if (!visited[ii][jj]) bfs(ii, jj);
    }
  }
  cout << cnt << " ";
}