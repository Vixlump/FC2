#pragma once
enum fc3_data {
	fc3_faction,////A
	fc3_function,//*a
	fc3_command,//+a
	fc3_action,//_a
	fc3_acsess,//_datatype
	fc3_array,//_array
	fc3_escape,//a*
	fc3_rawinput,//text
	fc3_error
};
enum fc3_datatypes {
	fc3_type_bool,
	fc3_type_int8,
	fc3_type_int16,
	fc3_type_int32,
	fc3_type_int64,
	fc3_type_int128,
	fc3_type_int256,
	fc3_type_int512,
	fc3_type_char,
	fc3_type_string,
	fc3_type_float,
	fc3_type_double,
	fc3_type_triple,
	fc3_type_chart,
	fc3_type_quantum,
	fc3_type_raw
};

bool fc3_compiler() {

}