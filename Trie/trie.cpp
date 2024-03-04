#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define ff first
#define ss second

const int MAXLEN = 1e6+10;
const int alphabet = 26;
int trie_table[MAXLEN][alphabet];
int total_nodes = 1; /// root node created
int cnt[MAXLEN]; /// count the occurrence

void add(string &s){

    int cur_node = 1; /// root node
    cnt[cur_node]++;

    for(int i=0; i<s.size(); i++){
        int ch = s[i]-'a'; /// current letter
        if(trie_table[cur_node][ch]==0){ /// if there is no edge for the character from current node
            total_nodes++;
            trie_table[cur_node][ch] = total_nodes;
            /// trie_table[cur_node][ch] = ++total_nodes; works same as above two lines
        }
        cur_node = trie_table[cur_node][ch];
        cnt[cur_node]++;
    }

}

int query(string &s){ /// find how many times S occurs as a prefix

    int cur_node = 1;
    for(int i=0; i<s.size(); i++){
        int ch = s[i]-'a';
        if(trie_table[cur_node][ch]==0) return 0; /// no edge, means S doesn't exist as a prefix
        cur_node = trie_table[cur_node][ch];
    }
    return cnt[cur_node];
}


void solve(int cs){

    int n, q; /// n = total strings, q = queries
    cin >> n >> q;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        add(s);
    }

    while(q--){
        string s;
        cin >> s;
        int ans = query(s);
        cout << ans << "\n";
    }
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	int test = 1;
	//cin >> test;

	for(int cs=1; cs<=test; cs++)
		solve(cs);

	return 0;
}
