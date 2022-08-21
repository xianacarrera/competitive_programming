#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int solve(int n){
    int current;
    int when5or0 = -1;
    int when6 = -1;    // stores the parity of the ten when remainder 6 will be encountered performing the operation
    // For example, if current is 18, then the next remainder 6 will be at 18 + 6 = 26.
    // The ten of 26 is 26 / 10 = 2, which is odd -> when6 = 0
    // If the first remainder 6 is at 36, for example, when6 will be (36 / 10) % 2 = 3 % 2 = 1

    int i;
    for (i = 0; i < n; i++){
        cin >> current;

        int remainder = current % 10;
        int quotient = current / 10;

        if (i == 0){
            if (remainder == 5){
                when5or0 = quotient + 1;
                continue;
            } else if (remainder == 0){
                when5or0 = quotient;
                continue;
            }
        } else if (when5or0 != -1 && remainder != 5 && remainder != 0){
            cout << "No\n";
            return i;
        } else if (when5or0 == -1 && (remainder == 5 || remainder == 0)){
            cout << "No\n";
            return i;
        }



        int when6current;
        int when5or0current;
        switch(remainder){
            case 0:
                when5or0current = quotient;
                if (when5or0 != when5or0current) {
                    cout << "No\n";
                    return i;
                }
                continue;
            case 5:
                when5or0current = quotient + 1;
                if (when5or0 != when5or0current) {
                    cout << "No\n";
                    return i;
                }
                continue;
            case 1:
            case 2:
            case 4:
            case 8:
                when6current = (quotient + 1) % 2;
                break;
            default:
                // 3, 6 -> when6current = quotient % 2;
                // 7, 9 -> when6current = (quotient + 2) % 2;      (same as quotient % 2)
                when6current = quotient % 2;
                break;
        }
        if (when6 == -1) when6 = when6current;
        else if (when6 != when6current) {
            cout << "No\n";
            return i;
        }
    }    

    cout << "Yes\n";
    return i;
}

int main(){
    int t, n;
    cin >> t;

    for (int i = 0; i < t; ++i){
        cin >> n;
        int last = solve(n);
        int dummy;
        for (int j = last + 1; j < n; j++) cin >> dummy;
    }

    return 0;
}