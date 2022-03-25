#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define endl "\n"
#define is ==
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define test ll T; cin>>T; while(T--) solve();
#define test1 ll T=1; while(T--) solve();
#define loop(i,s,n) for(ll i=s;i<n;i++)
#define rloop(i,s,n) for(ll i=s;i>=n;i--)
#define fill(a,value) memset(a,value,sizeof(a))
#define umap unordered_map
#define pb push_back
#define mp(a,b) make_pair(a,b)

// Take Vector
#define takeVector(n,T) vector<T> arr(n); for(int i=0;i<n;i++) cin>>arr[i];

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;

/*DEBUGGING TEMPLATE*/

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
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


/*######################################################################################################################################*/
/*SOLUTION*/ 

class LocCost{
public:
  pair<int,int> location;
  vector<pair<int,int>> path;
  int hero;
  bool reached = false;
  LocCost(pair<int,int> loc,int h){
    this->location = loc;
    this->hero = h;
    if(h == 0){
      reached = true;
    } 
  }
};

class Compare{
public:
  int operator()(const LocCost& l1,const LocCost& l2){
    return l1.hero > l2.hero;
  }
};

void ratRun(vector<vector<int>>& maze,pair<int,int>& start,pair<int,int>& goal){
  
  
  priority_queue<LocCost,vector<LocCost>,Compare> pq;
  
  LocCost ll(start,maze[start.first][start.second]);
  vector<pair<int,int>> ansPath;
  pq.push(ll);

  bool flag = false;
  map<pair<int,int>,bool> visited;
  visited[start] = true;
  int n = maze.size();

  int size = pq.size();
  for(auto& vec:maze){
    for(auto& val:vec){
      cout<<val<<" ";
    }
    cout<<endl;
  }

  while(!pq.empty()){
    auto current  = pq.top();pq.pop();
    if(current.reached == true){
      flag = true;
      ansPath = current.path;
      ansPath.emplace_back(current.location);
      break;
    }

    pair<int,int> position = current.location;
    int i = position.first;
    int j = position.second;
    
    if(position.first == goal.first && position.second == goal.second){
      flag = true;
      ansPath = current.path;
      ansPath.emplace_back(current.location);
      break;
    }
    // 8 options
    // up

    if(i-1 >= 0 && maze[i-1][j] != -1){
      pair<int,int> newCord = {i-1,j};
      if(visited.find(newCord) == visited.end()){
        LocCost upll(newCord,maze[i-1][j]);
        if(current.path.size() > 0){
          for(auto& pr:current.path){
            upll.path.emplace_back(pr);
          }
        }
        upll.path.emplace_back(current.location);
        pq.push(upll);
        visited[newCord] = true;
      }
    }

    //down
    if(i+1 < n && maze[i+1][j] != -1){
      pair<int,int> newCord = {i+1,j};
      if(visited.find(newCord) == visited.end()){
        LocCost downll(newCord,maze[i+1][j]);
        if(current.path.size() > 0){
          for(auto& pr:current.path){
            downll.path.emplace_back(pr);
          }
        }
        downll.path.emplace_back(current.location);
        pq.push(downll);
        visited[newCord] = true;
      }
    }

    //left
    if(j-1 >= 0 && maze[i][j-1] != -1){
      pair<int,int> newCord = {i,j-1};
      if(visited.find(newCord) == visited.end()){
        LocCost leftll(newCord,maze[i][j-1]);
        if(current.path.size() > 0){
          for(auto& pr:current.path){
            leftll.path.emplace_back(pr);
          }
        }
        leftll.path.emplace_back(current.location);
        pq.push(leftll);
        visited[newCord] = true;
      }
    }
    //right
    if(j+1 < n && maze[i][j+1] != -1){
      pair<int,int> newCord = {i,j+1};
      if(visited.find(newCord) == visited.end()){
        LocCost rightll(newCord,maze[i][j+1]);
        if(current.path.size() > 0){
          for(auto& pr:current.path){
            rightll.path.emplace_back(pr);
          }
        }
        rightll.path.emplace_back(current.location);
        pq.push(rightll);
        visited[newCord] = true;
      }
    }

    // diagonal1

    if(i-1 >= 0 && j-1 >= 0 && maze[i-1][j-1] != -1){
      pair<int,int> newCord = {i-1,j-1};
      if(visited.find(newCord) == visited.end()){
        LocCost dig1ll(newCord,maze[i-1][j-1]);
        if(current.path.size() > 0){
          for(auto& pr:current.path){
            dig1ll.path.emplace_back(pr);
          }
        }
        dig1ll.path.emplace_back(current.location);
        pq.push(dig1ll);
        visited[newCord] = true;
      }
    }

    //diagonal2

    if(i-1 >= 0 && j+1 < n && maze[i-1][j+1] != -1){
      pair<int,int> newCord = {i-1,j+1};
      if(visited.find(newCord) == visited.end()){
        LocCost dig2ll(newCord,maze[i-1][j+1]);
        if(current.path.size() > 0){
          for(auto& pr:current.path){
            dig2ll.path.emplace_back(pr);
          }
        }
        dig2ll.path.emplace_back(current.location);
        pq.push(dig2ll);
        visited[newCord] = true;
      }
    }

    //diagonal3

    if(i+1 < n && j-1 >= 0 && maze[i+1][j-1] != -1){
      pair<int,int> newCord = {i+1,j-1};
      if(visited.find(newCord) == visited.end()){
        LocCost dig3ll(newCord,maze[i+1][j-1]);
        if(current.path.size() > 0){
          for(auto& pr:current.path){
            dig3ll.path.emplace_back(pr);
          }
        }
        dig3ll.path.emplace_back(current.location);
        pq.push(dig3ll);
        visited[newCord] = true;
      }
    }

    //diagonal4
    if(i+1 < n && j+1 < n && maze[i+1][j+1] != -1){
      pair<int,int> newCord = {i+1,j+1};
      if(visited.find(newCord) == visited.end()){
        LocCost dig4ll(newCord,maze[i+1][j+1]);
        if(current.path.size() > 0){
          for(auto& pr:current.path){
            dig4ll.path.emplace_back(pr);
          }
        }
        dig4ll.path.emplace_back(current.location);
        pq.push(dig4ll);
        visited[newCord] = true;
      }
    }
  }

  if(flag){
    debug(true);
    for(auto& pr:ansPath){
      debug(pr);
    }

  }else{
    debug(false);
  }

}

