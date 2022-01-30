#pragma once

struct Empty {};

typedef bool fc2_datatype_bool; vector <fc2_datatype_bool> fc2_bool_var;
typedef wchar_t fc2_datatype_access; vector <fc2_datatype_access> fc2_access_var;
typedef int8_t fc2_datatype_int8; vector <fc2_datatype_int8> fc2_int8_var;
typedef int16_t fc2_datatype_int16; vector <fc2_datatype_int16> fc2_int16_var;
typedef int32_t fc2_datatype_int32; vector <fc2_datatype_int32> fc2_int32_var;
typedef int64_t fc2_datatype_int64; vector <fc2_datatype_int64> fc2_int64_var;
//typedef int128_t fc2_datatype_int128;
typedef float fc2_datatype_float; vector <fc2_datatype_float> fc2_float_var;
typedef double fc2_datatype_double; vector <fc2_datatype_double> fc2_double_var;
typedef long double fc2_datatype_triple; vector <fc2_datatype_triple> fc2_triple_var;
typedef std::string fc2_datatype_string; vector <fc2_datatype_string> fc2_string_var;
typedef std::string fc2_datatype_action; vector <fc2_datatype_action> fc2_action_var;
typedef std::ifstream fc2_datatype_chart; vector <fc2_datatype_chart> fc2_chart_var;
typedef std::ofstream fc2_datatype_quantum; vector <fc2_datatype_quantum> fc2_quantum_var;
typedef kata fc2_datatyepe_kata; vector <fc2_datatyepe_kata> fc2_kata_var;
typedef std::complex<long double> fc2_datatype_complex; vector <fc2_datatype_complex> fc2_complex_var;
//typedef new_abstract fc2_datatype_abstract;
typedef Empty fc2_datatype_empty; vector <fc2_datatype_empty> fc2_empty_var;
typedef vector <void *> fc2_datatype_raw; fc2_datatype_raw fc2_raw_var;
//typedef shared_memory fc2_datatype_playball;

enum fc2type {
	boolvar,
	accessvar,
	int8var,
	int16var,
	int32var,
	int64var,
	int128var,
	floatvar,
	doublevar,
	triplevar,
	stringvar,
	actionvar,
	chartvar,
	quantumvar,
	katavar,
	complexvar,
	abstractvar,
	emptyvar,
	rawvar,
	playballvar
};

template <typename T>
T fc2_data_request(vector <T> & fc2_type_var, unsigned long long int pos) {
	if (pos < fc2_type_var.size()) {
		return fc2_type_var[pos];
	} else {
		error_stream();
		return (T)NULL;
	}
}
template <typename T2>
void fc2_data_store(vector <T2> &fc2_type_var, unsigned long long int pos, T2 value) {
	if (pos < fc2_type_var.size()) {
		fc2_type_var[pos] = value;
		return;
	} else {
		fc2_type_var.push_back(value);
	}
}
template <typename T3>
void fc2_data_allocate(vector <T3> &fc2_type_var, T3 value) {
	fc2_type_var.push_back(value);
}