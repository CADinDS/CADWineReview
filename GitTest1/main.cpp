#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
	//************LOAD WINES************************************
	int counter = 0; //
	int price;
	int points;
	string province;
	string region;
	string country;
	string name;
	string variety;
	string winery;
	string description;
	ifstream file;
	file.open("winemag-data-130k-v2.csv");
	cout << "hello";
	string line;
	string token;
	getline(file, line);  //first line containing categories
	//vector<string> temp;
	while (getline(file, line)) {
		/*if (counter == 18881) {
			cout << "";
		}*/
		stringstream row(line);
		getline(row, token, ',');
		getline(row, token, ',');
		country = token;
		getline(row, token, ',');
		description = token;
		getline(row, token, ',');
		getline(row, token, ',');
		if (token != "") {
			points = stoi(token);    //line 18881
		}
		else {
			points = 0;
		}
		getline(row, token, ',');
		if (token != "") {
			price = stoi(token);
		}
		else {
			price = 0;
		}
		getline(row, token, ',');
		province = token;
		getline(row, token, ',');
		region = token;
		getline(row, token, ',');
		getline(row, token, ',');
		getline(row, token, ',');
		getline(row, token, ',');
		name = token;
		getline(row, token, ',');
		variety = token;
		getline(row, token, ',');
		winery = token;
		counter++;
	}
	cout << "winery:" << winery;

	//************TAKE USER INPUT************************************
	int menuOp;
	cout << "Welcome to the wine reccomendation software" << endl;
	cout << "Enter a menu option" << endl;
	cout << "1. Search for a wine" << endl;
	cout << "2. Search for types of wines" << endl;
	cin >> menuOp;
	if (menuOp == 1) {


	}
	else if (menuOp == 2) {
		
	}
	else {
		cout << "invalid input" << endl;
	}
	return 0;
}
