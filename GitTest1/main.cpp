#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <sstream>
#include "graph.h"
#include "tree.h"
#include "time.h"
using namespace std;

double InputCorrect(string num) {
	double PriceDouble;
	try {
		PriceDouble = stod(num);
	}
	catch (...) {
		cout << "Invalid price! Please enter in the form 12.00" << endl;
		string num2;
		cin >> num2;
		InputCorrect(num2);
	}
	return PriceDouble;
}

int main() {
	//************LOAD WINES************************************
	Tree t;
	AdjacencyList g;
	int counter = 0; //
	double var1, var2;
	ifstream file;
	file.open("data_shortversion.csv");
	//file.open("winemag_data_130k.csv");
	cout << "Welcome to the ~Wine Reccomendation Software~" << endl;
	cout << "loading wines";
	string line;
	string token;
	getline(file, line);  //first line containing categories
	while (getline(file, line)) {
		Wine w;  //graph wine
		Wines ww;  //tree wine
		//shows user wines are loading
		if (counter == 10000 || counter == 30000 || counter == 50000 || counter == 70000 || counter == 90000 || counter == 100000 || counter == 120000) {
			cout << ".";
		}
		stringstream row(line);
		getline(row, token, ','); //num
		getline(row, token, ','); //country
		w.country = token;
		ww.country = token;
		getline(row, token, ','); //description
		w.description = token;
		ww.description = token;
		getline(row, token, ','); //designation
		getline(row, token, ','); //points
		ww.points = token;
		if (token != " ") {  //??needed?
			w.points = stod(token);
			var1 = stod(token);
		}
		else {
			w.points = 0.0;
			var1 = 0.0;
		}
		getline(row, token, ','); //price
		ww.price = token;
		if (token != " ") {  //??needed?
			w.price = stod(token);
			var2 = stod(token);
		}
		else {
			w.price = 0.0;
			var2 = 0.0;
		}
		getline(row, token, ','); //province
		w.province = token;
		ww.province = token;
		getline(row, token, ','); //reg 1
		w.region = token;
		ww.region = token;
		getline(row, token, ','); //reg 2
		getline(row, token, ','); //taster
		getline(row, token, ','); //twitter handle
		getline(row, token, ','); //title
		w.name = token;
		ww.name = token;
		getline(row, token, ','); //variety
		w.variety = token;
		ww.variety = token;
		getline(row, token, ','); //winery
		w.winery = token;
		ww.winery = token;
		//add to Tree
		t.createTree(ww);
		//add to Graph
		//g.insertEdge(w); 
		counter++;
	}

	//************TAKE USER INPUT************************************
	clock_t startG, endG;
	clock_t startT1, endT1, startT2, endT2, startT3, endT3, startT4, endT4;
	int menuOp;
	string secondOp;
	cout << endl;
	cout << "Enter a menu option:" << endl;
	cout << "1. Search for a wine" << endl;
	cout << "2. Search for types of wines" << endl;
	cin >> menuOp;
	if (menuOp == 1) {
		cout << "Enter a wine name" << endl;
		cin >> secondOp;
		startG = clock();
		g.wineName(secondOp);
		endG = clock();
		cout << "Graph DS: " << double(endG - startG)/double(CLOCKS_PER_SEC) << endl;
	}
	else if (menuOp == 2) {
		string priceEntered;
		string regEntered;
		string provEntered;
		string countryEntered;
		double newPrice;
		cout << "Enter filter options" << endl;
		cout << "Specify Price: ";
		cout << "(ex. 15.00)" << endl;
		cin >> priceEntered;
		newPrice = InputCorrect(priceEntered);   //changes input string to a double for graph, if invalid input (word) recursively asks for new input
		startT1 = clock();
		t.checkForChildMatches(priceEntered, "price");
		endT1 = clock();
		cout << "Specify Region: ";
		cout << "(ex. Napa Valley)" << endl;
		cin >> regEntered;
		startT2 = clock();
		t.checkForChildMatches(regEntered, "region");
		endT2 = clock();
		cout << "Specify Province: ";
		cout << "(ex. California)" << endl;
		cin >> provEntered;
		startT3 = clock();
		t.checkForChildMatches(provEntered, "province");
		endT3 = clock();
		cout << "Specify Country: ";
		cout << ("ex. Italy") << endl;
		cin >> countryEntered;
		startT4 = clock();
		t.checkForChildMatches(countryEntered, "country");
		endT4 = clock();
		startG = clock();
		g.wineSearch(newPrice, regEntered, provEntered, countryEntered);
		endG = clock();
		cout << "Graph DS: " << double(endG - startG)/double(CLOCKS_PER_SEC) << endl;
		cout << "Tree DS: " << double((endT1 - startT1 + endT2 - startT2 + endT3 - startT3 + endT4 - startT4) / double(CLOCKS_PER_SEC)) << endl;
	}
	else {
		cout << "Invalid Menu Option, goodbye" << endl;
	}
	return 0;
}
