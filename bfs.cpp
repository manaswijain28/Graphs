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
   
    vector<bool> visited(n+1,false);

    queue<int> qu;
    visited[sourceNode] = true;

    qu.push(sourceNode);

    while(!qu.empty()){
        int topNode = qu.front();
        qu.pop();
        cout<<topNode<<" ";
        for(auto &it : adj[topNode]){
            if(!visited[it]){
                visited[it] = true;
                qu.push(it);
            }
        }
    }

    

    

    

}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
