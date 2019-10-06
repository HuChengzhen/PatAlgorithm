// 03-树2 List Leaves (25 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int value;
	int left, right;
};

vector<TreeNode> readTree() {
	int N;
	scanf("%d\n", &N);
	vector<TreeNode> tree(N);
	for (int i = 0; i < N; i++)
	{
		char left, right;
		scanf("%c %c\n", &left, &right);
		tree[i] = {
			i,
			left == '-' ? -1 : left - '0',
			right == '-' ? -1 : right - '0'
		};
	}
	return tree;
}

int headOfTree(vector<TreeNode> tree) {
	vector<bool> hasFather(tree.size(), false);
	for (int i = 0; i < tree.size(); i++)
	{
		if (tree[i].left != -1) {
			hasFather[tree[i].left] = true;
		}

		if (tree[i].right != -1) {
			hasFather[tree[i].right] = true;
		}
	}

	for (int  i = 0; i < tree.size(); i++)
	{
		if (hasFather[i] == false)
			return i;
	}
	return -1;
}


void levelOrderTraversal(vector<TreeNode> tree) {
	static bool isFirst = true;
	int head = headOfTree(tree);
	queue<TreeNode> q;
	if (head == -1) return;
	q.push(tree[head]);
	while (!q.empty())
	{
		TreeNode t = q.front();
		q.pop();
		if (t.left == -1 && t.right == -1) {
			if (isFirst) {
				printf("%d", t.value);
				isFirst = false;
			} else
				printf(" %d", t.value);
		}
		if (t.left != -1)
			q.push(tree[t.left]);
		if (t.right != -1)
			q.push(tree[t.right]);
	}
}


int main()
{
	auto tree = readTree();
	levelOrderTraversal(tree);
}
