#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, m, k;
    cin >> t;

    for (int i = 0; i < t; ++i){
        cin >> n >> m >> k;
        int burkles = (m - 1) + (n - 1) * m;
        if (burkles == k) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/*
6
1 1 0
2 2 2
2 2 3
2 2 4
1 4 3
100 100 10000

YES
NO
YES
NO
YES
NO
*/