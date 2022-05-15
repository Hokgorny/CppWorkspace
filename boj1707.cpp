#include <bits/stdc++.h>

using namespace std;

int k, v, e;
bool status;
bool visited[20001];

// bfs 탐색 하면서 방문점 기록
// 1. 방문점 벡터의 길이가 v와 일치하는가(모든 점을 방문했는가)
// 2. 시작점으로 회귀했는가
// 2-1. NO 종료조건 : 방문점에 다시 방문했을 때 + 1번 만족
// 2-2. YES 종료조건 : 최종리턴

void bfs(int start, vector<vector<int>> &nodes){
  vector<int> checked;
  checked.clear();
  queue<int> q;
  q.push(start);
  checked.push_back(start);
  visited[start] = true;

  while(!q.empty()){
    int now = q.front();
    q.pop();

    for (int j=0; j<nodes[now].size(); j++){
      int next = nodes[now][j];
      if (visited[next] && checked.size() == v && next != checked[checked.size() - 2]){
        status = true;
        return;
      }
      if (!visited[next]){
        q.push(next);
        visited[next] = true;
        checked.push_back(next);
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);
  cout.tie(0);

  cin >> k;
  while(k--){
    memset(visited, false, sizeof(visited));
    status = false;
    cin >> v >> e;
    vector<vector<int>> nodes(v + 1, vector<int> ());
    nodes.clear();

    for (int i=0; i<e; i++){
      int a, b;
      cin >> a >> b;
      nodes[a].push_back(b);
      nodes[b].push_back(a);
    }
    for (int i=1; i<=v; i++){
      bfs(i, nodes);
    }
    if (status = true) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}