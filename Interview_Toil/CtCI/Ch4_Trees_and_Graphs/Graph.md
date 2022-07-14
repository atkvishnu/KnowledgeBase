------------
# 1. Breadth First Search or BFS for a Graph

[Breadth-First Traversal (or Search)](http://en.wikipedia.org/wiki/Breadth-first_search) for a graph is similar to Breadth-First Traversal of a tree (See method 2 of [this post](https://www.geeksforgeeks.org/level-order-tree-traversal/)). The only catch here is, unlike trees, graphs may contain cycles, so we may come to the same node again. To avoid processing a node more than once, we use a boolean visited array. For simplicity, it is assumed that all vertices are reachable from the starting vertex.

For example, in the following graph, we start traversal from vertex 2. When we come to vertex 0, we look for all adjacent vertices of it. 2 is also an adjacent vertex of 0. If we don’t mark visited vertices, then 2 will be processed again and it will become a non-terminating process. A Breadth-First Traversal of the following graph is 2, 0, 3, 1.

![[https://media.geeksforgeeks.org/wp-content/uploads/bfs-5.png]]


Implementations of simple Breadth-First Traversal

The implementation uses an [adjacency list representation](http://en.wikipedia.org/wiki/Adjacency_list) of graphs. [STL](http://en.wikipedia.org/wiki/Standard_Template_Library)‘s [list container](http://www.yolinux.com/TUTORIALS/LinuxTutorialC++STL.html#LIST) is used to store lists of adjacent nodes and the queue of nodes needed for BFS traversal.

```cpp
// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include<iostream>
#include <list>
 
using namespace std;
 
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;  
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints BFS traversal from a given source s
    void BFS(int s); 
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
```

**Output:** 

Following is Breadth First Traversal (starting from vertex 2)
2 0 3 1

**Illustration :**

![[https://media.geeksforgeeks.org/wp-content/cdn-uploads/bfs2.png]]

![[https://media.geeksforgeeks.org/wp-content/cdn-uploads/bfs3.png]]

![[https://media.geeksforgeeks.org/wp-content/cdn-uploads/bfs7.png]]

![[https://media.geeksforgeeks.org/wp-content/cdn-uploads/bfs8.png]]

![[https://media.geeksforgeeks.org/wp-content/cdn-uploads/bfs10.png]]


the above code traverses only the vertices reachable from a given source vertex. All the vertices may not be reachable from a given vertex (for example Disconnected graph). To print all the vertices, we can modify the BFS function to do traversal starting from all nodes one by one (Like the [DFS modified version](https://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/)).



**Time Complexity: **

`O(V+E)` where V is a number of vertices in the graph and E is a number of edges in the graph.



-------------
# 2. Depth First Search (DFS)

[Depth First Traversal (or Search)](http://en.wikipedia.org/wiki/Depth-first_search) for a graph is similar to [Depth First Traversal of a tree.](https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/) The only catch here is, unlike trees, graphs may contain cycles (a node may be visited twice). To avoid processing a node more than once, use a boolean visited array.

**Example:**
**Input:** n = 4, e = 6   
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3   
**Output:** DFS from vertex 1 : 1 2 0 3   
**Explanation:**   
DFS Diagram:
![[https://media.geeksforgeeks.org/wp-content/uploads/20200507074112/ezgif.com-gif-maker61.gif]]

**Input:** n = 4, e = 6   
2 -> 0, 0 -> 2, 1 -> 2, 0 -> 1, 3 -> 3, 1 -> 3   
**Output:** DFS from vertex 2 : 2 0 1 3   
**Explanation:**   
DFS Diagram:

![[https://media.geeksforgeeks.org/wp-content/uploads/20200507075041/ezgif.com-gif-maker7.gif]]


**Approach:**   
Depth-first search is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and explores as far as possible along each branch before backtracking. So the basic idea is to start from the root or any arbitrary node and mark the node and move to the adjacent unmarked node and continue this loop until there is no unmarked adjacent node. Then backtrack and check for other unmarked nodes and traverse them. Finally, print the nodes in the path.

**Algorithm:**   
Create a recursive function that takes the index of the node and a visited array.

1.  Mark the current node as visited and print the node.
2.  Traverse all the adjacent and unmarked nodes and call the recursive function with the index of the adjacent node.

**Implementation:**   
Below are implementations of simple Depth First Traversal. The C++ implementation uses an adjacency list representation of graphs. STL’s list container is used to store lists of adjacent nodes.

```cpp
// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include <bits/stdc++.h>
using namespace std;
 
// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
 
// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}
```

**Output:**
Following is Depth First Traversal (starting from vertex 2)
2 0 1 3



**Complexity Analysis:** 

-   **Time complexity:** O(V + E), where V is the number of vertices and E is the number of edges in the graph.
-   **Space Complexity:** O(V), since an extra visited array of size V is required.



 **Handling A Disconnected Graph:**

-   **Solution:**   
    This will happen by handling a corner case.   
    The above code traverses only the vertices reachable from a given source vertex. All the vertices may not be reachable from a given vertex, as in a Disconnected graph. To do a complete DFS traversal of such graphs, run DFS from all unvisited nodes after a DFS.   
    _The recursive function remains the same._
-   **Algorithm:** 
    1.  Create a recursive function that takes the index of the node and a visited array.
    2.  Mark the current node as visited and print the node.
    3.  Traverse all the adjacent and unmarked nodes and call the recursive function with the index of the adjacent node.
    4.  Run a loop from 0 to the number of vertices and check if the node is unvisited in the previous DFS, call the recursive function with the current node.

**Implementation:**

```cpp
// C++ program to print DFS
// traversal for a given given
// graph
#include <bits/stdc++.h>
using namespace std;
 
class Graph {
 
    // A function used by DFS
    void DFSUtil(int v);
 
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints DFS traversal of the complete graph
    void DFS();
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFSUtil(int v)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i);
}
 
// The function to do DFS traversal. It uses recursive
// DFSUtil()
void Graph::DFS()
{
    // Call the recursive helper function to print DFS
    // traversal starting from all vertices one by one
    for (auto i : adj)
        if (visited[i.first] == false)
            DFSUtil(i.first);
}
 
// Driver  Code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
 
    cout << "Following is Depth First Traversal \n";
    g.DFS();
 
    return 0;
}
```

**Output:** 

Following is Depth First Traversal
0 1 2 3 9

**Complexity Analysis:** 

-   **Time complexity:** O(V + E), where V is the number of vertices and E is the number of edges in the graph.
-   **Space Complexity:** O(V), since an extra visited array of size V is required.


## Applications of Depth First Search
Depth-first search (DFS) is an algorithm (or technique) for traversing a graph.

**1) Detecting cycle in a graph**   
A graph has cycle if and only if we see a back edge during DFS. So we can run DFS for the graph and check for back edges.

**2) Path Finding**   
We can specialize the DFS algorithm to find a path between two given vertices u and z.   
i) Call DFS(G, u) with u as the start vertex.   
ii) Use a stack S to keep track of the path between the start vertex and the current vertex.   
iii) As soon as destination vertex z is encountered, return the path as the   
contents of the stack

**3)** [**Topological Sorting**](https://www.geeksforgeeks.org/topological-sorting/)   
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. In computer science, applications of this type arise in instruction scheduling, ordering of formula cell evaluation when recomputing formula values in spreadsheets, logic synthesis, determining the order of compilation tasks to perform in makefiles, data serialization, and resolving symbol dependencies in linkers [2].

**4) To test if a graph is** [**bipartite**](http://en.wikipedia.org/wiki/Bipartite_graph)   
We can augment either BFS or DFS when we first discover a new vertex, color it opposited its parents, and for each other edge, check it doesn’t link two vertices of the same color. The first vertex in any connected component can be red or black! 

**5) Finding Strongly Connected Components of a graph** A directed graph is called strongly connected if there is a path from each vertex in the graph to every other vertex. (See [this](https://www.geeksforgeeks.org/strongly-connected-components/) for DFS based algo for finding Strongly Connected Components) 

**6) Solving puzzles with only one solution**, such as mazes. (DFS can be adapted to find all solutions to a maze by only including nodes on the current path in the visited set.)

-------------------
# 3. Shortest Path from source to all vertices **Dijkstra**

Given a graph and a source vertex in the graph, find the shortest paths from the source to all vertices in the given graph.  
Dijkstra’s algorithm is very similar to [Prim’s algorithm for minimum spanning tree](https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/). Like Prim’s MST, we generate a _SPT (shortest path tree)_ with a given source as a root. We maintain two sets, one set contains vertices included in the shortest-path tree, other set includes vertices not yet included in the shortest-path tree. At every step of the algorithm, we find a vertex that is in the other set (set of not yet included) and has a minimum distance from the source.  
Below are the detailed steps used in Dijkstra’s algorithm to find the shortest path from a single source vertex to all other vertices in the given graph. 

Algorithm   
**1)** Create a set _sptSet_ (shortest path tree set) that keeps track of vertices included in the shortest-path tree, i.e., whose minimum distance from the source is calculated and finalized. Initially, this set is empty.   
**2)** Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. Assign distance value as 0 for the source vertex so that it is picked first.   
**3)** While _sptSet_ doesn’t include all vertices   
….**a)** Pick a vertex u which is not there in _sptSet_ and has a minimum distance value.   
….**b)** Include u to _sptSet_.   
….**c)** Update distance value of all adjacent vertices of u. To update the distance values, iterate through all adjacent vertices. For every adjacent vertex v, if the sum of distance value of u (from source) and weight of edge u-v, is less than the distance value of v, then update the distance value of v.

Let us understand with the following example:
![[https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg]]

The set _sptSet_ is initially empty and distances assigned to vertices are {0, INF, INF, INF, INF, INF, INF, INF} where INF indicates infinite. Now pick the vertex with a minimum distance value. The vertex 0 is picked, include it in _sptSet_. So _sptSet_ becomes {0}. After including 0 to _sptSet_, update distance values of its adjacent vertices. Adjacent vertices of 0 are 1 and 7. The distance values of 1 and 7 are updated as 4 and 8. The following subgraph shows vertices and their distance values, only the vertices with finite distance values are shown. The vertices included in SPT are shown in green colour.

![[https://www.geeksforgeeks.org/wp-content/uploads/MST1.jpg]]

Pick the vertex with minimum distance value and not already included in SPT (not in sptSET). The vertex 1 is picked and added to sptSet. So sptSet now becomes {0, 1}. Update the distance values of adjacent vertices of 1. The distance value of vertex 2 becomes 12.

![[https://www.geeksforgeeks.org/wp-content/uploads/DIJ2.jpg]]

Pick the vertex with minimum distance value and not already included in SPT (not in sptSET). Vertex 7 is picked. So sptSet now becomes {0, 1, 7}. Update the distance values of adjacent vertices of 7. The distance value of vertex 6 and 8 becomes finite (15 and 9 respectively).

![[https://www.geeksforgeeks.org/wp-content/uploads/DIJ3.jpg]]


Pick the vertex with minimum distance value and not already included in SPT (not in sptSET). Vertex 6 is picked. So sptSet now becomes {0, 1, 7, 6}. Update the distance values of adjacent vertices of 6. The distance value of vertex 5 and 8 are updated.

![[https://www.geeksforgeeks.org/wp-content/uploads/DIJ4.jpg]]

We repeat the above steps until _sptSet_ includes all vertices of the given graph. Finally, we get the following Shortest Path Tree (SPT).

![[https://www.geeksforgeeks.org/wp-content/uploads/DIJ5.jpg]]

_**implement**_
We use a boolean array sptSet[] to represent the set of vertices included in SPT. If a value sptSet[v] is true, then vertex v is included in SPT, otherwise not. Array dist[] is used to store the shortest distance values of all vertices.


```cpp

// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
#include <iostream>
using namespace std;
#include <limits.h>
 
// Number of vertices in the graph
#define V 9
 
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed distance array
void printSolution(int dist[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}
 
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i
 
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
 
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    // print the constructed distance array
    printSolution(dist);
}
 
// driver program to test above function
int main()
{
   
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijkstra(graph, 0);
 
    return 0;
}
```

**Output:** 

Vertex   Distance from Source
0                0
1                4
2                12
3                19
4                21
5                11
6                9
7                8
8                14


**Notes:**   
**1)** The code calculates the shortest distance but doesn’t calculate the path information. We can create a parent array, update the parent array when distance is updated (like [prim’s implementation](https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/)) and use it to show the shortest path from source to different vertices.  
**2)** The code is for undirected graphs, the same Dijkstra function can be used for directed graphs also.  
**3)** The code finds the shortest distances from the source to all vertices. If we are interested only in the shortest distance from the source to a single target, we can break the for loop when the picked minimum distance vertex is equal to the target (Step 3.a of the algorithm).  
**4)** Time Complexity of the implementation is O(V^2). If the input [graph is represented using adjacency list](https://www.geeksforgeeks.org/graph-and-its-representations/), it can be reduced to O(E log V) with the help of a binary heap. Please see   
[Dijkstra’s Algorithm for Adjacency List Representation](https://www.geeksforgeeks.org/greedy-algorithms-set-7-dijkstras-algorithm-for-adjacency-list-representation/) for more details.  
**5)** Dijkstra’s algorithm doesn’t work for graphs with negative weight cycles. It may give correct results for a graph with negative edges but you must allow a vertex can be visited multiple times and that version will lose its fast time complexity. For graphs with negative weight edges and cycles, [Bellman–Ford algorithm](http://en.wikipedia.org/wiki/Bellman-Ford_algorithm) can be used, we will soon be discussing it as a separate post.














------------------
# 4. Shortest Path from every vertex to every other vertex 
**Floyd Warshall**

The [Floyd Warshall Algorithm](http://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm) is for solving the All Pairs Shortest Path problem. The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.

**Example:** 

**Input:**
       graph[][] = { {0,   5,  INF, 10},
                    {INF,  0,  3,  INF},
                    {INF, INF, 0,   1},
                    {INF, INF, INF, 0} }
which represents the following graph
             10
       (0)------->(3)
        |                 /|\
      5 |                 |
        |                   | 1
       \|/               |
       (1)------->(2)
            3       
Note that the value of graph[i][j] is 0 if i is equal to j 
And graph[i][j] is INF (infinite) if there is no edge from vertex i to j.

**Output:**
Shortest distance matrix
      0      5      8      9
    INF      0      3      4
    INF    INF      0      1
    INF    INF    INF      0


**Floyd Warshall Algorithm**   
We initialize the solution matrix same as the input graph matrix as a first step. Then we update the solution matrix by considering all vertices as an intermediate vertex. The idea is to one by one pick all vertices and updates all shortest paths which include the picked vertex as an intermediate vertex in the shortest path. When we pick vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices. For every pair (i, j) of the source and destination vertices respectively, there are two possible cases.   
**1)** k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is.   
**2)** k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]  
The following figure shows the above optimal substructure property in the all-pairs shortest path problem.

![[https://media.geeksforgeeks.org/wp-content/uploads/dpFloyd-Warshall-.jpg]]


```cpp
// C++ Program for Floyd Warshall Algorithm
#include <bits/stdc++.h>
using namespace std;
  
// Number of vertices in the graph
#define V 4
  
/* Define Infinite as a large enough
value.This value will be used for
vertices not connected to each other */
#define INF 99999
  
// A function to print the solution matrix
void printSolution(int dist[][V]);
  
// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(int graph[][V])
{
    /* dist[][] will be the output matrix
    that will finally have the shortest
    distances between every pair of vertices */
    int dist[V][V], i, j, k;
  
    /* Initialize the solution matrix same
    as input graph matrix. Or we can say
    the initial values of shortest distances
    are based on shortest paths considering
    no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
  
    /* Add all vertices one by one to
    the set of intermediate vertices.
    ---> Before start of an iteration,
    we have shortest distances between all
    pairs of vertices such that the
    shortest distances consider only the
    vertices in set {0, 1, 2, .. k-1} as
    intermediate vertices.
    ----> After the end of an iteration,
    vertex no. k is added to the set of
    intermediate vertices and the set becomes {0, 1, 2, ..
    k} */
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
  
    // Print the shortest distance matrix
    printSolution(dist);
}
  
/* A utility function to print solution */
void printSolution(int dist[][V])
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}
  
// Driver code
int main()
{
    /* Let us create the following weighted graph
            10
    (0)------->(3)
     |         /|\
    5|          |
     |          | 1
    \|/         |
    (1)------->(2)
            3     */
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
  
    // Print the solution
    floydWarshall(graph);
    return 0;
}
```


**Output:** 

Following matrix shows the shortest distances between every pair of vertices
      0      5      8      9
    INF      0      3      4
    INF    INF      0      1
    INF    INF    INF      0

**Time Complexity:** O(V^3)


The above program only prints the shortest distances. We can modify the solution to print the shortest paths also by storing the predecessor information in a separate 2D matrix.   
Also, the value of INF can be taken as INT_MAX from limits.h to make sure that we handle maximum possible value. When we take INF as INT_MAX, we need to change the if condition in the above program to avoid arithmetic overflow. 

#include 

#define INF INT_MAX
..........................
if ( dist[i][k] != INF && 
     dist[k][j] != INF && 
     dist[i][k] + dist[k][j] < dist[i][j]
    )
 dist[i][j] = dist[i][k] + dist[k][j];
...........................











------------------

# 5. To detect cycle in a Graph **Union Find**

A [_disjoint-set data structure_](http://en.wikipedia.org/wiki/Disjoint-set_data_structure) is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. A [_union-find algorithm_](http://en.wikipedia.org/wiki/Disjoint-set_data_structure) is an algorithm that performs two useful operations on such a data structure:

_**Find:**_ Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.

_**Union:**_ Join two subsets into a single subset. Here first we have to check if the two subsets belong to same set. If no, then we cannot perform union.

In this post, we will discuss the application of Disjoint Set Data Structure. The application is to check whether a given graph contains a cycle or not.

_Union-Find Algorithm_ can be used to check whether an undirected graph contains cycle or not. Note that we have discussed an [algorithm to detect cycle](http://www.geeksforgeeks.org/archives/18516). This is another method based on _Union-Find_. This method assumes that the graph doesn’t contain any self-loops. 

We can keep track of the subsets in a 1D array, let’s call it parent[].  
Let us consider the following graph: 

![cycle-in-graph](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Cycle-in-graph.png)

For each edge, make subsets using both the vertices of the edge. If both the vertices are in the same subset, a cycle is found.

Initially, all slots of parent array are initialized to -1 (means there is only one item in every subset).

0   1   2
-1 -1  -1

Now process all edges one by one.  
_Edge 0-1:_ Find the subsets in which vertices 0 and 1 are. Since they are in different subsets, we take the union of them. For taking the union, either make node 0 as parent of node 1 or vice-versa. 

0   1   2    <----- 1 is made parent of 0 (1 is now representative of subset {0, 1})
1  -1  -1

_Edge 1-2:_ 1 is in subset 1 and 2 is in subset 2. So, take union.

0   1   2    <----- 2 is made parent of 1 (2 is now representative of subset {0, 1, 2})
1   2  -1

_Edge 0-2:_ 0 is in subset 2 and 2 is also in subset 2. Hence, including this edge forms a cycle.  
How subset of 0 is same as 2?   
0->1->2 // 1 is parent of 0 and 2 is parent of 1

```cpp
// A union-find algorithm to detect cycle in a graph
#include <bits/stdc++.h>
using namespace std;
 
// a structure to represent an edge in graph
class Edge
{
public:
    int src, dest;
};
 
// a structure to represent a graph
class Graph
{
public:
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges
    Edge* edge;
};
 
// Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph();
    graph->V = V;
    graph->E = E;
 
    graph->edge = new Edge[graph->E * sizeof(Edge)];
 
    return graph;
}
 
// A utility function to find the subset of an element i
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
 
// A utility function to do union of two subsets
void Union(int parent[], int x, int y)
{
    parent[x] = y;
}
 
// The main function to check whether a given graph contains
// cycle or not
int isCycle(Graph* graph)
{
    // Allocate memory for creating V subsets
    int* parent = new int[graph->V * sizeof(int)];
 
    // Initialize all subsets as single element sets
    memset(parent, -1, sizeof(int) * graph->V);
 
    // Iterate through all edges of graph, find subset of
    // both vertices of every edge, if both subsets are
    // same, then there is cycle in graph.
    for (int i = 0; i < graph->E; ++i) {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);
 
        if (x == y)
            return 1;
 
        Union(parent, x, y);
    }
    return 0;
}
 
// Driver code
int main()
{
    /* Let us create the following graph
        0
        | \
        |  \
        1---2 */
    int V = 3, E = 3;
    Graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
 
    if (isCycle(graph))
        cout << "graph contains cycle";
    else
        cout << "graph doesn't contain cycle";
 
    return 0;
}

```

**Output:** 

graph contains cycle


Note that the implementation of _union()_ and _find()_ is naive and takes O(n) time in the worst case. These methods can be improved to O(Logn) using _Union by Rank or Height_. We will soon be discussing _Union by Rank_ in a separate post.












-------------------
# 6. Minimum Spanning tree **Prim**

We have discussed [Kruskal’s algorithm for Minimum Spanning Tree](https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/). Like Kruskal’s algorithm, Prim’s algorithm is also a [Greedy algorithm](https://www.geeksforgeeks.org/archives/18528). It starts with an empty spanning tree. The idea is to maintain two sets of vertices. The first set contains the vertices already included in the MST, the other set contains the vertices not yet included. At every step, it considers all the edges that connect the two sets, and picks the minimum weight edge from these edges. After picking the edge, it moves the other endpoint of the edge to the set containing MST.   
A group of edges that connects two set of vertices in a graph is called [cut in graph theory](http://en.wikipedia.org/wiki/Cut_%28graph_theory%29). _So, at every step of Prim’s algorithm, we find a cut (of two sets, one contains the vertices already included in MST and other contains rest of the vertices), pick the minimum weight edge from the cut and include this vertex to MST Set (the set that contains already included vertices)._

_**How does Prim’s Algorithm Work?**_ The idea behind Prim’s algorithm is simple, a spanning tree means all vertices must be connected. So the two disjoint subsets (discussed above) of vertices must be connected to make a _Spanning_ Tree. And they must be connected with the minimum weight edge to make it a _Minimum_ Spanning Tree.

_**Algorithm**_   
**1)** Create a set _mstSet_ that keeps track of vertices already included in MST.   
**2)** Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign key value as 0 for the first vertex so that it is picked first.   
**3)** While mstSet doesn’t include all vertices   
….**a)** Pick a vertex _u_ which is not there in _mstSet_ and has minimum key value.   
….**b)** Include _u_ to mstSet.   
….**c)** Update key value of all adjacent vertices of _u_. To update the key values, iterate through all adjacent vertices. For every adjacent vertex _v_, if weight of edge _u-v_ is less than the previous key value of _v_, update the key value as weight of _u-v_  
The idea of using key values is to pick the minimum weight edge from [cut](http://en.wikipedia.org/wiki/Cut_(graph_theory)). The key values are used only for vertices which are not yet included in MST, the key value for these vertices indicate the minimum weight edges connecting them to the set of vertices included in MST.   
 

Let us understand with the following example:   
 

[![Prim’s Minimum Spanning Tree](https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg)](https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg)

  

  

The set _mstSet_ is initially empty and keys assigned to vertices are {0, INF, INF, INF, INF, INF, INF, INF} where INF indicates infinite. Now pick the vertex with the minimum key value. The vertex 0 is picked, include it in _mstSet_. So _mstSet_ becomes {0}. After including to _mstSet_, update key values of adjacent vertices. Adjacent vertices of 0 are 1 and 7. The key values of 1 and 7 are updated as 4 and 8. Following subgraph shows vertices and their key values, only the vertices with finite key values are shown. The vertices included in MST are shown in green color.

[![Prim’s Minimum Spanning Tree Algorithm 1](https://www.geeksforgeeks.org/wp-content/uploads/MST1.jpg)](https://www.geeksforgeeks.org/wp-content/uploads/MST1.jpg)

Pick the vertex with minimum key value and not already included in MST (not in mstSET). The vertex 1 is picked and added to mstSet. So mstSet now becomes {0, 1}. Update the key values of adjacent vertices of 1. The key value of vertex 2 becomes 8.  
 

[![Prim’s Minimum Spanning Tree Algorithm 2](https://www.geeksforgeeks.org/wp-content/uploads/MST2.jpg)](https://www.geeksforgeeks.org/wp-content/uploads/MST2.jpg)

Pick the vertex with minimum key value and not already included in MST (not in mstSET). We can either pick vertex 7 or vertex 2, let vertex 7 is picked. So mstSet now becomes {0, 1, 7}. Update the key values of adjacent vertices of 7. The key value of vertex 6 and 8 becomes finite (1 and 7 respectively).   
 

[![Prim’s Minimum Spanning Tree Algorithm 3](https://www.geeksforgeeks.org/wp-content/uploads/MST3.jpg)](https://www.geeksforgeeks.org/wp-content/uploads/MST3.jpg)

Pick the vertex with minimum key value and not already included in MST (not in mstSET). Vertex 6 is picked. So mstSet now becomes {0, 1, 7, 6}. Update the key values of adjacent vertices of 6. The key value of vertex 5 and 8 are updated.  
 

[![Prim’s Minimum Spanning Tree Algorithm 4](https://www.geeksforgeeks.org/wp-content/uploads/MST4.jpg)](https://www.geeksforgeeks.org/wp-content/uploads/MST4.jpg)

  

  

We repeat the above steps until _mstSet_ includes all vertices of given graph. Finally, we get the following graph.  
 

[![Prim’s Minimum Spanning Tree Algorithm 5](https://www.geeksforgeeks.org/wp-content/uploads/MST5.jpg)](https://www.geeksforgeeks.org/wp-content/uploads/MST5.jpg)



_**How to implement the above algorithm?**_   
We use a boolean array mstSet[] to represent the set of vertices included in MST. If a value mstSet[v] is true, then vertex v is included in MST, otherwise not. Array key[] is used to store key values of all vertices. Another array parent[] to store indexes of parent nodes in MST. The parent array is the output array which is used to show the constructed MST.


```cpp
// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph
#include <bits/stdc++.h>
using namespace std;
 
// Number of vertices in the graph
#define V 5
 
// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}
 
// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V])
{
    // Array to store constructed MST
    int parent[V];
     
    // Key values used to pick minimum weight edge in cut
    int key[V];
     
    // To represent set of vertices included in MST
    bool mstSet[V];
 
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST
 
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < V; v++)
 
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    // print the constructed MST
    printMST(parent, graph);
}
 
// Driver code
int main()
{
    /* Let us create the following graph
        2 3
    (0)--(1)--(2)
    | / \ |
    6| 8/ \5 |7
    | / \ |
    (3)-------(4)
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    // Print the solution
    primMST(graph);
 
    return 0;
}
```

**Output:** 

Edge   Weight
0 - 1    2
1 - 2    3
0 - 3    6
1 - 4    5


Time Complexity of the above program is O(V^2). If the input [graph is represented using adjacency list](https://www.geeksforgeeks.org/archives/27134), then the time complexity of Prim’s algorithm can be reduced to O(E log V) with the help of binary heap.













----------------
# 7. Minimum Spanning tree **Kruskal**

_**What is Minimum Spanning Tree?**_   
Given a connected and undirected graph, a _spanning tree_ of that graph is a subgraph that is a tree and connects all the vertices together. A single graph can have many different spanning trees. A _minimum spanning tree (MST)_ or minimum weight spanning tree for a weighted, connected, undirected graph is a spanning tree with a weight less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.  
_How many edges does a minimum spanning tree has?_   
A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph.   
_What are the applications of_ the _Minimum Spanning Tree?_   
See [this](https://www.geeksforgeeks.org/applications-of-minimum-spanning-tree/) for applications of MST.

Below are the steps for finding MST using Kruskal’s algorithm


**1.** Sort all the edges in non-decreasing order of their weight.   
**2.** Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.   
**3.** Repeat step#2 until there are (V-1) edges in the spanning tree.

Step #2 uses the [Union-Find algorithm](https://www.geeksforgeeks.org/union-find/) to detect cycles. So we recommend reading the following post as a prerequisite.   
[Union-Find Algorithm | Set 1 (Detect Cycle in a Graph)](https://www.geeksforgeeks.org/union-find/)   
[Union-Find Algorithm | Set 2 (Union By Rank and Path Compression)](https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/)  
The algorithm is a Greedy Algorithm. The Greedy Choice is to pick the smallest weight edge that does not cause a cycle in the MST constructed so far. Let us understand it with an example: Consider the below input graph.   
 

![Kruskal’s Minimum Spanning Tree Algorithm](https://media.geeksforgeeks.org/wp-content/uploads/20210727035309/UntitledDiagram92.png)

The graph contains 9 vertices and 14 edges. So, the minimum spanning tree formed will be having (9 – 1) = 8 edges. 

After sorting:

Weight   Src    Dest
1         7      6
2         8      2
2         6      5
4         0      1
4         2      5
6         8      6
7         2      3
7         7      8
8         0      7
8         1      2
9         3      4
10        5      4
11        1      7
14        3      5

Now pick all edges one by one from the sorted list of edges   
**1.** _Pick edge 7-6:_ No cycle is formed, include it.   
 

![Kruskal’s Minimum Spanning Tree Algorithm](https://media.geeksforgeeks.org/wp-content/uploads/20210727035707/UntitledDiagram100.png)

**2.** _Pick edge 8-2:_ No cycle is formed, include it.   
 

![Kruskal’s Minimum Spanning Tree Algorithm](https://media.geeksforgeeks.org/wp-content/uploads/20210727035650/UntitledDiagram99.png)

**3.** _Pick edge 6-5:_ No cycle is formed, include it.   
 

  

  

![Kruskal’s Minimum Spanning Tree Algorithm](https://media.geeksforgeeks.org/wp-content/uploads/20210727035627/UntitledDiagram98.png)

**4.** _Pick edge 0-1:_ No cycle is formed, include it.   
 

![Kruskal’s Minimum Spanning Tree Algorithm](https://media.geeksforgeeks.org/wp-content/uploads/20210727035604/UntitledDiagram97.png)

**5.** _Pick edge 2-5:_ No cycle is formed, include it.   
 

![Kruskal’s Minimum Spanning Tree Algorithm](https://media.geeksforgeeks.org/wp-content/uploads/20210727035542/UntitledDiagram96.png)

**6.** _Pick edge 8-6:_ Since including this edge results in the cycle, discard it.  
**7.** _Pick edge 2-3:_ No cycle is formed, include it.   
 

![Kruskal’s Minimum Spanning Tree Algorithm](https://media.geeksforgeeks.org/wp-content/uploads/20210727035519/UntitledDiagram95.png)

**8.** _Pick edge 7-8:_ Since including this edge results in the cycle, discard it.  
**9.** _Pick edge 0-7:_ No cycle is formed, include it.   
 

![Kruskal’s Minimum Spanning Tree Algorithm](https://media.geeksforgeeks.org/wp-content/uploads/20210727035450/UntitledDiagram94.png)

**10.** _Pick edge 1-2:_ Since including this edge results in the cycle, discard it.  
**11.** _Pick edge 3-4:_ No cycle is formed, include it.   
 

  

  

![Kruskal’s Minimum Spanning Tree Algorithm](https://media.geeksforgeeks.org/wp-content/uploads/20210727035418/UntitledDiagram93.png)

Since the number of edges included equals (V – 1), the algorithm stops here.

Below is the implementation of the above idea:

```cpp
#include <bits/stdc++.h>
using namespace std;
// DSU data structure
//  path compression + rank by union
 
class DSU
{
    int *parent;
    int *rank;
 
public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
 
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
 
    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = find(parent[i]);
    }
    // union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
 
        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};
 
class Graph
{
    vector<vector<int>> edgelist;
    int V;
 
public:
    Graph(int V)
    {
        this->V = V;
    }
 
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }
 
    int kruskals_mst()
    {
        // 1. Sort all edges
        sort(edgelist.begin(), edgelist.end());
 
        // Initialize the DSU
        DSU s(V);
        int ans = 0;
        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
 
            // take that edge in MST if it does form a cycle
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);
 
    // int n, m;
    // cin >> n >> m;
 
    // Graph g(n);
    // for (int i = 0; i < m; i++)
    // {
    //     int x, y, w;
    //     cin >> x >> y >> w;
    //     g.addEdge(x, y, w);
    // }
 
    cout << g.kruskals_mst();
    return 0;
}
```

**Output**

Following are the edges in the constructed MST
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10
Minimum Cost Spanning Tree: 19


**Time Complexity:** O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. After sorting, we iterate through all edges and apply the find-union algorithm. The find and union operations can take at most O(LogV) time. So overall complexity is O(ELogE + ELogV) time. The value of E can be at most O(V2), so O(LogV) is O(LogE) the same. Therefore, the overall time complexity is O(ElogE) or O(ElogV)

--------------
# 8. Topological Sort

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

For example, a topological sorting of the following graph is “5 4 2 3 1 0”. There can be more than one topological sorting for a graph. For example, another topological sorting of the following graph is “4 5 2 3 1 0”. The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).

[![graph](https://media.geeksforgeeks.org/wp-content/cdn-uploads/graph.png)](https://media.geeksforgeeks.org/wp-content/cdn-uploads/graph.png)

_**Topological Sorting vs Depth First Traversal (DFS)**_:

In [DFS](https://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/), we print a vertex and then recursively call DFS for its adjacent vertices. In topological sorting, we need to print a vertex before its adjacent vertices. For example, in the given graph, the vertex ‘5’ should be printed before vertex ‘0’, but unlike [DFS](https://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/), the vertex ‘4’ should also be printed before vertex ‘0’. So Topological sorting is different from DFS. For example, a DFS of the shown graph is “5 2 3 1 0 4”, but it is not a topological sorting.

**Algorithm to find Topological Sorting:** 

We recommend to first see the implementation of [DFS](https://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/). We can modify [DFS](https://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/) to find Topological Sorting of a graph. In [DFS](https://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/), we start from a vertex, we first print it and then recursively call DFS for its adjacent vertices. In topological sorting, we use a temporary stack. We don’t print the vertex immediately, we first recursively call topological sorting for all its adjacent vertices, then push it to a stack. Finally, print contents of the stack. Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack. 

Below image is an illustration of the above approach:

![Topological-Sorting](https://media.geeksforgeeks.org/wp-content/uploads/20200818211917/Topological-Sorting-1.png)

Following are the implementations of topological sorting.

```cpp
// A C++ program to print topological
// sorting of a DAG
#include <iostream>
#include <list>
#include <stack>
using namespace std;
 
// Class to represent a graph
class Graph {
    // No. of vertices'
    int V;
 
    // Pointer to an array containing adjacency listsList
    list<int>* adj;
 
    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[],
                             stack<int>& Stack);
 
public:
    // Constructor
    Graph(int V);
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints a Topological Sort of
    // the complete graph
    void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}
 
// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int>& Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    // Push current vertex to stack
    // which stores result
    Stack.push(v);
}
 
// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
 
// Driver Code
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given "
            "graph \n";
 
    // Function Call
    g.topologicalSort();
 
    return 0;
}

```


**Output**

Following is a Topological Sort of the given graph 
5 4 2 3 1 0


**Complexity Analysis:** 

-   **Time Complexity:** O(V+E).   
    The above algorithm is simply DFS with an extra stack. So time complexity is the same as DFS which is.
-   **Auxiliary space:** O(V).   
    The extra space is needed for the stack.

**Note:** Here, we can also use vector instead of the stack. If the vector is used then print the elements in reverse order to get the topological sorting.

**Applications:**   
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. In computer science, applications of this type arise in instruction scheduling, ordering of formula cell evaluation when recomputing formula values in spreadsheets, logic synthesis, determining the order of compilation tasks to perform in make files, data serialization, and resolving symbol dependencies in linkers










------------------

# 9. Boggle (Find all possible words in a board of characters)



Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.  
**Example:**   
 

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G', 'I', 'Z'},
                       {'U', 'E', 'K'},
                       {'Q', 'S', 'E'}};
      isWord(str): returns true if str is present in dictionary
                   else false.

Output:  Following words of dictionary are present
         GEEKS
         QUIZ


![Boggle](https://www.geeksforgeeks.org/wp-content/uploads/Boggle.png)


The idea is to consider every character as a starting character and find all words starting with it. All words starting from a character can be found using [Depth First Traversal](https://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/). We do depth first traversal starting from every cell. We keep track of visited cells to make sure that a cell is considered only once in a word.


```cpp
// C++ program for Boggle game
#include <cstring>
#include <iostream>
using namespace std;
 
#define M 3
#define N 3
 
// Let the given dictionary be following
string dictionary[] = { "GEEKS", "FOR", "QUIZ", "GO" };
int n = sizeof(dictionary) / sizeof(dictionary[0]);
 
// A given function to check if a given string is present in
// dictionary. The implementation is naive for simplicity. As
// per the question dictionary is given to us.
bool isWord(string& str)
{
    // Linearly search all words
    for (int i = 0; i < n; i++)
        if (str.compare(dictionary[i]) == 0)
            return true;
    return false;
}
 
// A recursive function to print all words present on boggle
void findWordsUtil(char boggle[M][N], bool visited[M][N], int i,
                   int j, string& str)
{
    // Mark current cell as visited and append current character
    // to str
    visited[i][j] = true;
    str = str + boggle[i][j];
 
    // If str is present in dictionary, then print it
    if (isWord(str))
        cout << str << endl;
 
    // Traverse 8 adjacent cells of boggle[i][j]
    for (int row = i - 1; row <= i + 1 && row < M; row++)
        for (int col = j - 1; col <= j + 1 && col < N; col++)
            if (row >= 0 && col >= 0 && !visited[row][col])
                findWordsUtil(boggle, visited, row, col, str);
 
    // Erase current character from string and mark visited
    // of current cell as false
    str.erase(str.length() - 1);
    visited[i][j] = false;
}
 
// Prints all words present in dictionary.
void findWords(char boggle[M][N])
{
    // Mark all characters as not visited
    bool visited[M][N] = { { false } };
 
    // Initialize current string
    string str = "";
 
    // Consider every character and look for all words
    // starting with this character
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            findWordsUtil(boggle, visited, i, j, str);
}
 
// Driver program to test above function
int main()
{
    char boggle[M][N] = { { 'G', 'I', 'Z' },
                          { 'U', 'E', 'K' },
                          { 'Q', 'S', 'E' } };
 
    cout << "Following words of dictionary are present\n";
    findWords(boggle);
    return 0;
}
```


**Output**

Following words of dictionary are present
GEEKS
QUIZ

Note that the above solution may print the same word multiple times. For example, if we add “SEEK” to the dictionary, it is printed multiple times. To avoid this, we can use hashing to keep track of all printed words.


In below set 2, we have discussed Trie based optimized solution:   
[**Boggle | Set 2 (Using Trie)**](https://www.geeksforgeeks.org/boggle-set-2-using-trie/)










--------------
# 10. Bridges in a Graph

An edge in an undirected connected graph is a bridge iff removing it disconnects the graph. For a disconnected undirected graph, definition is similar, a bridge is an edge removing which increases number of disconnected components.   
Like [Articulation Points](https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/), bridges represent vulnerabilities in a connected network and are useful for designing reliable networks. For example, in a wired computer network, an articulation point indicates the critical computers and a bridge indicates the critical wires or connections.

Following are some example graphs with bridges highlighted with red color.


![Bridge1](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Bridge1.png)![Bridge2](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Bridge2-300x176.png)![Bridge3](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Bridge3.png)

  

  

**How to find all bridges in a given graph?**   
A simple approach is to one by one remove all edges and see if removal of an edge causes disconnected graph. Following are steps of simple approach for connected graph.  
1) For every edge (u, v), do following   
…..a) Remove (u, v) from graph   
..…b) See if the graph remains connected (We can either use BFS or DFS)   
…..c) Add (u, v) back to the graph.  
Time complexity of above method is O(E*(V+E)) for a graph represented using adjacency list. Can we do better?

**A O(V+E) algorithm to find all Bridges**   
The idea is similar to [O(V+E) algorithm for Articulation Points](https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/). We do DFS traversal of the given graph. In DFS tree an edge (u, v) (u is parent of v in DFS tree) is bridge if there does not exist any other alternative to reach u or an ancestor of u from subtree rooted with v. As discussed in the [previous post](https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/), the value low[v] indicates earliest visited vertex reachable from subtree rooted with v. _The condition for an edge (u, v) to be a bridge is, “low[v] > disc[u]”_. 

Following are the implementations


```cpp
// A C++ program to find bridges in a given undirected graph
#include<iostream>
#include <list>
#define NIL -1
using namespace std;
 
// A class that represents an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
    void bridgeUtil(int v, bool visited[], int disc[], int low[],
                    int parent[]);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    void bridge();    // prints all bridges
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}
 
// A recursive function that finds and prints bridges using
// DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
void Graph::bridgeUtil(int u, bool visited[], int disc[],
                                  int low[], int parent[])
{
    // A static variable is used for simplicity, we can
    // avoid use of static variable by passing a pointer.
    static int time = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices adjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
 
        // If v is not visited yet, then recur for it
        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);
 
            // Check if the subtree rooted with v has a
            // connection to one of the ancestors of u
            low[u]  = min(low[u], low[v]);
 
            // If the lowest vertex reachable from subtree
            // under v is  below u in DFS tree, then u-v
            // is a bridge
            if (low[v] > disc[u])
              cout << u <<" " << v << endl;
        }
 
        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 
// DFS based function to find all bridges. It uses recursive
// function bridgeUtil()
void Graph::bridge()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
 
    // Initialize parent and visited arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }
 
    // Call the recursive helper function to find Bridges
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}
 
// Driver program to test above function
int main()
{
    // Create graphs given in above diagrams
    cout << "\nBridges in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.bridge();
 
    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.bridge();
 
    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.bridge();
 
    return 0;
}
```

Output: 

Bridges in first graph
3 4
0 3

Bridges in second graph
2 3
1 2
0 1

Bridges in third graph
1 6

**Time Complexity:** The above function is simple DFS with additional arrays. So time complexity is same as DFS which is O(V+E) for adjacency list representation of graph.

---------------













