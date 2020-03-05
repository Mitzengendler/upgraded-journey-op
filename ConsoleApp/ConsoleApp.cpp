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
}
