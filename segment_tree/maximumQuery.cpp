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
		tree[node] = a[st];
		return;
	}

	int mid = (st + en)/2;
	build(2*node, st, mid);
	build(2*node + 1, mid + 1, en);

	tree[node] = max(tree[2*node], tree[2*node+1]);
}


int query(int node, int st, int en, int l, int r){
	// out of range or no overlap
	if(st> r || en < l){
		return INT_MIN;
	}
	// overlap
	if(l<=st && en<=r)
		return tree[node];

	int mid = (st + en)/ 2;
	int q1 = query(2*node, st, mid, l, r);
	int q2 = query(2*node + 1, mid+1, en, l, r);

	return max(q1, q2);
}

void update(int node, int st, int en, int idx, int val){
	if(st == en){
		a[st] = val;
		tree[node] = val;
		return;
	}

	int mid = (st + en)/2;
	if(idx <= mid){
		update(2*node, st, mid, idx, val);
	}else{
		update(2*node+1, st, mid, idx, val);
	}

	tree[node] = max(tree[2*node], tree[2*node + 1]);


}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	int n; cin>> n;
	for (int i = 0; i< n; i++){
		cin >> a[i];
	}
	build(1, 0, n-1);

	int q; cin >> q;
	while(q--){
		int type; cin >> type;
		int l, r, idx, val;
		if(type == 1){
			cin >> l >> r;
			cout << query(1, 0, n-1, l, r) << nl;
		}
		if(type == 2){
			cin >> idx >> val;
			update(1, 0, n-1, idx, val);
		}
	}
	return 0;
}
