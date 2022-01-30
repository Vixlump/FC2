/*

Copyright (c) Cohen ter Heide 2014-2019 All rights reserved.

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.

Cohen ter Heide
support@lumpology.com

*/
//OSDK
//#include <os>

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//cstd control
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cinttypes>

//stream control
#include <iostream>
#include <fstream>
#include <sstream>

//filesystem control
//#include <filesystem>

//variable expantion
#include <string>
#include <memory>
#include <new>
//#include <cctype>

//math control
#include <cmath>
#include <complex>
#include <random>
#include <limits>

//time control
#include <ctime>
#include <chrono>

//threading control
#include <thread>
#include <atomic>
#include <mutex>
#include <vector>
//windows specific
//#include <windows.h>
//#include <graphics.h>

//#include "lib/v_stream.h"

//graphics library
//#include <aspectu/GL/glut.h>
//#include "aspectu/SDL2/SDL.h"
//#include "aspectu/GL/glew.h"
//#include "aspectu/GLFW/glfw3.h"
//#include "aspectu/aspectu.h"
//#include <GL/freeglut.h>
#include "var_x/abstract.h"
//audio library
//#include <AL/al.h>
//#include <AL/alut.h>
//mac include: #include <OpenAL/alut.h>

//computer vision library
//#include <opencv2/opencv.hpp>

//website and network
//#include <QtGui>
//#include <QtWebKit>

using namespace std;
using namespace chrono;
using namespace this_thread;
//namespace fs = std;
//using namespace std::filesystem;
//using namespace std::experimental::filesystem;

//pre process
//int active = 0;
auto FIRST_LINE = UINT_MAX;
thread_local unsigned int line = 0;
thread_local unsigned int line_bak = 0;  //mark
bool kill_cycle = true;
bool debug_kill_cycle = false;
unsigned long long int deprications = 0;
unsigned long long int error_level = 0;
unsigned long long int error_cap = 0;
string error_trace("S:");
string cmd_argv [127];
int argv_control_pointer = 0;
thread_local string process_m;   //mark


// threading bay
thread_local unsigned int thread_label = 1;  //mark
//thread * thread_t;
unsigned long long int adapted_threads = 1;
unsigned long long int known_threads = 1;

thread_local ifstream active_file("active.fc2"); //mark
thread_local vector <string> active_script; //mark

thread_local string active_file_controller("active.fc2");    //mark
thread_local string active_file_backup("active.fc2");    //mark
string original_active_file("active.fc2");

//abstract thingabs {8,9};
int * int_var;
unsigned long long int int_var_alnum;
double * double_var;
unsigned long long int double_var_alnum;
float * float_var;
unsigned long long int float_var_alnum;
long long int * int64_var;
unsigned long long int int64_var_alnum;
bool * bool_var;
unsigned long long int bool_var_alnum;
string * string_var;
unsigned long long int string_var_alnum;
ifstream * chart_var;
unsigned long long int chart_var_alnum;
ofstream * quantum_var;
unsigned long long int quantum_var_alnum;
ifstream * index_var;
unsigned long long int index_var_alnum;
char * access_var;
unsigned long long int access_var_alnum;
complex<double> * complex_var;
unsigned long long int complex_var_alnum;
kata * kata_var;
unsigned long long int kata_var_alnum;
struct fc2_action {string name;string value;};
vector <fc2_action> action_var;
void terminate_all();
void error_stream();
#include "var_y/fc2_datatypes.h"


//experimental stream
void scan_inquire();
void scan_stream();


//loading bay y
#include "var_y/script_loader.h"
#include "var_y/register_define.h"
//loading bay x
#include "var_x/p_t.h"
#include "var_x/error_stream.h"
#include "var_x/syx.h"
#include "var_x/debug_point.h"
#include "var_x/notation_cont.h"
#include "var_x/asignment.h"
#include "var_x/channelswap.h"
#include "var_x/abreg.h"
#include "var_x/x.h"
#include "var_x/v.h"
#include "var_x/funcx.h"
#include "var_x/a.h"
#include "var_x/c.h"
#include "var_x/f.h"
#include "var_x/i.h"
#include "var_x/m.h"
#include "var_x/r.h"
#include "var_x/t.h"
#include "var_x/e.h"
#include "var_x/scan.h"

//ground frame
int main(int argc, char *argv[]) {
    //process_m = new string [0];
	//thread memory allocations
	//process_t = new unsigned int [0];
	//thread_t = new thread [0];
	//vthr = 0;
	while (true) {
        if (argc>127) {
            terminate_all();
        } else if (argv_control_pointer<0) {
            cout<<"Program is damaged!"<<endl;
            terminate_all();
        } else {
            cmd_argv [argv_control_pointer] = argv[abs(argv_control_pointer)];
            argv_control_pointer = argv_control_pointer+1;
            if (argv_control_pointer>=argc) {break;}
        }
	}
	//cout<<cmd_argv<<endl;
	int_var = new int [0];
	double_var = new double [0];
	float_var = new float [0];
	int64_var = new long long int [0];
	bool_var = new bool [0];
	string_var = new string [0];
	chart_var = new ifstream [0];
	quantum_var = new ofstream [0];
	index_var = new ifstream [0];
	access_var = new char [0];
	complex_var = new complex<double> [0];
	kata_var = new kata [0];
	load_new_script();
	while (true) {
	scan_stream();
	if (debug_kill_cycle==true) {
        deprications = deprications+1;
		debug_stream();
		system("pause");
		terminate_all();
	}
	if (kill_cycle==true) {
		terminate_all();
	}
	//Ground frame will loop if no kill_cycle is true
	error_stream();
	}
return 0;
}
