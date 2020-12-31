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

int kadane(int arr[], int len){
	int current_max = arr[0], max_so_far = arr[0];
	
	for(int i=1; i < len; i++){
		current_max = max(arr[i], current_max+arr[i]);
		max_so_far = max(max_so_far, current_max);
	}
	return max_so_far;
}

void solve(){
	
	int t; cin >> t;
	int arr[t];
	
	for(int i=0; i<t; i++) cin >> arr[i];
	cout << kadane(arr,t) << endl;
	
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
