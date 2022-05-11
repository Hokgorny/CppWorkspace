#include <bits/stdc++.h>

using namespace std;

int n, m, t, nn, ans = INT_MAX;
bool b[10] = {};

int intsize(int num){
  int nsize = 0;
  if (num == 0) return 1;
  while(num > 0){
    num = num / 10;
    nsize++;
  }
  return nsize;
}

bool checknum(int num){
  int d = 0;
  int ss = intsize(num);
  for (int i=1; i<=ss; i++){
    d = (int) num % 10;
    if (b[d]) return false;
    num = (num - d) / 10;
  }
  return true;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);
  
  cin >> n >> m;
  for (int i=0; i<m; i++){
    cin >> t;
    b[t] = true; // 고장난 버튼 true로 표시
  }

  cout << checknum(n);
}