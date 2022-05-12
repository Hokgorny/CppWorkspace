#include <bits/stdc++.h>

using namespace std;

int t, l, y, x, gy, gx;
bool visited[301][301];
constexpr int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
constexpr int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(){
  memset(visited, false, sizeof(visited));
  queue<tuple<int, int, int>> q;
  q.push({0, y, x});
  visited[y][x] = true;

  if(y == gy && x == gx) return 0;

  while(!q.empty()){
    int depth = get<0>(q.front());
    int yy = get<1>(q.front());
    int xx = get<2>(q.front());
    q.pop();

    for (int i=0; i<8; i++){
      int newy = yy + dy[i];
      int newx = xx + dx[i];
      if (newy < 0 || newy >= l || newx < 0 || newx >= l) continue;
      if (newy == gy && newx == gx) return depth + 1;
      if (!visited[newy][newx]){
        q.push({depth + 1, newy, newx});
        visited[newy][newx] = true;
      }
    }
  }
  return 0;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  cin >> t;
  while(t--){
    cin >> l >> y >> x >> gy >> gx;
    cout << bfs() << "\n";
  }
}