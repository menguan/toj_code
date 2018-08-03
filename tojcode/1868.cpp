#include <iostream>  
#include <vector> 
#include <cstring>
#include <cmath> 
using namespace std;  
const int N = 1000000;  
vector<int> prime;  
bool vis[N];  
  
void init();  
  
int main()  
{  
    int n, c;  
  
    init();  
  
    while (cin>>n) {  
        if (n == 0)  
            break;  
  
        int tmp = n;  
        c = 0;  
        for (int i = 0; i < prime.size(); i++) {  
            if (tmp < prime[i])  
                break;  
  
            if (tmp % prime[i] == 0) {  
                c++;  
                while (tmp % prime[i] == 0) {  
                    tmp /= prime[i];  
                }  
            }  
        }  
        cout<<n<<" : "<<c<<endl;
    }  
  
  
    return 0;  
}  
  
void init()  
{  
    int m = (int)sqrt(N + 0.5);  
  
    memset(vis, false, sizeof(vis));  
  
    for (int i = 2; i < m; i++) {  
        if (!vis[i]) {  
            for (int j = i * i; j < N; j += i)  
                vis[j] = true;  
        }  
    }  
  
    for (int i = 2; i < N; i++) {  
        if (!vis[i])  
            prime.push_back(i);  
    }  
}  