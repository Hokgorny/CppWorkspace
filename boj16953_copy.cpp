#include <bits/stdc++.h>

using namespace std;

long long a, b;
bool visited[1000000001];

long long bfs(){
  queue<pair<long long, long long>> q;
  q.push({0, b});
  visited[b] = true;

  while(!q.empty()){
    long long depth = q.front().first;
    long long now = q.front().second;
    q.pop();
    visited[now] = true;

    for(auto i : {(double) now / 2, (double) (now - 1) / 10}){
      if (i != now / 2 || i != (now - 1) / 10) continue;
      long long next = i;
      if (next < a) continue;
      if (next == a) return depth + 2;
      if (!visited[next]){
        q.push({depth + 1, next});
        visited[next] = true;
      }
    }
  }
  return -1;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);

  cin >> a >> b;
  cout << bfs();
}