#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
int field[126][126];
bool visited[126][126];
vector<int> ans;
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

int bfs(){
  queue<tuple<int, int, int>> q; // 잃은돈, y좌표, x좌표
  q.push({field[0][0], 0, 0});
  visited[0][0] = true;

  while(!q.empty()){
    int money = get<0>(q.front());
    int y = get<1>(q.front());
    int x = get<2>(q.front());
    q.pop();
    visited[y][x] = true;
    
    if (y < 0 || y >= n || x < 0 || x >= n) ;
    else if (y == n - 1 && x == n - 1){
      ans.push_back(money);
    }
    else {
      for (int i=0; i<4; i++){
        int newy = y + dy[i];
        int newx = x + dx[i];
        if (!visited[newy][newx]){
          q.push({money + field[newy][newx], newy, newx});
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  return ans[0];
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  while(true){
    cnt++;
    ans.clear();
    memset(field, 0, sizeof(field));
    memset(visited, false, sizeof(visited));

    cin >> n;
    if (n == 0) break;

    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
        cin >> field[i][j];
      }
    }
    cout << "Problem " << cnt << ": " << bfs() << "\n";
  }
}