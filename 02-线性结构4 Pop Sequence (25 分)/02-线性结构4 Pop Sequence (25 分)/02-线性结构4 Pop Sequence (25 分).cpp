// 02-线性结构4 Pop Sequence (25 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isValidPopSequence(vector<int> sequence, int capacity) {
	stack<int> theStack;
	int j = 0;
	for (int i = 1; i <= sequence.size(); i++) {
		theStack.push(i);
		if (theStack.size() > capacity) {
			return false;
		}

		while (!theStack.empty() && theStack.top() == sequence[j]) {
			theStack.pop();
			j++;
		}
	}
	if (j == sequence.size()) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i < K; i++)
	{
		vector<int> sequence(N);

		for (int j = 0; j < N; j++) {
			int n;
			scanf("%d", &n);
			sequence[j] = n;
		}

		if (isValidPopSequence(sequence, M)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}
