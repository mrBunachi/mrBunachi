#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int id;
    vector<TreeNode*> children;
    TreeNode(int x) : id(x) {}
};

class Tree{
public:
    TreeNode* root = nullptr;
    unordered_map<int, TreeNode*> nodes; // Luu cac nut cua cay theo id

    void makeRoot(int u){
        if ( nodes.find(u) == nodes.end() ) {
            root = new TreeNode(u);
            nodes[u] = root;
        }
    }

    void insert(int u, int v){
        if ( nodes.find(u) == nodes.end() && nodes.find(v) != nodes.end() ) {
            TreeNode* newNode = new TreeNode(u);
            nodes[u] = newNode;
            nodes[v]->children.push_back(newNode);
        }
    }

    void preOrder(TreeNode* node){
        if ( node == nullptr )
            return;
        cout << node->id << ' ';
        for ( TreeNode* child : node->children )
            preOrder(child);
    }

    void inOrder(TreeNode* node){
        if ( node == nullptr )
            return;
        int n = node->children.size();
        if ( n>0 ) inOrder(node->children[0]);
        cout << node->id << ' ';
        for ( int i=1 ; i<n ; i++ )
            inOrder(node->children[i]);
    }

    void postOrder(TreeNode* node){
        if ( node == nullptr )
            return;
        for ( TreeNode* child : node->children )
            preOrder(child);
        cout << node->id << ' ';
    }
};

int main(){
    #define taskname "file"
    if ( fopen(taskname".inp", "r") ){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
    Tree tree;
    string command;
    while ( cin>>command && command != "*" ){
        if ( command == "MakeRoot" ){
            int u;
            cin >> u;
            tree.makeRoot(u);
        }   else if ( command == "Insert" ) {
            int u, v;
            cin >> u >> v;
            tree.insert(u, v);
        } else if (command == "PreOrder") {
            if (tree.root != nullptr) {
                tree.preOrder(tree.root);
                cout << endl;
            }
        } else if (command == "InOrder") {
            if (tree.root != nullptr) {
                tree.inOrder(tree.root);
                cout << endl;
            }
        } else if (command == "PostOrder") {
            if (tree.root != nullptr) {
                tree.postOrder(tree.root);
                cout << endl;
            }
        }
    }
    return 0;
}
