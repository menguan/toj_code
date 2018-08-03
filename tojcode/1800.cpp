#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Node{
    long long right,left,num;
};
Node node[100010];
int main()
{
    long long n,i,j,k;
    
    while(cin>>n,n)
    {
        
        
        for(i=1;i<=n;i++)
        {
            cin>>node[i].num;
            node[i].left=i;           
            node[i].right=i;
        }
        node[0].num=-1;
        node[n+1].num=-1;
        for(i=1;i<=n;i++)
        {
            while(node[i].num<=node[node[i].left-1].num)    
            {
                node[i].left=node[node[i].left-1].left;    
            }
        }
        for(i=n;i>=1;i--)
        {
            while(node[i].num<=node[node[i].right+1].num)
            {
                node[i].right=node[node[i].right+1].right;
            }
        }
        long long ans=0;
        long long temp;
        for(i=1;i<=n;i++)
        {
            temp=node[i].num*(node[i].right-node[i].left+1);
            if(ans<temp)
                ans=temp;
        }
        cout<<ans<<endl;
    }
    return 0;
}