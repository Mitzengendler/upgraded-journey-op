#include "IO.h"

string* read_io(int* pn, string name)
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
        getline(file, temp);
        n = stoi(temp);
        //file >> n;
        cout << "Количество команд: " << n << endl;
        *pn = n;

        //Inin matr for io input
        string* oned = one_d_io(pn);

        for (int i = 0; i < *pn; i++) {
            getline(file, temp);
            oned[i] = temp;
        }
        return oned;
    }
    file.close();
}

string** two_d_io(int* pn) {//del init io
    string** arr = new string* [*pn];
    for (int i = 0; i < *pn; i++) {
        arr[i] = new string[*pn];
    }
    return arr;
}

string* one_d_io(int* pn) {//del init io
    string* arr = new string [*pn];
    return arr;
}

void print_io(int* pn, string* matrix)
{
    for (int i = 0; i < *pn; i++) {
        cout << matrix[i];
        cout << endl;
    }
}

string** pretty_str(int* pn, string* arr)
{
    int leng;
    for (int i = 0; i < *pn; i++) {
        cout << "Символов в строке " << i + 1 << ": ";
        leng = arr[i].length();
        cout << leng << endl;
    }
    return 0;
}
