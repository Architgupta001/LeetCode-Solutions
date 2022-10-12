#include<bits/stdc++.h>
using namespace std;
//common file for PBDS
#include<ext/pb_ds/assoc_container.hpp>
//including tree_order_statistics_node_update
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//macro definition
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
#define ll long long
#define lld long double
#define ull unsigned long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repk(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define bit(x) __builtin_popcount(x)
#define bitll(x) __builtin_popcountll(x)
#define popb pop_back
#define pb push_back
#define eb emplace_back
#define ub upper_bound
#define lb lower_bound
#define ff first
#define ss second
#define um unordered_map
#define om ordered_map
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define precision(x, y) fixed << setprecision(y) << x
#define PI 3.1415926535897932384626
#define sz(x) ((ll)(x).size())
#define present(b, a) ((a).find((b)) != (a).end())  //if b is present in a
const ll mod = 1e9 + 7; //1000000007
const ll mod2 = 998244353;
const ll inf = LLONG_MAX;
const lld epsilon = 1e-12;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef pair<lld, lld> pd;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// ------------------------Do not write above this line-----------------------------------------------------------------------------------------------------------------
const int MAX=2e5+5;
const int MAXD=30; 
vector<int>children[MAX];
int up[MAX][MAXD];
int depth[MAX];

void dfs(int a){
    for(auto it:children[a]){
        depth[it]=depth[a]+1;
        up[it][0]=a;
        for(int j=1;j<MAXD;j++){
            up[it][j]=up[up[it][j-1]][j-1];
        }
        dfs(it);
    }
}

int lca(int a ,int b){
    if(depth[a]<depth[b]){
        swap(a,b);
    }
    // Make a and b on same depth
    int k=depth[a]-depth[b];
    for(int j=0;j<MAXD;j++){
        if(k&(1<<j)){
            a=up[a][j];
        }
    }

    // if b was ancestor of b
    if(a==b){
        return a;
    }
    // move both a and b from highest powers of 2;
    for(int i=MAXD-1;i>=0;i-- ){
        if(up[a][i]!=up[b][i]){
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0]; // At this stages both a and b are the children of their lca
}

void solve(){
    ll n;
    cin>>n;
    rep(v,n){
        ll cnt;
        cin>>cnt;
        for(int i=0;i<cnt;i++){
            int c;
            cin>>c;
            children[v].pb(c);
        }
    }
    dfs(0);
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
