#include <bits/stdc++.h>                  
#define endl "\n"
#define ll long long
using namespace std;

void bsearch(int a[], int l, int r, int x) {
	int mid = l+(r-l)/2;
	if(a[mid] == x) {
		cout << mid;
		return;
	}
	if(a[mid] > x) r = mid-1;
	else l = mid+1;
	return bsearch(a, l, r, x);
}
int main() {
	const int n = 10;
	int a[n] = {1,4,9,16,25,36,49,64,81,100};
	int l = 0, r = n-1;
	int x; cin >> x;
	bsearch(a, l, r, x);
	return 0;
}
