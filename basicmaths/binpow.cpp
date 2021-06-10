#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mod 1000000007
#define vi vector<int>

int pow_r(int a,int b){
	if(b==0) return 1;
	int rem=pow_r(a,b/2);
	if(b%2==1){
		return rem*rem*a;
	} 
	return rem*rem;
}

int modpow(int a,int b,int m=mod){
	a%=m;
	int ans=1;
	while(b>0){
		if(b&1) {
			ans=(ans*a)%m;
		}
		a=(a*a)%m;
		b>>=1;
	}
	return ans;
}

signed main() {
    int a=10,b=9;
    cout<<pow_r(a,b)<<endl; 
    cout<<modpow(10,b,mod)<<endl;
    return 0;
}