#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  
  bool visited[100001] = {};
  queue<pair<int, int>> q; // {노드 번호, 깊이}
  int depth = INT_MAX;

  q.push({n, 0});

  while(!q.empty()){
    int curr_pos = q.front().first;
    int curr_depth = q.front().second;
    q.pop();
    visited[curr_pos] = true;

    if (curr_pos == k && depth == INT_MAX){
      depth = curr_depth;
    }
    else if (curr_pos == k && curr_depth < depth){
      depth = curr_depth;
    }
    else if (visited[k] && curr_depth > depth) break;
    else {
      for(int next_pos : {curr_pos - 1, curr_pos + 1, curr_pos * 2}){
        if (next_pos < 0 || next_pos > 100000) continue;
        else if (!visited[next_pos]){
          if (next_pos == curr_pos * 2) q.push({next_pos, curr_depth});
          else q.push({next_pos, curr_depth + 1});
        }
      }
    }
  }
  cout << depth << '\n';
}