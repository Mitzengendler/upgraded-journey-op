#include "input.h"

string* read_it(string path, int* pnum)
{
    cout << path << endl;
    ifstream file;
    file.open(path);
    if (file.is_open()) {
        cout << "Файл открыт." << endl;
        string temp;
        int num;
        getline(file, temp);
        *pnum = stoi(temp);
        cout << *pnum << endl;
        string* one = one_d_arr(pnum); //Raw 1D string
        for (int i = 0; i < *pnum; i++) {
            getline(file, temp);
            one[i] = temp;
        }
        return one;
        //
        file.close();
    }
    else {
        cout << "Ошибка открылия файла!";
    }
}

string* one_d_arr(int* pn) {//del init io
    string* arr = new string[*pn];
    return arr;
}

void print(int* pn, string* arr)
{
    for (int i = 0; i < *pn; i++) {
        cout << arr[i] << endl;
    }
    cout << endl;
}