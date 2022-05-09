#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;

  // if (n == k){
  //   cout << 0 << '\n' << 1;
  //   return 0;
  // }
  
  bool visited[100001] = {};
  queue<pair<int, int>> q; // {노드 번호, 깊이}
  int num_of_goal = 0;
  int depth = INT_MAX;

  q.push({n, 0});

  while(!q.empty()){
    int curr_pos = q.front().first;
    int curr_depth = q.front().second;
    q.pop();
    visited[curr_pos] = true;

    if (curr_pos == k && depth == INT_MAX){
      depth = curr_depth;
      num_of_goal += 1;
    }
    else if (curr_pos == k && curr_depth == depth){
      num_of_goal += 1;
    }
    else if (visited[k] && curr_depth > depth) break;
    else {
      for(int next_pos : {curr_pos - 1, curr_pos + 1, curr_pos * 2}){
        if (next_pos < 0 || next_pos > 100000) continue;
        else if (!visited[next_pos]) q.push({next_pos, curr_depth + 1});
      }
    }
  }
  cout << depth << '\n' << num_of_goal;
}