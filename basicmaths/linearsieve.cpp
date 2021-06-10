#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mod 1000000007
#define vi vector<int>

// useful till 1e7..else aux memory becomes quite high
const int n= 1e5;
vi prime;
int low_factor[n+1]; // lowest prime factor of a number

void sieve(){
	for(int i=2;i<=n;i++){
		if(low_factor[i]==0){
			low_factor[i]=i;
			prime.pb(i);
		}
		for(int j=0;j<(int)prime.size() and prime[j]<=low_factor[i]
				and i*prime[j]<=n; j++)
			low_factor[i*prime[j]]=prime[j];
	}
}

signed main() {
    sieve();
    for(int i=0;i<10;i++) cout<<prime[i]<<" ";
    cout<<endl;
	for(int i=0;i<10;i++) cout<<low_factor[i]<<" ";

    return 0;
}