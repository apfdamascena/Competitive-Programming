#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define pf push_front
#define x first
#define y second
#define endl "\n"
const int INF = 0x3f3f3f3f;


//g++ -std=c++17 main.cpp -o main && time ./main < input.txt

vector<bool> eratostenes(int n){
	vector<bool> primos(n+1, true);
	primos[0] = primos[1] = false;
	
	for(int i=2; i<=n; i++){
		if(primos[i] && (ll)i*i<=n){
			for(int j=i*i; j<=n; j+=i){
				primos[j] = false;
			}
		}
	}
	return primos;
}

vector<bool> eratostenes(int n){
	vector<bool> primos(n+1, true);
	primos[0] = primos[1] = false;
	
	for(int i=2; i*i <= n; i++){
		if(primos[i]){
			for(int j=2; i*j <= n; j++){
				primos[i*j] = false;
			}
		}
	}
	return primos
}

void solve(){
	
	int t;cin >> t;
	vector<bool> p = eratostenes(17);
	for(bool k : p) cout << k << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
