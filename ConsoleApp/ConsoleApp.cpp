#include "input.h"

using namespace std;
namespace fs = std::filesystem;

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Program starts.\n";
    string* wholeString;

    int num = 0;
    int* pnum = &num;

    int n = 0;
    int* pn = &n;
    int m = 0;
    int* pm = &m;
    string* arr1 = one_d_arr(pn);
    string* arr2 = one_d_arr(pm);

    const fs::path currentDirectory{ fs::current_path() };
    for (fs::directory_iterator stepofIteration(currentDirectory), end; stepofIteration != end; ++stepofIteration) {
        if (stepofIteration->path().extension() == ".csv") {
            cout << "Found .csv file" << endl;
            wholeString = read_it(stepofIteration->path().string(), pnum);
            if (*pnum == 11) {
                arr1 = wholeString;
                *pn = *pnum;
            }
            if (*pnum == 9) {
                arr2 = wholeString;
                *pm = *pnum;
            }
        }
    }
    print(pn, arr1);
    print(pm, arr2);

    int z = n + m;
    int* pz = &z;
    string* allTeams = one_d_arr(pz);

    int iter = 0;
    for (int i = 0; i < *pz; i++) {
        if (i < *pn) {
            allTeams[i] = arr1[i];
        }
        else {
            allTeams[i] = arr2[iter];
            iter++;
        }
    }

    string** prettyTable = two_d_eleven(pz);
    pretty(pz, allTeams, prettyTable);
    cout << endl;
    for (int i = 0; i < *pz; i++) {
        for (int j = 0; j < 11; j++) {
            cout << setw(4) << prettyTable[i][j];
        }
        cout << endl;
    }
	
	string* tm = teams(pz, prettyTable);
    output(pz, tm);
	string** sc = score(pz, prettyTable);
    showscore(pz, sc);
    int** res = init2d(pz);
    calcres(pz, sc, res);
	int *sumsc = init1d(pz);
    summ(pz, res, sumsc);
    for (int j = 0; j < 20; j++) {
        cout << sumsc[j] << " ";
    }
    sort(pz, tm, sumsc);
    cout << endl;
    cout << endl;
    for (int j = 0; j < 20; j++) {
        cout << sumsc[j] << " ";
    }
}
