#include <iostream>
#include <string>
#include <set>
using namespace std;


multiset<int> little;
multiset<int,greater<int> >big;


int main()
{
	int T, N, m, a;
	string op;
	cin>>T;
	while(T--){
		little.clear();
		big.clear();
		cin>>N;
		for(int i = 0; i < N; ++i){
			cin>>a;
			little.insert(a);
		}
		for(int i = 0; i < (N+1)/2; ++i){
			big.insert(*little.begin());
			little.erase(little.begin());
		}

		cin>>m;
		for(int i = 0; i < m; ++i){
			cin>>op;
			if(op == "add"){
				cin>>a;
				if(a > *big.begin())
					little.insert(a);
				else big.insert(a);
				if(big.size() < little.size()){
					big.insert(*little.begin());
					little.erase(little.begin());
				}else if(big.size() > little.size()+1){
					little.insert(*big.begin());
					big.erase(big.begin());
				}
			}else {
				cout<<*(big.begin())<<endl;
			}
		}
	}
	return 0;
}
	