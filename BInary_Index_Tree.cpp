#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define pf push_front
#define x first
#define y second
#define endl "\n"
const int INF = 0x3f3f3f3f;


//g++ -std=c++17 main.cpp -o main && time ./main < input.txt

const int maxn = 1e5+5;

int bit[maxn];

int query(int x){
	
	int soma = 0;
	while(x > 0){
		soma += bit[x];
		int lso = (x & -x);
		x -= lso;
	}
	return soma;
}

void update(int x, int value){
	while(x < maxn){
		bit[x] += value;
		int lso = (x & -x);
		x += lso;
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		int a; cin >> a;
		update(i, a);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
