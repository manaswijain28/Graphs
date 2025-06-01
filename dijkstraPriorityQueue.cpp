

//bfs using a priority queue

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
