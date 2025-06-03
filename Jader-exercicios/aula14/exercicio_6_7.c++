#include <vector>
#include <iostream>

std::vector<int> buscaSequencialOcorrencias(const std::vector<int>& vetor, int chave) {
    std::vector<int> indices;
    for (int i = 0; i < vetor.size(); ++i) {
        if (vetor[i] == chave) {
            indices.push_back(i);
        }
    }
    return indices;
}
int buscaBinariaPontoInsercao(const std::vector<int>& vetor, int chave) {
    int inicio = 0, fim = vetor.size() - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (vetor[meio] == chave) {
            return meio; 
        } else if (vetor[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return inicio; 
}

#include <iostream>

int main() {
    std::vector<int> dados = {1, 3, 3, 5, 7, 9};

    auto indices = buscaSequencialOcorrencias(dados, 3);
    std::cout << "Ocorrências de 3: ";
    for (int idx : indices) std::cout << idx << " ";
    std::cout << "\n";

    int pos = buscaBinariaPontoInsercao(dados, 4);
    std::cout << "4 deve ser inserido na posição: " << pos << "\n";

    return 0;
}

