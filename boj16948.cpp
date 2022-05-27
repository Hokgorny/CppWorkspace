#include <bits/stdc++.h>

using namespace std;

int n, r1, c1, r2, c2;
bool visited[201][201];

int bfs(){
  queue<tuple<int, int, int>> q;
  q.push({0, r1, c1});

  if (r1 == r2 && c1 == c2) return 0;

  while (!q.empty()){
    int depth = get<0>(q.front());
    int y = get<1>(q.front());
    int x = get<2>(q.front());
    q.pop();

    vector<pair<int, int>> v = {{y - 2, x - 1}, {y - 2, x + 1}, {y, x - 2}, {y, x + 2}, {y + 2, x - 1}, {y + 2, x + 1}};

    for (auto [newy, newx] : v){
      if (newy < 0 || newy >= n || newx < 0 || newx >= n) continue;
      if (newy == r2 && newx == c2) return depth + 1;
      if (!visited[newy][newx]){
        q.push({depth + 1, newy, newx});
        visited[newy][newx] = true;
      }
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);

  cin >> n >> r1 >> c1 >> r2 >> c2;

  cout << bfs();

  return 0;
}