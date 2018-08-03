#include<iostream>
using namespace std;
int main()
{
    int f2,f5;int last;
    int n,m;int temp;int tmp;
    while(cin>>n>>m)
    {
        last=1;
        f2=0;f5=0;
        for(int i=0;i<m;i++)
        {
            temp=last*(n-i);tmp=m-i;
            while(temp%2==0) f2++,temp/=2;
            while(temp%5==0) f5++,temp/=5;
            while(tmp%2==0) f2--,tmp/=2;
            while(tmp%5==0) f5--,tmp/=5;
            for(int i=0;i<10;i++)
            {
               if((i*tmp)%10==temp%10)
               {
                   last=i;
                   break;
               }         
            }
        }
        if(f5>f2)
        {
            cout<<5<<endl;
            continue;
        }
        f2-=f5;
        while(f2--)
          last*=2;
        cout<<last%10<<endl;
    }
}                                      
