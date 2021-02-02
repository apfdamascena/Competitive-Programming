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


const int N = 1e5+5;
int tree[4*N];
int v[N];

void build(int p, int l, int r){
	if( l == r ){
		tree[p] = v[r];
	} else {
		int m = (l+r)/2, lc = 2*p, rc = lc+1;
		build(lc, l, m);
		build(rc, m+1, r);
		tree[p] = min(tree[lc], tree[rc]);
	}
}

void update(int p, int l, int r, int i, int x){
	if(l == r){
		tree[p] = x;
 	} else {
		int m = (l+r)/2, lc = 2*p, rc = lc+1;
		if(i <= m){
			update(lc, l, m, i, x);
		} else {
			update(rc, m+1, r, i, x);
		}
		tree[p] = min(tree[lc], tree[rc]);
	}
}

int query(int p, int l, int r, int ql, int qr){
	if( ql <= l && r <= qr){
		return tree[p];
	} else {
		int m = (l+r)/2, lc = 2*p, rc = lc+1;
		if(qr <= m){
			return query(lc, l, m, ql, qr);
		} else if (ql > m){
			return query(rc, m+1, r, ql, qr);
		} else {
			return min(query(lc, l, m, ql, qr), query(rc, m+1, r, ql, qr));
		}
	}
	
}

int query2(int p, int l, int r, int ql, int qr){
	if( ql <= l && r <= qr){
		return tree[p];
	} else if(qr < l || r < ql){
		return INF;
	} else {
		int m = (l+r)/2, lc= 2*p, rc = lc+1;
		return min(query2(lc, l, m, ql, qr), query2(rc, m+1, r, ql, qr));
	}
}

void solve(){
	int n; cin >> n;	
	for(int i=1; i<=n; i++) cin >> v[i];
	
	//1-based
	build(1,1,n);
	
	
	for(int i=1; i<= 4*n; i++) cout << tree[i] <<  " ";

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}

