#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
struct page
{
       int num[4];
};
int main()
{
    int n,sheets;
    page pages[30];
    int i,p,ps,temp=0,back=0;
    while(cin>>n,n)
    {
        memset(pages,0,sizeof(pages));
        sheets=n/4;
        if(n%4!=0) sheets++;
        back=temp=ps=0;p=-1;
        for(i=1;i<=n;i++)
        {
          if(i<=sheets*2)
          {
            if(i%2==1) p++;
            if(!temp)
              pages[p].num[1]=i;
            else
              pages[p].num[2]=i;
           temp=(temp+1)%2;
           back=0;
          }
          else
          {
           if(back==0){p++;back=1;}
           if(i%2==1) p--;
           if(temp==0)
             pages[p].num[3]=i;
           else
             pages[p].num[0]=i;
           temp=(temp+1)%2;
          }
        }
        cout<<"Printing order for "<<n<<" pages:"<<endl;
        for(i=0;i<sheets;i++)
        {
         if(pages[i].num[0]==0&&pages[i].num[1]==0)
           continue;
         cout<<"Sheet "<<i+1<<", front: ";
         if(pages[i].num[0]!=0) cout<<pages[i].num[0]<<", ";
         else cout<<"Blank, ";
         if(pages[i].num[1]!=0) cout<<pages[i].num[1]<<endl;
         else cout<<"Blank"<<endl;
         if(pages[i].num[2]==0&&pages[i].num[3]==0)
           continue;
         cout<<"Sheet "<<i+1<<", back : ";
         if(pages[i].num[2]!=0) cout<<pages[i].num[2]<<", ";
         else cout<<"Blank, ";
         if(pages[i].num[3]!=0) cout<<pages[i].num[3]<<endl;
         else cout<<"Blank"<<endl;  
        }
    }
}
                                           
                                          
            
