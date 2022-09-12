// =================================================================
//
// File: main.cpp
// Author: Ricardo Navarro Gómez - A01708825
// Date: 11/09/2022
//
// =================================================================
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iomanip>
#include "header.h"
#include "ship.h"
#include "selection.h"

using namespace std;

int main(int argc, char* argv[]) {

  ifstream input;
  ofstream mysolution;

  if (argc != 3){
    cout<< "Error"<<endl;
    return -1;
  }

  input.open(argv[1]);
  if (!input.is_open()){
    cout << "Error al abrir el archivo\n";
    return -1;
  }

	mysolution.open(argv[2]);
	int num;
	string prefix, date, time, ubi;
	char entry;
	//Read the file first line
	input >>num >> prefix;
	//Ships vector with the amount of ships
	vector <Ship> ships;
	ships.resize(num);
	//Ships with prefix
	vector<Ship>ships_only_ubi;

	//We fill the vector with ships from the file
	for (int i=0; i<num; i++){
		input >> date >> time >> entry >> ubi;
		ships[i] = Ship(date, time, entry, ubi);
	}

	//We sort the ships by date
	selectionSort(ships);

	//We search for the prefix in the vector with all the ships
	for (int i = 0; i < num; i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		if(first_3 == prefix){
			//Format to show the found ships with the prefix
			mysolution << setfill('0');
			mysolution << setw(2) << ships[i].day << "-";
			mysolution << setw(2) << ships[i].month << "-";
			mysolution << setw(2) << ships[i].year << " ";
			mysolution << setw(2) << ships[i].hour << ":";
			mysolution << setw(2) << ships[i].minute << " ";
			mysolution << ships[i].entry <<" " << ships[i].ubi << "\n";
		}
	}

	input.close();
	mysolution.close();

	return 0;
}
