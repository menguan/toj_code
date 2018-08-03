#include<iostream> 
#include<stdio.h> 
int main() 
{ 
    double n,c,t; 
    while(scanf("%lf%lf",&n,&c)!=EOF) 
    {  
        if(n==0) 
        {  
            printf("0\n"); 
            continue; 
        } 
        else t=c/2/n; //求导 
        t=(int)t; 
        int t1=t-1,t2=t,t3=t+1,ans1,ans2,ans3; 
        ans1=2*n*t-n-c; //t-1  已经减去了t(c-tn) 
        ans2=2*n*t-c+n; 
        ans3=4*n*t-2*c; 
        if(ans1>=0) //0的时候就是一开始的t 
        { 
            if(ans3>=0) 
                t=t1; 
            else 
                t=t3; 
        } 
        else 
        { 
            if(ans2>=0) 
                t=t2; 
            else 
                t=t3; 
        } 
        printf("%d\n",(int)t); 
    } 
} 
