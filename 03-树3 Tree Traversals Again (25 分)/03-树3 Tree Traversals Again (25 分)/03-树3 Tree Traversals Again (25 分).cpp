// 03-树3 Tree Traversals Again (25 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

typedef struct TreeNode* Tree;

struct TreeNode {
	int value;
	Tree left, right;
};


Tree buildTree(vector<int> preOrder, vector<int> inOrder) {
	if (preOrder.size() > 0) {
		int value = preOrder[0];
		int middle = 0;
		Tree tree;
		for (int i = 0; i < inOrder.size(); i++)
		{
			if (value == inOrder[i]) {
				middle = i;
				break;
			}
		}
		tree = (Tree)malloc(sizeof(struct TreeNode));
		tree->value = value;

		vector<int> preLeft(preOrder.begin() + 1, preOrder.begin() + 1 + middle);
		vector<int> inLeft(inOrder.begin(), inOrder.begin() + middle);
		tree->left = buildTree(preLeft, inLeft);

		vector<int> preRight(preOrder.begin() + 1 + middle, preOrder.end());
		vector<int> inRight(inOrder.begin() + middle + 1, inOrder.end());
		tree->right = buildTree(preRight, inRight);

		return tree;
	}

	return NULL;
}


void postOrderTravelsal(Tree tree) {
	static bool isFirst = true;

	if (tree) {
		postOrderTravelsal(tree->left);
		postOrderTravelsal(tree->right);
		if (isFirst) {
			printf("%d", tree->value);
			isFirst = false;
		}
		else {
			printf(" %d", tree->value);
		}
	}
}


int main()
{
	int N;
	scanf("%d\n", &N);
	vector<int> preOrder(N);
	vector<int>	inOrder(N);
	char operation[5];
	int preCount = 0;
	int inCount = 0;
	stack<int> s;
	for (int i = 0; i < N * 2; i++)
	{
		scanf("%s", operation);
		if (strcmp(operation, "Push") == 0) {
			int value;
			scanf(" %d\n", &value);
			s.push(value);
			preOrder[preCount] = value;
			preCount++;
		}
		else {
			int value = s.top();
			s.pop();
			inOrder[inCount] = value;
			inCount++;
		}
	}

	Tree tree = buildTree(preOrder, inOrder);
	postOrderTravelsal(tree);

}
