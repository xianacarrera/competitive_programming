#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(int n){
    vector<ll> a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];

    sort(a.begin(), a.end());

    ll mayor = a[3], menor = a[0], mayor2 = a[2], menor2 = a[1];


    ll actual;
    for (int i = 4; i < n; ++i){
        cin >> actual;

        if (actual >= mayor){
            mayor2 = mayor;
            mayor = actual;
        } else if (actual >= mayor2){
            mayor2 = actual;
        }

        if (actual <= menor){
            menor2 = menor;
            menor = actual;
        } else if (actual <= menor2){
            menor2 = actual;
        }
    }

    ll ans = mayor + mayor2 - menor - menor2;
    cout << ans << "\n";
}


int main(){
    int t, n;
    cin >> t;

    for (int i = 0; i < t; ++i){
        cin >> n;
        solve(n);
    }

    return 0;
}