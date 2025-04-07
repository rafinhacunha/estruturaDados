#include <iostream>
using namespace std;

int main(){
    int mat1[2][2];
    int mat2[2][2];
    cout << "Matriz 1" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> mat1[i][j];
        }
    }
    cout << "Matriz 2" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> mat2[i][j];
        }
    }
    int matsoma[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matsoma[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matsoma[i][j] << " ";
        }
        cout << "\n";
    }
}