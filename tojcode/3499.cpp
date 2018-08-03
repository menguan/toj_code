#include<iostream>
using namespace std; 
int id[20000];
int sz[20000];
int find(int p)
{
	while (p != id[p])
	{
		id[p] = id[id[p]];
		p = id[p];
	}
	return p;
}
void add(int p, int q)
{
	int i = find(p);
	int j = find(q);
	if (i == j) return;
	if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
	else { id[j] = i; sz[i] += sz[j]; }
	
}


int main()
{
  int n,m,k;
  while(cin>>n>>m>>k)
  {
    for (int i = 0; i < n; i++)
	id[i] = i; 
	for (int i = 0; i < n; i++)
	sz[i] = 1;
	int p,q;
    while(m--)
    {
      cin>>p>>q;
      add(p,q);
    }
    while(k--)
    {
      cin>>p>>q;
      if(find(p)==find(q))
      cout<<"YES"<<endl;
      else
      cout<<"NO"<<endl;
    }
  }
}           

