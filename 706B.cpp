#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n;
    vector<int> shops;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        shops.push_back(x);
    }

    sort(shops.begin(), shops.end());
    cin >> q;
    for (int i = 0; i < q; i++){
        int m;
        cin >> m;
        auto u = upper_bound(shops.begin(), shops.end(), m);

        cout << u - shops.begin() << "\n";
    }

    return 0;
}