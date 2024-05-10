#include <string.h>
#include <iostream>

using namespace std;

void ADDVERTEX(int count, int graph[20][20], char** names);
void ADDEDGE(int count, int graph[20][20], char** names);

void PRINTLABELS(int count, char** names);
void PRINTGRAPH(int count, int graph[20][20], char** names);

int SEARCH(int count, char** names, char* Label);

void REMOVEVERTEX(int count, int graph[20][20], char** names);





int main() {
  int count = -1;
  int graph[20][20];
  for (int c=0; c<20; c++) {
    for (int d=0; d<20; d++) {
      
      graph[c][d] = -1;
    }
  }

  
  char** names = new char*[50];
  for (int a=0; a<20; a++) {
    char* text = new char[50];
    strcpy(text, "" ) ;
    names[a] = text ;
  }
  for (int b=0; b<20; b++) {
    //cout << b << ": " << names[b] << endl;
  }


  int quit = 0;
  while (quit==0) {
    cout << endl;
    cout << "What would you like to do? " << endl;
    cout << "QUIT  ADDVERTEX  ADDEDGE  REMOVEVERTEX  REMOVEEDGE  PRINTLABELS  PRINTGRAPH" << endl;
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
  }
  return 0;
}

void ADDVERTEX(int count, int graph[20][20], char** names) {
  //cout << "Reached Add Vertex section" << endl;
  cout << endl;
  cout << "What is the label for your vertex?" << endl;
  char* Label = new char[50];
  cin >> Label;
  names[count] = Label;
  cout << "Label is: " << Label << endl;
}
void ADDEDGE(int count, int graph[20][20], char** names) {
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
    cout << "Either one or both of your names are invalid." << endl;
  }
  else {
    cout << "What is the weight of the edge?" << endl;
    int weight;
    cin >> weight;
    graph[startingIndex][endingIndex]=weight;
  }
}

void PRINTLABELS(int count, char** names) {
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
  if (strcmp(Label, "")==0) {
    return -1;
  }
  for (int a=0; a<count+1; a++) {
    if (strcmp(names[a], Label)==0) {
      return a;
    }
  }
  return -1;
}

void REMOVEVERTEX(int count, int graph[20][20], char** names) {
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
