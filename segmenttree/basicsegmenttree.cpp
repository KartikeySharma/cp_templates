#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mod 1000000007
#define vi vector<int>

const int N= 1e5+5;
int t[4*N]; // t[x] stores sum in node x

// node v connected to 2*v and 2*v+1

// tl,tr -> node range
// id -> updating pt
// val -> new value
void update(int v,int tl,int tr,int id,int val){
	if(tl==id and tr==id){
		t[v]=val;
		return;
	}
	if(id>tr or tl>id){
		//outside range
		return;
	}
	//it is inside
	int tm=(tl+tr)>>1; // break into 2 parts
	update(2*v,tl,tm,id,val);
	update(2*v+1,tm+1,tr,id,val);
	t[v]=t[2*v]+t[2*v+1]; // sum of left and right
}

// l,r is query range
int query(int v,int tl,int tr,int l,int r){
	// no overlap
	if(tl>r or tr<l) return 0;
	// full overlap
	if(l<=tl and tr<=r){
		// l....[tl....tr]....r
		return t[v]; //picking element fully
	}
	// partial overlap
	int tm=(tl+tr)>>1;
	int ans=0;
	ans+=query(2*v,tl,tm,l,r);
	ans+=query(2*v+1,tm+1,tr,l,r);
	return ans;
}

signed main() {
    // v,tl,tr= 1,0,len-1
	update(1,0,N-1,2,5);
	update(1,0,N-1,3,6);
	cout<<query(1,0,N-1,2,3);


    return 0;
}