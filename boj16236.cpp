#include <bits/stdc++.h>

using namespace std;
struct shark{
  int y;
  int x;
  int size;
  int stomach;
};
int n;
int field[21][21];
int ttime = 0;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};
tuple<int, int, int> newprey;

bool findprey(shark &s){
  vector<tuple<int, int, int>> prey;
  vector<tuple<int, int, int>>().swap(prey);
  queue<tuple<int, int, int>> q;
  q = queue<tuple<int, int, int>> ();
  bool visited[21][21] = {};

  q.push({s.y, s.x, 0});

  while(!q.empty()){ // prey를 찾는다.
    int y = get<0>(q.front());
    int x = get<1>(q.front());
    int depth = get<2>(q.front());
    q.pop();
    visited[y][x] = true;

    if (field[y][x] < s.size && field[y][x] > 0){
      prey.push_back({y, x, depth});
    }
    else {
      for (int i=0; i<4; i++){
        int newy = y + dy[i];
        int newx = x + dx[i];
        if (newx < 0 || newx >= n || newy < 0 || newy >= n) continue;
        if (!visited[newy][newx] && field[newy][newx] >= 0 && field[newy][newx] <= s.size){
          q.push({newy, newx, depth + 1});
          visited[newy][newx] = true;
        }
      }
    }
  }
  if (!prey.empty()){
    
    // sort(prey.begin(), prey.end());
    newprey = prey.front();
    return true;
  }
  else return false;
  return false;
}

void eatprey(shark &s){
  int yy = get<0>(newprey);
  int xx = get<1>(newprey);
  int movetime = get<2>(newprey);

  s.stomach++;
  ttime += movetime;
  field[yy][xx] = 0;
  s.y = yy;
  s.x = xx;
  if (s.stomach == s.size){
    s.size++;
    s.stomach = 0;
  }
}

int main(void){
  freopen("input.txt", "r", stdin);

  shark s;
  s.size = 2;
  s.stomach = 0;

  cin >> n;
  fill(&field[0][0], &field[20][21], -1);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> field[i][j];
      if(field[i][j] == 9){
        s.y = i;
        s.x = j;
      }
    }
  }

  while(true){
    if (findprey(s)) eatprey(s);
    else break;
  }

  cout << ttime;
}