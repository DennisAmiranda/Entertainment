#include <bits/stdc++.h>
#define ll long long
#define NUM 10
using namespace std;

int hash_function(int data) {
    return data%NUM;
}
int inizializza(vector<int> tab[]) {
    for(int i=0; i<NUM; ++i) {
        tab[i].resize(0);
    }
}
void visualizza(vector<int> tab[]) {
    for(int x=0; x<10; ++x) {
        cout<<endl<<"Bucket "<<x<<":";
        for(int y=0; y<tab[x].size(); ++y) {
            cout<<" -> ["<<tab[x][y]<<"]";
        }
    }
}
int cerca(vector<int> lista, int nuovo) {
    int bucket = hash_function(nuovo);
    for(int x=0; x<lista.size(); ++x) {
        if(nuovo==lista[x])
            return 1;
    }
    return 0;
}
void add_elemento(vector<int> tab[], int nuovo) {
    int bucket;
    bucket = hash_function(nuovo);
    if(cerca(tab[bucket], nuovo) == 1)
        return;
    else
        tab[bucket].push_back(nuovo);
}
int main() {
    srand(time(NULL));
    vector<int> tab[NUM];
    inizializza(tab);
    for(int n=0; n<20; ++n)
        add_elemento(tab, rand()%100);
    visualizza(tab);
    return 0;
}
