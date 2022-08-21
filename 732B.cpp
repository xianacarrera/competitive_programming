#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k;           // 1 <= n, k <= 500
    cin >> n >> k;

    vector<int> a(n);       // a will store both input and output

    int twalks = 0;            // total number of additional walks (the answer)
    int pending = 0;         

    // We will go through the input examining each element and its previous one in turn
    // That way, we will study all consecutive pairs

    cin >> a[0];            // n >= 1
    for (int i = 1; i < n; ++i){
        cin >> a[i];
        pending = max(0, k - a[i - 1] - a[i]);     // If there are sufficient walks, pending will be 0
        twalks += pending;
        a[i] += pending;    // Put the pending walks in the second element to "help" the next pair
    }

    cout << twalks << "\n";
    for (int j = 0; j < n; ++j)
        cout << a[j] << " ";
    return 0;
}