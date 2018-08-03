#include<iostream>
#include<cstring>
using namespace std;
int a[30];
void init()
{
     a[0]=1;
     for(int i=1;i<=21;i++)
      a[i]=2*a[i-1];
}
void f(int p)
{
     if(p==0)
       return ;
    //cout<<"kk"<<p<<endl;
     //system("pause");
     for(int i=20;i>=0;i--)
     {         
        if(p>=a[i])
        {
             //cout<<p<<" jj "<<i<<" "<<a[i]<<endl;
             if(a[i]==2)
             {
               if(p==2)
                 cout<<"2";
               else  
                cout<<"2+";
               f(p-2);
               return;
             }
             else if(a[i]==1)
             {
               cout<<"2(0)";
               return ;
             }   
             cout<<"2(";
             f(i);
             if(p==a[i])
               cout<<")";
             else  
               cout<<")+";
             p-=a[i];
             f(p);
              return ;
        }
     }
}
int main()
{
    int t;
    init();
    //for(int i=0;i<21;i++)
    //  cout<<a[i]<<endl;
    while(cin>>t)
    {
      if(t==-1)
        return 0;           
      cout<<t<<" = ";
      f(t);
      cout<<endl;
    }
}           
