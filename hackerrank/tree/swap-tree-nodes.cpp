#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */

class Node {
    public:    
        int data;
        Node *left, *right;

        Node( int data ) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }

        ~Node() {
            delete this -> left;
            delete this -> right;
        }
};

Node* constructTree( vector<vector<int>> nodes ) {
    Node* root = new Node(1);
    queue<Node*> q;
    q.push( root );

    int index = 0;
    while( !q.empty() ) {
        Node* front = q.front();
        q.pop();

        if ( nodes.at(index).at(0) != -1 ) {
            Node *left = new Node( nodes.at(index).at(0) );
            front -> left = left;
            q.push(left);
        }

        if ( nodes.at(index).at(1) != -1 ) {
            Node *right = new Node( nodes.at(index).at(1) );
            front -> right = right;
            q.push(right);
        }
        
        index++;
    }
    return root;
}

void swapTreeNodes( Node* root, int level, int target ) {

    if (!root)
        return;

    if ( level % target == 0 ) {
        Node *tempLeft = root -> left;
        root -> left = NULL;
        root -> left = root -> right;
        root -> right = NULL;
        root -> right = tempLeft;
    }

    swapTreeNodes( root -> left, level+1, target );    
    swapTreeNodes( root -> right, level+1, target );
}

void printInOrder(Node* root, vector<int> *sub) {
    if (!root)
        return;

    printInOrder( root -> left, sub );
    sub -> push_back( root -> data );
    printInOrder( root -> right, sub );
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {

    vector<vector<int>> sol;
    Node *root = constructTree( indexes );
    
    for (int i = 0; i < queries.size(); ++i) {
        vector<int> *sub = new vector<int>();
        swapTreeNodes( root, 1, queries.at(i) );
        queries[i] = INT_MIN;
        printInOrder( root, sub );
        sol.push_back(*sub);
    }
    return sol;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];

            if (j != result[i].size() - 1) {
                cout << " ";
            }
        }

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
