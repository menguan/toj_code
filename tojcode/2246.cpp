#include <cstdio>  //不看题解根本下不了手  乱改别人代码还错了一次 
int n, gold, p;  
inline int Ans()  
{  
    int t = (n - 1) >> 1;  
    if (p == n) return gold - t;  
    if ((p - n) & 1) return 0;  
    return 1;  
}  
inline int Ans2()  
{  
    int t = gold << 1, i;  
    for (i = 1; i < n - t; i <<= 1)  
        ;  
    if (i != n - t) i >>= 1;  
    if (p > t + i) return -1;  
    return 0;  
}  
    
int main()  
{  
    int t;  
    scanf("%d", &t);  
    while (t--)  
    {  
        scanf("%d%d%d", &n, &gold, &p);  
        if (n <= 2 * gold + 1)  
            printf("%d\n", Ans());  
        else
            puts(p > 2 * gold + 2 && Ans2() ? "Thrown" : "0"); 
    }  
}
