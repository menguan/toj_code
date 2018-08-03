#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
  
  
const int M = 9901;  
  
struct Matrix {  
    int v[3][3];  
} m;  
  
Matrix mtMul(Matrix A, Matrix B)     
        {  
    Matrix C;  
    C.v[0][0] = (A.v[0][0] * B.v[0][0] + A.v[0][1] * B.v[1][0]) % M;  
    C.v[0][1] = (A.v[0][0] * B.v[0][1] + A.v[0][1] * B.v[1][1]) % M;  
    C.v[1][0] = (A.v[1][0] * B.v[0][0] + A.v[1][1] * B.v[1][0]) % M;  
    C.v[1][1] = (A.v[1][0] * B.v[0][1] + A.v[1][1] * B.v[1][1]) % M;  
    return C;  
}  
  
Matrix mtPow(Matrix A, int k)        
        {  
    if (k == 1)  
        return A;  
    A = mtPow(A, k / 2);  
    if (k % 2 == 0) {  
        return mtMul(A, A);  
    } else {  
        return mtMul(mtMul(A, A), m);  
    }  
}  
  
int main(){  
    int n;  
    m.v[0][0] = 0,m.v[0][1] = 1;  
    m.v[1][0] = 1,m.v[1][1] = 1;  
  
    while(scanf("%d",&n)!=EOF,n != -1)
    {  
    
        Matrix A = mtPow(m,n+1);  
  
        printf("%d\n",A.v[0][1]);  
    }  
  
    return 0;  
}

