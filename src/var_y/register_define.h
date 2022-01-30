#pragma once
struct fc2_script {
	vector <string> script;
};

struct fc2_function {
	string function_name;
	vector <string> inside;
	vector <string> function_script_name_backup;
	vector <string> function_script_name_backup_backup;
	vector <fc2_script> function_script_backup;
	vector <unsigned int> function_line_backup;
	vector <unsigned int> function_line_backup_backup;
	unsigned int total_calls = 0;
	unsigned short int function_flag = 0;
};
unsigned int current_fc2_function = 0;
vector <fc2_function> created_fc2_functions;


void fc2_define_function() {
	fc2_function local_function_builder;
	line++;
	local_function_builder.function_name = active_script[line - 1];
	while (true) {
		line++;
		if (active_script[line - 1] == "f+") {
			break;
		} else {
			local_function_builder.inside.push_back(active_script[line - 1]);
			//cout<<local_function_builder.function_name
				//<<" Registered["<< active_script[line - 1]
				//<< "] On Line[" << line <<"]"<< endl;
		}
	}
	created_fc2_functions.push_back(local_function_builder);
	//cout << "Total Registered Functions[" << created_fc2_functions.size() << "]" << endl;
}

void fc2_swap_to_function(int &i) {
	//setup function swap:
	current_fc2_function = i;
	fc2_script local_script;
	created_fc2_functions[i].total_calls++;
	created_fc2_functions[i].function_line_backup.push_back(line);
	created_fc2_functions[i].function_line_backup_backup.push_back(line_bak);
	created_fc2_functions[i].function_script_name_backup.push_back(active_file_controller);
	created_fc2_functions[i].function_script_name_backup_backup.push_back(active_file_backup);
	local_script.script = active_script;
	created_fc2_functions[i].function_script_backup.push_back(local_script);
	
	//run function here:
	line = 0;
	active_script.clear();
	active_script = created_fc2_functions[i].inside;
	scan_stream();

	//return to script from function:
	line = created_fc2_functions[i].function_line_backup.back();
	line_bak = created_fc2_functions[i].function_line_backup_backup.back();
	active_file_controller = created_fc2_functions[i].function_script_name_backup.back();
	active_file_backup = created_fc2_functions[i].function_script_name_backup_backup.back();
	active_script.clear();
	active_script = created_fc2_functions[i].function_script_backup.back().script;
	
	//unload recursion data from function:
	created_fc2_functions[i].total_calls--;
	created_fc2_functions[i].function_line_backup.pop_back();
	created_fc2_functions[i].function_line_backup_backup.pop_back();
	created_fc2_functions[i].function_script_name_backup.pop_back();
	created_fc2_functions[i].function_script_name_backup_backup.pop_back();
	created_fc2_functions[i].function_script_backup.back().script.clear();
	created_fc2_functions[i].function_script_backup.pop_back();
}

string fc2_action_value(string name) {
	for (int i = 0; i < action_var.size(); i++) {
		if (action_var[i].name == name) {
			return action_var[i].value;
		}
	}
	return "";
}

void fc2_function_jump_case() {
	line++;
	string fc2_jump_location = active_script[line - 1];
	line = 0;
	while (true) {
		line++;
		if (active_script[line - 1] == "*@") {
			line++;
			if (active_script[line - 1] == fc2_jump_location) {
				break;
			}
		}
	}
}

void fc2_function_action_case() {
	line++;
	string local_recive_action_value = fc2_action_value(active_script[line - 1]);
	line++;
	if (active_script[line - 1] == local_recive_action_value) {
		fc2_function_jump_case();
	} else {
		line++;
	}
}
#include "var_y/function_flags.h"
bool fc2_function_action_index() {
	if (active_script[line - 1] == "//A") {
		line++;
		if (active_script[line - 1] == "*action") {
			if (created_fc2_functions.empty() == false) {
				created_fc2_functions[current_fc2_function].function_line_backup.back() += 1;
				unsigned int collect_line_for_action = created_fc2_functions[current_fc2_function].function_line_backup.back();
				fc2_action local_actor_maker;
				local_actor_maker.value =
					created_fc2_functions[current_fc2_function].function_script_backup.back().script[collect_line_for_action - 1];
				line++;
				local_actor_maker.name = active_script[line - 1];
				for (int i = 0; i < action_var.size(); i++) {
					if (action_var[i].name == local_actor_maker.name) {
						action_var[i].value = local_actor_maker.value;
						return true;
					}
				}
				action_var.push_back(local_actor_maker);
			}
			return true;
		} else if (active_script[line - 1] == "*case") {
			fc2_function_action_case();
			return true;
		} else if (active_script[line - 1] == "*jump") {
			fc2_function_jump_case();
			return true;
		} else if (active_script[line - 1] == "*escape") {
			unsigned int collect_line_for_action = created_fc2_functions[current_fc2_function].function_line_backup.back();
			if (created_fc2_functions[current_fc2_function].function_script_backup.back().script[collect_line_for_action - 1 + 1]== created_fc2_functions[current_fc2_function].function_name + "*"
				|| created_fc2_functions[current_fc2_function].function_script_backup.back().script[collect_line_for_action - 1 + 1] == "~~~*") {
				created_fc2_functions[current_fc2_function].function_line_backup.back() += 1;
				fc2_function_jump_case();
			} else {
				line++;
			}
			return true;
		} else if (active_script[line - 1] == "*flag") {
			fc2_function_flags_selector();
			return true;
		} else if (active_script[line - 1] == "*whitespace") {

			return true;
		} else {
			error_stream();
		}
		return true;
	} else {
		return false;
	}
}

bool fc2_function_command_index() {

	return false;
}

bool fc2_function_sublib_index() {

	return false;
}

bool fc2_check_for_functions() {
	for (int i = 0; i < created_fc2_functions.size(); i++) {
		if ("*"+created_fc2_functions[i].function_name == active_script[line - 1]) {
			fc2_swap_to_function(i);
			return true;
		}
	}
	return false;
}