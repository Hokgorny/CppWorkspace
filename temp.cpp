#include <bits/stdc++.h>

using namespace std;

int n, m, ans = INT_MAX;
int field[1001][1001];
bool visited[1001][1001][2][2]; // y, x, y바리 통과 여부, x바리 통과 여부
int visited_depth[1001][1001];
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

int bfs(){
  queue<tuple<int, int, int, int, int, int, int>> q; // 깊이, 뚫은 라인 y, 뚫은 라인 x, 뚫은 지점의 좌표 (y or x), 뚫은 방향, y, x
  q.push({0, -1, -1, -1, 0, 0, 0});
  visited[0][0][0][0] = true;

  if (n == 1 && m == 1) return 0;
  
  while(!q.empty()){
    int depth = get<0>(q.front());
    int by = get<1>(q.front());
    int bx = get<2>(q.front());
    int bp = get<3>(q.front());
    int bd = get<4>(q.front());
    int y = get<5>(q.front());
    int x = get<6>(q.front());
    int ylimit = (by == -1) ? 1 : 0;
    int xlimit = (bx == -1) ? 1 : 0;
    q.pop();

    for (int i=4; i>=0; i--){
      int newy, newx;
      if (i < 4){ // 일반적인 상하좌우 이동
        newy = y + dy[i];
        newx = x + dx[i];
        if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
        if (newy == n - 1 && newx == m - 1) ans = min(ans, depth + 1);
        if (!visited[newy][newx][ylimit][xlimit]){ // 다음칸 방문 안돼있을 때
          if (field[newy][newx] == 0){ // 그 칸이 0이라면 이동하고
            q.push({depth + 1, by, bx, bp, bd, newy, newx});
            visited[newy][newx][ylimit][xlimit] = true;
            visited_depth[newy][newx] = depth + 1;
          }
          else if (newx == by){ // 그 칸이 0이 아닌 경우(else) 뚫어둔 라인이라면(y축)
            if (i == 1 && bd == -1 && newy < bp){ // -y 방향으로 뚫린 경우
              q.push({depth + 1, by, bx, bp, bd, newy, newx});
              visited[newy][newx][ylimit][xlimit] = true;
              visited_depth[newy][newx] = depth + 1;
            }
            else if (i == 0 && bd == 1 && newy > bp){ // +y 방향으로 뚫린 경우
              q.push({depth + 1, by, bx, bp, bd, newy, newx});
              visited[newy][newx][limit] = true;
              visited_depth[newy][newx] = depth + 1;
            }
          }
          else if (newy == bx){ // 그 칸이 0이 아닌 경우(else) 뚫어둔 라인이라면(x축)
            if (i == 3 && bd == -1 && newx < bp){ // -x 방향으로 뚫린 경우
              q.push({depth + 1, by, bx, bp, bd, newy, newx});
              visited[newy][newx][limit] = true;
              visited_depth[newy][newx] = depth + 1;
            }
            else if (i == 2 && bd == 1 && newx > bp){ // +x 방향으로 뚫린 경우
              q.push({depth + 1, by, bx, bp, bd, newy, newx});
              visited[newy][newx][limit] = true;
              visited_depth[newy][newx] = depth + 1;
            }
          }
        }
        else if (visited[newy][newx][limit] && depth + 1 < visited_depth[newy][newx]){ // 방문은 돼있지만 탐색깊이는 지금이 더 작을 때
          if (field[newy][newx] == 0){ // 그 칸이 0이라면 이동하고
            q.push({depth + 1, by, bx, bp, bd, newy, newx});
            visited_depth[newy][newx] = depth + 1;
          }
          else if (newx == by){ // 그 칸이 0이 아닌 경우(else) 뚫어둔 라인이라면(y축)
            if (i == 1 && bd == -1 && newy < bp){ // -y 방향으로 뚫린 경우
              q.push({depth + 1, by, bx, bp, bd, newy, newx});
              visited[newy][newx][limit] = true;
              visited_depth[newy][newx] = depth + 1;
            }
            else if (i == 0 && bd == 1 && newy > bp){ // +y 방향으로 뚫린 경우
              q.push({depth + 1, by, bx, bp, bd, newy, newx});
              visited[newy][newx][limit] = true;
              visited_depth[newy][newx] = depth + 1;
            }
          }
          else if (newy == bx){ // 그 칸이 0이 아닌 경우(else) 뚫어둔 라인이라면(x축)
            if (i == 3 && bd == -1 && newx < bp){ // -x 방향으로 뚫린 경우
              q.push({depth + 1, by, bx, bp, bd, newy, newx});
              visited[newy][newx][limit] = true;
              visited_depth[newy][newx] = depth + 1;
            }
            else if (i == 2 && bd == 1 && newx > bp){ // +x 방향으로 뚫린 경우
              q.push({depth + 1, by, bx, bp, bd, newy, newx});
              visited[newy][newx][limit] = true;
              visited_depth[newy][newx] = depth + 1;
            }
          }
        }
      }
      else if (i == 4 && limit == 0){ // 바리스타 사용, 이동은 한칸만
        for (int j=0; j<4; j++){
          newy = y + dy[j];
          newx = x + dx[j];
          if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
          if (newy == n - 1 && newx == m - 1) ans = min(ans, depth + 1);
          if (field[newy][newx] == 1 && j == 0){ // +y 방향 뚫기
            int newby = x;
            int newbp = y;
            int newbd = 1;
            if (!visited[newy][newx][1]){
              q.push({depth + 1, newby, bx, newbp, newbd, newy, newx});
              visited[newy][newx][1] = true;
              visited_depth[newy][newx] = depth + 1;
            }
            else if (visited[newy][newx][1] && depth + 1 < visited_depth[newy][newx]){
              q.push({depth + 1, newby, bx, newbp, newbd, newy, newx});
              visited_depth[newy][newx] = depth + 1;
            }
          }
          else if (field[newy][newx] == 1 && j == 1){ // -y 방향 뚫기
            int newby = x;
            int newbp = y;
            int newbd = -1;
            if (!visited[newy][newx][1]){
              q.push({depth + 1, newby, bx, newbp, newbd, newy, newx});
              visited[newy][newx][1] = true;
              visited_depth[newy][newx] = depth + 1;
            }
            else if (visited[newy][newx][1] && depth + 1 < visited_depth[newy][newx]){
              q.push({depth + 1, newby, bx, newbp, newbd, newy, newx});
              visited_depth[newy][newx] = depth + 1;
            }
          }
          else if (field[newy][newx] == 1 && j == 2){ // +x 방향 뚫기
            int newbx = y;
            int newbp = x;
            int newbd = 1;
            if (!visited[newy][newx][1]){
              q.push({depth + 1, by, newbx, newbp, newbd, newy, newx});
              visited[newy][newx][1] = true;
              visited_depth[newy][newx] = depth + 1;
            }
            else if (visited[newy][newx][1] && depth + 1 < visited_depth[newy][newx]){
              q.push({depth + 1, by, newbx, newbp, newbd, newy, newx});
              visited_depth[newy][newx] = depth + 1;
            }
          }
          else if (field[newy][newx] == 1 && j == 3){ // -x 방향 뚫기
            int newbx = y;
            int newbp = x;
            int newbd = -1;
            if (!visited[newy][newx][1]){
              q.push({depth + 1, by, newbx, newbp, newbd, newy, newx});
              visited[newy][newx][1] = true;
              visited_depth[newy][newx] = depth + 1;
            }
            else if (visited[newy][newx][1] && depth + 1 < visited_depth[newy][newx]){
              q.push({depth + 1, by, newbx, newbp, newbd, newy, newx});
              visited_depth[newy][newx] = depth + 1;
            }
          }
        }
      }
    }
  }
  return ans;
}

int main(){  
  scanf("%d %d", &n, &m); // y, x
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      scanf("%1d", &field[i][j]);
    }
  }

  int res = bfs();
  if (res == INT_MAX) printf("%d", -1);
  else printf("%d", res);

  return 0;
}