#include <ext/pb_ds/priority_queue.hpp>
using __gnu_pbds::priority_queue;

struct node{
	int to, dist;
	node (int to0 = 0, int dist0 = 0): to(to0), dist(dist0) {}
	inline bool operator < (const node &b) const {return dist > b.dist;}
};

priority_queue <node> pq;

void Dijkstra(int s){
	int i, y; node t;
	for(i = 1; i <= V; i++) d[i] = (i == s ? 0 : INF);
	for(pq.push(node(s, 0)); !pq.empty(); ){
		t = pq.top(); pq.pop();
		if(d[t.to] < t.dist) continue;
		for(i = first[t.to]; i; i = next[i])
			if(t.dist + e[i].w < d[y = e[i].v]){
				d[y] = t.dist + e[i].w;
				pq.push(node(y, d[y]));
			}
	}
}