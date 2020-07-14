#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define pf push_front
#define x first
#define y second
const int INF = 0x3f3f3f3f;

//g++-9 -std=c++17 main.cpp -o main && time ./main < input.txt

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int value): data(value), left(nullptr), right(nullptr){}
};

bool BSTutil(Node* node, int min, int max){
	if(node == nullptr) return 1;
	if(node->data < min || node->data > max) return 0;
	return BSTutil(node->left,min,node->data-1) && BSTutil(node->right,node->data+1,max);
}

bool isBST(Node *node){ return BSTutil(node,-INF,+INF);}

void solve(){
	Node *root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(3);

	if(isBST(root)) cout << "ok" << endl;
	else cout << "nop" << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
