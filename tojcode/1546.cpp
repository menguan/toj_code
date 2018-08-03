#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <cstring>
using namespace std;
char a[104][6], s[6], ans[6];
int n;
/*
int violence() 
{
 int diff=0;
 int po1,po2;
 int pos[5];
 for(int i=0;i<5;i++)
 {
   pos[s[i]-'A']=i;
 }      
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<5;j++)
     {
         diff+=abs(pos[a[i][j]-'A']-j);        
     }
 }
 return diff/2;
}
*/
int violence() {
 int diff=0, i, j, k, p;
 for (i=0; i < n; i++) {
  for (j=0; j < 4; j++) {
   for (k=j+1; k < 5; k++) {
    for (p=0; p < 5; p++) {
     if (a[i][p] == s[j])
      break;
     if (a[i][p] == s[k]) {
      diff++;
      break;
     }
    }
   }
  }
 }
 return diff;
}

int main()
{
 int m, min, i;
  while (true) {
  scanf("%d", &n);
  if (n == 0)
   break;
  for (i=0; i < n; i++)
   scanf("%s", a+i); 
  strcpy(s,"ABCDE");
  min = 10000000;
  do {
   m = violence();
   if (m < min) {
    min = m;
    strcpy(ans, s);
   }
  } while (next_permutation(s, s+5));
  printf("%s is the median ranking with value %d.\n", ans, min);
 }
}
