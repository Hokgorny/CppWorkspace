#include <bits/stdc++.h>

using namespace std;

int n, m, ans = INT_MAX;
int field[51][51];
bool visited[51][51];
vector<pair<int, int>> virus;

void bfs(pair<int, int> v1, pair<int, int> v2, pair<int, int> v3){
  int t = 0;

  ans = min(ans, t);
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  cin >> n >> m;
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      cin >> field[i][j];
      if (field[i][j] == 2) virus.push_back({i, j});
    }
  }
  // 바이러스 3개 콤비네이션 구현
}