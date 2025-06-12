bool checkCycle(int node){
    visited[node] = true;
    inStack[node] = true;

    for(auto it : adj[node]){
        if(inStack[it]){
            return true;
        }

        if(!visited[node] && checkCycle(node)){
            return true;
        }
    }

    inStack[node] = false;
    return false;
}
