
bool static cmp(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}

vector<vector<int>> kruskal(int n,vector<vector<int>> &edges){
    vector<vector<int>> mst;

    UnionFind dsu(n);  //O(V)

    sort(edges.begin(),edges.end(),cmp);   //O(E logE)

    for(auto edge: edges){  //O(E)
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if(!dsu.isSameSet(u,v)){
            dsu.unionSet(u,v);
            mst.push_back({u,v});
        }

    }

    return mst;


}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        edges.push_back({u,v,wt});
    }

    vector<vector<int>> mst = kruskal(n,edges);

    for(int i=0;i<(n-1);i++){
        cout<<mst[i][0]<<" "<<mst[i][1]<<endl;
    }

}
