#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
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
		w.number = token;
		getline(row, token, ','); //country
		w.country = token;
		ww.country = token;
		getline(row, token, ','); //description
		w.description = token;
		ww.description = token;
		getline(row, token, ','); //designation
		getline(row, token, ','); //points
		ww.points = token;
		if (token != "") {  //??needed?
			w.points = stod(token);
		}
		else {
			w.points = 0.0;
		}
		getline(row, token, ','); //price
		ww.price = token;
		if (token != "") {  //??needed?
			w.price = stod(token);
		}
		else {
			w.price = 0.0;
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
		if (counter == 1) {
			cout << "";
		}
		//add to Tree
		t.createTree(ww);
		//add to Graph
		g.insertEdge(w); 
		counter++;
		cout << counter << endl;
	}

	//************TAKE USER INPUT************************************
	clock_t startG, endG;
	clock_t startT, endT;
	int menuOp;
	string secondOp;
	cout << endl;
	cout << "Enter a menu option:" << endl;
	cout << "1. Search for a wine" << endl;
	cout << "2. Search for types of wines" << endl;
	cin >> menuOp;
	if (menuOp == 1) {
		cout << "Enter a wine name" << endl;
		string line;
		cin >> line;
		getline(cin, secondOp);
		secondOp = line + secondOp;
		vector<Wines> treeMatches;
		startG = clock();
		g.wineName(secondOp);
		endG = clock();
		cout << "Graph DS: " << double(endG - startG)/double(CLOCKS_PER_SEC) << endl;
		startT = clock();
		treeMatches = t.getName(secondOp);
		endT = clock();
		cout << "Tree DS: " << double(endT - startT) / double(CLOCKS_PER_SEC) << endl;
	}
	else if (menuOp == 2) {
		string priceEntered;
		string regEntered;
		string provEntered;
		string countryEntered;
		string wineryEntered;
		string varEntered;
		string pointsEntered;
		double newPrice;
		double newPoints;
		double dif = 0.0;
		cout << "Enter filter options" << endl;

		cout << "Specify Country: ";
		cout << ("ex. Italy") << endl;
		
		line = "";
		cin >> line;
		getline(cin, countryEntered);
		countryEntered = line + countryEntered;
		startT = clock();
		t.checkForChildMatches(countryEntered, "country");
		endT = clock();
		dif = double(endT - startT);

		cout << "Specify Region: ";
		cout << "(ex. Napa Valley)" << endl;
		line = "";
		cin >> line;
		getline(cin, regEntered);
		regEntered = line + regEntered;
		startT = clock();
		t.checkForChildMatches(regEntered, "region");
		endT = clock();
		dif += double(endT - startT);

		cout << "Specify Province: ";
		cout << "(ex. California)" << endl;
		line = "";
		cin >> line;
		getline(cin, provEntered);
		provEntered = line + provEntered;
		startT = clock();
		t.checkForChildMatches(provEntered, "province");
		endT = clock();
		dif += double(endT - startT);

		cout << "Specify Winery: ";
		cout << "(ex. Louis Lator)" << endl;
		line = "";
		cin >> line;
		getline(cin, wineryEntered);
		wineryEntered = line + wineryEntered;
		startT = clock();
		t.checkForChildMatches(wineryEntered, "winery");
		endT = clock();
		dif += double(endT - startT);

		cout << "Specify Variety: ";
		cout << "(ex. Chardonnay)" << endl;
		line = "";
		cin >> line;
		getline(cin, varEntered);
		varEntered = line + varEntered;
		startT = clock();
		t.checkForChildMatches(varEntered, "variety");
		endT = clock();
		dif += double(endT - startT);
		
		cout << "Specify Price: ";
		cout << "(ex. 15.00)" << endl;
		cin >> priceEntered;
		newPrice = InputCorrect(priceEntered);   //changes input string to a double for graph, if invalid input (word) recursively asks for new input
		startT = clock();
		t.checkForChildMatches(priceEntered, "price");
		endT = clock();
		dif += double(endT - startT);

		cout << "Specify Points: ";
		cout << "(ex. 85)" << endl;
		cin >> pointsEntered;
		newPoints = InputCorrect(pointsEntered);
		startT = clock();
		t.checkForChildMatches(pointsEntered, "points");
		endT = clock();
		dif += double(endT - startT);		
		
		startG = clock();
		g.wineSearch(newPrice, regEntered, provEntered, countryEntered);
		endG = clock();
		cout << "Graph DS: " << double(endG - startG)/double(CLOCKS_PER_SEC) << endl;
		cout << "Tree DS: " << dif / double(CLOCKS_PER_SEC) << endl;
	}
	else {
		cout << "Invalid Menu Option, goodbye" << endl;
	}
	return 0;
}
