#include <bits/stdc++.h>

using namespace std;

int l, r, c, ans;
char field[31][31][31]; // 높이z, 세로y, 가로x
bool visited[31][31][31];
constexpr int dz[6] = {1, -1, 0, 0, 0, 0};
constexpr int dy[6] = {0, 0, 1, -1, 0, 0};
constexpr int dx[6] = {0, 0, 0, 0, 1, -1};
tuple<int, int, int> start;
tuple<int, int, int> goal;

int bfs(){
  queue<tuple<int, int, int, int>> q; // 깊이, z, y, x
  q.push({0, get<0>(start), get<1>(start), get<2>(start)});
  visited[get<0>(start)][get<1>(start)][get<2>(start)] = true;

  while(!q.empty()){
    int depth = get<0>(q.front());
    int z = get<1>(q.front());
    int y = get<2>(q.front());
    int x = get<3>(q.front());
    q.pop();

    for (int i=0; i<6; i++){
      int newz = z + dz[i];
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (newz < 0 || newz >= l || newy < 0 || newy >= r || newx < 0 || newx >= c) continue;
      if (field[newz][newy][newx] == 'E') return depth + 1;
      else if (!visited[newz][newy][newx] && field[newz][newy][newx] == '.'){
        q.push({depth + 1, newz, newy, newx});
        visited[newz][newy][newx] = true;
      }
    }
  }
  return -1;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  while(true){
    cin >> l >> r >> c;
    if (l == 0 && r == 0 && c == 0) break;

    memset(field, 0, sizeof(field));
    memset(visited, false, sizeof(visited));

    for (int i=0; i<l; i++){ // 높이z
      for (int j=0; j<r; j++){ // 세로y
        for (int k=0; k<c; k++){ // 가로x
          cin >> field[i][j][k];
          if (field[i][j][k] == 'S') start = {i, j, k};
          if (field[i][j][k] == 'E') goal = {i, j, k};
        }
      }
    }
    ans = bfs();
    if (ans >= 0) cout << "Escaped in " << ans << " minute(s).\n";
    else cout << "Trapped!\n";
  }
}