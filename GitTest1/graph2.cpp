
#include "graph.h"
#include <string>
#include <map>
#include <iostream>

#include <unordered_map>

#include <vector>

using namespace std;
//O(1)F

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


//O(

void AdjacencyList::insertEdge(Wine newWine) {
    if (graph.size() == 0) {
        vector<Wine> emptyVec;
        graph[newWine] = emptyVec;
    }
    else {
        graph[newWine].push_back(graph.rbegin()->first);
    }
    size++;
}



//O(graph.size())

void AdjacencyList::wineSearch(double price, string region, string province, string country) {

    bool pricef = false;

    bool regionf = false;

    bool provincef = false;

    bool countryf = false;

    vector<vector<string>> errorMes;
    bool dontPrint = false;
    bool found = false;

    for (auto i = graph.begin(); i != graph.end(); i++) {

        found = false;
        vector<string> nodeMess;

        if (i->first.country == country) {

            countryf = true;

            found = true;

        }
        else {
            nodeMess.push_back("country");
            found = false;
        }

            if (i->first.price == price)

                pricef = true;

            else {

                nodeMess.push_back("price");

                found = false;

            }

            if (i->first.region == region)

                regionf = true;

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
            if (errorMes.size() == 0)
                errorMes.push_back(nodeMess);
            int add = 0;
            for (int i = 0; i < errorMes.size(); i++) {
                if (nodeMess == errorMes[i])
                    add++;
            }
            if (add == 0)
                errorMes.push_back(nodeMess);
        
        if (found == true) {
            Wine::printWine(i->first);
            dontPrint = true;
        }
    }
    
    if (errorMes.size() > 0 && dontPrint == false) {
        cout << "We apologize but there is no wine in our database that contains these parameters. Please change the " << endl;
        for (int j = 0; j < errorMes.size(); j++) {
            cout << "    ";
            for (int k = 0; k < errorMes[j].size(); k++) {
                if (k < errorMes[j].size() - 1)
                    cout << errorMes[j][k] << ", ";
                else
                    cout << errorMes[j][k];
            }
            if (errorMes.size() > 1 && j != errorMes.size()-1)
                cout << endl << "or" << endl;
        }
        cout << endl << endl;
    }
}

//O(graph.size())
void AdjacencyList::wineName(string name) {
    cout << endl << "Searching..." << endl;
    bool found = false;

    for (auto i = graph.begin(); i != graph.end(); i++) {
        if (i->first.name == name) {
            Wine::printWine(i->first);
            found = true;
        }
    }

    if (found == false)
        cout << "We apologize but there is no wine in our database called " << name << ". Please search again." << endl;
}
