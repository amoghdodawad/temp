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

        vector<int> bfs(int src){
            vector<bool> visited(numberOfNodes, false);
            vector<int> ans;
            queue<int> q;
            q.push(src);
            visited[src] = true;
            while(!q.empty()){
                int i = q.front();
                ans.push_back(i);
                q.pop();
                for(int j=0;j<numberOfNodes;++j){
                    if(matrix[i][j] && !visited[j]){
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
            return ans;
        }
        
};