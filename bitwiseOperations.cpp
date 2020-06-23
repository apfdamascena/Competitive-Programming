#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define pf push_front
#define x first
#define y second
const int INF = 0x3f3f3f3f;

//g++-9 -std=c++17 main.cpp -o main && time ./main < input.txt

void solve(){
  int n=31;
  //shift operation to multiply/divide an integer by 2.
  n = (n << 1); // n = 62
  n = (n >> 1); // n = 31
  
  //we must use OR operation to set/turn on the j-th item of the set.
  n = 34;        //(100010) -> binary representation
  int j = 3;     //(001000)we want to modify the 3-th to 1.
  n |= (1 << j); //(101010)
  
  //AND operation to check if the j-th item is set on.
  n = 42;        //(101010)
  j = 3; //1<<j -> (001000)
  int t = n & (1 << j);
  // t == 0 if j-th item isn't set on
  // t != 0 if j-th item is set on
  
  // AND operation to clean the j-th element.
  n = 42;         //(101010)
  j=1; // !(1 << j) (111101)
  n &= !(1<< j);  //(101000)
  
  // XOR operation to toggle the j-th item of the set
  n = 40;         //(101000)
  j=2 // (1 << j) ->(000100)
  n ^= (1 << j);  //(101100)
  
  // AND operation to get the last significant digit/
  n = 40;
  t = (n & (!n));
  //in this case, the last significant digit is on 3-th position.
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
