#include <iostream>
using namespace std;

void matrizSequencial(int m, int n) {
    int* matriz = new int[m * n];

    for (int i = 0; i < m * n; i++) {
        matriz[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i * n + j] << " ";
        }
        cout << endl;
    }

    delete[] matriz;
}

int main() {
    int linhas, colunas;
    cin >> linhas >> colunas;
    matrizSequencial(linhas, colunas);
    return 0;
}