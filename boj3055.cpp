#include <bits/stdc++.h>

using namespace std;

int r, c;
char field[51][51];
bool vs[51][51];
int vw[51][51];
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};
pair<int, int> start, goal;
vector<pair<int, int>> water;

void wbfs(){
  queue<tuple<int, int, int>> qw;
  for (int i=0; i<(int) water.size(); i++){
    qw.push({1, water[i].first, water[i].second});
    vw[water[i].first][water[i].second] = 1;
  }

  while (!qw.empty()){
    int wdepth = get<0>(qw.front());
    int wy = get<1>(qw.front());
    int wx = get<2>(qw.front());
    qw.pop();

    for (int i=0; i<4; i++){
      int wnewy = wy + dy[i];
      int wnewx = wx + dx[i];
      if (wnewy < 0 || wnewy >= r || wnewx < 0 || wnewx >= c) continue;
      if (vw[wnewy][wnewx] == 999999999 && field[wnewy][wnewx] != 'X' && field[wnewy][wnewx] != 'D'){
        qw.push({wdepth + 1, wnewy, wnewx});
        vw[wnewy][wnewx] = wdepth + 1;
      }
    }
  }
}

int sbfs(){
  queue<tuple<int, int, int>> qs;
  qs.push({1, start.first, start.second});
  vs[start.first][start.second] = true;

  while (!qs.empty()){
    int sdepth = get<0>(qs.front());
    int sy = get<1>(qs.front());
    int sx = get<2>(qs.front());
    qs.pop();

    for (int i=0; i<4; i++){
      int snewy = sy + dy[i];
      int snewx = sx + dx[i];
      if (snewy < 0 || snewy >= r || snewx < 0 || snewx >= c) continue;
      if (field[snewy][snewx] == 'D') return sdepth;
      if (!vs[snewy][snewx] && sdepth + 1 < vw[snewy][snewx] && field[snewy][snewx] != 'X'){
        qs.push({sdepth + 1, snewy, snewx});
        vs[snewy][snewx] = true;
      }
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);
  fill(&vw[0][0], &vw[50][51], 999999999);

  cin >> r >> c;
  for (int i=0; i<r; i++){
    for (int j=0; j<c; j++){
      cin >> field[i][j];
      if (field[i][j] == 'S') start = {i, j};
      if (field[i][j] == 'D') goal = {i, j};
      if (field[i][j] == '*') water.push_back({i, j});
    }
  }
  wbfs();
  int ans = sbfs();

  if (ans == -1) cout << "KAKTUS";
  else cout << ans;

  return 0;
}