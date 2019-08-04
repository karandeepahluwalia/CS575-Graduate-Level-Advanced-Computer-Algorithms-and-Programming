#include "Pair.h"
#include "MinHeap.h"
#include "Pair.h"
#include<cmath>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <stdlib.h>
#include <algorithm>
#include <ctime>

using namespace std;
void prim(vector<vector<int>> &graph, int num_vertex){
  vector<int> cost(num_vertex,1000);
  vector<int> parent(num_vertex,0);
  //create cost array
  //create parent array
  vector<bool> inSet(num_vertex,false);
//Create a check to see what vertices are in the tree
  inSet[0] =true;
  cost[0] = 0;
  pq = Heap();
  //built the heap as well as set up the starting nodes
  for(int i = 0;i<num_vertex;i++){
    pq.push(i,cost[i]);
  }
  bool nontree = true;
  while(nontree){
    pq = Heap();
    for(int i = 0;i<num_vertex;i++){
      if(!inSet[i]){
        pq.push(i,cost[i]);
      }
    }
    Pair temp = pq.pop();
    for(int j=0;j<num_vertex;j++){
      if(!inset[j]){
        if((graph[temp.getName()][j]!=0)||(temp.getName()==1)){
          if(cost[temp.getName()]>graph[temp.getName()][j]){
            cost[temp.getName()]=graph[temp.getName()][j];
            parent[temp.getName()]=j;
          }
        }
      }
    }
    inSet[temp.getName()] = true;
    nontree =false;
    for(int k=0;k<num_vertex;k++){
      if(!inSet[k]){
        nontree = true;
      }
    }
  }
  cout<<"These are the edges"<<endl;
  for(int l=1;l<num_vertex;l++){
    cout<<"Edge from "<<l<<" to "<<parent[l]<<endl;
  }
}
//find function
int find(int i,int parent[]){
  while(parent[i] != i){
    i = parent[i];
  }
  return i;
}
//union function
void union(int i,int j,int parent[]){
  int a = find(i);
  int b = find(j);
  parent[a] = b;
}
void kruskal(vector<vector<int>> &graph, int num_vertex){
  int parent[num_vertex];
  int min = 0;
  //create the different disjoint sets
  for(int i=0;i<num_vertex;i++){
    parent[i]=i;
  }
  //for loop to compare smallest edges and add them one by one
  while(paths<num_vertex-1){
    int low = 1000, a =-1,b=-1;
    for(int j=0;j<num_vertex;j++){
      for(int k=0;k<num_vertex;k++){
        if(find(i,parent)!=find(j,parent)&&graph[i][j]<min){
          low = cost[i][j];
          a= i;
          b = j;
        }
      }
    }
    //add sets together and print out edge
    union(a,b,parent);
    cout<<"Edge from "<<a<<" to "<<b<<endl;
    paths++;
    mincost+=low;
  }
}
int main(){
  //So I get a different random number between 5 and 10 every time
  srand ( time(NULL) );
  int num_vertices = rand()%6+5;
  cout<<"Random value is: "<<num_vertices<<endl;
  //Create the graph matrix and the paths matrix
  vector<vector<int>> graph(num_vertices);
  vector<vector<int>> path(num_vertices);
  for(int i=0;i<num_vertices;i++){
    graph[i] = vector<int> (num_vertices);
    path[i] = vector<int> (num_vertices);
  }
  //Fill graph matrix
  for(int j=0;j<num_vertices;j++){
    for(int k=j+1;k<num_vertices;k++){
      graph[j][k] = rand()%10+1;
      graph[k][j] = graph[j][k];
    }
  }
  //Display original graph
  cout<<"This is the original graph:"<<endl;
  for(int j=0;j<num_vertices;j++){
    for(int k=0;k<num_vertices;k++){
      cout<<graph[j][k]<<"  ";
    }
    cout<<endl;
  }
  string a;
  //Take user input and direct them to right program
  cout<<"Type p for Prims algorithm and k for Kruskals"<<endl;
  cin>>a;
  if(a=="p"){
    prim(graph,num_vertices);
  }else if(a=="k"){
    kruskal(graph,num_vertices);
  }else{
    cout<<"Error. Input wrong. Run program again"<<endl;
  }
  cout<<"Program exiting"<<endl;
}
