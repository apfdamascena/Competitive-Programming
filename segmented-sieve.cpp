#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
#define pb push_back
#define pf push_front
#define x first
#define y second
#define endl "\n"
#define all(a) (a).begin(),(a).end()
#define show(a) for(auto p : a) cout << p << " ";
#define rep(a,b,c) for(int i=a; i<b; i+= c)
#define present(c, x) ((c).find(x) != (c).end())
const int INF = 0x3f3f3f3f;
//g++ -std=c++17 main.cpp -o main && time ./main < input.txt



#define MAX 1e9
vector<bool> primes(sqrt(MAX)+1,true);

void eratostenes(){
	primes[0] = primes[1] = false;
	
	for(int i=2; i*i <= sqrt(MAX)+1; i++){
		if(primes[i]){
			for(int j=2; i*j <= sqrt(MAX)+1; j++){
				primes[i*j] = false;
			}
		}
	}
}

            
void solve(){
	int t; cin >> t;
	eratostenes();
	
	while(t--){
		int n,m; cin >> n >> m;
		
		int segmented[m-n+1];
		memset(segmented,0, sizeof segmented);
		
		
		for(int i = 2; i <= sqrt(m)+1; i++){
			if(primes[i]){
				
				for(ll j = max(i*i, (n+i-1)/(i*i)); j <= m; j += i){
					segmented[j-n] = 1;
				}
			}
		}
		
		if(n == 1) segmented[0] = 1;
		
		for(int i=0; i < m-n+1; i++){
			if(segmented[i] == 0) cout << i+n << endl;
		}
		
		if(t) cout << endl;
		
		
	}	
}


 
int main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}
