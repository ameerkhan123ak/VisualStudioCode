#include <bits/stdc++.h>
using namespace std;

map<string, int> status;
vector<string> nodes;
int n, m, apis, ind;

// Locking function
string lock(string name)
{
	ind = find(nodes.begin(), nodes.end(), name) - nodes.begin() + 1;
	int c1 = ind * 2, c2 = ind * 2 + 1;
	if (status[name] == 1 || status[name] == 2)
		return "false";
	else {
		int p = ind / 2;
		status[nodes[p - 1]] = 2;
		status[name] = 1;
		return "true";
	}
}

// Unlocking function
string unlock(string name)
{
	if (status[name] == 1) {
		status[name] = 0;
		return "true";
	}
	else
		return "false";
}

// Upgrade function
string upgrade(string name)
{
	ind = find(nodes.begin(), nodes.end(), name) - nodes.begin() + 1;

	// left child of ind
	int c1 = ind * 2;

	// right child of ind
	int c2 = ind * 2 + 1;
	if (c1 >= 1 && c1 < n && c2 >= 1 && c2 < n) {
		if (status[nodes[c1 - 1]] == 1 && status[nodes[c2 - 1]] == 1) {
			status[nodes[c1 - 1]] = 0;
			status[nodes[c2 - 1]] = 0;
			status[nodes[ind - 1]] = 1;
			return "true";
		}
		else
			return "false";
	}
    return "false";
}

// Function to perform operations
string operation(string name, int code)
{
	string result = "false";

	// Choose operation to perform
	if (code == 1)
		result = lock(name);
	else if (code == 2)
		result = unlock(name);
	else if (code == 3)
		result = upgrade(name);
	return result;
}

int main()
{
	// Given Input
	// n = 7;
	// m = 2;
	// apis = 5;
    cin>>n;
    cin>>m;
    cin>>apis;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        nodes.push_back(s);
    }
    
    vector<pair<int,string>> queries;
    while(apis--)
    {
        int choice;
        string place;
        int id;
        cin>>choice;
        cin>>place;
        cin>>id;
        queries.push_back(make_pair(choice,place));
    }

	for (auto q : queries)
		status[q.second] = 0;

	// Function Call
	for (auto q : queries)
		cout << operation(q.second, q.first) << " ";
}

// nodes = { "World", "Asia",	 "Africa", "China",
	// 		"India", "SouthAfrica", "Egypt" };
	// vector<pair<int, string> > queries = { { 1, "China" },
	// 									{ 1, "India" },
	// 									{ 3, "Asia" },
	// 									{ 2, "India" },
	// 									{ 2, "Asia" }};
    // int x; 
    // string y;

// for(auto i: nodes) cout<<i<<" ";
    // cout<<endl;

    // for(auto i: queries)
    // {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    // Precomputation
