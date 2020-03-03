#include "IO.h"

using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Program starts!\n";
    cout << "Enter name of input file(with .csv): ";
    int n = 0;
    int* pn = &n;
    string name;
    getline(cin, name); //pp.csv - НАЗВАНИЕ ВХОДНОГО ФАЙЛА
    string** io = read_io(pn, name);
    print_io(pn, io);
    delete[] io;
}
