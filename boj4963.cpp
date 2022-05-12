#include <bits/stdc++.h>

using namespace std;

int w, h, cnt;
int field[51][51] = {};
bool visited[51][51] = {};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(int yy, int xx){
  queue<pair<int, int>> q;
  q = queue<pair<int, int>> ();

  q.push({yy, xx});
  visited[yy][xx] = true;

  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int j=0; j<8; j++){
      int newy = y + dy[j];
      int newx = x + dx[j];
      if (newy < 0 || newy >= h || newx < 0 || newx >= w) continue;
      if (field[newy][newx] == 0) continue;
      if (!visited[newy][newx]){
        q.push({newy, newx});
        visited[newy][newx] = true;
      }
    }
  }
  cnt++;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  while(true){
    vector<pair<int, int>> start;
    start.clear();
    memset(field, 0, sizeof(field));
    memset(visited, 0, sizeof(visited));
    cnt = 0;

    cin >> w >> h;
    if (w == 0 && h == 0) break;

    for (int i=0; i<h; i++){
      for (int j=0; j<w; j++){
        cin >> field[i][j];
        if (field[i][j] == 1) start.push_back({i, j});
      }
    }
    for (int i=0; i<start.size(); i++){
      if (!visited[start[i].first][start[i].second]){
        bfs(start[i].first, start[i].second);
      }
    }
    if (w == 1 && h == 1) cnt = field[0][0];
    cout << cnt << "\n";
  }
}