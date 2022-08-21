#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> pi;

char next(char c){
    if (c == 'R') return 'B';
    else return 'R';
}

void solve(int n){
    queue<pi> cola;

    char c;
    for (int i = 0; i < n; ++i){
        cin >> c;
        if (c == '?') continue;
        cola.push(make_pair(i, c));
    }

    int ind = 0;
    char letra = 'B';
    pi p;
    while (!cola.empty()){
        p = cola.front();
        cola.pop();

        if (p.second == 'R'){
            if ((p.first - ind) % 2 == 0) letra = 'R';
            else letra = 'B';
        } else {
            if ((p.first - ind) % 2 == 0) letra = 'B';
            else letra = 'R';
        }
        while (ind < p.first){
            cout << letra;
            letra = next(letra);
            ++ind;
        }
        cout << p.second;
        letra = next(letra);
        ++ind;
    }
    while (ind < n){
        cout << letra;
        letra = next(letra);
        ++ind;
    }
    cout << "\n";
}


int main(){
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++){
        cin >> n;   
        solve(n);
    }
    return 0;
}


/*
5
7
?R???BR
7
???R???
1
?
1
B
10
?R??RB??B?


BRRBRBR
BRBRBRB
B
B
BRRBRBBRBR

*/