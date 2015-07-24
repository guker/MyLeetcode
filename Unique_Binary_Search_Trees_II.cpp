#include<iostream>
#include<vector>


using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};


class solution 
{
public:
	vector<TreeNode*> generateTrees(int n)
	{
		return createTree(1,n);
	}

	vector<TreeNode*> createTree(int start, int end)
	{
		vector<TreeNode*> results;
		if(start > end)
		{
			results.push_back(NULL);
			return results;
		}

		for(int k = start; k <= end; k++)
		{
			vector<TreeNode*> left = createTree(start,k-1);
			vector<TreeNode*> right = createTree(k+1,end);
			for(int i = 0; i < left.size();i++)
			{
				for(int j = 0; j < right.size(); j++)
				{
					TreeNode* root = new TreeNode(k);
					root->left = left[i];
					root->right = right[j];
					results.push_back(root);
				}
			}
		}
		return results;
	}

	
};
int main()
{
	vector<TreeNode*> Tr;
	solution sln;
	Tr = sln.generateTrees(3);
	

    return true;

}