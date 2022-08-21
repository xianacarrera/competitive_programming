#include <bits/stdc++.h>
using namespace std;

#define ll long long


void solve(ll a, ll b, ll c, ll d){
    ll ad = a * d;
    ll bc = b * c;

    ll menor, mayor;

    if (ad == bc){
        cout << "0\n";
        return;
    }
    if (ad < bc) menor = ad, mayor = bc;
    else menor = bc, mayor = ad;

    if (menor == 0){
        cout << "1\n";
        return;
    }

    if (mayor % menor == 0){
        cout << "1\n";
        return;
    }
    cout << "2\n";
}


int main(){
    int t;
    cin >> t;

    ll a, b, c, d;

    for (int i = 0; i < t; ++i){
        cin >> a >> b >> c >> d;
        solve(a, b, c, d);
    }
    return 0;
}
