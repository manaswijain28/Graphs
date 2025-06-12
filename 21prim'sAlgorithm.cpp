vector<vector<int>> prims(int n,vector<vector<pair<int,int>>> &adj){
    vector<vector<int>> mst;

    vector<int> visited(n+1);
    vector<int> min_cost(n+1,INT_MAX);

    priority_queue<vector<int>,vector<vector<int>> ,greater<>> pq;

    min_cost[1] = 0;
    pq.push({0,1,-1});

    while(!pq.empty()){
        vector<int> temp = pq.top();
        pq.pop();

        int cost = temp[0];
        int u = temp[1];
        int par = temp[2];

        if(visited[u]){
            continue;
        }

        visited[u] = 1;

        if(par != -1){
            mst.push_back({par,u,cost});
        }

        for(auto it : adj[u]){
            if(!visited[it.first] && it.second < min_cost[it.first]){
                min_cost[it.first] = it.second;

                pq.push({it.second,it.first,u});
            }
        }
    }


    return mst;


} 

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    vector<vector<int>> mst = prims(n,adj);

    for(int i=0;i<(n-1);i++){
        cout<<mst[i][0]<<" "<<mst[i][1]<<" "<<mst[i][2]<<endl;
    }

}
