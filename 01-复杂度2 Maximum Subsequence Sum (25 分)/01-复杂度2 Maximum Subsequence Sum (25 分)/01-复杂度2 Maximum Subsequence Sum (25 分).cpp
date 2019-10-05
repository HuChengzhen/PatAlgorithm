// 01-复杂度2 Maximum Subsequence Sum (25 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;
void printMaxSubSequenceSum(vector<int> list);
int main()
{
	int K;
	scanf("%d", &K);
	vector<int> list(K);

	for (auto i = list.begin(); i < list.end(); i++) {
		int N;
		scanf("%d", &N);
		*i = N;
	}
	printMaxSubSequenceSum(list);
}

void printMaxSubSequenceSum(vector<int> list) {
	int tempSum = 0;
	int max = 0;
	int first, last;
	first = last = 0;
	int tempFirst = list[0];
	bool allNegtive = true;

	for (auto i = list.begin(); i < list.end(); i++) {
		if (*i >= 0) {
			allNegtive = false;
		}
		tempSum += *i;
		if (tempSum > max) {
			max = tempSum;
			last = *i;
			first = tempFirst;
		}
		else if (tempSum < 0) {
			tempSum = 0;
			if (i < list.end() - 1) {
				tempFirst = *(i + 1);
			}
		}
	}

	if (allNegtive) {
		printf("0 %d %d", *list.begin(), *(list.end() - 1));
		return;
	}
	printf("%d %d %d", max, first, last);
}
