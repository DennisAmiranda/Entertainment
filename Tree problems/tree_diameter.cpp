#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
#define n 10
vector<int> adj[n];
queue<int> q;

int lbfs(int root) {
	q.push(root);
	int a=0, mx=-INF, h=1;
	while(!q.empty()) {
		int s = q.front(); q.pop();
		for(auto u : adj[s]) {
			++a;
			q.push(u);
		}
		if(h>=1) --h;
		if(h==0) {mx=max(mx,a); h=a; a=0;}
	}
	return mx;
}

// initializing the tree with adjacency lists 
int main() {
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[1].push_back(4);
	adj[2].push_back(6);
	adj[3].push_back(5);
	adj[3].push_back(7);
	adj[4].push_back(9);
	adj[6].push_back(8);
	cout << "The lbfs of this tree is: " << lbfs(1);
	return 0;
}
