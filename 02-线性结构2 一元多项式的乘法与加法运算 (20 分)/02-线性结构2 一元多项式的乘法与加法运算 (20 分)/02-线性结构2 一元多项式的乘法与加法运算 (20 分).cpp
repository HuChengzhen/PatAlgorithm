// 02-线性结构2 一元多项式的乘法与加法运算 (20 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

struct PolyNode {
	int exponent;
	int coefficient;
};

vector<PolyNode> readPoly()
{
	int length;
	scanf("%d", &length);
	vector<PolyNode> poly(length);
	for (auto i = poly.begin(); i < poly.end(); i++)
	{
		int coefficient;
		int exponent;
		scanf("%d %d", &coefficient, &exponent);
		*i = {
			exponent,
			coefficient
		};
	}
	return poly;
};

vector<PolyNode> addPoly(vector<PolyNode> poly1, vector<PolyNode> poly2) {
	vector<PolyNode> polySum;
	auto i = poly1.begin();
	auto j = poly2.begin();
	while (i < poly1.end() && j < poly2.end())
	{
		if ((*i).exponent > (*j).exponent) {
			PolyNode node = *i;
			polySum.push_back(node);
			i++;
		}
		else if ((*i).exponent < (*j).exponent) {
			PolyNode node = *j;
			polySum.push_back(node);
			j++;
		}
		else {
			if ((*i).coefficient + (*j).coefficient != 0) {
				PolyNode node = {
					(*i).exponent,
					(*i).coefficient + (*j).coefficient
				};
				polySum.push_back(node);
			}
			i++;
			j++;
		}
	}
	while (i < poly1.end()) {
		PolyNode node = *i;
		polySum.push_back(node);
		i++;
	}

	while (j < poly2.end())
	{
		PolyNode node = *j;
		polySum.push_back(node);
		j++;
	}
	if (polySum.size() == 0) {
		polySum.push_back({ 0,0 });
		return polySum;
	}

	return polySum;
}

void printPoly(vector<PolyNode> poly) {

	if (poly.size() == 0) {
		printf("0 0");
		return;
	}

	for (auto i = poly.begin(); i <poly.end(); i++)
	{
		if (i == poly.begin())
			printf("%d %d", (*i).coefficient, (*i).exponent);
		else
			printf(" %d %d", (*i).coefficient, (*i).exponent);
	}
}

vector<PolyNode> mutiplyPoly(vector<PolyNode> poly1, vector<PolyNode> poly2) {
	vector<PolyNode> tempMuti(poly2.size());
	vector<PolyNode> tempSum(0);
	for (auto i = 0; i < poly1.size(); i++) {
		PolyNode node = poly1[i];
		for (auto j = 0; j < poly2.size(); j++) {
			int exponent = node.exponent + poly2[j].exponent;
			int coefficient = node.coefficient * poly2[j].coefficient;
			tempMuti[j] = {
				exponent,
				coefficient
			};
		}
		tempSum = addPoly(tempSum, tempMuti);
	}
	return tempSum;
}

int main()
{
	 vector<PolyNode> poly1 = readPoly();
	 vector<PolyNode> poly2 = readPoly();
	 auto poly4 = mutiplyPoly(poly1, poly2);
	 printPoly(poly4);
	 printf("\n");
	 auto poly3 = addPoly(poly1, poly2);
	 printPoly(poly3);
}



