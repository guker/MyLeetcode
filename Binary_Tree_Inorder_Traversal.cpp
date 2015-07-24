#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<stdio.h>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* CreateBiTree()
{
	TreeNode* root = new TreeNode(0);
	TreeNode* p = root;
	TreeNode* r;
	p->val = 1;
	r = new TreeNode(0);
	p->right = r;
	r->val = 2;
	p = r;
    r = new TreeNode(0);
	p->left = r;
	r->val = 3;

	return root;
}

class solution 
{
public:
	/*/// ·ÇµÝ¹é
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> path;
		stack<TreeNode*> st;
		if(root == NULL)
			return path;
		TreeNode* p = root;
		while(p != NULL || !st.empty())
		{
			while(p != NULL)
			{
				st.push(p);
				p = p->left;
			}
			if(!st.empty())
			{
				p = st.top();
				st.pop();
				path.push_back(p->val);
				p = p->right;
			}
		}
		return path;
	}
	*/ 
	vector<int> result;
	void inorder(TreeNode* root)
	{
		if(root == NULL)
			return;
		inorder(root->left);
		result.push_back(root->val);
		inorder(root->right);
	}

	vector<int> inorderTraversal(TreeNode* root)
	{
		result.clear();
		inorder(root);
		return result;
	}
	
};
int main()
{
	TreeNode* root;
	root = CreateBiTree();
	solution sln;
	vector<int> results;
	results = sln.inorderTraversal(root);
    return true;

}