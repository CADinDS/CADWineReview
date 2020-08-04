# GitTest1
graph.cpp Overview 
  printWine(Wine wine)
    This function is used to print the wine which fits the inputted characteristics

  void insertEdge(Wine newWine);
    This function is how the graph is created. We check to see if the graph is empty or not. If it is empty, we create a note which doesn't point to anything. 
    If it is not empty, we create a new node and pointed to the last one in the graph.

  void wineSearch(double price, double points, std::string winery, std::string variety, std::string region, std::string province, std::string country);
     This function takes and all of the user's inputted wine characteristics and iterated through the graph to see if any of the wines match those 
     characteristics.When a matching wine is found it is printed. If no matching wine is found an error message will be outputinstructing the user to change 
     one or more of their values.

  void wineName(string name);
    This function iterates through the entire graph to see if any of the wines have the same name as the inputted name. If they do that wine is printed. If 
    there is no match an error message is outputted telling the user to search again



tree.cpp Overview 
  The tree data structure is created to have each level of the tree hold a different topic of information. The root node just holds the string wine. From then 
  on we have each descending level holding the information for country, region, province, winery, variety, price, points, name, and description, respectively. 

  Node* makeChildOf(Node* parent, string data);
    This function creates a new child mode coming from the imported parent node.

  Node* addNode(Node* parent,string data);
    This function checks to see if the parent node already has a child with the matching data. If it does, it returns that existing note. If it doesn't, 
    it creates a new node by calling makeChildOf(Node* parent, string data).

  void createTree(Wines wine);
    This function creates the tree. iIf the root equals null, meaning there is nothing in the tree, then it creates the root, sets location equal to the root,
    and calls makeChildOf(Node* parent, string data) for all of that wine's information. If the Roots is not now then it calls addnode for all of the wines 
    information.

  void checkForChildMatches(string data,string topic);
  vector<Wines> returnWineNames();
  vector<Wines> getName(string name);
