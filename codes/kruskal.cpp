#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
    int getSize(int node){
        return size[find(node)];
    }
};

class Graph {
    vector<vector<int>> matrix;
    int numberOfNodes, numberOfEdges;
    public:
        Graph(int numberOfNodes, int numberOfEdges){
            this->numberOfNodes = numberOfNodes;
            this->numberOfEdges = numberOfEdges;
            for(int i=0; i < numberOfNodes; ++i){
                vector<int> temp(numberOfNodes,0);
                matrix.push_back(temp);
            }
        }

        void initialiseGraph(){
            for(int i=0; i < numberOfEdges; ++i){
                int u,v,w;
                cin >> u >> v >> w;
                matrix[u][v] = w;
                matrix[v][u] = w;
            }
        }

        int kruskal(){
            int sum = 0;
            int edges = 0;
            DisjointSet ds(numberOfNodes);
            vector<pair<int,pair<int,int>>> edge;
            for(int i=0;i<numberOfNodes;++i){
                for(int j=0;j<i;+j){
                    if(matrix[i][j]){
                        edge.push_back({matrix[i][j],{i,j}});
                    }
                }
            }
            sort(edge.begin(),edge.end());
            int start = 0;
            for(auto it : edge){
                if(ds.find(it.second.first) != ds.find(it.second.second)){
                    sum += it.first;
                    ds.unionBySize(it.second.first,it.second.second);
                }
            }
            return sum;
        }
        
};