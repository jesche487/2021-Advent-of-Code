#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph
{
public:
    // Constructor dynamically creates the necessary vectors and arrays
	Graph(int n, vector<string> globalcaves) : nodes(n)
	{
		adj = new std::vector<int> [nodes];
		visited = new bool[nodes];
		caves = globalcaves;
		
		doublevisit = false;
		
		count = 0;
	}
	
	// Adds an edge to the adjancency list
	void add_edge(int i, int j) { adj[i].push_back(j);}

    // Prints each edge in the graph
	void print() 
	{
	    for(int i = 0; i < nodes; i++) 
	    {
		    for(auto e : adj[i]) 
		    { 
		        cout << "(" << i << "," << e  << ")" << endl; 
		    }
	    }
	    
	    for(int i = 0; i < caves.size(); i++) {
	        cout << "node " << i << " " << caves[i] << endl;
	    }
	    
	    cout << "count: " << count << endl;
	}

    void set_special(string str) { special = str; }
    int get_nodes() { return nodes; }
    bool empty(int n) { return adj[n].empty(); }
  
    // Helper function for dfs
    void cave_search(int s);
	void cs(int);

private:
    int nodes;
	std::vector<int>* adj;
	bool *visited;
	
	string special;
	bool doublevisit;
	
	queue<int> q;
	vector<string> caves;
	int count;
};