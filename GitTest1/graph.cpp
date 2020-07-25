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
    void insertEdge(Wine from, Wine to);
    Wine wineSearch(double price, string region, string province, string country);
    Wine wineName(string name);

};

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
void AdjacencyList::insertEdge(Wine from, Wine to) {
    graph[from].push_back(to);
    if (graph.find(to) == graph.end())
        graph[to] = {};
}

Wine AdjacencyList::wineSearch(double price, string region, string province, string country) {
    bool found = false;
    for (auto i = graph.begin(); i != graph.end(); i++) {
        if (i->first.price == price && i->first.region == region && i->first.province == province && i->first.country == country) {
            Wine::printWine(i->first);
            found = true;
        }
    }
    if (found == false)
        cout << "We apologize but the is no wine in our database that contains these parameters. Please search again." << endl;
}


Wine AdjacencyList::wineName(string name) {
    bool found = false;
    for (auto i = graph.begin(); i != graph.end(); i++) {
        if (i->first.name == name) {
            Wine::printWine(i->first);
            found = true;
        }
    }
    if (found == false)
        cout << "We apologize but the is no wine in our database called " << name << ". Please search again." << endl;
}
