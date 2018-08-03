#include<iostream>
#include<cstring>
using namespace std;
const int inf=1010101010;
int fun(int a,int b,int c,int d,int e,int f)
{
    int ret=0;
    if(a*c>e)  return inf;
    else if(a*c<e) ret++;
    if(b*d>f)  return inf;
    else if(b*d<f) ret++;
    return ret+a*b-1;
}
int main()
{
    int n=4;
    int a,b,c,d,e,f;
    while(cin>>a>>b>>c>>d>>e>>f&&(a+b+c+d+e+f))
    {
       int tmp;         
       int ans=inf;            
       tmp=fun(a,b,c,d,e,f);         
       if(tmp<ans)ans=tmp;
       tmp=fun(b,a,c,d,e,f);         
       if(tmp<ans)ans=tmp;  
       tmp=fun(a,b,d,c,e,f);         
       if(tmp<ans)ans=tmp;  
       tmp=fun(b,a,d,c,e,f);         
       if(tmp<ans)ans=tmp;
       if(ans==inf)  cout<<"The paper is too small."<<endl;
       else  cout<<"The minimum number of cuts is "<<ans<<"."<<endl;
    }
}                                                  
