import java.util.*;

public class BFS 
{
    public static void addEdge(ArrayList<ArrayList<Integer>> adj,int u,int v)
    {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }
    public static void printAdjList(ArrayList<ArrayList<Integer>> adj,int n)
    {
        for(int i=0;i<n;i++)
        {
            System.out.print(i + ": ");
            for(int j=0;j<adj.get(i).size();j++)
            {
                System.out.print(adj.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }
    public static void BreadthFirstSearch(ArrayList<ArrayList<Integer>> adj,int v)
    {
        int V = adj.size();
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[V];
        visited[v] = true;
        q.add(v);
        while(!q.isEmpty())
        {
            int vertex = q.remove();
            System.out.print(vertex + " ");
            for(int i=0;i<adj.get(vertex).size();i++)
            {
                int adjVertex = adj.get(vertex).get(i);
                if(!visited[adjVertex])
                {
                    visited[adjVertex] = true;
                    q.add(adjVertex);
                }
            }
        }
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
        printAdjList(adj, n);
        //BreadthFirstSearch(adj, 0);
    }
}