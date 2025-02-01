#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 


using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


using namespace std;
using ll = long long;
using ld = long double;


#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define forinc(i,a,b) for (i = a; i < b; i++)
#define fordec(i,a,b) for (i = a; i >= b; i--)
#define pii pair<int, int>


void display(vector<int> v){
    for (auto i : v) cout << i << ' ';
    cout << "\n";
}

void dfs(int u, map<int, vector<int>> mp, vector<int> &par) {
    for(int v : mp[u]) {
        if(v != par[u]) {
            par[v] = u;
            dfs(v, mp, par);
        }
    }
}

struct DSU {
    int n, cnt;
    vector<int> parent;
    DSU(int n = 0) {
        init(n);
    }
    void init(int n_) {
        n = cnt = n_;
        parent.assign(n, -1);
        // iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) { return parent[u] < 0 ? u : parent[u] = find(parent[u]); }
    bool join(int u, int v) {
        u = find(u); v = find(v);
        if(u == v)  return false;
        if(parent[u] < parent[v])   swap(u, v);
        parent[v] += parent[u];
        parent[u] = v;
        return true;
    }
    bool same(int u, int v) { return find(u) == find(v); }
};
 


void solve() {
    // code here
    
    int n, m, i, j;
    cin>>n>>m;
    vector<int> ans;
    vector<int> par(1000001);
    map<int, vector<int>> mp;
    DSU dd = DSU(n);
    for(int i = 0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        u--;v--;

        if(!dd.join(v,u)){
            dfs(u, mp, par);

            int x = v;
            while(x!= 0){
                ans.push_back(x);
                x = par[x];
            }
            cout<<ans.size()+1<<"\n";
            forinc(i,0,ans.size()) cout<<ans[i]+1<<' ';
            cout<<v+1;
            return ;
        }

        else {
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

    }

    cout<<"IMPOSSIBLE"; 
    

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;

    while (t--)
    {
        // cout<<"-----------"<<endl;
        solve();
        // cout << "\n";
    }

    return 0;
}

// max heap
// priority_queue<int,vector<int>,greater<int>> pq;