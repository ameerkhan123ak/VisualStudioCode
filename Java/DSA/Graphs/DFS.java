import java.util.*;

import javax.print.attribute.HashPrintJobAttributeSet;

public class DFS 
{
    public static void addEdge(ArrayList<ArrayList<Integer>> adj,int u,int v)
    {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }
    public static void dfs(ArrayList<ArrayList<Integer>> adj,boolean[] visited,int v)
    {
        visited[v] = true;
        System.out.print(v + " ");
        for(int i=0;i<adj.get(v).size();i++)
        {
            int vertex = adj.get(v).get(i);
            if(!visited[vertex])
            {
                dfs(adj, visited, vertex);
            }
        }
    }
    public static void DepthFirstSearch(ArrayList<ArrayList<Integer>> adj,int v)
    {
        int V = adj.size();
        boolean[] visited = new boolean[V];
        dfs(adj,visited,v);
    }
    public static void main(String[] args)
    {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        int n = 5;
        for(int i=0;i<n;i++) adj.add(new ArrayList<Integer>());
        addEdge(adj, 0, 1);
        addEdge(adj, 0, 4);
        addEdge(adj, 1, 2);
        addEdge(adj, 1, 3);
        addEdge(adj, 1, 4);
        addEdge(adj, 2, 3);
        addEdge(adj, 3, 4);
        DepthFirstSearch(adj, 0);
        HashMap<Integer,Integer> m = new HashMap<>();
    }
}