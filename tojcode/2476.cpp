#include<iostream>//两次筛法
#include<cstring>
#include<stdio.h> 
using namespace std;
const int nMax = 1000010;
const int mMax = 90000;
bool p[nMax];
int cnt, H_pri[mMax];
int H_se_pri[nMax];
void H_priList(){        
    int i, j, k;
    for(i = 1; i < nMax; i += 4)
        p[i] = 1;
    for(i = 5; i * i < nMax; i += 4)
        if(p[i])
        {
            k = i << 1;
            for(j = i + k; j < nMax; j += k)
                p[j] = 0;
        }
    for(cnt = 0, i = 5; i < nMax; i += 4)
        if(p[i]) H_pri[cnt ++] = i;
}

 

void H_se_priList(){    
    int i, j, w;
    memset(p, 0, sizeof(p));
    for(i = 0; H_pri[i] * H_pri[i] < nMax; i ++)     
        for(j = i; j < cnt; j ++)
        {
            w = H_pri[i] *  H_pri[j];
            if(w >= nMax) break;
            if((w - 1) % 4 == 0) p[w] = 1;
        }
    for(i = 1; i < nMax; i ++)
    {                      
        H_se_pri[i] = H_se_pri[i - 1];
        if(p[i]) H_se_pri[i] ++;
    }
}

 

int main(){
    int num;
    H_priList();
    H_se_priList();
    while(scanf("%d", &num) && num)
        printf("%d %d\n", num, H_se_pri[num]);
    return 0;
}
