// 03-树1 树的同构 (25 分)2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	char value;
	int left, right;
};

vector<TreeNode> readTree() {
	int N;
	scanf("%d\n", &N);
	vector<TreeNode> tree(N);
	for (int i = 0; i < N; i++)
	{
		char value, left, right;
		scanf("%c %c %c\n", &value, &left, &right);
		tree[i] = {
			value,
			left == '-' ? -1 : left - '0',
			right == '-' ? -1 : right - '0'
		};
	}
	return tree;
}

int headOfTree(vector<TreeNode> tree) {

	vector<bool> hasFather(tree.size(), false);

	for (size_t i = 0; i < tree.size(); i++)
	{
		if (tree[i].left != -1) {
			hasFather[tree[i].left] = true;
		}

		if (tree[i].right != -1) {
			hasFather[tree[i].right] = true;
		}
	}

	for (int i = 0; i < tree.size(); i++)
	{
		if (hasFather[i] == false) {
			return i;
		}
	}
	return -1;
}


bool isSameTree(vector<TreeNode> tree1, int head1, vector<TreeNode> tree2, int head2) {
	if (head1 != -1 && head2 != -1) {
		if (tree1[head1].value == tree2[head2].value) {
			return (isSameTree(tree1, tree1[head1].left, tree2, tree2[head2].left) &&
				isSameTree(tree1, tree1[head1].right, tree2, tree2[head2].right)) ||
				(isSameTree(tree1, tree1[head1].left, tree2, tree2[head2].right) &&
					isSameTree(tree1, tree1[head1].right, tree2, tree2[head2].left));
		}
	}

	if (head1 == -1 && head2 == -1) {
		return true;
	}

	return false;
}


bool isSameTree(vector<TreeNode> tree1, vector<TreeNode> tree2) {
	int head1 = headOfTree(tree1);
	int head2 = headOfTree(tree2);
	return isSameTree(tree1, head1, tree2, head2);
}

int main()
{
	vector<TreeNode> tree1 = readTree();
	vector<TreeNode> tree2 = readTree();
	if (isSameTree(tree1, tree2)) {
		printf("Yes");
	}
	else {
		printf("No");
	}
}
