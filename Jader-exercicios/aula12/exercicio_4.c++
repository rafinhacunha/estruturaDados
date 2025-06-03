#include <iostream>
#include <vector>
using namespace std;

struct Par {
    int chave;
    char id;  
};


void insertionSortEstavel(vector<Par>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        Par key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].chave > key.chave)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

void selectionSortInstavel(vector<Par>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j].chave < arr[minIdx].chave)
                minIdx = j;
        if (minIdx != i)
            swap(arr[i], arr[minIdx]);
    }
}

void imprimir(const vector<Par>& arr) {
    for (auto p : arr)
        cout << "(" << p.chave << "," << p.id << ") ";
    cout << endl;
}

int main() {
    vector<Par> original = {
        {2, 'A'},
        {1, 'B'},
        {2, 'C'},
        {1, 'D'}
    };

    cout << "Original: ";
    imprimir(original);

    vector<Par> insertion = original;
    vector<Par> selection = original;

    insertionSortEstavel(insertion);
    selectionSortInstavel(selection);

    cout << "Insertion Sort (estável): ";
    imprimir(insertion);

    cout << "Selection Sort (instável): ";
    imprimir(selection);

    return 0;
}
