import java.util.*;

public class GraphsRepresentation
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
    }
}