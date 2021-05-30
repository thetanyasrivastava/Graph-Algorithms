//https://practice.geeksforgeeks.org/problems/topological-sort/1

//T.C. = O(N+E)
//S.C. = O(N) + O(N)
//A.S.C. = O(N)

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> s;
	    vector<bool> vis(V,false);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,adj,vis,s);
	        }
	    }
	    
	    vector<int> res;
	    while(!s.empty())
	    {
	        int curr=s.top();
	        s.pop();
	        res.push_back(curr);
	    }
	    
	    return res;
	}
	
	void dfs(int node,vector<int> adj[],vector<bool> &vis,stack<int> &s)
	{
	    vis[node]=true;
	    
	    for(auto x: adj[node])
	    {
	        if(!vis[x])
	            dfs(x,adj,vis,s);
	    }
	    s.push(node);
	}
	};
