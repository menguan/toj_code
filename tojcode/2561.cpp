#include <cstdlib>//网上找的邻接表拿vector和list建的 
#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>
#include <cstring> 
using namespace std;
int const MAX_N = 105;
int const MAX_E = 301;
typedef struct _NODE
{
    int count;
    vector<int> list;
    
    _NODE() : count(0), list(vector<int>()){}; 
    
}NODE;
int main()
{
    int n, e;
    int ID = 1;
    while( cin >> n, n )
    {
        cin >> e;
        int start, end;
        int tempE = e;
        int index = 0;
        int flag = 0;
        vector<NODE> vec(MAX_N);
                  
        while(tempE-- > 0)  //count表示连接的边数 大于1就是所求路上的节点 
        {
            cin >> start >> end;
            
            vec[start].count++;
            vec[start].list.push_back(end);
            
            vec[end].count++;
            vec[end].list.push_back(start);
        }
        
        if(n - 1 != e)//无环图节点数比边数多1 
        {
            cout << "Graph " << ID << " is not a caterpillar." << endl;
            ID++;
            continue;
        }
        
        vector<NODE>::iterator it = vec.begin();
        vector<NODE>::iterator end1 = vec.begin() + e;
        
        for(; it != end1; it++)
        {
            int count = 0;
            if(it->count > 1)//对每一个所求路上的节点 只能与最多两个路上节点相邻 
            {
                vector<int>::iterator eachIt = (it->list).begin();
                vector<int>::iterator eachEnd = (it->list).end();
                
                for(; eachIt != eachEnd; eachIt++)
                {
                    if(vec[*eachIt].count > 1)
                        count++;
                }
            }
            
            if(count > 2)
            {
                cout << "Graph " << ID << " is not a caterpillar." << endl;
                flag = 1;
                break;
            }
        }
        
        if(!flag)
            cout << "Graph " << ID << " is a caterpillar." << endl;
        
        ID++;
    }
}
