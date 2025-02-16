#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 


// using namespace __gnu_pbds;
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


struct DSU {
    int n, cnt;
    vector<int> parent;
    DSU(int n = 0) {
        init(n);
    }
    void init(int n_) {
        n = cnt = n_;
        parent.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) { return u == parent[u] ? u : parent[u] = find(parent[u]); }
    bool join(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            parent[v] = u;
            cnt--;
            return true;
        }
        return false;
    }
    bool same(int u, int v) { return find(u) == find(v); }
};
 
unordered_map<int, int> dijkstra(unordered_map<int, vector<pair<int, int>>> &graph, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_map<int, int> distances;
    
    for (auto &node : graph) {
        distances[node.first] = numeric_limits<int>::max();
    }
    distances[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        
        if (current_distance > distances[current_node]) {
            continue;
        }
        
        for (auto &neighbor : graph[current_node]) {
            int next_node = neighbor.second;
            int weight = neighbor.first;
            int distance = current_distance + weight;
            
            if (distance < distances[next_node]) {
                distances[next_node] = distance;
                pq.push({distance, next_node});
            }
        }
    }
    
    return distances;
}


int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] < a[i] && a[i] < d[l])
            d[l] = a[i];
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}

void creatingSubset(int n) {
    for (int b = 0; b < (1<<n); b++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (b&(1<<i)) subset.push_back(i);
        }
    }
}



void solve() {
    // code here
    

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;

    while (t--){
        // cout<<"-----------"<<endl;
        solve();
        cout << "\n";
    }

    return 0;
}

// max heap
// priority_queue<int,vector<int>,greater<int>> pq;