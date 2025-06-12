#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int dest;
    Node* next;
};

struct Graph{
    int V;
    Node** adjList;
};

Node* createNode(int dest){
    Node* newNode = new Node();
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V){
    Graph* graph = new Graph();
    graph->V = V;
    graph->adjList = new Node*[V];
    for (int i=0; i<V; i++){
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest){
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[dest];
    graph->adjList[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(Graph* graph){
    for (int i=0; i<graph->V; i++){
        Node* temp = graph->adjList[i];
        cout << "顶点 " << i << " 的邻接表：" << endl;
        while (temp){
            cout << temp->dest << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

int main(){
    int V = 5;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    system("pause");
    return 0;
}