#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string w;
        cin >> w;
        bool reflag = 0;
        int l = w.length();
        if (w.find("anti") == 0) {
            w = w.substr(4, l - 4);
            cout << "against ";
        } else if (w.find("post") == 0) {
            w = w.substr(4, l - 4);
            cout << "after ";
        } else if (w.find("pre") == 0) {
            w = w.substr(3, l - 3);
            cout << "before ";
        } else if (w.find("re") == 0) {
            w = w.substr(2, l - 2);
            reflag = 1;
        } else if (w.find("un") == 0) {
            w = w.substr(2, l - 2);
            cout << "not ";
        }
        l = w.length();
        if (l - 2 > 0 && w.rfind("er") == l - 2) {
            w = w.substr(0, l - 2);
            w.insert(0, "one who ");
            w += "s";
        } else if (l - 3 > 0 && w.rfind("ing") == l - 3) {
            w = w.substr(0, l - 3);
            w.insert(0, "to actively ");
        } else if (l - 3 > 0 && w.rfind("ize") == l - 3) {
            w = w.substr(0, l - 3);
            w.insert(0, "change into ");
        } else if (l - 1 > 0 && w.rfind("s") == l - 1) {
            w = w.substr(0, l - 1);
            w.insert(0, "multiple instances of ");
        } else if (l - 4 > 0 && w.rfind("tion") == l - 4) {
            w = w.substr(0, l - 4);
            w.insert(0, "the process of ");
            w += "ing";
        }
        cout << w;
        if (reflag)cout << " again";
        cout << endl;
    }
    return 0;
}
