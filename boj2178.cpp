#include <bits/stdc++.h>

using namespace std;

int n, m;
int field[101][101] ={};
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int bfs(int num){
  queue<tuple<int, int, int>> q;
  bool visited[101][101] = {};
  int ans = INT_MAX;

  q.push({1, 0, 0});
  while(!q.empty()){
    int depth = get<0>(q.front());
    int y = get<1>(q.front());
    int x = get<2>(q.front());
    q.pop();

    for (int i=0; i<4; i++){
      int newy = y + dy[i];
      int newx = x + dx[i];
      if (newy < 0 || newy >= n || newx < 0 || newx >= m) continue;
      else if (field[newy][newx] == 0) continue;
      else if (newy == n - 1 && newx == m - 1){
        ans = min(ans, depth + 1);
      }
      else if (!visited[newy][newx]){
        q.push({depth + 1, newy, newx});
        visited[newy][newx] = true;
      }
    }
  }
  return ans;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  scanf("%d %d\n", &n, &m);
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      scanf("%1d", &field[i][j]);
    }
  }

  cout << bfs(n);
}