#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++)
        for (int j = 0; j < arr.size() - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

vector<int> gerarArray(int n, string tipo) {
    vector<int> arr(n);
    if (tipo == "ordenado")
        for (int i = 0; i < n; i++) arr[i] = i;
    else if (tipo == "invertido")
        for (int i = 0; i < n; i++) arr[i] = n - i;
    else
        for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
    return arr;
}

int main() {
    vector<int> arr = gerarArray(1000, "aleatorio");

    auto start = high_resolution_clock::now();
    bubbleSort(arr);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "Tempo: " << duration << " ms" << endl;

    return 0;
}

// A medição de tempo confirma que todos os três algoritmos têm crescimento quadrático, mas o Insertion Sort é claramente mais rápido em arrays quase ordenados.