#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printRoad(vector<int> &heap, int index) {
    while (index > 0) {
        printf("%d ", heap[index]);
        index = (index - 1) / 2;
    }
    printf("%d", heap[index]);
    printf("\n");
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> heap;
    for (int i = 0; i < N; ++i) {
        int v;
        scanf("%d", &v);
        heap.push_back(v);
        push_heap(heap.begin(), heap.end(), greater<int>());
    }

    for (int i = 0; i < M; ++i) {
        int t;
        scanf("%d", &t);
        printRoad(heap, t - 1);
    }


    return 0;
}