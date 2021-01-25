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

//subsets

vector<int> subset;
int n = 3;

void find_subsets(int k){
	if(k == n+1){
		cout << "(";
		for(auto i = subset.begin(); i!= subset.end(); i++) cout << *i;
		cout << ")";
	} else {
		find_subsets(k+1);
		subset.pb(k);
		find_subsets(k+1);
		subset.pop_back();
	}
}

void solve(){
	find_subsets(1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
