//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

//DFS

class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> vis(V,false);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            if(dfs(i,adj,vis,V,-1))
	                   return true;
	        }
	    }
	    return false;
	}
  
bool dfs(int start,vector<int> adj[],vector<bool> vis,int V,int parent)
{
    vis[start]=true;
    
    for(auto x:adj[start])
    {
        if(!vis[x]){
            if(dfs(x,adj,vis,V,start))
                return true;
        }
        else if(x!=parent)
            return true;
    }
    return false;
  }
};
