#include "graph.h"

// Resets all of visited to false before calling dfs
void Graph::cave_search(int s)
{
    for(int i = 0; i < nodes; i++) visited[i] = false;
    cs(s);
}

void Graph::cs(int s) 
{
	if(visited[s]) return;
	
	if(caves[s] == "end") {
	    count++; 
	    return;
	}

    //if it is a small cave, only allow visits once	
    //but if it is special then let it go twice
    bool doublevisited = false;
    
	if(!isupper(caves[s][0])) {
	    if(caves[s] == special && doublevisit == false) {
	        doublevisit = true;
	        doublevisited = true;
	    } else {
    	    visited[s] = true;
	    }
	}
	
	//process node s
	std::cout << caves[s] << "\t";
	for(auto u: adj[s]) {
		cs(u);	
	}
	
	//ask andy to show you later or he gets a fade
	visited[s] = false;

    if(doublevisited) {
        doublevisit = false;
    }	
}
