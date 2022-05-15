#include <bits/stdc++.h>

using namespace std;

int n, m;
int field[51][51];
bool visited[51][51];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};

void reset(){
  memset(visited, false, sizeof(visited));
}

int main(void){
  ios_base::sync_with_stdio(false); // scanf 사용시 아래 두 문장 삭제
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  cin >> n >> m;
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      cin >> field[i][j];
      if (field[i][j] == 1) house.push_back({i, j});
      if (field[i][j] == 2) chicken.push_back({i, j});
    }
  }
  
}