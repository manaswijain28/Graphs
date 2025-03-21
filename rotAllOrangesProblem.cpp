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

    // vector<vector<int>> grid(n,vector<int> (n));

    // for(auto &i : grid){
    //     for(auto &j : i){
    //         cin>>j;
    //     }
    // }

    pair<int,int> rottedOrangeCoordinates;

    cin>>rottedOrangeCoordinates.first >> rottedOrangeCoordinates.second;


    vector<vector<int>> ans(n,vector<int> (n));
    ans[rottedOrangeCoordinates.first][rottedOrangeCoordinates.second] = 0;

    queue<pair<int,int>> qu;

    qu.push(rottedOrangeCoordinates);

    vector<vector<bool>> visited(n,vector<bool> (n));
    visited[rottedOrangeCoordinates.first][rottedOrangeCoordinates.second] = true;

    int mx = 0;

    while(!qu.empty()){
        pair<int,int> topNode = qu.front();
        qu.pop();

        for(int i=0;i<4;i++){
            pair<int,int> neigh = {topNode.first+dx[i],topNode.second+dy[i]};

            if(neigh.first >= 0 && neigh.first < n && neigh.second >= 0 && neigh.second <n ){
                if(visited[neigh.first][neigh.second] == false){
                    qu.push(neigh);
                    visited[neigh.first][neigh.second] = true;
                    ans[neigh.first][neigh.second] = ans[topNode.first][topNode.second]+1;
                    mx = max(mx,ans[neigh.first][neigh.second]);

                }
            }
        }


    }

    cout<<mx<<endl;




}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
