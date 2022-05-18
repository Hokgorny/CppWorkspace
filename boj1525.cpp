#include <bits/stdc++.h>

using namespace std;

struct puzzle {
  int field[3][3];
  int depth;
  // constexpr auto operator==(const puzzle&) const = default;
};
bool operator == (puzzle const& p1, puzzle const& p2){
  if (p1.depth == p2.depth){
    for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        if (p1.field[i][j] != p2.field[i][j]) return false;
      }
    }
    return true;
  }
  else if (p1.depth != p2.depth) return false;
  return false;
}
puzzle pz;
int ans[3][3] = {
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 0}
};
vector<puzzle> visited; // y, x, 0 ~ 9
pair<int, int> start;
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

bool anscheck(puzzle pzc){
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
      if (pzc.field[i][j] != ans[i][j]) return false;
    }
  }
  return true;
}

bool visitcheck(puzzle pzc){
  if (find(visited.begin(), visited.end(), pzc) == visited.end()) return false;
  return true;
}

void act_visit(puzzle pzc){
  visited.push_back(pzc);
}

int bfs(){
  queue<puzzle> q;
  q.push(pz);
  act_visit(pz);

  while (!q.empty()){
    puzzle now = q.front();
    q.pop();

    for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        if (now.field[i][j] == 0) start = {i, j};
      }
    }

    for (int i=0; i<4; i++){
      int newy = start.first + dy[i];
      int newx = start.second + dx[i];
      if (newy < 0 || newy >= 3 || newx < 0 || newx >= 3) continue;

      puzzle next = now;
      next.depth++;
      int temp0 = next.field[start.first][start.second];
      int tempnot0 = next.field[newy][newx];
      next.field[start.first][start.second] = tempnot0;
      next.field[newy][newx] = temp0;
      if (anscheck(next)) return next.depth;
      if (!visitcheck(next)){
        q.push(next);
        act_visit(next);
      }
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);

  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
      cin >> pz.field[i][j];
      if (pz.field[i][j] == 0) start = {i, j};
    }
  }
  pz.depth = 0;
  cout << bfs();
  return 0;
}