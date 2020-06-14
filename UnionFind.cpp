#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define x first
#define y second
const int INF = 0x3f3f3f3f;
//g++-9 -std=c++17 main.cpp -o main && time ./main < input.txt
#define maxn 100100

int pai[maxn];

void init(){
	for(int i=1; i<= maxn; i++){
		pai[i] = i;
	}
}

int find(int x){
	if(pai[x] == x) return x;
	return pai[x]=find(pai[x]);
}

void join(int x,int y){
	pai[find(x)] = find(y);
}

void solve{}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	// solve();
	// int t;cin >> t;
	// for(int i=0; i<t; i++) solve();
	return 0;
}
