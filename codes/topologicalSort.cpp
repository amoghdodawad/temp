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
            }
        }

        vector<int> dijkstra(int src){
            queue<int> q;
	        vector<int> ans;
            vector<int> indegree (numberOfNodes,0);
            for(int i=0;i < numberOfNodes; ++i){
                for(int j=0;j < numberOfNodes; ++j){
                    if(matrix[i][j]) indegree[j]++;
                }
            }
                
            for(int i=0;i < numberOfNodes; ++i){
                if(!indegree[i]){
                    q.push(i);
                }
            }
                
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto val : matrix[node]){
                    indegree[val]--;
                    if(!indegree[val]){
                        q.push(val);
                    }
                }
                ans.push_back(node);
            }
            return ans;
    }
};