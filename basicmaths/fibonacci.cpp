#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mod 1000000007
#define vi vector<int>

//iterative
int iter_fib(int n){
	int f[n+1];
	f[0]=0;f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]+f[i-2];
	}
	return f[n];
}

// fast doubling method
pair<int,int> fib(int n){
	if(n==0) return {0,1};
	auto p= fib(n/2);
	int c=p.first*(2*p.second-p.first);
	int d=p.first*p.first+p.second*p.second;
	if(n&1){
		return {d,c+d};
	}
	return {c,d};
}

signed main() {
	cout<<iter_fib(10)<<endl;
 	auto n=fib(10);
 	// n.second is F(n+1);
 	cout<<n.first<<" "<<n.second<<endl;

    return 0;
}