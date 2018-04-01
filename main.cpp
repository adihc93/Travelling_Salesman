#include <iostream>

#include <bits/stdc++.h>
using namespace std;
#define V 10
int graph[V][V],n;
//getting graph
void get()
{
	cout<<"Enter No. of Cities: ";
	cin>>n;
	cout<<"\nEnter Cost Matrix\n";
	for(int i=0;i < n;i++)
	{
		cout<<"\nEnter Elements of Row # : "<<i+1<<endl;
		for( int j=0;j < n;j++)
			cin>>graph[i][j];
	}
	cout<<"\n\nThe cost list is:\n\n";
	for( int i=0;i < n;i++)
	{
		cout<<"\n\n";
		for(int j=0;j < n;j++)
			cout<<"\t"<<graph[i][j];
	}
}

// implementation of traveling Salesman Problem
int travllingSalesmanProblem()
{
    int path_curr[V];
    int path_min[V];
    int s = 0;

    vector<int> vertex;
    for (int i = 0; i < n; i++)
        if (i != s)
            vertex.push_back(i);

    int min_path = INT_MAX;
    do {

        int current_pathweight = 0;

        int k = s;
        path_curr[0]=k+1;

        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
            path_curr[i+1]=k+1;
        }


        current_pathweight += graph[k][s];

        if(min_path>current_pathweight){
            min_path=current_pathweight;
            for(int i=0; i<n; i++){
                path_min[i]=path_curr[i];
            }
        }

    } while (next_permutation(vertex.begin(), vertex.end()));
    cout<<"\n\nOptimum Path: ";
    for(int i=0; i<n; i++){
        cout<<path_min[i]<<"->";
    }
    cout<<s+1<<endl;

    return min_path;
}

int main()
{
    get();
    cout <<"Optimum Cost: "<< travllingSalesmanProblem() << endl;
    return 0;
}
