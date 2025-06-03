#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

void printArray(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j+1] = arr[j--];
        arr[j+1] = key;
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

void testarOrdenacao(void (*sortFunc)(vector<int>&), string nome) {
    cout << "=== Testando: " << nome << " ===" << endl;

    vector<vector<int>> testes = {
        {1, 2, 3, 4, 5},                    // ordenado
        {5, 4, 3, 2, 1},                    // invertido
        {3, 1, 4, 1, 5, 9, 2},              // aleatório
        {2, 2, 2, 2, 2},                    // repetidos
    };

    for (int i = 0; i < testes.size(); ++i) {
        vector<int> arr = testes[i];
        cout << "Original: ";
        printArray(arr);
        sortFunc(arr);
        cout << "Ordenado: ";
        printArray(arr);
        cout << endl;
    }
}
int main() {
    testarOrdenacao(bubbleSort, "Bubble Sort");
    testarOrdenacao(insertionSort, "Insertion Sort");
    testarOrdenacao(selectionSort, "Selection Sort");
    return 0;
}
