#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
 
// Number of vertices in given graph
#define V 6
 
/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
   // memset(visited, 0, sizeof(visited));
 
    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}

int main()
{
    // Let us create a graph shown in the above example
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
	for(int p=0; p<V; p++){
		for(int q=0; q<V; q++){
			cout<<graph[p][q]<<" ";
		}
		cout<<endl;
	}
	int path[V]={0,0,0,0,0,0};
	cout<<endl<<bfs(graph, 0, 5, path)<<endl;
	int i = path[5];
	while(i != -1){
		//cout << i << " ";
		i = path[i];
	}
	int path_flow = 1000;
	int u;

 	for (i=5; i!=0; i=path[i])
        {
            u = path[i];
            path_flow = min(path_flow, graph[u][i]);
        }
 
        // update residual capacities of the edges and reverse edges
        // along the path
        for (i=5; i != 0; i=path[i])
        {
            u = path[i];
            graph[u][i] -= path_flow;
            graph[i][u] += path_flow;
        }
	cout<<endl;
	for(int p=0; p<V; p++){
		for(int q=0; q<V; q++){
			cout<<graph[p][q]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
