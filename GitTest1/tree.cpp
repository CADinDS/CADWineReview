//
//  main.cpp
//  Wine Project
//
//  Created by Catherine  Healy on 7/19/20.
//  Copyright © 2020 Catherine  Healy. All rights reserved.
//
//COMMENT NOTE: PV = Private Variable

#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Wine {
    string country, region, province, winery, variety, price, points, name, description;
};

class Node {
public:
    string data; //the string the node will hold
    vector<Node*> children; //the children of that node its a vector bc its unknown how many children it will have
    Node(string d){ //contructor
        data = d;
    }
};

class Tree{
private:
    Node* root = nullptr; //PV to hold root node
    Node* location = nullptr; //PV to hold location of where you are looking at
    
    //PVs to hold infromation about the wine(s) you are searching for
    string country;
    string region;
    string province;
    string winery;
    string variety;
    string price;
    string points;
    
public:
    Node* makeChildOf(Node* parent, string data); //make a node coming from another node
    Node* addNode(Node* parent, string data); //adding a node to the tree
    void createTree(Wine wine); //creating the tree
    void checkForChildMatches(string data, string topic); //check to see if any of the children of a node match hte string youre looking for
    vector<Wine> returnWineNames(); //get a vector of the Wine structs with the inputted constraints
    
    //seting the private variable to the inputted string
    void setCountry(string c);
    void setRegion(string r);
    void setProvience(string p);
    void setWinery(string w);
    void setVariety (string v);
    void setPrice (string p);
    void setPoints(string p);
    
    //retreiving the private variable
    string getCountry();
    string getRegion();
    string getProvience();
    string getWinery();
    string getVariety();
    string getPrice();
    string getPoints();

};


Node* Tree::makeChildOf(Node* parent, string data){
    Node* child; //create the child node
    parent->children.push_back(child); //add that child to the parents children
    child = new Node(data); //point child to a new node with the data
    return child;
}

Node* Tree::addNode(Node* parent, string data){

       vector<Node*>::iterator itr;
       for(itr=parent->children.begin(); itr != parent->children.end(); itr++) {  //iterate through parent's children
           if ((*itr)->data == data){ //if data matches any of the children's data
               return (*itr); //return that Node*
           }
       }
       //if it doesnt
       Node* child; //create a new Node*
       child = makeChildOf(parent, data); //make it a child of parent with its data
       return child; //return the new node
}

void Tree::createTree(Wine wine){
    
    //pointers for the info of a wine
    Node* country;
    Node* region;
    Node* province;
    Node* winery;
    Node* variety;
    Node* price;
    Node* points;
    Node* name;
    Node* description;


    if(root == nullptr){ //if there is nothing in the tree
        root = new Node("wine"); //set the root node to wine
        location = root; //set location* to the root so when going through the tree you start at begining
        
        //add each level as a child of the other since the tree is empty
        country = makeChildOf(root, wine.country);
        region = makeChildOf(country, wine.region);
        province = makeChildOf(region, wine.province);
        winery = makeChildOf(province, wine.winery);
        variety = makeChildOf(winery, wine.variety);
        price = makeChildOf(variety, wine.price);
        points = makeChildOf(price, wine.points);
        name = makeChildOf(points, wine.name);
        description = makeChildOf(name, wine.description);

    }
    else {
        //check to see if the parent already has the child as a node
            //if it does go on to the grandchild
            //if it does not make add it as a child then go on to the grandchild
        country = addNode(root, wine.country);
        region = addNode(country, wine.region);
        province = addNode(region, wine.province);
        winery = addNode(province, wine.winery);
        variety = addNode(winery, wine.variety);
        price = addNode(variety, wine.price);
        points = addNode(price, wine.points);
        name = addNode(points, wine.name);
        description = addNode(name, wine.description);
       
    }
}

void Tree::checkForChildMatches(string data, string topic){
    bool foundMatch = false; //a check to see if one of the children's data matches the inputted data
    
    vector<Node*>::iterator itr;
    for(itr=location->children.begin(); itr != location->children.end(); itr++) {  //iterate through parent's (location's) children
        if ((*itr)->data == data){ //if data matches any of the children's data
            
            location = (*itr); //set location to that Node*
            foundMatch = true; //a match was found
        }
    }
    if(foundMatch == false){ //no match was found
        cout<<"There is no matching "<<topic<< " in the tree.\n Please input another option"<<endl; //error message
        string newData;
        cin>>newData; //take in the new string
        checkForChildMatches(newData, topic); //go through the process again with the new string
    }
    
    //set the constraints infromation into the private variables
    if(topic == "country"){
        setCountry(data);
    }
    else if(topic == "region"){
        setRegion(data);
    }
    else if(topic == "province"){
        setProvience(data);
    }
    else if(topic == "winery"){
        setWinery(data);
    }
    else if(topic == "variety"){
        setVariety(data);
    }
    else if(topic == "price"){
        setPrice(data);
    }
    else if(topic == "points"){
        setPoints(data);
    }
}

vector<Wine> Tree::returnWineNames(){
    
    vector<Wine> wineNames; //create a vector of Wines to return
    Wine w; //create a wine
    
    //set the wine w information to the infromation that the user inputted
    w.country = getCountry();
    w.region = getRegion();
    w.province = getProvience();
    w.winery = getWinery();
    w.variety = getVariety();
    w.price = getPrice();
    w.points = getPoints();
    
    
    
    vector<Node*>::iterator itr; //iterator needed incase there is more than one wine that has those characteristics
       for(itr=location->children.begin(); itr != location->children.end(); itr++) {  //iterate through parent's (location's) children

           w.name = (*itr)->data; //get the name of the wine in question and set it to w
           
           if ((*itr)->children.size() > 1){ //if there is more than one wine with the same name and all other factors but two+ different descriptions you need to make two nodes with the different descriptions
             
               vector<Node*>::iterator itr2;
               for(itr2=(*itr)->children.begin(); itr2 != (*itr)->children.end(); itr2++) {   //go through children of the name
                   w.description = (*itr2)->data;
                   wineNames.push_back(w); //push back a wine with all the same informatiion but with the unique description for it
               }
           }
           else{ //this is if there is only one description for the name
               w.description = (*itr)->children[0]->data;
               wineNames.push_back(w);
           }
       }
    return wineNames;
}
