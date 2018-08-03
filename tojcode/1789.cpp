#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define N 10010

using namespace std;

void cheng(vector<int> &a,vector<int> &b)
{
	int i,j,k,c[N],m;
	k = a.size()+b.size()-1;
	m = b.size();
	for ( i = 0 ; i < k ; i++)
	{
		if( i >= m )	j = i-m+1;
		else	j = 0 ;
		for ( c[i] = 0 ; j <= i ; j++)
		{
			if( j < a.size() && (i-j) < b.size() )
				c[i] += a[j]*b[i-j];
		}
	}
	a.clear();
	for( i = 0 ; i < k ; i++)	a.push_back(c[i]);
}

int main()
{
	int i,j,n,m,num,x;
	int res[N];
	cin>>num;
	while (num--)
	{
		vector<int> a,b,c;
		cin>>m>>n;
		for ( i = 0 ; i <= m ; i++)
		{
			cin>>x;
			a.push_back(x);
		}
		for ( i = 0 ; i <= n ; i++)
		{
			cin>>x;
			b.push_back(x);
			c.push_back(x);		
		}
		memset(res,0,sizeof(res));
		for ( i = 1 , res[0] = a[0] ; i <= m ; i++)
		{
			
			for ( j = 0 ; j < c.size() ; j++)
				res[j] += c[j]*a[i];
			cheng(c,b);//b自乘增加一次幂 
		}		
		for ( i = 0 ; i <= n*m ; i++)
		{
			if( !(i == n*m && res[i] == 0 && i == 0 ))
			{
				if( i )
					cout<<" ";
				cout<<res[i];
			}
			else	cout<<0;
		}
		cout<<endl;
	}
}
