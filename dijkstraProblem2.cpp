vector<int> dijkstra(int n,vector<vector<pair<int,int>>> &adj,int src){
    vector<int> dist(n+1,INF);

    //min heap of pairs
    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<>> pq;

    dist[src] = 0;
    pq.push({0,src});

    while(!pq.empty()){
        int currDist = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if(currDist > dist[u]){
            continue;
        }

        for(auto &it : adj[u]){
            int v = it.first;
            int wt = it.second;

            if(dist[v] > dist[u]+wt){
                dist[v] = dist[u]+wt;
                pq.push({dist[v],v});
            }
        }

    }

    return dist;
}


void solve(){

    // cout<<"H"<<endl;

    vector<int> distFromSource = dijkstra(n,adj,src);
    vector<int> distFromDestination = dijkstra(n,adj,destination);

    int minDist = distFromSource[destination];

    for(auto &it : edges){
        int u,v,w;
        tie(u,v,w) = it;

        int reduceWeight = w/2;

        int newDist = distFromSource[u] + reduceWeight + distFromDestination[v];
        minDist = min(minDist,newDist);


        newDist = distFromSource[v] + reduceWeight + distFromDestination[u];
        minDist = min(minDist,newDist);

    }

    cout<<minDist<<endl;



    


}
