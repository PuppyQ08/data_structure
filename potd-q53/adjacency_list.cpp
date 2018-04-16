#include <iostream>
#include <string>
#include "adjacency_list.h"
using namespace std;

bool containsEdge(Graph const * const g, int src, int dest) {
        // Your code here
        if(g != NULL && src < g->n){
        LinkedListNode * idx = g->adjLists[src].edges;
        while(idx != NULL){
          if(idx->v == dest) return true;
          idx = idx->next;
        }
      }
      return false;
}

void addEdge(Graph* g, int src, int dest) {
        // Your code here
        if(containsEdge(g,src,dest)) return;
        else
          if(g != NULL && src < g->n){
          LinkedListNode * srcidx = g->adjLists[src].edges;
          //update src
          if(srcidx != NULL){
          while(srcidx->next != NULL){
            srcidx = srcidx->next;
          }
          srcidx->next = new LinkedListNode();
          srcidx->next->next = NULL;
          srcidx->next->v = dest;
        }
          else{
            g->adjLists[src].edges = new LinkedListNode();
            g->adjLists[src].edges->next = NULL;
            g->adjLists[src].edges->v = dest;
          }
        }
}

int numOutgoingEdges(Graph const * const g, int v) {
        // Your code here
        int count = 0;
        if(g != NULL && v < g->n){
        LinkedListNode * serchidx = g->adjLists[v].edges;

        while(serchidx != NULL){
          count++;
          serchidx = serchidx->next;
        }
      }
        return count;
}


int numIncomingEdges(Graph const * const g, int v) {
        // Your code here
        int count = 0;
        if(g != NULL && v < g->n){
        for(int i = 0; i < g->n; i++){
            LinkedListNode * serchidx = g->adjLists[i].edges;
            while(serchidx != NULL){
              if(serchidx->v == v) count++;
              serchidx = serchidx->next;
            }
        }
      }
      return count;
}

// No need to modify the functions below

Graph* createVertices(int numV) {
        Graph* g = new Graph();
        g->adjLists = new AdjacencyList[numV];
        g->n = numV;

        // Initialize the vertices
        for (int i = 0; i < numV; i += 1) {
                g->adjLists[i].vertex = i;
                g->adjLists[i].edges = NULL;
        }

        return g;
}

void printGraph(Graph const * const g) {
    for (int i = 0; i < g->n; i += 1) {
        AdjacencyList adjList = g->adjLists[i];

        int v = adjList.vertex;
        // Vertex
        cout << "Vertex: " << v << endl;

        // Print number of incoming and outgoing edges
        int inc = numIncomingEdges(g, v);
        int out = numOutgoingEdges(g, v);
        cout << "Number of incoming edges: " << inc << endl;
        cout << "Number of outgoing edges: " << out << endl;

        cout << "\n" << endl;
    }
}
