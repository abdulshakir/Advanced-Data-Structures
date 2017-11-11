#include<bits/stdc++.h>
using namespace std;
class shortestpath
{
public:
	int size;
	
	
	shortestpath(int a)
	{
		size=a;
		v=new vector<pair<int,int> >[size];
		dist=new int[size];
		vis=new bool[size];
	}
	
	
	vector < pair < int , int > >* v;   // each vertex has all the connected vertices with the edges weights
int* dist ;
bool* vis ;
	
	
	
void giveedge(int a,int b,int w)
{
	pair<int,int> p=make_pair(a,w);
		v[b].push_back(p);
		p=make_pair(b,w);
		v[a].push_back(p);
				
} 
	
	

int dijkstra(int a,int b){
         
		 for(int j=0;j<size;j++)
			dist[j]=100000000;	
		                                        // set the vertices distances as infinity
    memset(vis, false , sizeof vis);            // set all vertex as unvisited
    dist[a] = 0;
    multiset < pair < int , int > > s;          // multiset do the job as a min-priority queue

    s.insert(make_pair(0 , a));                          // insert the source node with distance = 0

    while(!s.empty()){

        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.second; int wei = p.first;
        if( vis[x] ) continue;                  // check if the popped vertex is visited before
         vis[x] = true;

        for(int i = 0; i < v[x].size(); i++){
            int e = v[x][i].first; int w = v[x][i].second;
            if(dist[x] + w < dist[e]  ){            // check if the next vertex distance could be minimized
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
            }
        }
    }
    
    return dist[b];
}

};



