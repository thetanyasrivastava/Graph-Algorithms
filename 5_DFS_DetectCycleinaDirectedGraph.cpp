//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

//T.C. = O(V+E)
//S.C. = O(2V)
//A.S.S. = O(V)


class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    vector<bool> vis(V,false);
	    vector<bool> dfsVis(V,false); 
	    // to find if the node is visited in the current movement/dfs or not
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            if(dfs(i,adj,vis,dfsVis))
	                return true;
	        }
	    }
	    
	    return false;
	}
	
	bool dfs(int s,vector<int> adj[],vector<bool> &vis,vector<bool> &dfsVis)
	{
	    vis[s]=true;
	    dfsVis[s]=true;
	    
	    for(auto x: adj[s])
	    {
	        if(!vis[x])
	        {
	            if(dfs(x,adj,vis,dfsVis))
	                return true;
	        }
	        else if(dfsVis[x])      //vis[x]=1 & dfsVis[x]=1
	            return true;
	    }
	    
	    dfsVis[s]=false;
	    return false;
	}
};
