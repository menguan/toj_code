#include<iostream>//别人的代码要看很久才弄明白   
#include<cstring>
#include<stdio.h>
using namespace std;
char a[10101010];
int t1,t2,l,r,n,res,len;
int b[1000];
int main()
{
    while(cin>>n,n)
    {
       memset(b,0,sizeof(b));
       getchar();
       gets(a);
       len=strlen(a);
       l=r=t1=t2=res=0;
       while(l<=r&&r<len)
       {
          //cout<<r<<"kk"<<l<<" "<<t2<<endl;
          
          while(t1<=n&&r<len)
          {
              if(b[a[r]]==0)
              {
                 b[a[r]]=1;t1++;
                 if(t1>n)  break;
              }
              else  b[a[r]]++;
              r++;t2++;
          }if(r-l>res) res=r-l;
          //if(t2>res) res=t2;
          if(r>len)  break;
          while(1)
          {
            b[a[l]]--;
            if(b[a[l]]==0)  break;
            l++;t2--;
          }                                                         
          l++;t1--;r++;
       }
       cout<<res<<endl;
    }
}
  l++;t1--;r++;
       }
       cout<<res<<endl;
    }
}
