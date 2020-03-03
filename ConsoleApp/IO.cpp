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

void pretty_str(int* pn, string* arr, string** prettyTable)
{
    for (int ll = 0; ll < *pn; ll++) {
        arr[ll] += ',';
    }
    for (int i = 0; i < *pn; i++) {
        int iter = 0;
        string ll;
        for (int j = 0; j < arr[i].length(); j++) {
            if (arr[i][j] == ',') {
                prettyTable[i][iter] = ll;
                iter++;
                ll.clear();
                continue;
            }
            else {
                ll = ll + arr[i][j];
            }
        }
    }
    for (int i = 0; i < *pn; i++) {
        for (int j = 0; j < *pn; j++) {
            cout << setw(4) << prettyTable[i][j];
        }
        cout << endl;
    }
}

string** two_d_scoreTable_init(int* pn) {
    string** arr = new string * [*pn];
    for (int i = 0; i < *pn; i++) {
        arr[i] = new string[*pn - 1];
    }
    return arr;
}

void table(int* pn, string* commandName, string** scoreTable, string** rawArray)
{
    for (int i = 0; i < *pn; i++) {
        commandName[i] = rawArray[i][0];
    }
    for (int i = 0; i < *pn; i++) {
        for (int j = 0; j < *pn - 1; j++) {
            scoreTable[i][j] = rawArray[i][j + 1];
        }
    }
}

void print_commandName(int* pn, string* commandName)
{
    for (int i = 0; i < *pn; i++) {
        cout << commandName[i] << endl;
    }
}

void print_scoreTable(int* pn, string** scoreTable)
{
    for (int i = 0; i < *pn; i++) {
        for (int j = 0; j < *pn - 1; j++) {
            cout << scoreTable[i][j] << " ";
        }
        cout << endl;
    }
}
