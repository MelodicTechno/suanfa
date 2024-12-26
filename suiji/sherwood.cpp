#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Sherwood {
public:
    Sherwood(int n) : n(n) {
        std::srand(std::time(0));
    }

    void generateRandomForest() {
        forest.clear();
        for (int i = 0; i < n; ++i) {
            forest.push_back(generateRandomTree());
        }
    }

    void printForest() const {
        for (const auto& tree : forest) {
            printTree(tree);
            std::cout << std::endl;
        }
    }

private:
    struct TreeNode {
        int value;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
    };

    int n;
    std::vector<TreeNode*> forest;

    TreeNode* generateRandomTree() {
        int depth = std::rand() % 5 + 1; // Random depth between 1 and 5
        return generateRandomTreeHelper(depth);
    }

    TreeNode* generateRandomTreeHelper(int depth) {
        if (depth == 0) return nullptr;
        TreeNode* node = new TreeNode(std::rand() % 100);
        node->left = generateRandomTreeHelper(depth - 1);
        node->right = generateRandomTreeHelper(depth - 1);
        return node;
    }

    void printTree(TreeNode* root) const {
        if (!root) return;
        std::cout << root->value << " ";
        printTree(root->left);
        printTree(root->right);
    }
};

int main() {
    Sherwood sherwood(3);
    sherwood.generateRandomForest();
    sherwood.printForest();
    return 0;
}