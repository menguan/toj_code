#include<iostream>
using namespace std;
int main()
{
    //cout<<(19575+325)%33<<endl;
    //cout<<19900%23<<" "<<19900%28<<" "<<19900%33<<" "<<19900%325<<endl;
    int p,e,i,d;int cas=1;
    while(cin>>p>>e>>i>>d)
    {
        if(p==-1&&e==-1&&i==-1&&d==-1)
        {
           break;
        }
        p=p%23;
        e=e%28;
        i=i%33;
        int j=i;
        while(!((j-p)%23==0&&(j-e)%28==0))
        {
            j+=33;
        }
        j-=d;
        if(j<=0)
         j+=21252;                                  
         
                 cout<<"Case "<<cas++<<": the next triple peak occurs in "<<j<<" days."<<endl;
             
        
    }
}
                                                         
                                                           
