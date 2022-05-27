#include <bits/stdc++.h>

using namespace std;

int t, a, b;

int main(){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);

  cin >> t;
  for (int i=1; i<=t; i++){
    cin >> a >> b;
    cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << "\n";
  }

  return 0;
}