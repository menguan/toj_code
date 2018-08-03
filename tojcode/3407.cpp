#include<stdio.h>
int t,n,s;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        while(n--)
        {
          scanf("%d",&s);
          if(s%4==0)
            ans^=(s-1);
          else if(s%4==3)
            ans^=(s+1);
          else
            ans^=s;
        }
        if(ans)
          puts("Alice");
        else
          puts("Bob");
    }
}  
                     
                                
    
