#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1e9;


pair<double, double> bezier(float alpha, pair<double, double> coord[], int n, int i) {
    for(int k=1; k<n; ++k) {
        for(int j=0; j<n-k; ++j) {
            double a = (1-alpha)*coord[j].first + coord[j+1].first*alpha;
            double b = (1-alpha)*coord[j].second + coord[j+1].second*alpha;
            //((alpha*(coord[j+1].first - coord[j].first)) + coord[j].first)
            //((alpha*(coord[j+1].second - coord[j].second))+ coord[j].second);
            coord[j].first = a;
            coord[j].second = b;
        }
    }// [{z}, {y}, {x}];
    return {coord[0].first, coord[0].second};
}


void reset(pair<double, double> coord[], pair<double, double> setter[], int m) {
    for(int i=0; i<m; ++i) {
        coord[i].first = setter[i].first;
        coord[i].second = setter[i].second;
    }
}

int main() {
    int m, n;
    float alpha=0.0, nx=0;
    cout << setprecision(4);
    cin >> m >> n;
    pair<double, double> coord[m];
    pair<double, double> setter[m];
    for(int i=0; i<m; ++i) {
        float a, b;
        cin >> a >> b;
        coord[i].first = a*1.0;
        coord[i].second = b*1.0;
        setter[i].first = a*1.0;
        setter[i].second = b*1.0;
    }
    for(alpha; alpha<=1.0; alpha += (1/((n*1.0)-1))) {
        pair<double, double> temp =bezier(alpha, coord, m, 0);
        cout << round(temp.first) << " " << round(temp.second) << " ";
        reset(coord, setter, m);
    }
    return 0;
}
