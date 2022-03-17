#include <vector>
#include <queue>
using namespace std;

template <typename type>
class treeNode {
	public:
		type data;
		vector<treeNode*> childrens;
		treeNode( type data ) {
			this -> data = data;
		}

		~treeNode() {
			for (int i = 0; i < childrens.size(); ++i) {
				delete childrens.at(i);
			}
		}
};