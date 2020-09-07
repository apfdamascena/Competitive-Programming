#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define pf push_front
#define x first
#define y second
const int INF = 0x3f3f3f3f;

//g++-9 -std=c++17 main.cpp -o main && time ./main < input.txt

int parent[100010], sizes[100010];

void makeSet(int w){
	for(int i=1; i<=w; i++){
		parent[i]=i;
		sizes[i] = 1;
	}	
}

int findSet(int i){
	if(parent[i] == i) return i;
	return parent[i] = findSet(parent[i]);
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

void unionSet(int a, int b){
	a = findSet(a);
	b = findSet(b);
	if(a != b){
		if(sizes[a] < sizes[b]) swap(a,b);
		parent[b] = a;
		sizes[a] += sizes[b];
	}
}

void solve(){
	makeSet(5);
	unionSet(2,3);
	unionSet(3,4);
	cout << isSameSet(2,3) << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
