#include <cstdio>  //直接抄了 真打击人
 using namespace std;
 int main() {
     int N, i, k, sum, flag;
     int fen[5010];
     while (scanf("%d",&N) != EOF && N) {
         sum = 0;flag = 1;k = N;
         for (i = 0; i < N; i ++) {
             scanf("%d", fen + i);
             if (fen[i] == 1 && flag) 
               k = i, flag = 0;
         }
         
         for (i = k; i < N; i ++) {
             if (!fen[i]) {
                 if (i + 1 < N) {
                     if (fen[i + 1]) continue;
                     else {
                         fen[i + 1] = 1;
                         sum ++;
                         
                     }
                 }
             }
             
         }
         if(!fen[N - 1]) printf("%d\n",sum + (k + 1) / 2);
         else printf("%d\n", sum + k / 2);    
     }
     return 0;
 }