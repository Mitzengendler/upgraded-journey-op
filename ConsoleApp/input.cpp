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

string** two_d_out(int* pn)
{
    string** arr = new string * [*pn];
    for (int i = 0; i < *pn; i++) {
        arr[i] = new string[10];
    }
    return arr;
}

string** score(int* pn, string** prettyTable)
{
    string** sc = two_d_out(pn);
    for (int i = 0; i < *pn; i++) {
        int itr = 0;
        for (int j = 1; j < 11; j++) {
            sc[i][itr] = prettyTable[i][j];
            itr++;
        }
    }
    return sc;
}

void showscore(int* pn, string** sc)
{
    for (int i = 0; i < *pn; i++) {
        for (int j = 0; j < 10; j++) {
            cout << setw(3) << sc[i][j] << ' ';
        }
        cout << endl;
    }
}

int* init1d(int* pn)
{
    int* arr = new int [*pn];
    return arr;
}

int** init2d(int* pn)
{
    int** arr = new int * [*pn];
    for (int i = 0; i < *pn; i++) {
        arr[i] = new int[10];
    }
    return arr;
}

void calcres(int* pn, string** in, int** out)
{
    for (int i = 0; i < *pn; i++) {
        int n1 = 0, n2 = 0;
        for (int j = 0; j < 10; j++) {
            for (int h = 0; h < 3; h++) {
                if (h == 1) {
                    continue;
                }
                char t = in[i][j][h];
                string l(1, t);
                if(h == 0){
                    n1 = stoi(l);
                }
                if (h == 2) {
                    n2 = stoi(l);
                }
            }
            if (n1 > n2) {
                out[i][j] = 3;
            }
            if (n1 == n2) {
                out[i][j] = 1;
            }
            if (n1 < n2) {
                out[i][j] = 0;
            }
        }
	}
}
void summ(int* pn, int** in, int* out)
{
    for (int i = 0; i < *pn; i++) {
        int sum = 0;
        for (int j = 0; j < 10; j++) {
            sum += in[i][j];
        }
        out[i] = sum;
    }
}

void sort(int* pn, string* team, int* score)
{
    for (int i = 0; i < *pn - 1; i++)
    {
        for (int j = i + 1; j < *pn; j++)
        {
            if (score[i] < score[j])
            {
                int temp;
                string t;
                temp = score[i];
                score[i] = score[j];
                score[j] = temp;
                t = team[i];
                team[i] = team[j];
                team[j] = t;
            }
        }
    }
}

string** initfinal(int* pn)
{
    string** arr = new string* [*pn];
    for (int i = 0; i < *pn; i++) {
        arr[i] = new string[2];
    }
    return arr;
}

void fillfinal(int* pn, string* team, int* score, string** out)
{
    for (int i = 0; i < *pn; i++) {
        out[i][0] = team[i];
        out[i][1] = to_string(score[i]);
    }
}

void putInFile(int* pn, string** matrix, string name) {
    ofstream outfile(name);
    ofstream file;
    file.open(name);
    if (file.is_open() == 0) {
        cout << "Error opening file!";
        exit(0);
    }
    if (file.is_open())
    {
        for (int i = 0; i < *pn; i++) {
            for (int j = 0; j < 2; j++) {
                if (j == 0) {
                    file << matrix[i][j] << ",";
                }
                if (j == 1) {
                    file  << matrix[i][j];
                }
            }
            file << "\n";
        }
        file.close();
    }
}