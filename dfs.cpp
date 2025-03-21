#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve() {

    // cout<<"hello"<<endl;
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int sourceNode = 1;
    vector<int> dfsTraversal;
    vector<bool> visited(n+1,false);

    function<void(int)> dfs = [&](int node)->void{
        dfsTraversal.push_back(node);
        visited[node] = true;

        for(auto &it : adj[node]){
            if(visited[it] == false){
                dfs(it);
            }
        }
    };

    dfs(sourceNode);
    for(auto &it : dfsTraversal){
        cout<<it<<" ";
    }
    cout<<endl;

    

    

}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
