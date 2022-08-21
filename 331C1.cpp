#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
#include<time.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
#define x first
#define y second
#define mk make_pair
typedef pair<ll, ll>pr;

map<pr, pr>dp;//map<pr<the maximum number that can be subtracted, current value>, pr<minimum operand, remainder> >dp

pr dfs(pr a) {
	if (a.y <10) //Returns the smallest operand and the high-order value ay (may be negative) within 10
		return mk(a.x || a.y, a.y-max(a.x, a.y));

	if (dp.find(a) != dp.end())//If memoized data is found, read it directly
		return dp[a];

	ll p = 1;
	while (p <= a.y/10)//Get the minimum value in the same position as ay (because ay<10 and return first, so it will not be affected)
		p *= 10;

	//The number of splits will be calculated below
	pr b = dfs(mk(max(a.x, a.y/p), a.y%p));//low calculation
	ll ans = b.x;//Add the lower operand
	b = dfs(mk(a.x, ay/p*p + b.y));//High-level calculation
	return dp[a] = mk(bx + ans, b.y);
}

int main() {
	ll n;
	scanf("%lld", &n);
	printf("%lld\n", dfs(mk(0, n)).x);
	return 0;
}