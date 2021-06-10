#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mod 1000000007
#define vi vector<int>

/*
int gcd(int a,int b){
	if(!b) return a;
	else return gcd(b,a%b);
}
*/

int gcd(int a,int b){
	while(b){
		a%=b;
		swap(a,b);
	}
	return a;
}

signed main() {
    cout<<gcd(3,5)<<endl;

    return 0;
}