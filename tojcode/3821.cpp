#include<iostream>//网上找的最挫的一个 
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAX = 10000000;


bool pri[MAX], f[MAX];


void makePrime()      
{
    int i, j;
    pri[0] = pri[1] = 0;
    for(i = 2; i < MAX; i ++)
    {
        pri[i] = 1;
    }
    for(i = 2; i * i < MAX; i ++)
    {
        if(pri[i]) {
            for(j = i * i; j < MAX; j += i)
            {
                pri[j] = 0;
            }
        }
    }
}


int main()
{
    int t, n, i, up, val, ans;
    char str[10];
    makePrime();
    scanf("%d", &t);
    while(t --)
    {
        scanf("%s", str);
        n = strlen(str);
        up = 1;
        while(n --) up *= 2;
        n = strlen(str);
        sort(str, str + n);
        memset(f, 0, sizeof(f));
        ans = 0;
        for(val = 1; val < up; val ++)
        {
            int k = 0, num[10];
            for(i = n - 1; i >= 0; i --)            
            {
                if((val >> i) & 1) {
                    num[k ++] = str[n - i - 1] - '0';
                }
            }
            do                                       
            {
                int sum = 0, v = 1;
                for(i = k - 1; i >= 0; i --)
                {
                    sum += v * num[i];
                    v *= 10;
                }
                if(pri[sum] && !f[sum]) {
                    ans ++;
                    f[sum] = true;
                }
            }
            while(next_permutation(num, num + k));
        }
        printf("%d\n", ans);
    }
    return 0;
 
}