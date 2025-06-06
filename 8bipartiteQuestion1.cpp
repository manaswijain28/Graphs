#include <bits/stdc++.h>
using namespace std;
typedef int64_t T;
#define ll long long
// const int MM = 1000000007;
const ll p = 1e13;
const int m = 1e6+1;

//***************************************************
const int mod = 998244353;
const int maxn = 1e6+1;
struct MOD {
    int64_t v; explicit operator int64_t() const { return v % mod; }
    MOD() { v = 0; }
    MOD(int64_t _v) {
        v = (-mod < _v && _v < mod) ? _v : _v % mod;
        if (v < 0) v += mod;
    }
    friend bool operator==(const MOD& a, const MOD& b) {
        return a.v == b.v;
    }
    friend bool operator!=(const MOD& a, const MOD& b) {
        return !(a == b);
    }
    friend bool operator<(const MOD& a, const MOD& b) {
        return a.v < b.v;
    }

    MOD& operator+=(const MOD& m) {
        if ((v += m.v) >= mod) v -= mod;
        return *this;
    }
    MOD& operator-=(const MOD& m) {
        if ((v -= m.v) < 0) v += mod;
        return *this;
    }
    MOD& operator*=(const MOD& m) {
        v = v * m.v % mod; return *this;
    }
    MOD& operator/=(const MOD& m) { return (*this) *= inv(m); }
    friend MOD pow(MOD a, int64_t p) {
        MOD ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
            return ans;
    }
    friend MOD inv(const MOD& a) {
        assert(a.v != 0);
        return pow(a, mod - 2);
    }

    MOD operator-() const { return MOD(-v); }
    MOD& operator++() { return *this += 1; }
    MOD& operator--() { return *this -= 1; }
    MOD operator++(int32_t) { MOD temp; temp.v = v++; return temp; }
    MOD operator--(int32_t) { MOD temp; temp.v = v--; return temp; }
    friend MOD operator+(MOD a, const MOD& b) { return a += b; }
    friend MOD operator-(MOD a, const MOD& b) { return a -= b; }
    friend MOD operator*(MOD a, const MOD& b) { return a *= b; }
    friend MOD operator/(MOD a, const MOD& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const MOD& m) {
        os << m.v; return os;
    }
    friend istream& operator>>(istream& is, MOD& m) {
        int64_t x; is >> x;
        m.v = x;
        return is;
    }
    friend void __print(const MOD &x) {
        cerr << x.v;
    }
};


vector<MOD> fct(maxn, 1), invf(maxn, 1);
void calc_fact() {
    for(int i = 1 ; i < maxn ; i++) {
        fct[i] = fct[i - 1] * i;
    }
    invf.back() = MOD(1) / fct.back();
    for(int i = maxn - 1 ; i ; i--)
        invf[i - 1] = i * invf[i];
}

MOD choose(int n, int r) { // choose r elements out of n elements
    if(r > n)   return MOD(0);
    assert(r <= n);
    return fct[n] * invf[r] * invf[n - r];
}

MOD place(int n, int r) { // x1 + x2 ---- xr = n and limit value of xi >= n
    assert(r > 0);
    return choose(n + r - 1, r - 1);
}


//***************************************************

ll expo2(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = (ans * a);  
        }
        a = (a*a);
        b >>= 1;  //divide by 2
    }
    return ans;

}

// ll fact(ll n){
//     ll a = 1;
//     for(ll i = 1;i<=n;i++){
//         a *= i;
//     }

//     return a;
// }

// ll De(ll n){
//     if(n==0){
//         return 1;
//     }

//     ll a = fact(n);
//     ll ans = 0;
//     for(ll i=2;i<=n;i++){
//         if(i%2==0){
//             ans += a/fact(i);
//         }else{
//             ans -= a/fact(i);
//         }
//     }


//     return ans;


// }

int col[2] = {0,0};
void dfs(int node,int parent,int color,vector<vector<int>> &adj){
    col[color]++;
    for(auto &it : adj[node]){
        if(it != parent){
            dfs(it,node,color^1,adj);
        }
    }
}

void solve(){

    // cout<<"H"<<endl;

    //this is for tree
    int n;
    cin>>n;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    dfs(1,1,0,adj);
    cout<<1ll*col[0]*col[1]-(n-1)<<endl;


    
        


}

int main() {



    calc_fact();
    int t;
    cin>>t;
    while(t--){
     solve();


 }




}
