#include <bits/stdc++.h>
using namespace std;


void solve(int n){
    vector<int> encontrado(n+ 1, -1);
    int comienzo = 0;
    int temp;

    for (int i = 0; i < n; i++){
        cin >> temp;
        if (encontrado[temp] >= 0){
            comienzo = max(comienzo, encontrado[temp] + 1);
        }
        encontrado[temp] = i;
    }

    cout << comienzo << "\n";
}

int main(){
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++){
        cin >> n;    // length of sequence
        solve(n);
    }
}