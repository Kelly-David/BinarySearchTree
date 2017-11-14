/**
* David Kelly C00193216
* Date: 24/02/2017
* DSA/Advanced Programming Assignment: Binary Search Tree (BST) implementation.
**/
#include <iostream>
#include <vector>
#include <algorithm>    
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>   
#include <random>
#include "BST.h"

using namespace std;

fstream fileA("a.txt", ios::in);
fstream fileB("b.txt", ios::in);
fstream fileC("c.txt", ios::in);
fstream fileD("d.txt", ios::in);
fstream fileE("e.txt", ios::in);
/*Test Files*/
fstream testFile("test.txt", ios::in);

/*Function: Read int from file, return int vector*/
vector<int> readFileData(fstream& n) {
	vector<int> numbers;
	string line;
	string delimiter = ",";
	if (n.is_open()) {
		while (getline(n, line)) {
			size_t pos = 0;
			string token;
			while ((pos = line.find(delimiter)) != string::npos) {
				token = line.substr(0, pos);
				int t = stoi(token);
				numbers.push_back(t);
				line.erase(0, pos + delimiter.length());
			}
		}
		n.close();
	}
	return numbers;
}

int main() {

	int pk, ch, tmp, root, fifth;
	string out;
	bool go = true;
	bool menu = true;
	vector<int> input;

	while (go) {
		menu = true;
		BinarySearchTree bst;
		cout << "Pick a file (1-5), or 0 to exit : " << endl;
		cin >> pk;
		if (pk == 1) {
			input = readFileData(fileA);
		}
		else if (pk == 2) {
			input = readFileData(fileB);
		}
		else if (pk == 3) {
			input = readFileData(fileC);
		}
		else if (pk == 4) {
			input = readFileData(fileD);
		}
		else if (pk == 5) {
			input = readFileData(fileE);
		}
		//Test files
		else if (pk == 6) {
			input = readFileData(testFile);
		}
		else {
			return 0;
		}
		int current;

		for (int i = 0; i < input.size(); i++) {
			if (i == 4) {
				fifth = input[i];
			}
			current = input[i];
			bst.add(current);
		}
		while (menu) {
			cout << endl << endl;
			cout << " Binary Search Tree Operations " << endl;
			cout << " ----------------------------- " << endl;
			cout << " 1. Insert " << endl;
			cout << " 2. In-Order Traversal " << endl;
			cout << " 3. Visualisation " << endl;
			cout << " 4. Search " << endl;
			cout << " 5. Remove 5th " << endl;
			cout << " 6. Remove Root " << endl; //Works once - 5th is defined during tree build
			cout << " 7. Switch File " << endl; //Build another tree
			cout << " Enter your choice : ";
			cin >> ch;
			switch (ch) {
			case 1: cout << " Enter Number to be inserted : ";
				cin >> tmp;
				bst.add(tmp);
				break;
			case 2: cout << endl;
				cout << " In-Order Traversal " << endl;
				cout << " -------------------" << endl;
				bst.printTree();
				break;
			case 3: cout << endl;
				cout << " Visualisation " << endl;
				cout << " -------------------" << endl;
				bst.postorder();
				break;
			case 4: cout << endl;
				cout << " Enter value : " ;
				cin >> tmp;
				out = (bst.search(tmp)) ? " found" : " not found";
				cout << " Value " << tmp << out << endl;
				break;
			case 5: cout << " Remove 5th : " << endl;
				cout << " --------------------" << endl;
				bst.remove(fifth);
				cout << " Fifth Node : " << fifth << " removed." << endl;
				break;
			case 6: cout << endl;
				cout << " Remove Root " << endl;
				cout << " --------------------" << endl;
				root = bst.getRoot();
				bst.remove(root);
				cout << " Root : " << root << " removed." << endl;
				cout << " New root : " << bst.getRoot() << endl;
				break;
			case 7:
				input.clear();
				menu = false;
			}
		}
	}
	return 0;
}