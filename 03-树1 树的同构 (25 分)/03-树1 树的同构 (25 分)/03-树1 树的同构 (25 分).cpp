// 03-树1 树的同构 (25 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode* Tree;

struct TreeNode {
	char Value;
	Tree left;
	Tree right;
};

struct TreeArrayNode
{
	char value;
	char left, right;
};

Tree buildTree() {
	int N;
	scanf("%d\n", &N);
	vector<TreeArrayNode> treeArray(N);
	for (int i = 0; i < N; i++)
	{
		char value;
		char left, right;
		scanf("%c %c %c\n", &value, &left, &right);
		treeArray[i] = {
			value,
			left,
			right
		};
	}
	vector<Tree> trees(N);
	for (int i = 0; i < N; i++)
	{
		Tree tree = (Tree)malloc(sizeof(struct TreeNode));
		tree->Value = treeArray[i].value;
		trees[i] = tree;
	}

	for (int i = 0; i < N; i++)
	{
		if (treeArray[i].left != '-') {
			trees[i]->left = trees[treeArray[i].left - '0'];
		}
		else {
			trees[i]->left = NULL;
		}

		if (treeArray[i].right != '-') {
			trees[i]->right = trees[treeArray[i].right - '0'];
		}
		else {
			trees[i]->right = NULL;
		}
	}
	vector<bool> hasFather(N, false);

	for (int i = 0; i < N; i++)
	{
		if (treeArray[i].left != '-') {
			hasFather[treeArray[i].left - '0'] = true;
		}

		if (treeArray[i].right != '-') {
			hasFather[treeArray[i].right - '0'] = true;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (hasFather[i] == false)
			return trees[i];
	}
	return NULL;
}


void printTree(Tree tree) {
	if (tree) {
		printf("%c", tree->Value);
		printTree(tree->left);
		printTree(tree->right);
	}
}

bool isSameTree(Tree tree1, Tree tree2) {
	if (tree1 && tree2) {
		if (tree1->Value == tree2->Value) {
			return (isSameTree(tree1->left, tree2->left) && isSameTree(tree1->right, tree2->right)) || (isSameTree(tree1->left, tree2->right) && isSameTree(tree1->right, tree2->left));
		}
		else {
			return false;
		}
	}

	if (!tree1 && !tree2) return true;

	return false;
}


int main()
{
	Tree tree1 = buildTree();
	//printTree(tree1);

	Tree tree2 = buildTree();
	if (isSameTree(tree1, tree2)) {
		printf("Yes");
	}
	else {
		printf("No");
	}
}
