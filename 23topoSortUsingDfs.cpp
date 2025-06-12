void dfs(int node){
    visited[node] = true;
    for(auto it : adj[node]){
        if(visited[it] == 0){
            dfs(it;)
        }
    }

    ans.push_back(node);
}

void topoSort(){
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);

        }
    }

    reverse(ans.begin(),ans.end());
}
