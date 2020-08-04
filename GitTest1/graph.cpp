#include "graph.h"
#include <string>
#include <map>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//printWine will be called when a wine is found, it prints out the important charactistics of the wine
void Wine::printWine(Wine wine) {
    cout << wine.name << endl;
    cout << "     Province: " << wine.province << endl;
    cout << "     Country: " << wine.country << endl;
    cout << "     Region: " << wine.region << endl;
    cout << "     Winery: " << wine.winery << endl;
    cout << "     Variety: " << wine.variety << endl;
    cout << "     Price: " << wine.price << endl;
    cout << "     Points: " << wine.points << endl;
    cout << "     Description: " << wine.description << endl;
}

//insertEdge is what creates the graph
void AdjacencyList::insertEdge(Wine newWine) {
    //if the graph is empty, just add a node that doesn't point to anything
    if (graph.size() == 0) {
        //empty vector because it doesn't have any other nodes to point to
        vector<Wine> emptyVec;
        graph[newWine] = emptyVec;
    }
    else {
        //insert newWine and have it point to the last node in the graph
        graph[newWine].push_back(graph.rbegin()->first);
    }
}

//wineSearch uses the inputted wine characteristics to search for a wine that matches the characteristics
void AdjacencyList::wineSearch(double price, double points, string winery, string variety, string region, string province, string country) {
    //the following bools determine if the inputted characteristic was found or not
    bool pricef = false;
    bool pointsf = false;
    bool regionf = false;
    bool varietyf = false;
    bool provincef = false;
    bool wineryf = false;
    bool countryf = false;
    //errorMes is a vector of vectors that contain the characteristics that could be changed to find a wine
    vector<vector<string>> errorMes;
    bool dontPrint = false;
    bool found = false;

    //iterate through the graph to find a matching wine
    for (auto i = graph.begin(); i != graph.end(); i++) {
        found = true;
        //nodeMess will be inputted into errorMes
        vector<string> nodeMess;
        //check if each input equals the characteristic of the wine, if not, add the character to nodeMess and found = false
        if (i->first.country == country) {
            countryf = true;
        }
        else {
            nodeMess.push_back("country");
            found = false;
        }
        if (i->first.price == price) {
            pricef = true;
        }
        else {
            nodeMess.push_back("price");
            found = false;
        }
        if (i->first.region == region) {
            regionf = true;
        }
        else {
            nodeMess.push_back("region");
            found = false;
        }

        if (i->first.province == province)
            provincef = true;
        else {
            nodeMess.push_back("province");
            found = false;
        }
        if (i->first.winery == winery)
            wineryf = true;
        else {
            nodeMess.push_back("winery");
            found = false;
        }
        if (i->first.variety == variety)
            varietyf = true;
        else {
            nodeMess.push_back("variety");
            found = false;
        }
        if (i->first.points == points) {
            pointsf = true;
        }
        else {
            nodeMess.push_back("points");
            found = false;
        }
        //if there are no error messages in errorMess, insert nodeMess
        if (errorMes.size() == 0)
            errorMes.push_back(nodeMess);
        int add = 0;
        //iterate through errorMes to see if nodeMess is already listed
        for (int i = 0; i < errorMes.size(); i++) {
            if (nodeMess == errorMes[i])
                add++;
        }
        //if there wasn't an error that matches nodeMess in errorMess, insert nodeMess into it
        if (add == 0)
            errorMes.push_back(nodeMess);
        //if the wine was found, print it and don't print the error message
        if (found == true) {
            Wine::printWine(i->first);
            dontPrint = true;
        }
    }

    //if there were error messages and the wine wasn't found, go through the errorMess and print out the message and the options to change in order to find a wine
    if (errorMes.size() > 0 && dontPrint == false) {
        cout << "We apologize but there is no wine in our database that contains these parameters. Please change the " << endl;
        //goes through the errorMes to print each message
        for (int j = 0; j < errorMes.size(); j++) {
            cout << "    ";
            for (int k = 0; k < errorMes[j].size(); k++) {
                if (k < errorMes[j].size() - 1)
                    cout << errorMes[j][k] << ", ";
                else
                    cout << errorMes[j][k];
            }//add an or after each option
            if (errorMes.size() > 1 && j != errorMes.size() - 1)
                cout << endl << "or" << endl;
        }
        cout << endl << endl;
    }
}




//wineName searches the graph to find the wine that has the inputted name
void AdjacencyList::wineName(string name) {
    cout << endl << "Searching..." << endl;
    bool found = false;
    //go through the graph to find the name
    for (auto i = graph.begin(); i != graph.end(); i++) {
        //if the name is found, print the wine info
        if (i->first.name == name) {
            Wine::printWine(i->first);
            found = true;
        }
    }
    //if the name didn't match the names in the graph, print an error message
    if (found == false)
        cout << "We apologize but there is no wine in our database called " << name << ". Please search again." << endl;
}


