#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);

  int n, ans = 1;
  cin >> n;
  for (int i=1; i<=n; i++){
    ans = ans * i;
  }
  cout << ans;
}