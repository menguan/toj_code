#include <cstdio> 
int n, sum;

int cal (int a, int n ) {//对半来求幂  又学了一手 
    if ( n == 1 ) return a;
    sum = cal(a, n / 2);
    sum = ( sum % 2006 ) * ( sum % 2006 ) % 2006;
    if ( n % 2 ) sum = ( a % 2006 ) * ( sum % 2006 ) % 2006;
    return sum;
    }
    
int main () {
    while ( scanf("%d", &n), n) {
          sum = cal(n, n);
          printf("%d\n", sum);
          }
    return 0;
    }/* 
#include <cstdio> 
int n, sum;

int cal (int a, int n ) {//对半来求幂  又学了一手 
    if ( n == 1 ) return a;
    sum = cal(a, n / 2);
    sum = ( sum % 2006 ) * ( sum % 2006 ) % 2006;
    if ( n % 2 ) sum = ( a % 2006 ) * ( sum % 2006 ) % 2006;
    return sum;
    }
    
int main () {
    while ( scanf("%d", &n), n) {
          sum = cal(n, n);
          printf("%d\n", sum);
          }
    return 0;
    }
*/ 