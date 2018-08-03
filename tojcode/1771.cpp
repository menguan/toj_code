#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iostream>  
#include <fstream>  
#include <map> 
#include <iomanip> 
  
using namespace std;  
  
  
int main()  
{  
    int n, k;  
    map<int, int> winMap;  
    map<int, int> lostMap;  
    int player1, player2;  
    string s1, s2;  
    int t = 0;  
    int i;  
    while (cin >> n) {  
        if (n == 0) break;  
  
        if (t++) cout << endl;  
  
        cin >> k;  
        winMap.clear();  
        lostMap.clear();  
  
        i = k * n * (n - 1) / 2;  
        while (i--) {  
            cin >> player1 >> s1 >> player2 >> s2;  
            if (s1 == "paper" && s2 == "rock") {  
                winMap[player1]++;  
                lostMap[player2]++;  
            } else if (s1 == "rock" && s2 == "paper") {  
                winMap[player2]++;  
                lostMap[player1]++;  
            } else if (s1 == "scissors" && s2 == "paper") {  
                winMap[player1]++;  
                lostMap[player2]++;  
            } else if (s1 == "paper" && s2 == "scissors") {  
                winMap[player2]++;  
                lostMap[player1]++;  
            } else if (s1 == "rock" && s2 == "scissors") {  
                winMap[player1]++;  
                lostMap[player2]++;  
            } else if (s1 == "scissors" && s2 == "rock") {  
                winMap[player2]++;  
                lostMap[player1]++;  
            }  
        }  
  
  
        for (int i = 1; i <= n; i++) {  
            int total = winMap[i] + lostMap[i];  
            if (total == 0) {  
                cout << "-" << endl;  
                continue;  
            }  
            cout << setprecision(3) << fixed << (double)winMap[i] / total << endl;  
        }  
  
    }  
  
    return 0;  
}  
