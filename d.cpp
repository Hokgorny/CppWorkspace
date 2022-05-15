#include <bits/stdc++.h>

using namespace std;

int n, aeiou1 = 0, aeiou2 = 0;
char s1s, s1e, s2s, s2e, s1[100001], s2[100001];

int main(void){
  ios_base::sync_with_stdio(0); // scanf 사용시 아래 두 문장 삭제
  cin.tie(0);

  cin >> n;
  for (int i=0; i<n; i++){
    cin >> s1[i];
    if (i == 0) s1s = s1[i];
    if (i == n - 1) s1e = s1[i];
    if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u') aeiou1++;
  }
  for (int i=0; i<n; i++){
    cin >> s2[i];
    if (i == 0) s2s = s2[i];
    if (i == n - 1) s2e = s2[i];
    if (s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u') aeiou2++;
  }
}