class UnionFind{
private: vector<int> p,rank;
public: 

    //constructor to assign parent of every node as itself
    UnionFind(int n){
        rank.assign(n,0);
        p.assign(n,0);
        for(int i=0;i<n;i++){
            p[i] = i;
        }


    }
    
    //finding the parent of each node
    int findSet(int i){
        return (p[i] == i) ? i : p[i] = findSet(p[i]);

    }
    
    //if the two nodes are in the same components then they have the same parent
    bool isSameSet(int i,int j){
        return findSet(i) == findSet(j);
    }

    void unionSet(int i,int j){

        //if not in same component
        if(!isSameSet(i,j)){

            //finding parent
            int x = findSet(i);
            int y = findSet(j);

            if(rank[x] > rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x] == rank[y]){
                    rank[y]++; 
                }
            }
        }
    }


}
