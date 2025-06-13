
void solve(){

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }

    vector<int> topo_order;
    vector<int> indegree(n+1);

    for(int i=1;i<=n;i++){
        for(auto it : adj[i]){
            indegree[it.first]++;
        }
    }

    //if there is no node with indegree as 0 it means that 
    //the graph contains cycle..

    queue<int> q;

    for(int i=1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.top();
        q.pop();

        topo_order.push_back(u);

        for(auto it : adj[u]){
            indegree[it.first]--;
            if(indegree[it.first] == 0){
                q.push(it.first);
            }
        }
    }

    vector<int> dp(n+1,0);
    for(int i=(n-1);i>=0;i--){
        int u = topo_order[i];

        for(auto it : adj[u]){
            int v = it.first;
            int wt = it.second;

            dp[u] = max(dp[u],wt+dp[v]);
        }
    }

    cout<<*max_element(dp.begin(),dp.end());



    cout<<endl;
    //O(v+e) 
    


    

}
