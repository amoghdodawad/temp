#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

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

        void dfsUtil(int src, vector<bool>& visited, vector<int>& ans){
            visited[src] = true;
            ans.push_back(src);
            for(int i=0;i<numberOfNodes;++i){
                if(matrix[src][i] && !visited[i]){
                    dfsUtil(i, visited, ans);
                }
            }
        }

        vector<int> dfs(int src){
            vector<bool> visited(numberOfNodes, false);
            vector<int> ans;
            queue<int> q;
            q.push(src);
            dfsUtil(src,visited,ans);
            return ans;
        }
        
};