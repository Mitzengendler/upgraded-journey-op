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
    string* io = read_io(pn, name);
    print_io(pn, io);
    cout << endl;
    string** prettyTable = two_d_io(pn);
    pretty_str(pn, io, prettyTable);
    string* commandName = one_d_io(pn);
    string** scoreTable = two_d_scoreTable_init(pn);
    //table(pn, commandName, scoreTable, prettyTable);
}
