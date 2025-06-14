
void kasaraju(int n,vector<vector<int>> &adj,vector<vector<int>> &components, vector<vector<int>> &adj_cond){
    vector<int> visited(n+1,0);
    vector<int> order;
    

    // *********** topological order ******************* //
    function<void(int)> dfs = [&](int node)->void{
        visited[node] = 1;
        for(auto it : adj[node]){
            if(visited[it] == 0){
                dfs(it);
            }
        }
        order.push_back(it);
    };

    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            dfs(i);
        }
    }

    fill(visited.begin(),visited.end(),0);
    reverse(order.begin(),order.end());


    // ************* transpose *********** //

    vector<vector<int>> adj_rev(n+1);
    for(int i=1;i<=n;i++){
        for(auto it : adj[i]){
            adj_rev[it].push_back(i);
        }
    }


    // *********** getting all strongly connected components **************//


    auto func = [&](int src){
        vector<int> component;
        function<void(int)> dfs_rev = [&](int node)->void{
            visited[node] = 1;
            component.push_back(node);

            for(auto it : adj[node]){
                if(visited[it] == 0){
                    dfs_rev(it);
                }
            }

        };

        dfs_rev(src);
        components.push_back(component);
    }
    
    vector<int> roots(n+1);

    for(auto u : order){
        if(visited[u]){
            continue;
        }

        func(u);

        // condensation //
        vector<int> &component = components.back();
        int root = *min_element(component.begin(),component.end());

        for(auto it : component){
            roots[it] = root;
        }

    }


    // **** to get the condensed graph **** //

    adj_cond.resize(n+1);

    for(int i=1;i<=n;i++){
        for(auto it : adj[i]){
            if(roots[i] != roots[it]){
                adj_cond[roots[i]].push_back(roots[it]);
            }
        }
    }




}
