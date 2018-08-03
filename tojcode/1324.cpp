#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
long long gcd(long long a , long long b)
{ return b==0 ? a : gcd(b,a%b); }
int main()
{
    long long p,q;
    while(cin>>p>>q&&(p+q))
    {
      // cout<<q<<endl;
       if(p==q)  
       { printf("2 0\n"); continue;}
       if(p==0)  
       { printf("0 2\n"); continue;}
      
       long long g=gcd(p,q); 
      // cout<<p<<" "<<q<<" "<<g<<endl;
       p/=g; q/=g;
       //cout<<p<<" " <<q<<endl;
       long long i,j;
       for(i=2; i<=50000; i++)
           if(i*(i-1)%q==0)
           {
              //  cout<<i<<endl;
         //       system("pause");
                long long m=i*(i-1)/q*p;
                j=(long long)sqrt(m+0.5);
                if(j*(j+1)==m&&j>0)
                    break;
           }   
        if(i>50000) 
          cout<<"impossible\n";
        else        
          cout<<j+1<<" "<<i-j-1<<endl;
    }
    return 0;
}
