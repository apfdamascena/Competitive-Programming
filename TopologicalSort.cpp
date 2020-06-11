#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define x first
#define y second
const int INF = 0x3f3f3f3f;
//g++-9 -std=c++17 main.cpp -o main && time ./main < input.txt

vector<int> dependencias;
vector < vector<int> > adj;
queue<int> q;
vector<int> ordem;
int na,nv;
set<int> s;

void toposort(){
	for(int i=1; i<=nv; i++) if(dependencias[i] == 0 && s.find(i) != s.end()) q.push(i);
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		ordem.pb(curr);
		for(int k : adj[curr]){
			dependencias[k]--;
			if(dependencias[k] == 0) q.push(k);
		}
	}
	reverse(ordem.begin(), ordem.end());
	for( int ord : ordem){
		cout << ord << " ";
	}
}
void solve(){
	cin >> nv >> na;
	adj.resize(nv+1);
	dependencias.resize(nv+1,0);
	int a,b;
	while(na--){
		cin >> a >> b; // a depende de b;
		adj[b].pb(a);
		s.insert(a); s.insert(b);
		dependencias[a]++;
	}
	toposort();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
