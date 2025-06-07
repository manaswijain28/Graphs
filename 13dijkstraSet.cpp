#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve() {

    //n nodes m edges

    int n,m;
    cin>>n>>m;

    // directed hai, x -> y with wt z
    vector<pair<int,int>> adj[n+1];

    // sabhi nodes ka source se kya distance hai
    vector<ll> dist(n+1,LLONG_MAX);
    
    // source ka khudese min distance to 0 hi hoga 
    dist[1] = 0;

    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;

        adj[x].push_back({y,z});
    }

    //set banaya taki hum vo node utha paye jiska dist 
    //min hai 

    set<pair<ll,int>> st;

    st.insert({0,1}); //distnace,node number for source

    while(!st.empty()){

        // taking the min distance wala node
        pair<ll,int> a = *st.begin();
        st.erase(st.begin());

        //uske adjacent nodes pe jayenge

        for(auto &it : adj[a.second]){
            int x = it.first;
            int wt = it.second;

            if(dist[x]>(a.first+wt)){

                // if vo adjacent node already present hai set me
                // with some distance greater uske liye hum delete karenge
                // if present nahi hai then kuch nahi hoga

                st.erase({dist[x],x});
                dist[x] = a.first + wt;
                st.insert({dist[x],x});


            }
        }



    }

    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;





}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
