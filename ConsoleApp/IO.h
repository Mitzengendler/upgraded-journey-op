#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

string** read_io(int* pn, string name);
string** init_io(int* pn);
void print_io(int* pn, string** matrix);