//Author:@syedrajo20
//

#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

const int N = 1e5+2;
int a[N], tree[4*N];

void build(int node, int st, int en){

	if(st == en){
		tree[node] = a[st]; //leaf node
		return;
	}

	int mid = (st+en)/2; //update mid
	build(2*node, st, mid); // build left tree
	build(2*node + 1, mid + 1, en); //build right tree

	// that's where we modify based on problem
	tree[node] = tree[2*node] + tree[2*node + 1]; // leftChild +rightChild

}


int query(){

}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	int n;
	cin >> n;
	for(int i = 0; i< n; i++){
		cin >> a[i];
	}

	build(1, 0, n-1);
	for(int i = 1; i<= 15; i++){
		cout << tree[i] << " ";
	}
	cout << nl;
	return 0;

}
