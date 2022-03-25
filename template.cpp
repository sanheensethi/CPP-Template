#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define endl "\n"
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" : "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*######################################################################################################################################*/

bool subsetSum(int* arr,int sum,int n){
	if(n==0 && sum != 0) return false;
	if(sum == 0) return true;
	// if current element is big then sum dont pick
	if(arr[n-1] > sum){
		return subsetSum(arr,sum,n-1);
	}else{
		// pick the element
		bool val1 = subsetSum(arr,sum-arr[n-1],n-1);
		if(val1) return true;
		bool val2 = subsetSum(arr,sum,n-1);
		if(val2) return true;
		return false;
	}
}


bool subsetSumMem(int* arr,int sum,int n,int* mem){
	if(n == 0 && sum != 0) return false;
	if(sum == 0) return true;
	// if currect element is big then sum dont pick
	if(arr[n-1] > sum){
		return subsetSumMem(arr,sum,n,mem);
	}else{}
}

void solve(){
	int n;cin>>n;
	int sum;cin>>sum;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	if(subsetSum(arr,sum,n)){
		cout<<"True";
	}else{
		cout<<"False";
	}

	return;
}

/*######################################################################################################################################*/


signed main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	
	fastio();
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}