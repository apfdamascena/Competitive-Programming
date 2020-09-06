#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define pf push_front
#define x first
#define y second
const int INF = 0x3f3f3f3f;

//g++-9 -std=c++17 main.cpp -o main && time ./main < input.txt

int parent[110];
int size[110];

void make_set(int v){
	parent[v] = v;
	size[v] = 1;
}

int find_set(int v){
	if(v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a != b) {
		if(size[a] < size[b]) swap(a,b);
		parent[b] = a;
		size[a] += size[b];
	}
}

void solve(){}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
