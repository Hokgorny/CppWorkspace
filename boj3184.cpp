#include <bits/stdc++.h>

using namespace std;

int r, c, sheeps = 0, wolfs = 0;
char field[251][251];
bool visited[251][251];
vector<pair<int, int>> sheep;
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

void bfs(pair<int, int> start){
  int scnt = 1, wcnt = 0;
  queue<pair<int, int>> q;
  q.push(start);
  visited[start.first][start.second] = true;

  while (!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int ii=0; ii<4; ii++){
      int newy = y + dy[ii];
      int newx = x + dx[ii];
      if (newy < 0 || newy >= r || newx < 0 || newx >= c) continue;
      if (!visited[newy][newx] && field[newy][newx] != '#'){
        if (field[newy][newx] == 'o') scnt++;
        if (field[newy][newx] == 'v') wcnt++;
        q.push({newy, newx});
        visited[newy][newx] = true;
      }
    }
  }
  if (scnt != 0 || wcnt != 0){
    if (scnt > wcnt) wolfs -= wcnt;
    else if (scnt <= wcnt) sheeps -= scnt;
  }
}


int main(){
  scanf("%d %d\n", &r, &c);
  for (int i=0; i<r; i++){
    for (int j=0; j<c; j++){
      scanf("%c", &field[i][j]);
      if (field[i][j] == 'o'){
        sheep.push_back({i, j});
        sheeps++;
      }
      if (field[i][j] == 'v') wolfs++;
    }
    char temp;
    scanf("%c", &temp);
  }

  for (int i=0; i<sheep.size(); i++){
    if (!visited[sheep[i].first][sheep[i].second]) bfs(sheep[i]);
  }

  cout << sheeps << ' ' << wolfs;

  return 0;
}