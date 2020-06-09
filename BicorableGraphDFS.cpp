#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define x first
#define y second
const int INF = 0x3f3f3f3f;

vector< vector<int> > adj;
vector < bool > visited;
vector < bool > color;

// verify bicolorable graph
bool dfs(int v,bool c){
	for(int x : adj[v]){
		if(!visited[x]){
			visited[x] = true;
			color[x] = !color[v];
			if(!dfs(x,c)) return false;
		} else if(color[x] == color[v]) return false;
	}
	return true;
}
// helper function
void solve(){
	int edges,v1,v2;
	cin >> edges;

	visited.resize(edges+1);
	adj.resize(edges+1);
	color.resize(edges+1);


	for(int j=0; j<edges; j++){
		cin >> v1 >> v2;
		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}

	if(dfs(0,0)) cout << "BICOLORABLE." << endl;
	else cout << "NOT BICOLORABLE." << endl;

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int w;
	while(cin >> w, w){
		solve();
		adj.clear();
		color.clear();
		visited.clear();
	}
	return 0;
}
