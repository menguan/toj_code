#include<stdio.h>
int main()  
{  
    int t,n,k,p;  
    double sum;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d%d%d",&p,&n,&k);  
        sum=1.0;  
        for(int i=n-k;i<=n;i++)  
        {  
            sum=sum*(i*p)/(i*p+1.0);  
        }  
        printf("%.9f\n",sum);  
    }  
    return 0;  
}  
