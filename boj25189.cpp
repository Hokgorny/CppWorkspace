#include <bits/stdc++.h>

using namespace std;

int n, m, rf, cf, rh, ch;
int field[1001][1001];
bool visited[1001][1001][2];
bool activated[2][1001]; // 첫번째 차원은 y/x
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

int bfs(){
  queue<tuple<int, int, int, int>> q; // 탐색깊이, 시니컬사용수, y(r, n), x(c, m)
  q.push({0, 0, rf - 1, cf - 1});
  visited[rf - 1][cf - 1][0] = true;
  visited[rf - 1][cf - 1][1] = true;

  if (rf == rh && cf == ch) return 0;

  while(!q.empty()){
    int depth = get<0>(q.front()); // 탐색깊이
    int limit = get<1>(q.front()); // 시니컬 사용 횟수
    int y = get<2>(q.front()); // 현재 y 좌표
    int x = get<3>(q.front()); // 현재 x 좌표
    q.pop();

    for (int i=0; i<6; i++){
      int newlimit, newy, newx;
      if (i < 4){ // 시니컬 사용 x
        newlimit = limit;
        newy = y + dy[i] * field[y][x];
        newx = x + dx[i] * field[y][x];
        if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
        if (newy == rh - 1 && newx == ch - 1) return depth + 1;
        if (!visited[newy][newx][newlimit]){
          q.push({depth + 1, newlimit, newy, newx});
          visited[newy][newx][newlimit] = true;
        }
      }
      else if (i == 4 && limit < 1 && !activated[1][x]){ // 시니컬 사용(y 방향)
        newlimit = limit + 1;
        newx = x;
        for (int j=0; j<n; j++){
          newy = j;
          if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
          if (newy == rh - 1 && newx == ch - 1) return depth + 1;
          if (!visited[newy][newx][1]){
            q.push({depth + 1, newlimit, newy, newx});
            visited[newy][newx][newlimit] = true;
            activated[1][x] = true;
          }
        }
      }
      else if (i == 5 && limit < 1 && !activated[0][y]){ // 시니컬 사용(x 방향)
        newlimit = limit + 1;
        newy = y;
        for (int j=0; j<m; j++){
          newx = j;
          if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
          if (newy == rh - 1 && newx == ch - 1) return depth + 1;
          if (!visited[newy][newx][1]){
            q.push({depth + 1, newlimit, newy, newx});
            visited[newy][newx][newlimit] = true;
            activated[0][y] = true;
          }
        }
      }
    }
  }
  return -1;
}


int main(void){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);

  cin >> n >> m;
  cin >> rf >> cf >> rh >> ch;

  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      cin >> field[i][j];
    }
  }

  cout << bfs();
}