#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define pf push_front
#define x first
#define y second
const int INF = 0x3f3f3f3f;
//g++-9 -std=c++17 main.cpp -o main && time ./main < input.txt

ll  binpow_recursive(ll a, ll b){
	if(b==0) return 1;
	ll res = binpow_recursive(a, b/2);
	if(b&1) return res * res
	else res*res*a;
}

ll binpow(ll a, ll b) {
	ll res = 1;
	while( b > 0){
		if(b&1) res = res*a;
		a = a*a;
		b >>= 1;
	}
	return res;
}
// Effective calculation of large exponents module any number
ll bigbinpow(ll a, ll b, ll m){
	a %= m;
	ll res = 1;
	while( b > 0){
		if(b&1) res = res*a%m;
		a = a * a % m;
		b >>= 1;
	}
}

//If m is a prime number, we can speed up this algorithm a little by calculating xˆ (n mod (m - 1)) instead of xˆn.
//This comes directly from Fermat's little theorem 

void solve(){}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
