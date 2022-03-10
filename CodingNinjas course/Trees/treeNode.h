#include <vector>
using namespace std;

template <typename type>
class treeNode {
	public:
		type data;
		vector<treeNode*> childrens;
		treeNode( type data ) {
			this -> data = data;
		}
};