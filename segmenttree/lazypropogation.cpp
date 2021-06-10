#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mod 1000000007
#define vi vector<int>

const int N= 1e5+5;

int t[4*N]; 
// base array storing the sum/operation you are performing
bool lazy[4*N];
// lazy tags (true if the man at node has some unpropogated value)
int upd[4*N];
// memory of the man

// process of telling the man to remember val
// eg) add 7 to leaves of node...then we apply(7)
// tl,tr-> node range and v is node number
void apply(int v,int tl,int tr,int val){
	int leaves= (tr-tl+1);
	t[v]+=val*leaves; // set correct info at node
	if(tl!=tr){
		//not a leaf, mark it lazy
		lazy[v]=1;
		upd[v]+=val;
	}
}

// assigning the task to his sub-employees
// only if it is lazy, then pushdown
void pushdown(int v,int tl,int tr){
	if(lazy[v]){
		lazy[v]=0; //not lazy now
		//he was remembering upd[v];
		int tm=(tl+tr)/2;
		// assigned to chilrdren
		apply(2*v,tl,tm,upd[v]);
		apply(2*v+1,tm+1,tr,upd[v]);
		
		// update is now done and it dosent need to remember
		upd[v]=0;
	}
}

// l,r-> update range
// add val to all leaves in the range l,r
void update(int v,int tl,int tr,int l,int r,int val){
	if(tl>r or tr<l){ // no overlap
		return;
	}
	if(l<=tl and tr<=r){ //fully within
		// assign the val to the man
		// ask him to remember the value
		apply(v,tl,tr,val);
		return;
	}
	// partial overlap
	pushdown(v,tl,tr); // remove lazy tag before going down
	// why?
	// so that the children have
	// correct info
	int tm=(tl+tr)>>1;
	update(2*v,tl,tm,l,r,val);
	update(2*v,tm+1,tr,l,r,val);
	t[v]= t[2*v]+t[2*v+1]; // store correct value at this node
}

// pretty much unchanged from basicsegment tree,
// except from the pushdown
int query(int v,int tl,int tr,int l,int r){
	if(tl>r or tr<l) return 0;
	if(l<=tl and r>=tr){
		return t[v];
	}

	pushdown(v,tl,tr);
	// why remove lazy tag?
	// so children have correct info
	int tm=(tl+tr)>>1;
	int ans=0;
	ans+= query(2*v,tl,tm,l,r);
	ans+= query(2*v+1,tm+1,tr,l,r);
	return ans;
}


// v,tl,tr -> 1,0,len-1
signed main() {
	update(1,0,N-1,2,5,3); // add 3 to [2,5];
	cout<< query(1,0,N-1,1,3);	// print sum in range [1,3]
    
    return 0;
}