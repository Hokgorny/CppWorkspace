#include <bits/stdc++.h> //2022 05 08

using namespace std;

int bfs(int l[], int s[]){
  queue<int> q;
  bool visited[101] = {}; // 해당 노드 방문 여부
  int least_num[101] = {}; // 해당 노드까지 주사위 굴린 횟수
  int ans = 1000;

  q.push(1);
  visited[1] = true;

  while(!q.empty()){
    int y = q.front();
    q.pop();

    for(int i=1; i<=6; i++){
      if (y + i > 100){
        continue;
      }
      else if (y + i == 100){
        least_num[y + i] = least_num[y] + 1;
        q = queue<int> (); // 100 도달했으면 최소거리 보장되므로 바로 종료
        break;
      }
      else if (l[y + i] != 0 && !visited[l[y + i]]){
        q.push(l[y + i]);
        visited[l[y + i]] = true;
        least_num[l[y + i]] += least_num[y] + 1;
      }
      else if (s[y + i] != 0 && !visited[s[y + i]]){
        q.push(s[y + i]);
        visited[s[y + i]] = true;
        least_num[s[y + i]] = least_num[y] + 1;
      }
      else if (l[y + i] == 0 && s[y + i] == 0 && !visited[y + i]){
        q.push(y + i);
        visited[y + i] = true;
        least_num[y + i] = least_num[y] + 1;
      }
    }
  }
  return least_num[100];
}

int main(void)
{
  freopen("input.txt", "r", stdin);

  int n, m;
  cin >> n >> m;
  int l[101] = {}, s[101] = {};
  // memset(l, 0, sizeof(int) * 101); //배열 초기화. 0으로 초기화 할때는
  // memset(s, 0, sizeof(int) * 101); //int l[101] = {0, };으로 간단히 가능

  for(int i=0; i<n; i++){
    int x, y;
    cin >> x >> y;
    l[x] = y;
  }
  for(int i=0; i<m; i++){
    int u, v;
    cin >> u >> v;
    s[u] = v;
  }
  
  cout << bfs(l, s);
}