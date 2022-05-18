#include <bits/stdc++.h>

using namespace std;

int n, m, ans = INT_MAX;
int field[1001][1001];
bool visited[1001][1001][4]; // y, x, case(0 ~ 3)
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

/*
4가지 case 존재
case 0 : 처음부터 지금까지 일반으로만 움직인 경우
case 1 : +y 방향 바리스타 사용 중인 경우
case 2 : +x 방향 바리스타 사용 중인 경우
case 3 : 바리스타에서 일반으로 나온 경우
case 0 -> 0 or 1 or 2
case 1 -> 1 or 3
case 2 -> 2 or 3
case 3 -> 3
*/

int bfs(){
  queue<tuple<int, int, int, int>> q;
  q.push({0, 0, 0, 0});
  visited[0][0][0] = true;

  while (!q.empty()){
    int depth = get<0>(q.front());
    int status = get<1>(q.front());
    int y = get<2>(q.front());
    int x = get<3>(q.front());
    q.pop();

    int newy, newx;
    if (status == 0){ // 현재 case 0일 경우 (0 or 1 or 2로 갈 수 있음)
      for (int i=0; i<4; i++){ // case 0로 이동
        newy = y + dy[i];
        newx = x + dx[i];
        if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
        if (newy == n - 1 && newx == m - 1) return depth + 1;
        if (!visited[newy][newx][0] && field[newy][newx] == 0){
          q.push({depth + 1, 0, newy, newx});
          visited[newy][newx][0] = true;
        }
      }
      newy = y + 1; // case 1로 이동
      newx = x;
      if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
      if (newy == n - 1 && newx == m - 1) return depth + 1;
      if (!visited[newy][newx][1]){
          q.push({depth + 1, 1, newy, newx});
          visited[newy][newx][1] = true;
      }
      newy = y; // case 2로 이동
      newx = x + 1;
      if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
      if (newy == n - 1 && newx == m - 1) return depth + 1;
      if (!visited[newy][newx][2]){
          q.push({depth + 1, 2, newy, newx});
          visited[newy][newx][2] = true;
      }
    }
    if (status == 1){ // 현재 case 1일 경우 (1 or 3으로 갈 수 있음)
      newy = y + 1; // case 1로 이동
      newx = x;
      if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
      if (newy == n - 1 && newx == m - 1) return depth + 1;
      if (!visited[newy][newx][1]){
          q.push({depth + 1, 1, newy, newx});
          visited[newy][newx][1] = true;
      }
      for (int i=0; i<4; i++){ // case 3으로 이동
        newy = y + dy[i];
        newx = x + dx[i];
        // if (i == 1) continue; // 다시 올라갈 필요 없어
        if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
        if (newy == n - 1 && newx == m - 1) return depth + 1;
        if (!visited[newy][newx][3] && field[newy][newx] == 0){
          q.push({depth + 1, 3, newy, newx});
          visited[newy][newx][3] = true;
        }
      }
    }
    if (status == 2){ // 현재 case 2일 경우 (1 or 3으로 갈 수 있음)
      newy = y; // case 2로 이동
      newx = x + 1;
      if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
      if (newy == n - 1 && newx == m - 1) return depth + 1;
      if (!visited[newy][newx][2]){
          q.push({depth + 1, 2, newy, newx});
          visited[newy][newx][2] = true;
      }
      for (int i=0; i<4; i++){ // case 3으로 이동
        newy = y + dy[i];
        newx = x + dx[i];
        // if (i == 3) continue; // 다시 올라갈 필요 없어
        if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
        if (newy == n - 1 && newx == m - 1) return depth + 1;
        if (!visited[newy][newx][3] && field[newy][newx] == 0){
          q.push({depth + 1, 3, newy, newx});
          visited[newy][newx][3] = true;
        }
      }
    }
    if (status == 3){ // 현재 case 3일 경우 (3으로만 갈 수 있음)
      for (int i=0; i<4; i++){ // case 3으로 이동
        newy = y + dy[i];
        newx = x + dx[i];
        if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
        if (newy == n - 1 && newx == m - 1) return depth + 1;
        if (!visited[newy][newx][3] && field[newy][newx] == 0){
          q.push({depth + 1, 3, newy, newx});
          visited[newy][newx][3] = true;
        }
      }
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);

  scanf("%d %d", &n, &m);

  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      scanf("%1d", &field[i][j]);
    }
  }

  cout << bfs();
  return 0;
}