#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void traversal(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    traversal(node->left);
    traversal(node->right);
    cout << node->val << endl;
}


int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    traversal(root);

    return 0;

}