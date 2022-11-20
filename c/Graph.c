/*
* coding = utf-8
* @Author : Khalil Chen
* @Created Time : 2022-11-01 20:57:02
* @Description : */
#include "stdlib.h" 
#include "stdio.h" 
#include "S2Q.h"
#define PL printf("\n");

/*
* @Description: defination of Graph:adj list
* @Arguments:
* @Return: 
*/
#define MAXSIZE 100
//define arc node
typedef struct ArcNode{
	int val; struct ArcNode *next;
	int weight;
}ArcNode;

//define vertex node 
typedef struct VNode{
	int val;
	ArcNode *firstarc;
}VNode, AdjList[MAXSIZE];


//define Graph
typedef struct{
	AdjList verts;
	int vcnt,acnt;
}ALGraph,*Graph;

/*
* @Description: construct graph instance by adj list
* @Arguments:
* @Return: 
*/
Graph ConstructALGraph(){
	Graph g = (Graph )malloc(sizeof(ALGraph));
	printf("input the number of vcnt and acnt\n");
	scanf("%d %d", &(g->vcnt), &(g->acnt));

	//input the vertex node val
	printf("input the vertex node val, the val should be same of index of Adjlist, like : 0,1,2,3,4!\n");
	for(int i = 0;i < g->vcnt; i++){
		scanf("%d", &g->verts[i].val);
		g->verts[i].firstarc = NULL;
	}

	//input the arc list, insert from head
	ArcNode *p;
	int e; int s;
	printf("input the arc list: start and end vnode from arc!\n");
	for(int i = 0;i < g->acnt; i++){
		scanf("%d %d", &s, &e);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->val = e;
		p->next = g->verts[s].firstarc;
		g->verts[s].firstarc = p;
	}
	return g;

}
/* * @Description: print the Graph which stored in arr of list
* @Arguments:
* @Return: 
*/
void printGraph(Graph g){
	for(int i = 0; i < g->vcnt; i++){
		printf("%d->", g->verts[i].val);
		ArcNode *p = g->verts[i].firstarc;
		while(p){
			printf("%d->", p->val);
			p = p->next;
		}
		printf("NULL\n");
	}
}

/*
* @Description: reverse the adjlist of Graph into new Graph
* @Arguments: Graph, Graph
* @Return: 
*/
void ReverseAdj(Graph g1, Graph g2){
	//input vnode arr
	g2->vcnt = g1->vcnt;
	g2->acnt = g1->acnt;

	printf("input the node of g2!\n");
	for(int i = 0; i < g2->vcnt; ++i){
		scanf("%d", &g2->verts[i].val);
		g2->verts[i].firstarc = NULL;
	}

	//reverse the end and start of every ArcNode
	for(int s = 0; s < g1->vcnt; ++s){
		ArcNode *p = g1->verts[s].firstarc;
		while(p){
			//head insert
			int e = p->val;
			ArcNode *nn = (ArcNode *)malloc(sizeof(ArcNode));
			nn->val = s; 
			nn->next = g2->verts[e].firstarc;
			g2->verts[e].firstarc = nn;
			p = p->next;
		}
	}
}
/*
* @Description: DFS of Graph which stored in arr of list
* @Arguments: Graph
* @Return: 
*/
//consistent sequence used
int visited[MAXSIZE] = {0};
void ClearVisited(){
	for(int i = 0; i < MAXSIZE; ++i)visited[i] = 0;
}
//dfs
void DFS(Graph g, int i){
	//root
	if(visited[i])return;
	visited[i] = 1;

	//neighbors
	ArcNode *p = g->verts[i].firstarc;
	while(p){
		int neighbor = p->val;
		DFS(g, neighbor);
		p = p->next;
	}

}

//traverse: 不是每个图都是完全连通的
void Dtraverse(Graph g){
	for(int i = 0;i < g->vcnt; ++i){
		if(!visited[i])DFS(g, i);
	}
	ClearVisited();
}

/*
* @Description: 求连通分量
* @Arguments: Graph
* @Return: int
*/
int LinkCnt(Graph g){
	int lcnt = 0;
	for(int i = 0; i < g->vcnt; ++i){
		if(!visited[i]){
			DFS(g, i);
			lcnt++;
		}
	}
	ClearVisited();
	return lcnt;
}

/*
* @Description: BFS of Graph which stored in arr of list
* @Arguments: Graph, int
* @Return: 
*/

void BFS(Graph g, int i){
	//like level traverse in tree
	queue *q = Queue();
	InQueue(q,(void*)i);
	visited[i] = 1;
	while(q->front != q->near){
		//Dequeue
		int cur = (int)DeQueue(q);
		//Inqueue
		ArcNode *p = g->verts[cur].firstarc;
		while(p){
			int neighbor = p->val;
			if(!visited[neighbor]){
				visited[neighbor] = 1;
				InQueue(q, (void*)(neighbor));
			}
			p = p->next;
		}
	}	
}

void Btraverse(Graph g){
	for(int i = 0; i < g->vcnt; ++i){
		if(!visited[i])BFS(g, i);
	}
	ClearVisited();

}
/*
* @Description: find the shortest race 
* @Arguments: Graph ,int ,int
* @Return: 
*/
//这里是有向无权图，第一次访问一定是最短的，如果是无向图只要一次，如果是有权图还得更新或者使用Dijkstra
int distance[MAXSIZE] = {0};
void ClearDisance(){
	for(int i = 0; i < MAXSIZE; ++i)distance[i] = 0;
}
void FindShortestRaceBtraverse(Graph g, int a, int b){
	queue *q = Queue();
	InQueue(q,(void*)a);
	while(q->front != q->near){
		//Dequeue
		int cur = (int)DeQueue(q);
		
		//Inqueue
		ArcNode *p = g->verts[cur].firstarc;
		while(p){ int neighbor = p->val;
			if(!visited[neighbor]){
				visited[neighbor] = 1;
				distance[neighbor]= distance[cur]+1;
				InQueue(q, (void*)neighbor);
			}
			p = p->next;
		}
	}

}
void FindShortestRace(Graph g, int a, int b){
	FindShortestRaceBtraverse(g, a, b);
	if(!visited[b]){
		ClearVisited();
		ClearDisance();	
		FindShortestRaceBtraverse(g, b, a);
	}else{
		printf("shortest race from %d->%d: %d\n", a, b, distance[b]);
		goto Clear;
	}

	if(!visited[a]){
		printf("no race between %d and %d!\n", a, b);
	}else{
		printf("shortest race from %d->%d: %d\n", b, a, distance[a]);
	}
Clear:
	ClearDisance();
	ClearVisited();
}

void GraphTest(){
	printf("Test Graph function:---------------\n");
	Graph g1 = ConstructALGraph();
	//Graph g2 = (Graph)malloc(sizeof(ALGraph)); 
	printf("    print g1:\n");
	printGraph(g1); PL
	//test function
	FindShortestRace(g1, 0, 2);
	//pirnt the result
	/*printf("\n    print g1g2:\n");
	printGraph(g1);
	PL
	printGraph(g2);
	PL*/
	printf("Test Graph finished:---------------\n");
}

int main(int argc, char **argv){
	GraphTest();
	return 0;
}
