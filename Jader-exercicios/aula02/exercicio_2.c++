#include <iostream>
using namespace std;

int main(){
    int vet[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> vet[i];
    }
    for (int i = 7; i >= 0; i--)
    {
        cout << " " << vet[i];
    }
    
}