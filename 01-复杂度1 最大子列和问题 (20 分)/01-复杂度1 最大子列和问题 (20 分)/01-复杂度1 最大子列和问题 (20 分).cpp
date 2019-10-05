// 01-复杂度1 最大子列和问题 (20 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;
int maxSubSequenceSum(vector<int> list);

int main()
{
	int length;
	scanf("%d", &length);
	vector<int> list(length);
	for (int i = 0; i < length; i++) {
		int n;
		scanf("%d", &n);
		list[i] = n;
	}

	printf("%d", maxSubSequenceSum(list));
}

int maxSubSequenceSum(vector<int> list) {
	int tempSum, max;
	tempSum = max = 0;
	for (auto i = list.begin(); i < list.end(); i++) {
		tempSum += *i;
		if (tempSum > max) {
			max = tempSum;
		}
		else if (tempSum < 0) {
			tempSum = 0;
		}
	}
	return max;
}