#include <iostream>
using namespace std;

void mul(int m1, int m2, int** M, int n1, int n2, int** N){
    if (m2 != n1) {
        cout << "multiplication is not possible as rows and columns are not equal." << endl;
        return;
    }

    int** result = new int* [m1];
    for (int i = 0; i < m1; ++i) {
        result[i] = new int[n2];
        for (int j = 0; j < n2; ++j) {
            result[i][j] = 0;
        }
    }
    
    
    
    for (int i = 0; i < m1; ++i) {
        for (int j = 0; j < n2; ++j) {
            for (int k = 0; k < m2; ++k) {
                result[i][j] += M[i][k] * N[k][j];
            }
        }
    }

    //printing the results
    cout << "result of multiplication is :" << endl;
    for (int i = 0; i < m1; ++i) {
        for (int j = 0; j < n2; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < m1; ++i) {
        delete[] result[i];
    }
    delete[] result;
}

int main() {
    int M[][2] = { { 1, 1 }, { 2, 2 } };
    int N[][2] = { { 1, 1 }, { 2, 2 } };
    int m1 = 2, m2 = 2, n1 = 2, n2 = 2;
    int** ptrM = new int* [m1];
    int** ptrN = new int* [n1];

    for (int i = 0; i < m1; ++i) {
        ptrM[i] = M[i];
    }

    for (int i = 0; i < n1; ++i) {
        ptrN[i] = N[i];
    }

    mul(m1, m2, ptrM, n1, n2, ptrN);

  //dlt space 
    delete[] ptrM;
    delete[] ptrN;

    return 0;
}