#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] < 97) {
            s[i] += 32;
        }
    }
    string x = "kangaroo";
    string y = "kiwibird";
    int kan = 0, kiw = 0;
    for(int i = 0; i < s.size(); i ++) {
        for(int j = 0; j < x.size(); j ++) {
            if(s[i] == x[j]) kan ++;
        }
        for(int j = 0; j < y.size(); j ++) {
            if(s[i] == y[j]) kiw ++;
        }
    }
    if(kan > kiw) {
        cout << "Kangaroos";
    }
    if(kan == kiw) {
        cout << "Feud continues";
    }
    if(kan < kiw) {
        cout << "Kiwis";
    }
}