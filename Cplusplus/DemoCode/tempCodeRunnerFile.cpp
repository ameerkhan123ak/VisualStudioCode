Graph g1(5);
	g1.addEdge(0,1);
	g1.addEdge(1,2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
    if(g1.isCyclic()) cout<<"Cycle";
    else cout<<"Not cycle";