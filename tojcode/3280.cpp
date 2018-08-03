#include <iostream> 
#include <deque> 
#include <vector> 
#include <string> 
#include <map> 
#include <algorithm> 
#include <functional> 
#include <stdio.h>
using namespace std; 

struct Pt 
{ 
int a, b; 
}; 

inline int operator < (const Pt& left, const Pt& right) 
{ 
return (left.a < right.a) || (left.a==right.a && left.b < right.b); 
} 
inline int cmp(const Pt& left, const Pt& right) 
{ 
return left.b < right.b; 
} 
Pt important[105]; 
Pt girls[105]; 

int main() 
{ 
int n, m; 
while (scanf("%d%d", &n, &m)==2) 
{ 
for (int i = 0; i < m; ++i) scanf("%d%d", &important[i].a, &important[i].b); 
for (int i = 0; i < n; ++i) scanf("%d%d", &girls[i].a, &girls[i].b); 
int pos = 0; 
if (m > 0) sort(important, important+m); 
int last = important[0].b; 

for (int i = 0; i < m; ++i) 
{ 
if (important[i].a > last) 
{ 
important[pos++].b = last; 
important[pos].a = important[i].a; 
last = important[i].b; 
} 
if (important[i].b > last) last = important[i].b; 
} 
important[pos++].b = last; 
if (m>0) m = pos; 
pos = 0; 
for (int i = 0; i < n; ++i) 
{ 
int l = 0, r = m - 1; 
int t = girls[i].a; 
int failed = 0; 
while (l <= r) 
{ 
int mid = (l+r)/2; 
if (important[mid].a > t) r = mid - 1; 
else l = mid + 1; 
} 
if (l < m) 
{ 
if (girls[i].b > important[l].a) failed = 1; 
} 
if (l - 1 >= 0) 
{ 
if (important[l-1].b > t) failed = 1; 
} 
if (!failed) 
{ 
girls[pos++]= girls[i]; 
} 
} 
n = pos; 
if (n == 0) {puts("0");continue;} 
sort(girls, girls+n, cmp); 
int cnt = 1; 
int k = 0; 
for (int i = 1; i < n; ++i) if (girls[i].a >= girls[k].b) 
{ 
k = i; 
++cnt; 
} 
printf("%d\n", cnt); 
} 
return 0; 
}
