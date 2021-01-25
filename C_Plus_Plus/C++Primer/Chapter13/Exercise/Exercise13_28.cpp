#include "INCLUDE.hpp"

class TreeNode
{
public:
    TreeNode() : value(""), count(0), left(nullptr), right(nullptr) { }
    TreeNode(TreeNode & other) : value(other.value), count(other.count) { *left = *other.left; *right = *other.right; }
    TreeNode & operator=(const TreeNode & rhs); 
    ~TreeNode();
private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree
{
public:
    BinStrTree() : root(nullptr) { }
    BinStrTree(BinStrTree & other) { *root = *other.root; }
    BinStrTree & operator=(const BinStrTree & rhs) { TreeNode * tmp = new TreeNode(*rhs.root); delete root; root = tmp; return *this; }
    ~BinStrTree() { delete root; }
private:
    TreeNode *root;
};

TreeNode & TreeNode::operator=(const TreeNode & rhs)
{
    value = rhs.value; 
    count = rhs.count; 

    TreeNode * tmp1 = new TreeNode(*rhs.left);
    delete left;
    left = tmp1;

    TreeNode * tmp2 = new TreeNode(*rhs.right);
    delete right;
    right = tmp2;

    return *this;
}

TreeNode::~TreeNode()
{
    delete left;
    delete right;
}

int main()
{

}