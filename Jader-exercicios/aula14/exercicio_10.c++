#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

int buscaSequencial(const vector<int>& v, int chave) {
    for (int i = 0; i < v.size(); ++i)
        if (v[i] == chave) return i;
    return -1;
}

int buscaBinaria(const vector<int>& v, int chave) {
    int ini = 0, fim = v.size() - 1;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        if (v[meio] == chave) return meio;
        else if (v[meio] < chave) ini = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

vector<int> gerarVetor(int tamanho) {
    vector<int> v(tamanho);
    mt19937 gen(random_device{}());
    uniform_int_distribution<> dis(1, 1000000);
    for (int& x : v) x = dis(gen);
    return v;
}

template<typename Func>
double medirTempo(Func func, const vector<int>& v, int chave, int repeticoes = 5) {
    double total = 0.0;
    for (int i = 0; i < repeticoes; ++i) {
        auto inicio = high_resolution_clock::now();
        func(v, chave);
        auto fim = high_resolution_clock::now();
        total += duration<double, micro>(fim - inicio).count();
    }
    return total / repeticoes;
}

int main() {
    vector<int> tamanhos = {100, 1000, 10000, 100000, 1000000}; // Evite 10^7 se estiver testando localmente
    cout << "Tamanho\tSeq(us)\tBin(us)\n";

    for (int tam : tamanhos) {
        vector<int> v = gerarVetor(tam);
        int chave_seq = v.back(); 

        double tempo_seq = medirTempo(buscaSequencial, v, chave_seq);

        sort(v.begin(), v.end());
        int chave_bin = -1;
        double tempo_bin = medirTempo(buscaBinaria, v, chave_bin);

        cout << tam << "\t" << tempo_seq << "\t" << tempo_bin << endl;
    }

    return 0;
}
