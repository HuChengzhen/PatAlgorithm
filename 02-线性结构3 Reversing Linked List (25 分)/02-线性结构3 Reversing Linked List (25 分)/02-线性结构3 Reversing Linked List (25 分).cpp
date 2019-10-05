// 02-线性结构3 Reversing Linked List (25 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <stack>

using namespace std;

struct Node {
	int address;
	int value;
	int next;
};


void printNode(Node node) {
	static bool isFirst = true;
	if (isFirst) {
		printf("%05d %d", node.address, node.value);
		isFirst = false;
	}
	else {
		printf(" %05d\n%05d %d", node.address, node.address, node.value);
	}
}

int main()
{
	int first, N, K;
	scanf("%d %d %d", &first, &N, &K);
	map<int, Node> linkList;
	for (int i = 0; i < N; i++) {
		int address, value, next;
		scanf("%d %d %d", &address, &value, &next);
		linkList[address] = {
			address,
			value,
			next
		};
	}

	int count = 0;
	int p = first;

	while (p != -1)
	{
		p = linkList[p].next;
		count++;
	}

	p = first;
	stack<Node> nodeStack;

	for (int i = 0; count >=K; count -= K, i = 0)
	{
		for (; i < K; i++) {
			Node node = linkList[p];
			nodeStack.push(node);
			p = node.next;
		}

		while (!nodeStack.empty())
		{
			Node node = nodeStack.top();
			nodeStack.pop();
			printNode(node);
		}
	}
	for (; count > 0; count--) {
		Node node = linkList[p];
		printNode(node);
		p = node.next;
	}
	printf(" -1");
}

