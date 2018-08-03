#include<iostream>
#include<string.h>
using namespace std;
//首行
void f1(int s,char k)
{
    if(k=='1'||k=='4')
    {
      for(int i=1;i<=s+2;i++)
      {
         cout<<" ";
      }
    }
    else
    {
        cout<<" ";
        for(int i=1;i<=s;i++)
        {
          cout<<"-";
        }
        cout<<" ";
    }
}
//中上行
void f2(int s,char k)
{
    if(k=='1'||k=='2'||k=='3'||k=='7')
    {
        for(int i=1;i<=s+1;i++)
        {
            cout<<" ";
        }
        cout<<"|";
    }
    else if(k=='4'||k=='8'||k=='9'||k=='0')
    {
        cout<<"|";
        for(int i=1;i<=s;i++)
        {
            cout<<" ";
        }
        cout<<"|";
    }
    else
    {
        cout<<"|";
        for(int i=1;i<=s+1;i++)
        {
            cout<<" ";
        }
    }
}
//中行            
void f3(int s,char k)
{
    if(k=='1'||k=='7'||k=='0')
    {
       for(int i=1;i<=s+2;i++)
       {
         cout<<" ";
       }
    }
    else
    {
        cout<<" ";
        for(int i=1;i<=s;i++)
        {
          cout<<"-";
        }
        cout<<" ";
    }
}
//中下行
void f4(int s,char k)
{
    if(k=='2')
    {       
        cout<<"|";
        for(int i=1;i<=s+1;i++)
        {
            cout<<" ";
        }                               
    }
    else if(k=='6'||k=='8'||k=='0')
    {
        cout<<"|";
        for(int i=1;i<=s;i++)
        {
            cout<<" ";
        }
        cout<<"|";
    }
    else
    {
        for(int i=1;i<=s+1;i++)
        {
            cout<<" ";
        }
        cout<<"|";
    }
}
//底行
void f5(int s,char k)
{
    if(k=='1'||k=='4'||k=='7')
    {
      for(int i=1;i<=s+2;i++)
      {
         cout<<" ";
      }
    }
    else
    {
        cout<<" ";
        for(int i=1;i<=s;i++)
        {
          cout<<"-";
        }
        cout<<" ";
    }
}    
             
int main()
{
    int s;
    string k;
    while(cin>>s>>k)
    {    
        if(s==0&&k=="0")
            return 0;
        int kk=k.length();
        //首行 
        for(int j=0;j<kk;j++)
        {
            if(j==kk-1)
              f1(s,k[j]);
            else
            {
              f1(s,k[j]);
              cout<<" ";
            }
        }
        cout<<endl;
        //中上行
        for(int i=1;i<=s;i++)
        {
            for(int j=0;j<kk;j++)
            {
              if(j==kk-1)
                f2(s,k[j]);
              else
              {
                f2(s,k[j]);
                cout<<" ";
              }
            }
            cout<<endl;
        }
        //中行
        for(int j=0;j<kk;j++)
        {
            if(j==kk-1)
              f3(s,k[j]);
            else
            {
              f3(s,k[j]);
              cout<<" ";
            }
        }
        cout<<endl;
        //中下行
        for(int i=1;i<=s;i++)
        {
            for(int j=0;j<kk;j++)
            {
              if(j==kk-1)
                f4(s,k[j]);
              else
              {
                f4(s,k[j]);
                cout<<" ";
              }
            }
            cout<<endl;
        }
        //下行
        for(int j=0;j<kk;j++)
        {
            if(j==kk-1)
              f5(s,k[j]);
            else
            {
              f5(s,k[j]);
              cout<<" ";
            }
        }
        cout<<endl<<endl;
         
        }
    return 0;
} 