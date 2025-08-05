#include <vector>
#include <string>

int buscaBinariaStrings(const std::vector<std::string>& vetor, const std::string& chave) {
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
    return -1; // não encontrado
}
