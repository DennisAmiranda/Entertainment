#include <iostream>
#include <cmath>
using namespace std;

unsigned long MCD(unsigned long a, unsigned long b) {
	unsigned long r = a%b;
	if(r==0) return b;
	return MCD(b,r);
}

unsigned long cifratura(unsigned long k[], unsigned long m) {
	unsigned long s = 1;
	for(unsigned long i=0; i<k[1]; ++i) s = (s*m)%k[0];
	return s;
}
unsigned long decifratura(unsigned long h[], unsigned long c) {
	unsigned long s= 1;
	for(unsigned long i =0; i<h[1]; ++i) s = (s*c)%h[0];
	return s;
}
int main() {
	unsigned long p,q;
	cout << "Inserire p: ";
	cin >> p;
	cout << "Inserire q: ";
	cin >> q;
	unsigned long n=p*q, f=(p-1)*(q-1);
	cout << "n = p*q        : " << n << endl;
	cout << "f = (p-1)*(q-1): " << f << endl;

	unsigned long e = 17;
	if(!MCD(e,f)==1 && e<f) return -1;
	cout << "Esponente pubblico e: " << e << endl;
	unsigned long d = 2753;
	if(!((e*d)%f==1)) return -1;
	cout << "Esponente privato d: " << d << endl;
	unsigned long m;

	unsigned long k[]={n,e}, h[]={n,d};
	cout << "messaggio da cifrare, : m=";
	cin >> m;
	unsigned long c = cifratura(k,m);
	cout << "Cifratura di m: c=" << c << endl;
	m = decifratura(h,c);
	cout << "Decifratura di c: m=" << m << endl;

	return 0;
}
