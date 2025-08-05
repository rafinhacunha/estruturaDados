#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr, int maxVal) {
    vector<int> count(maxVal + 1, 0);
    for (int num : arr) count[num]++;
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]-- > 0) {
            arr[index++] = i;
        }
    }
}

void countingSortWithNegatives(vector<int>& arr) {
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    int offset = -minVal;
    vector<int> count(maxVal - minVal + 1, 0);

    for (int num : arr) count[num + offset]++;
    int index = 0;
    for (int i = 0; i < count.size(); i++) {
        while (count[i]-- > 0) {
            arr[index++] = i - offset;
        }
    }
}
