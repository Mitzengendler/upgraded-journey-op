#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

string* read_io(int* pn, string name);
string* one_d_io(int* pn);
string** two_d_io(int* pn);
void print_io(int* pn, string* matrix);
string** pretty_str(int* pn, string* arr);