#include<iostream>
#include<map>
using namespace std;
 //sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss

int main() {
    string a;
    int ma[26];
    for (int i = 1; i <= 26; i++) {
        ma[i - 1] = i;
    }
    while (getline(cin, a)) {
        map<char, int> res;
        map<char, int> cur;
        int l = a.length();
        int sum = 0;
        for (int i = 0; i < l; i++) {
            int j, k;
            if (a[i] >= 'a' && a[i] <= 'z') {
                j = i - 1;
                k = i + 1;
                res[a[i]] = ma[a[i] - 'a'];
                cur[a[i]] = ma[a[i] - 'a'];
                while (a[j] == ' ' && j > 0)j--;
                while (a[k] == ' ' && k < l)k++;
                if (j - 1 >= 0 && a[j - 1] == a[j]) {
                    if (a[j] == '+') {
                        cur[a[i]]++;
                        res[a[i]]++;
                    } else {
                        cur[a[i]]--;
                        res[a[i]]--;
                    }
                    j -= 2;
                } else if (k + 1 < l && a[k + 1] == a[k]) {
                    if (a[k] == '+') {
                        res[a[i]]++;
                    } else {
                        res[a[i]]--;
                    }
                }
                while (a[j] == ' ' && j > 0)j--;
                if (j <= 0)sum += cur[a[i]];
                else if (a[j] == '+')sum += cur[a[i]];
                else sum -= cur[a[i]];
            }
        }
        cout << "Expression: " << a << endl;
        cout << "    value = " << sum << endl;
        map<char, int>::iterator it = res.begin();
        for (it; it != res.end(); it++) {
            cout << "    " << it->first << " = " << it->second << endl;
        }
    }
    return 0;
}