void solve(){
  int n1 = 10,n2 = 10;
  vector<vector<int>> maze(n1,vector<int>(n2,-1));
      maze = {
              {-1,4,2,3,4,2,2,4,-1,-1},
              {-1, 5, 2 ,-1, -1 ,-1, 2 ,5, 4 ,-1},
              {-1, 6, 1 ,1 ,3, 4 ,1 ,-1, 3, -1},
              {-1, 5, -1 ,-1, 2 ,-1, 1, -1, 3 ,-1},
              {-1 ,3,-1 ,-1, 2 ,-1 ,2, -1, 6, -1},
              {-1 ,2 ,-1 ,-1, 2 ,-1 ,1, 3, 4, 4 },
              {-1, 2, 1, 3 ,4 ,-1, 1 ,-1 ,-1 ,5},
              {-1 ,3, -1 ,-1 ,3 ,2,1, -1, -1 ,3},
              {-1 ,2, -1 ,-1 ,-1 ,-1 ,1 ,-1 ,2, 2},
              {-1 ,1 ,2 ,2 ,1 ,1, 0 ,-1, 1, -1}
            };

    pair<int,int> start,goal;
    // int a,b;cin>>a,b;
    // int c,d;cin>>c,d;
    start = {0,4};
    goal = {9,6};
    ratRun(maze,start,goal);

}

/*######################################################################################################################################*/


signed main() {
  #ifndef ONLINE_JUDGE
  	freopen("Error.txt", "w", stderr);
  #endif
  fastio();
  test1
  // test
  return 0;
}
