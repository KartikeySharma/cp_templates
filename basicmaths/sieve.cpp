#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mod 1000000007
#define vi vector<int>

/*
#define MAXN 100005
vector<int>prime;
bool is_composite[MAXN];
void sieve(int n=MAXN){
	mem(is_composite,false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) 
			prime.push_back (i);
		for (unsigned int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) 
				break;
		}
	}
}
*/

const int n=1e5;
vector<bool> is_prime(n+1,true);
vector<int> prime;
void sieve(){
	prime.pb(0);prime.pb(1);
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i*i<=n;i++){
		if(is_prime[i]){
			prime.pb(i);
			for(int j=i*i;j<=n;j+=i) is_prime[j]=false;
		}
	}
}

signed main() {
    sieve();
 	for(int i=0;i<15;i++) cout<<prime[i]<<" ";  	

    return 0;
}