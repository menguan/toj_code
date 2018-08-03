#include <iostream>//因为要去给别的场子捣乱 所以虽然很水的题还是懒得打了 
#include <cstring>
using namespace std;
int map[27][27],chan[27];
int mmin,n;
bool ok(int i, int c)
{
    for(int j=0;j<n;++j)
        if(map[i][j]&&c==chan[j])
            return false;
    return true;
}
void dfs(int i)
{
    if(i==n)
    {
        int m=0;
        for(int j=0;j<n;++j)
            if(m<chan[j])m=chan[j];
        if(mmin>m)mmin=m;
    }
    else
    {
        for(int c=0;c<4;++c)
        {
            if(ok(i,c))
            {
                int tmp=chan[i];
                chan[i]=c;
                dfs(i+1);
                chan[i]=tmp;
            }
        }
    }
}
int main()
{
	char ch[50];
	while(cin>>n,n)
	{
		memset(map,0,sizeof(map));
		
		for(int i=0;i<n;++i)
		{
			cin>>ch;
			if(strlen(ch)>2)
			{
				for(int j=2;j<strlen(ch);++j)
				{
					int k=ch[j]-65;
					map[i][k]=map[k][i]=1;
				}
			}
		}
		
		for(int k=0;k<n;++k) chan[k]=-1;
		
		mmin=5;
	    dfs(0);
	    mmin++;
	    if(mmin>1)
	       cout<<mmin<<" channels needed."<<endl;
	    else cout<<mmin<<" channel needed."<<endl;
	}
	return 0;
}
