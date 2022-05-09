#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;

  // if (n == k){
  //   cout << 0;
  //   return 0;
  // }
  
  vector<bool> visited(100001, false);
  vector<int> num(100001, 0);
  queue<int> q;

  q.push(n);

  while(!visited[k]){
    visited[n] = true;
    int x = q.front();
    q.pop();
    
    for (int i=0; i<3; i++){
      int c;
      if (i == 0){
        if (x - 1 >= 0) c = x - 1;
        else continue;
      }
      else if (i == 1){
        if (x + 1 <= 100000) c = x + 1;
        else continue;
      }
      else if (i == 2) {
        if (x * 2 >= 0 && x * 2 <= 100000) c = x * 2;
        else continue;
      }
      
      if (c == k){
        cout << num[x] + 1;
        return 0;
      }
      else if (!visited[c]){
        q.push(c);
        visited[c] = true;
        num[c] = num[x] + 1;
      }
    }
  }
}