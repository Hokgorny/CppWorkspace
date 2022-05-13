#include <bits/stdc++.h>

using namespace std;

long long a, b;

long long bfs(){
  queue<pair<long long, long long>> q;
  q.push({0, a});

  while(!q.empty()){
    long long depth = q.front().first;
    long long now = q.front().second;
    q.pop();

    for(auto i : {now * 2, now * 10 + 1}){
      long long next = i;
      if (next > b) continue;
      if (next == b) return depth + 2;
      else{
        q.push({depth + 1, next});
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