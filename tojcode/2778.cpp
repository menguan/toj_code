#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
char a[10],b[10],c[10];
//int aa[10],bb[10];
int an,bn,cn,cm;int al,bl,cl;
bool flag;
int getwei(int p)
{
    int ret=1;
    for(int i=1;i<p;i++)
      ret*=10;
    return ret;
}
/* 
void dfsc(int posc,int num,int aaa,int bbb)
{
    if(flag)  return;
    if(posc==cl)
    {
       if(num>=cn)
        {
            if(aaa*bbb==num)
              flag=1;
        }       
         
       return;
    }
    num*=10;
    if(c[posc]=='*')
    {
       for(int i=0;i<=9;i++)
       {
           if(i==0&&num==0)
             continue;
           dfsc(posc+1,num+i,aaa,bbb);
       }
    }
    else
    {
        dfsc(posc+1,num+c[posc]-'0',aaa,bbb);
    }
}
*/
void check(int aa,int bb)
{
     //cout<<aa<<" "<<bb<<" "<<cn<<" "<<flag<<endl;
     int ret=aa*bb;
     if(ret<cn)
       return ;
     if(ret>cm)
       return ;  
     for(int i=cl-1;i>=0;i--)
     {
        
        if(ret%10==(c[i]-'0')||c[i]=='*')
        {
          //cout<<ret%10<<" "<<c[i]<<" "<<i<<endl;
          ret/=10;
          continue;
        }  
        flag=0;
        return ;
     }
     flag=1;
     //cout<<aa<<" "<<bb<<" "<<cn<<" "<<flag<<endl;
     return ;
}  
                
void dfsb(int posb,int num,int aaa)
{
    if(flag)  return;
    if(posb==bl)
    {
       //cout<<"b: "<<num<<endl;
       if(num>=bn)
         check(aaa,num);
       return;
    }
    num*=10;
    if(b[posb]=='*')
    {
       for(int i=0;i<=9;i++)
       {
           if(i==0&&num==0)  continue;
           dfsb(posb+1,num+i,aaa);
       }
    }
    else
    {
        dfsb(posb+1,num+b[posb]-'0',aaa);
    }
} 
void dfsa(int posa,int num)
{
    if(flag)  return;
    if(posa==al)
    {
       //cout<<"a: "<<num<<endl;
       if(num>=an)
       {  //cout<<num<<endl;
         dfsb(0,0,num);}
       return;
    }
    num*=10;
    if(a[posa]=='*')
    {
       for(int i=0;i<=9;i++)
       {
           if(i==0&&num==0)  continue;
           dfsa(posa+1,num+i);
       }
    }
    else
    {
        dfsa(posa+1,num+a[posa]-'0');
    }
}                 
int main()
{
    int t;
    //cin>>t;
    scanf("%d",&t);
    while(t--)
    {
          scanf("%s%s%s",&a,&b,&c);    
          //cin>>a>>b>>c;
          //memset(aa,0,sizeof(aa));
          //memset(bb,0,sizeof(bb));
          al=strlen(a);
          bl=strlen(b);
          cl=strlen(c);
          an=getwei(al);
          bn=getwei(bl);
          cn=getwei(cl);
          cm=cn*10-1;
          flag=0;
          dfsa(0,0);
          if(flag)
            puts("Yes");
          else
            puts("No");
    }
}
              
