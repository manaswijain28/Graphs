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

    vector<vector<int>> components;
    vector<int> visited(n+1,false);

    auto dfs = [&](int sourceNode){
        vector<int> comp;
        function<void(int)> func = [&](int node)->void{
            comp.push_back(node);
            visited[node] = true;

            for(auto &it : adj[node]){
                if(visited[it] == false){
                    func(it);
                }
            }

        };

        func(sourceNode);

        components.push_back(comp);

    };


    for(int i=1;i<=n;i++){
        if(visited[i] == false){
            dfs(i);
        }
    }


    for(int i=0;i<components.size();i++){
        for(int j=0;j<components[i].size();j++){
            cout<<components[i][j]<<" ";
        }
        cout<<endl;
    }

    

    

    

}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
