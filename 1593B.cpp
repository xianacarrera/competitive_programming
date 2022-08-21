#include <bits/stdc++.h>
using namespace std;

// 00, 25, 50, 75

int solve(string n){
    bool cinco = false;
    bool cero = false;
    int ans00 = 0, ans2575 = 0, ans50 = 0;

    for (int j = n.length() - 1; j >= 0; --j){
        if (n[j] == '0'){
            if (!cero){
                cero = true;
                ++ans2575;
            } else return ans00;   // FOUND 00
        } else if (n[j] == '5'){
            if (cero) return ans50;
            if (!cinco) cinco = true;
            else {
                ++ans2575;
            }
            ++ans00;
            ++ans50;
        } else if (cinco && (n[j] == '2' || n[j] == '7')){
            return ans2575;
        } else {
            ++ans00;
            ++ans2575;
            ++ans50;
        }
    }
    return 0;
}


int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i){
        string n;
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}