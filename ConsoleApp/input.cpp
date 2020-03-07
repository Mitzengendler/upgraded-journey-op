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

string** two_d_eleven(int* pn)
{
    string** arr = new string * [*pn];
    for (int i = 0; i < *pn; i++) {
        arr[i] = new string[11];
    }
    return arr;
}

void pretty(int* pn, string* arr, string** prettyTable) {
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
}
////////////////////////////////////////////////////////
string* teams(int* pn, string** prettyTable){
    string* tm = one_d_arr(pn);
    for(int i = 0; i < *pn; i++ ){
        for(int j = 0; j <= 0; j++){
            tm[i] = prettyTable[i][j];
        }
    }
    return tm;
}

void output(int* pn, string* tm){
for(int i = 0; i < *pn; i++ ){
    for(int j = 0; j <= 0; j++){
            cout<<setw(3)<< tm[i]<<' '<<endl;
        }
    }
}
