#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <ostream>
#include <cmath>
#include <new>

using namespace std;

//abstract variables and commands
struct kata {
  string name;
  unsigned short int idtype;
  unsigned long long int idstack;
};
struct abstract {
    long double real;
    long double imag;
};
void cout_abstract(abstract pass_v) {
    if (pass_v.imag>0) {
        cout << pass_v.real << "+" << pass_v.imag<<"i";
    } else if (pass_v.imag<0) {
        cout << pass_v.real << pass_v.imag<<"i";
    } else if (pass_v.imag==0) {
        cout << pass_v.real;
    } else {
        cout <<"";
    }
}
/*
void math_abstract(abstract pass_v,string math_cont, abstract pass_v2,) {
    if ((math_cont=="^")or(math_cont=="pow")) {

    } else if ((math_cont=="log")or(math_cont=="`")) {

    } else if (math_cont=="+") {

    } else if (math_cont=="-") {

    } else if (math_cont=="sqrt") {

    } else if (math_cont=="abs") {

    } else if (math_cont=="cbrt") {

    } else if (math_cont=="") {

    } else if (math_cont=="") {

    } else if (math_cont=="") {
}
*/
//string
int convert_string_int(string pass_v) {
    return atof(pass_v.c_str());
}
float convert_string_float(string pass_v) {
    return atof(pass_v.c_str());
}
double convert_string_double(string pass_v) {
    return atof(pass_v.c_str());
}
bool convert_string_bool(string pass_v) {
    if (atof(pass_v.c_str())>=1) {
        return true;
    } else if (atof(pass_v.c_str())<=0) {
        return false;
    } else {
        return false;
    }
}
/*abstract convert_string_abstract(string pass_v) {
}
*/
//int
string convert_int_string(int pass_v) {
    ostringstream convert_pass_v;
    convert_pass_v<<pass_v;
    return convert_pass_v.str();
}
float convert_int_float(int pass_v) {
    return pass_v;
}
double convert_int_double(int pass_v) {
    return pass_v;
}
bool convert_int_bool(int pass_v) {
    if (pass_v>=1) {
        return true;
    } else if (pass_v<=0) {
        return false;
    } else {
        return false;
    }
}
/*abstract convert_string_abstract(int pass_v) {
}*/
//float
string convert_float_string(float pass_v) {
    ostringstream convert_pass_v;
    convert_pass_v<<pass_v;
    return convert_pass_v.str();
}
int convert_float_int(float pass_v) {
    return pass_v;
}
double convert_float_double(float pass_v) {
    return pass_v;
}
bool convert_float_bool(float pass_v) {
    if (pass_v>=1) {
        return true;
    } else if (pass_v<=0) {
        return false;
    } else {
        return false;
    }
}
/*abstract convert_string_abstract(float pass_v) {
}*/
//double
string convert_double_string(double pass_v) {
    ostringstream convert_pass_v;
    convert_pass_v<<pass_v;
    return convert_pass_v.str();
}
int convert_double_int(double pass_v) {
    return pass_v;
}
float convert_double_float(double pass_v) {
    return pass_v;
}
bool convert_double_bool(double pass_v) {
    if (pass_v>=1) {
        return true;
    } else if (pass_v<=0) {
        return false;
    } else {
        return false;
    }
}
/*abstract convert_string_abstract(double pass_v) {
}*/
//bool
string convert_bool_string(bool pass_v) {
    if (pass_v==true) {
        return ("1");
    } else if (pass_v==false) {
        return ("0");
    } else {
        return ("");
    }
}
int convert_bool_int(bool pass_v) {
    if (pass_v==true) {
        return 1;
    } else if (pass_v==false) {
        return 0;
    } else {
        return 0;
    }
}
double convert_bool_double(bool pass_v) {
    if (pass_v==true) {
        return 1;
    } else if (pass_v==false) {
        return 0;
    } else {
        return 0;
    }
}
float convert_bool_float(bool pass_v) {
    if (pass_v==true) {
        return 1;
    } else if (pass_v==false) {
        return 0;
    } else {
        return 0;
    }
}
/*abstract convert_string_abstract(bool pass_v) {
}*/
