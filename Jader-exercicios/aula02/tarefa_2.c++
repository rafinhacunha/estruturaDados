#include <iostream>
using namespace std;

int main(){
    int arr[5];
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    }
    bool repetido = false;
    for(int i = 0; i < 5; i++){
        bool jaMostrou = false;
        for(int j = i + 1; j < 5; j++){
            if(arr[i] == arr[j] && !jaMostrou){
                cout << "O numero " << arr[i] << " se repete." << endl;
                jaMostrou = true;
                repetido = true;
            }
        }
    }
    if(!repetido)
        cout << "Nao ha numeros duplicados." << endl;
    return 0;
}