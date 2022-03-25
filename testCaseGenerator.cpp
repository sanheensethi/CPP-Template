// Stress Testing

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define endl "\n"
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define test ll T; cin>>T; while(T--) solve();
#define test1 ll T=1; while(T--) solve();
#define loop(i,s,n) for(ll i=s;i<n;i++)
#define rloop(i,s,n) for(ll i=s;i>=n;i--)
#define fill(a,value) memset(a,value,sizeof(a))

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

string stringGenerator(int length,bool capital = false,bool mix = false){
  string str;
  int mod = 26;
  if(capital && !mix){
    str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  }else if(!capital && !mix){
    str = "abcdefghijklmnopqrstuvwxyz";
  }else if(!capital && mix){
    str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    mod = 52;
  }

  string ans = "";
  for(int i=0;i<length;i++){
    int index = rand()%mod;
    ans += str[index];
  }
  return ans;
}


/*######################################################################################################################################*/

int brute(int n,string s){
  
}

int opti(int n,string s){
  return 0;
}

/*######################################################################################################################################*/


signed main(){
	#ifndef ONLINE_JUDGE
		freopen("Error.txt", "w", stderr);
	#endif
	srand(time(NULL));
	int t = 100;                                                                                       
	// cin>>t;
	bool flag = true;
  while(t--){
	   int n = rand()%10+1;
     string s = "";
     for(int i = 0;i<n;i++){
        int r = rand()%2;
        if(r == 1){
          s+= '1';
        }else{
          s+='0';
        }
     }

     if(brute(n,s) != opti(n,s)){
        debug(n);
        debug(s);
        debug(brute(n,s));
        debug(opti(n,s));
        flag = false;
        break;
     }


  }

	if(flag){
		debug("All Passed.");
	}
	else{
		debug("Wrong Answer.");
	}
}