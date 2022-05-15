#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main(void){
  ios_base::sync_with_stdio(false); // scanf 사용시 아래 두 문장 삭제
  cin.tie(nullptr);

  cin >> n >> a >> b;
  int drink = a / 2 + b;
  if (n > drink) cout << drink;
  else cout << n;
}