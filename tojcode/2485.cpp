#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int t;
    int n;
    int a[20],temp;
    queue<int>card;

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1; i<=n; i++)
            card.push(i);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                temp=card.front();
                card.pop();
                card.push(temp);
            }
            temp=card.front();
            card.pop();
            a[temp]=i;
        }
        cout<<a[1];
        for(int i=2;i<=n;i++)
            cout<<" "<<a[i];
        cout<<endl;
    }
    return 0;
}
