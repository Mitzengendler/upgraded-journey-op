#include "IO.h"

string** read_io(int* pn, string name)
{
    ifstream file;
    
    file.open(name);
    if (file.is_open() == 0) {
        cout << "Ошибка открылия файла!";
        exit(0);
    }
    else {
        cout << "Файл открыт." << endl;
        string temp;
        int n;
        file >> n;
        cout << "Количество команд: " << n << endl;
        *pn = n;

        //Inin matr for io input
        string** arrl = init_io(pn);

        for (int i = 0; i < *pn; i++) {
            for (int j = 0; j < *pn; j++) {
                getline(file, temp, ',');
                arrl[i][j] = temp;
            }
        }
        return arrl;
    }
    file.close();
}

string** init_io(int* pn) {//del init io
    string** arr = new string* [*pn];
    for (int i = 0; i < *pn; i++) {
        arr[i] = new string[*pn];
    }
    return arr;
}

void print_io(int* pn, string** matrix)
{
    for (int i = 0; i < *pn; i++) {
        for (int j = 0; j < *pn; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}