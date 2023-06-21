package Trees;
class BinarySearchTree 
{
	class Node
	{
		int key;
		Node left=null;
		Node right=null;
		
		Node(int key)
		{
			this.key = key;
			left =  right  = null;
		}
	}
	Node root;
	
	public BinarySearchTree()
	{
		root=null;
	}
	
	public BinarySearchTree(int val)
	{
		root = new Node(val);
	}
	public void insert(int val) 
	{
		insert(root,val);
	}
	public Node insert(Node root,int val)
	{
		if(root==null)
			return new Node(val);
		if(val < root.key)
			root.left = insert(root.left,val);
		else 
			root.right = insert(root.right,val);
		return root;
	}
	public Node search(Node root,int val)
	{
		if(root==null || root.key == val) return root;
		
		if(val < root.key) search(root.left,val);
		
		return search(root.right,val);
		
	}
	public void inorderTraversal(Node root)
	{
		if(root==null) return; 
		inorderTraversal(root.left);
		System.out.print(root.key + " ");
		inorderTraversal(root.right);
	}
	/*
	 * Deletion Scenarios:
	 * Leaf Node: Make the parent point to null
	 * Node with one child: Link the one child to the parent
	 * Node with two children: Replace the node to be deleted with its
	 *                         inorder successor. then delete that 
	 *                         inorder successor from its right subtree
	 */
	 public Node delete(Node root,int val)
	 {
		 if(root==null) return root;
		 if(val < root.key) 
			 root.left = delete(root.left,val);
		 else if(val > root.key)
			 root.right = delete(root.right,val);
		 else
		 {
			 if(root.left == null)
				 return root.right;
			 else if(root.right == null)
				 return root.left;
			 root.key = min(root.right);
			 root.right = delete(root.right,root.key);
		 }
		 return root;
	 }
	 public int min(Node root)
	 {
		 int minVal = root.key;
		 while(root.left != null)
		 {
			 minVal = root.left.key;
			 root = root.left;
		 }
		 return minVal;
	 }
}

public class BinarySearchTrees
{
	public static void main(String[] args)
	{
		BinarySearchTree b = new BinarySearchTree(50);
		b.insert(20);
		b.insert(70);
		b.insert(10);
		b.insert(25);
		b.insert(60);
		b.insert(90);
		b.inorderTraversal(b.root); System.out.println();
		b.delete(b.root,70);
		b.inorderTraversal(b.root);
	}
}