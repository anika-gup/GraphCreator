#include <string.h>
#include <iostream>

using namespace std;

void ADDVERTEX(int count, int graph[20][20], char** names);
void ADDEDGE(int count, int graph[20][20], char** names);

void PRINTLABELS(int count, char** names);
void PRINTGRAPH(int count, int graph[20][20], char** names);

int SEARCH(int count, char** names, char* Label);

void REMOVEVERTEX(int count, int graph[20][20], char** names);
void REMOVEEDGE(int count, int graph[20][20], char** names);


/*
Graph Creator
Anika Gupta
Can add/remove vertices and edges, and find shortest path using Dijkstra's Algorithm
 */

int main() {
  int count = -1;

  //creating graph and setting all values to -1
  int graph[20][20];
  for (int c=0; c<20; c++) {
    for (int d=0; d<20; d++) {
      
      graph[c][d] = -1;
    }
  }

  // creating array with all of the vertex lables
  char** names = new char*[50];
  for (int a=0; a<20; a++) {
    char* text = new char[50];
    strcpy(text, "" ) ;
    names[a] = text ;
  }
  


  int quit = 0;
  while (quit==0) {
    //giving user options
    cout << endl;
    cout << "What would you like to do? " << endl;
    cout << "QUIT  ADDVERTEX  ADDEDGE  REMOVEVERTEX  REMOVEEDGE \n PRINTLABELS  PRINTGRAPH  FINDSHORTEST" << endl;
    cout << endl;
    char input[50];
    cin >> input;
    if (strcmp(input, "ADDVERTEX")==0) {
      // create then call this funct
      count++;
      ADDVERTEX(count, graph, names);
    }
    else if (strcmp(input, "QUIT")==0) {
      quit  =1;
    }
    else if (strcmp(input, "ADDEDGE")==0) {
      // create then call this funct
      ADDEDGE(count, graph, names);
    }
    else if (strcmp(input, "PRINTLABELS")==0) {
      PRINTLABELS(count, names);
    }
    else if (strcmp(input, "PRINTGRAPH")==0) {
      PRINTGRAPH(count, graph, names);
    }
    else if (strcmp(input, "REMOVEVERTEX")==0) {
      REMOVEVERTEX(count, graph, names);
    }
    else if (strcmp(input, "REMOVEEDGE")==0) {
      REMOVEEDGE(count, graph, names);
    }
    else if (strcmp(input, "FINDSHORTEST")==0) {
      // Find shortest path
      //STILL NEED TO CODE THIS----------------------------
    }
  }
  return 0;
}

void ADDVERTEX(int count, int graph[20][20], char** names) {
  // Adds a vertex (creates new label)

  
  cout << endl;
  cout << "What is the label for your vertex?" << endl;
  char* Label = new char[50];
  cin >> Label;
  names[count] = Label;
  cout << "Label is: " << Label << endl;
}


void ADDEDGE(int count, int graph[20][20], char** names) {
  //Adds an edge (weighted with direction).
  
  cout << "Adding an edge!" << endl;
  cout << "What is your starting node's label?" << endl;
  char s[50];
  cin>> s;
  int startingIndex = SEARCH(count, names, s);
  cout << "What is your ending node's label?" << endl;
  char e[50];
  cin >> e;
  int endingIndex = SEARCH(count, names, e);
  if ((endingIndex==-1) || (startingIndex==-1)) {
    // User's given nodes don't exist
    cout << "Either one or both of your names are invalid." << endl;
  }
  else {
    cout << "What is the weight of the edge?" << endl;
    int weight;
    cin >> weight;
    //Setting edge in graph:
    graph[startingIndex][endingIndex]=weight;
  }
}

void PRINTLABELS(int count, char** names) {
  //Prints all of the labels of the vertices in graph.
  cout << "Printing Labels." << endl;
  for (int a=0; a<count+1; a++) {
    if (strcmp(names[a], "")!=0) {
      cout << names[a] << endl;
    }
    //cout << names[a] << endl;
  }
  cout << endl;
}

void PRINTGRAPH(int count, int graph[20][20], char** names) {
  //Prints the graph 
  for (int a=0; a<count+1; a++) {
    for (int b=0; b<count+1; b++) {
      if ( (strcmp(names[a], "")!=0) && (strcmp(names[b], "")!=0)) {
	cout << graph[a][b] << "  ";
      }
      //cout << graph[a][b] << "   ";
    }

    if (strcmp(names[a], "")!=0) {
      cout << endl;
    }
  }
}

int SEARCH(int count, char** names, char* Label) {
  //Searches for whether a certain label exists in the graph and if it does exist, returns index value where it exists on the graph
  if (strcmp(Label, "")==0) {
    // (means a deleted vertex)
    return -1;
  }
  for (int a=0; a<count+1; a++) {
    if (strcmp(names[a], Label)==0) {
      // found label in graph, returning index of it.
      return a;
    }
  }

  //vertex not found:
  return -1;
}

void REMOVEVERTEX(int count, int graph[20][20], char** names) {
  //Removes a vertex
  
  char toDelete[50];
  cout << "What is the label of the vertex to delete?" << endl;
  cin >> toDelete;
  int index = SEARCH(count, names, toDelete);
  if (index==-1) {
    cout << "That vertex doesn't exist." << endl;
  }
  else {
    char* newLabel = new char[50];
    strcpy(newLabel, "");
    names[index] = newLabel;
    for (int a=0; a<count+1; a++) {
      graph[a][index] = -1;
      graph[index][a] = -1;
    }
  }
}

void REMOVEEDGE(int count, int graph[20][20], char** names) {
  // Removes an edge
  cout << "What is the starting node's label?   " << endl;
  char s[50];
  cin >> s;
  int startingIndex = SEARCH(count, names, s);
  cout << "What is your ending ndoe's label?" << endl;
  char e[50];
  cin >> e;
  int endingIndex = SEARCH(count, names, e);
  if ((endingIndex==-1) || (startingIndex==-1)) {
    cout << "Either one or both of your names are invalid." << endl;
  }
  else {
    graph[startingIndex][endingIndex] = -1;
  }
}
