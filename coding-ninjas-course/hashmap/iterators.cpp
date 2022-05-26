#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	unordered_map<string, int> Umap;
	Umap["a"] = 1;
	Umap["b"] = 2;
	Umap["c"] = 3;
	Umap["d"] = 4;
	Umap["e"] = 5;
	Umap["f"] = 6;

	unordered_map<string, int> :: iterator it;
	for (it = Umap.begin(); it != Umap.end(); ++it) {
		cout << it -> first << "  " << it -> second << endl;
	}

	cout << endl;
	vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> :: iterator vit;
	for (vit = arr.begin(); vit != arr.end(); ++vit) {
		cout << *vit << " "; 	
	}

	cout << endl;

	map<string, int> Omap;
	Omap["a"] = 1;
	Omap["b"] = 2;
	Omap["c"] = 3;
	Omap["d"] = 4;
	Omap["e"] = 5;
	Omap["f"] = 6;

	map<string, int> :: iterator oit;
	for (oit = Omap.begin(); oit != Omap.end(); ++oit) {
		cout << oit -> first << "  " << oit -> second << endl;
	}

}