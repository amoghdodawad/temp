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

        vector<int> dijkstra(int src){
            priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
            vector<int> distance (numberOfNodes,1e+9);
            distance[src] = 0;
            pq.push({ 0, src });
            
            while(!pq.empty()){
                int node = pq.top().second;
                int dist = pq.top().first;
                pq.pop();
                for(int i=0; i < numberOfNodes; ++i){
                    if(matrix[node][i] != 0 && dist + matrix[node][i] < distance[i]){
                        distance[i] = dist + matrix[node][i];
                        pq.push({distance[i],i});
                    }
                }
            }
            return distance;
        }
        
};