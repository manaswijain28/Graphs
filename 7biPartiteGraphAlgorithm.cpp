//it is just implemented code, not verified using an example
#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve() {

    // cout<<"hello"<<endl;
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1,vector<int> ());

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    vector<int> color(n+1,0); //0 is uncoloured, 1 first color, 2 second color
    bool possible = true; //kisi bhi point par answer possible nahi hai


    function<bool(int)> dfs = [&](int node)->void{
        bool ok = true;
        for(auto &it : adj[node]){
            //if the neighbour is uncolured 
            if(color[it] == 0){
                if(color[node] == 1){
                    color[it] = 2;
                }else{
                    color[it] = 1;
                }
            //if already colored
            }else{
                if(color[node] == color[it]){
                    ok = false;
                }
            }
        }

        return ok;
    }

    //to cover all the connected componects in the graph
    for(int i=1;(i<=n) && possible;i++){
        if(color[i] != 0){
            continue;
        }

        color[i] = 1;
        possible = possible && dfs(i);


    }

    //O(n + m)


}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
