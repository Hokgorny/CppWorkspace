#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("input.txt", "r", stdin);

  int problems;
  cin >> problems;
  problems += 87;

  int need = (800-621) - (175 * (1 - pow(0.995, problems)));
  cout << need;
}