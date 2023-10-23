#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

bool SortAscending(const pair<int, pair<int,int>>& p1, const pair<int, pair<int,int>>& p2)
{
   return tie(p1.second.second, p2.second.first, p2.first) > tie(p2.second.second, p1.second.first, p1.first);
}


int main(int argc, char* argv[]) {
	int m, n, s;
	cin >> m >> n >> s;
	pair<int, pair<int, int>> score[m];
	bool solved[m][n];
	for(int i=0; i<m; ++i) {score[i].second.first = INF; score[i].second.second=0; score[i].first=i;}
	map<int, pair<string, int>> tsk;
	int a, c, k;
	string b;
	for(int i=0; i<n; ++i) {
		cin >> a;
		cin >> b;
		cin >> c;
		tsk.insert(make_pair(a, make_pair(b,c)));
	}
	for(int i=0; i<s; ++i) {
		cin >> a;
		cin >> c;
		cin >> b;
		cin >> k;
		if(tsk.find(c)->second.first == b && !solved[a-1][c]) {
			score[a-1].second.second+=tsk.find(c)->second.second;
			score[a-1].first=a-1;
			score[a-1].second.first=min(score[a-1].second.first, k);
			solved[a-1][c]=true;
		}else if(tsk.find(c)->second.first == b) {
			score[a-1].second.first=min(score[a-1].second.first, k);
		}
	}
	sort(score, score+m, SortAscending);
	for(int i=0; i<m; i++) {
		if(score[i].second.first == INF) {
			score[i].second.first = 0;
		}
		cout << score[i].first+1 << " " << score[i].second.second << endl;
	}
	return 0;
}
