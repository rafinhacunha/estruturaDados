#include <iostream>
using namespace std;

int main(){
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    int maximo = arr[0];
    int minimo = arr[0];
    int soma = arr[0];
    for (int i = 1; i < 5; i++)
    {
        if (arr[i] > maximo)
            maximo = arr[i];
        if (arr[i] < minimo)
            minimo = arr[i];
        soma += arr[i];
    }
    float media = soma / 5.0;
    int acimaMedia = 0;
    for (int i = 0; i < 5; i++) {
        if (arr[i] > media)
            acimaMedia++;
    }
    cout << "\nResultado:" << endl;
    cout << "Maximo: " << maximo << endl;
    cout << "Minimo: " << minimo << endl;
    cout << "Media: " << media << endl;
    cout << "Quantidade de valores acima da media: " << acimaMedia << endl;
}