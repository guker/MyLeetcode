/********************************************************************************** 
* 
* Invert a binary tree.
*      4
*    /   \
*   2     7
*  / \   / \
* 1   3 6   9
* 
* to
*      4
*    /   \
*   7     2
*  / \   / \
* 9   6 3   1
* 
* Trivia:
* This problem was inspired by this original tweet by Max Howell:
* (https://twitter.com/mxcl/status/608682016205344768)
*
*  | Google: 90% of our engineers use the software you wrote (Homebrew), 
*  | but you can’t invert a binary tree on a whiteboard so fuck off.
*               
**********************************************************************************/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/// 递归实现
	TreeNode* invertTree_recursive(TreeNode* root) {
		if (root==NULL) return root;
		TreeNode* node = invertTree_recursive(root->left);
		root->left = invertTree_recursive(root->right);
		root->right = node;
		return root;
	}
	/// 非递归实现
	TreeNode* invertTree_non_recursive(TreeNode* root) {
		if (root==NULL) return root;
		vector<TreeNode*> stack;
		stack.push_back(root);
		while (!stack.empty()) {
			TreeNode* node = stack.back();
			stack.pop_back();
			swap(node->left, node->right);
			if (node->left) stack.push_back(node->left);
			if (node->right) stack.push_back(node->right);
		}
		return root;
	}

	TreeNode* invertTree(TreeNode* root) {
		if (rand()%2){
			return invertTree_non_recursive(root);
		}
		return invertTree_recursive(root);    
	}
};
