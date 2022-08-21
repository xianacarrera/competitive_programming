#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++){
        cin >> n;
        
        if (n == 0){
            cout << "0\n";
            continue;
        } 
        if (n == 1 || n == -1){
            cout << "2\n";
            continue;
        }

        int ans = ceil(n / 3.0);
        cout << ans << "\n";
    }
    return 0;
}