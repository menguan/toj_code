#include<iostream>
using namespace std;
int main()
{
    int a;
    int cell[101];
    
    cin>>a;
    while(a--)
    {
        for(int ii=0;ii<101;ii++)
        {
            cell[ii]=1;
        }
        int b,c=0;
        cin>>b;
        
        for(int i=1;i<=b;i++)
        {
            for(int j=1;j<=b;j++)
            {
                if(j%i==0)
                cell[j]*=-1;
            }
        }
        for(int k=1;k<=b;k++)
        {
            if(cell[k]==-1)
            c++;
        }
        cout<<c<<endl;
    }
    
    return 0;
}    
    