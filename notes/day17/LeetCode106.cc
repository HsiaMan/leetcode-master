#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* 二叉树节点定义 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* Solution：构造二叉树（LC106） */
class Solution {
private:
    unordered_map<int, int> indexMap; // 中序值 -> 下标

    TreeNode* build(
        vector<int>& inorder, int inL, int inR,
        vector<int>& postorder, int postL, int postR
    ) {
        if (postL > postR) return nullptr;

        int rootVal = postorder[postR];
        TreeNode* root = new TreeNode(rootVal);

        int idx = indexMap[rootVal];
        int leftSize = idx - inL;

        root->left = build(
            inorder, inL, idx - 1,
            postorder, postL, postL + leftSize - 1
        );

        root->right = build(
            inorder, idx + 1, inR,
            postorder, postL + leftSize, postR - 1
        );

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        indexMap.clear();
        for (int i = 0; i < inorder.size(); ++i) {
            indexMap[inorder[i]] = i;
        }

        return build(
            inorder, 0, inorder.size() - 1,
            postorder, 0, postorder.size() - 1
        );
    }
};

/* ---------- 测试辅助函数 ---------- */

/* 前序遍历（验证结构用） */
void preorderPrint(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

/* 中序遍历（验证是否等于原 inorder） */
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

/* 后序遍历（验证是否等于原 postorder） */
void postorderPrint(TreeNode* root) {
    if (!root) return;
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->val << " ";
}

/* 释放内存（防止泄漏） */
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

/* ---------------- main ---------------- */
int main() {
    // 测试用例（就是我们一直用的那棵稍微复杂的树）
    vector<int> inorder   = {4, 7, 2, 1, 5, 3, 8, 6};
    vector<int> postorder = {7, 4, 2, 5, 8, 6, 3, 1};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Preorder  : ";
    preorderPrint(root);
    cout << endl;

    cout << "Inorder   : ";
    inorderPrint(root);
    cout << endl;

    cout << "Postorder : ";
    postorderPrint(root);
    cout << endl;

    freeTree(root);
    return 0;
}
