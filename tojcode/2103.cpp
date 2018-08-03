#include<iostream>//这个比我自己想的还多一步
#include<algorithm>
#include<cstring>
using namespace std;
int a[31];
int step[100];
int round;
void change(int n)
{
        int c;
        for(c=1;c<n-c+1;c++)
        {
                int tmp=a[c];
                a[c]=a[n-c+1];
                a[n-c+1]=tmp;
        }
};
int main()
{
        int n;
        while(cin>>n,n)
        {
                int N;round=0;
                for(N=1;N<=n;N++)
                {
                        cin>>a[N];
                }
                for(N=n;N>=1;N--)
                {
                        if(a[N]==N)continue;
                        int i;
                        for(i=2;i<N;i++)
                        {
                                if(a[i]==N)
                                {
                                        change(i);
                                        step[round++]=i;
                                }
                        }
                        change(N);
                        step[round++]=N;
                }
                cout<<round;
                for(N=0;N<round;N++)
                {
                        cout<<' '<<step[N];
                }
                cout<<endl;
        }
}
