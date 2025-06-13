void solve(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int> topo_order;
    vector<int> indegree(n+1);

    for(int i=1;i<=n;i++){
        for(auto it : adj[i]){
            indegree[it]++;
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
        int u = q.front();
        q.pop();

        topo_order.push_back(u);

        for(auto it : adj[u]){
            indegree[it]--;
            if(indegree[it] == 0){
                topo_order.push_back(it);
            }
        }
    }

    return topo_order;
    //O(v+e)
    


    

}
