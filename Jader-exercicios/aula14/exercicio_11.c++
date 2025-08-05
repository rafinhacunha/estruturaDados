// A complexidade média O(n) da busca sequencial assume que a probabilidade de encontrar o elemento é uniforme em todas as posições do vetor.
// Mas se 90% das buscas forem por elementos que estão nos primeiros 5% do vetor, então a maioria das buscas termina muito rapidamente.
// Nesse caso, o tempo médio de execução deixa de ser proporcional a n e passa a depender da distribuição probabilística dos elementos buscados.

/* int buscaSequencialOtima(std::vector<int>& v, int chave) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == chave) {
            // Opcional: mover o elemento para frente para acelerar buscas futuras
            if (i > 0) std::swap(v[i], v[i - 1]);
            return i;
        }
    }
    return -1;
}*/
 
// Conclusão:
// Quando a distribuição de acessos é desbalanceada, a análise teórica clássica (O(n)) não reflete o desempenho real. A localidade de referência pode e deve ser explorada com técnicas adaptativas para obter grandes ganhos de desempenho na prática.