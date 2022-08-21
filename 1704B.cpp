#include <bits/stdc++.h>
using namespace std;

// | v - a_i | <= x     <=>      a_i - x <= v <= x + a_i


void solve(int n, int x){
    int lower = -2100000000, upper = 2100000000;
    int a;
    int changes = 0;

    for (int i = 0; i < n; ++i){
        cin >> a;

        // Obtain lower and upper limit for v
        int nlower = a - x;
        int nupper = a + x;

        if (lower <= nupper && nlower <= upper){
            lower = max(nlower, lower);
            upper = min(nupper, upper);
        } else {
            ++changes;
            lower = nlower;
            upper = nupper;
        }
    }
    cout << changes << "\n";
}


int main(){
    int t;
    int x, n;
    cin >> t;

    for (int i = 0; i < t; ++i){
        cin >> n >> x;
        solve(n, x);
    }
    return 0;
}