//this is not the complete code but the start of the code, rest same as finding connected components

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};

// (x,y) = (i+dx[i],j+dy[i])
void solve() {

    // cout<<"hello"<<endl;
    int n;
    cin>>n;

    // nxn matrix

    vector<vector<int>> grid(n,vector<int> (n));

    for(auto &i : grid){
        for(auto &j : i){
            cin>>j;
        }
    }

    //we can also make a map

    map<pair<int,int>,vector<pair<int,int>>> adj;
    set<pair<int,int>> validNodes;
    map<pair<int,int>,bool> visited;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 0){
                continue;
            }

            for(int k=0;k<4;k++){
                int newX = i + dx[k];
                int newY = j + dy[k];
                if(newX >=0 && newX < n && newY >= 0 && newY < n){
                    if(grid[newX][newY] == 1){
                        adj[{i,j}].push_back({newX,newY});

                    }
                }

            }
        }
    }


    for(auto i : validNodes){
        //do normal dfs from here
    }








       

}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
