#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Wine {
    string name, province, region, description, country, variety, winery;
    double price, points;
    static void printWine(Wine wine);
};

class AdjacencyList {
private:
    map<Wine, vector<Wine>> graph; 
public:
    void insertEdge(Wine newWine);
    void wineSearch(double price, string region, string province, string country);
    void wineName(string name);

};

//O(1)
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
    graph[newWine].push_back(graph.begin()->first);
}

//O(graph.size())
void AdjacencyList::wineSearch(double price, string region, string province, string country) {
    bool pricef = false;
    bool regionf = false;
    bool provincef = false;
    bool countryf = false;
    vector<vector<string>> errorMes;

    for (auto i = graph.begin(); i != graph.end(); i++) {
        bool found = false;
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
        errorMes.push_back(nodeMess);

        if (found == true) {
            Wine::printWine(i->first);
        }

        
    }
    if (errorMes.size() > 0) {
        cout << "We apologize but the is no wine in our database that contains these parameters. Please change the ";
        for (int j = 0; j < errorMes.size(); j++) {
            cout << "   ";
            for (int k = 0; k < errorMes[j].size(); k++) {
                if (k < errorMes[j].size() - 1)
                    cout << errorMes[j][k] << ", ";
                else
                    cout << errorMes[j][k];
            }
            cout << endl << "or" << endl;
        }
    }
}

//O(graph.size())
void AdjacencyList::wineName(string name) {
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

//while (graph)
    //find the country
    //price, region, 
   // have a bool for each feature (wrong word lol) and then at the end of the loop if nothing was returned
