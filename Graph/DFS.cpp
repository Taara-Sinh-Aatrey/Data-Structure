#include<stdio.h>
#include<stdlib.h>

typedef struct vector
{
	int *arr;
	int size;
	int capacity;
}vector;

void push_back(vector *v,int val)
{
	if(v->size == v->capacity)
	{
		v->capacity *= 2;
		v->arr = (int*)realloc(v->arr,v->capacity*sizeof(int));
	}
	v->arr[v->size] = val;
	v->size++;
}

void pop_back(vector *v)
{
	v->size--;
	if(v->capacity == 2*v->size)
	{
		v->capacity /= 2;
		v->arr = (int*)realloc(v->arr,v->capacity*sizeof(int));
	}
}


typedef struct graph
{
	int V;   // Nodes from 0 to V-1
	vector *adj;
}graph;

graph* createGraph(int v)
{
	graph* g = (graph*)malloc(sizeof(graph));
	g->V = v;
	g->adj = (vector*)malloc(sizeof(vector)*v);
	int i = 0;
	for(i = 0; i < v; i++)
	{
		g->adj[i].arr = (int *)malloc(sizeof(int)*2);
		g->adj[i].size = 0;
		g->adj[i].capacity = 2;
	}
	return g;
}

void addEdge(graph *g,int u,int v)
{
	push_back(&(g->adj[u]),v);
	push_back(&(g->adj[v]),u);
}

void DFS(graph *g,int u,int vis[])
{
	vis[u] = 1;
	printf("%d ",u);
	int i = 0;
	for(i = 0; i < g->adj[u].size; i++)
	{
		if(!vis[g->adj[u].arr[i]])
		DFS(g,g->adj[u].arr[i],vis);
	}
}

int main()
{
	graph* g = createGraph(7);
	addEdge(g,0,1);
	addEdge(g,0,3);
	addEdge(g,1,3);
	addEdge(g,1,2);
	addEdge(g,1,5);
	addEdge(g,1,6);
	addEdge(g,2,4);
	addEdge(g,2,5);
	addEdge(g,4,6);

	// DFS 
    int vis[g->V] = {};
	DFS(g,0,vis);
}