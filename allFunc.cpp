#include<bits/stdc++.h> 
 
using namespace std;
using ll = long long;
using ld = long double;

int nCr(int n, int r) {

    if (r > n) return 0;
    if (r == 0 || n == r) return 1;

    double res = 0;

    for (int i = 0; i < r; i++) {
        res += log(n-i) - log(i+1);
    }
    return (int)round(exp(res));
}


#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
 
inline ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    while(T--){
        ll N, P;
        cin >> N >> P;
 
        vector<ll> A(N);
        for(auto &x: A) cin >> x;
 
 
        const ll INF = 1e18;
        vector<ll> t_i(N, INF);
 
 
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, std::greater<pair<ll, int>>> pq;
 
 
        for(int i=0; i<N; i++){
            if(A[i] == 0){
                t_i[i] = 0;
                pq.emplace(0, i);
            }
        }
 
 
        vector<int> directions = {-1, 1};
 
        while(!pq.empty()){
            pair<ll, int> current = pq.top();
            pq.pop();
 
            ll current_t = current.first;
            int u = current.second;
 
 
            if(current_t > t_i[u]) continue;
 
            for(auto dir: directions){
                int v = u + dir;
                if(v <0 || v >=N) continue;
 
 
                ll required_t;
                if(A[v] == 0){
                    required_t = 0;
                }
                else{
                    required_t = ceil_div(A[v], (ll)P);
                }
 
                ll new_t = max(current_t, required_t);
 
                if(new_t < t_i[v]){
                    t_i[v] = new_t;
                    pq.emplace(new_t, v);
                }
            }
        }
 
        for(int i=0; i<N; i++){
            if(A[i]==0){
                cout << "0 ";
            }
            else{
                cout << t_i[i] << " ";
            }
        }
        cout << "\n";
    }
}