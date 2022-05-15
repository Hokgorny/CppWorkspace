#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main(void){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);

  cin >> n >> m >> k;
  int ans = (m + (k - 3));
  while (ans <= 0){
    ans += n;
  }
  ans = ans % n;
  if (ans == 0) cout << n;
  else cout << ans;
}