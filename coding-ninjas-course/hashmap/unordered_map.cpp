#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	unordered_map<int, int> ourmap;

	// insert
	ourmap[1] = 100;

	// size of map
	cout << ourmap.size() << endl;

	// access
	cout << ourmap.at(1) << endl;

	// erase
	ourmap.erase(1);
	cout << ourmap.size() << endl;

	ourmap[2] = 200;
	// count its always either 1 or 0
	cout << ourmap.count(1) << "\t" << ourmap.count(2) << endl;
}