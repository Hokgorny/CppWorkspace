#include <stdio.h>
long long n, m;
int main(){
  scanf("%d %d", &n, &m);
  if ((n-1)%(m+1)==0) printf("Can't win");
  else printf("Can win");
}