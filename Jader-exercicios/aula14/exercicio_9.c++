#include <vector>
#include <string>

int buscaTernaria(const std::vector<int>& vetor, int chave) {
    int inicio = 0, fim = vetor.size() - 1;

    while (inicio <= fim) {
        int terco1 = inicio + (fim - inicio) / 3;
        int terco2 = fim - (fim - inicio) / 3;

        if (vetor[terco1] == chave) return terco1;
        if (vetor[terco2] == chave) return terco2;

        if (chave < vetor[terco1]) {
            fim = terco1 - 1;
        } else if (chave > vetor[terco2]) {
            inicio = terco2 + 1;
        } else {
            inicio = terco1 + 1;
            fim = terco2 - 1;
        }
    }

    return -1; // não encontrado
}
