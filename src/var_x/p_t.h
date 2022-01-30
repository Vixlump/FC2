void fc_getline() {
	//active_script[line-1] = active_script[line-1];
		line++;
		/*
		cout<<thread_label<<":"<<active_script[line-1]<<endl;
		system("pause");
		*/
}

//external stream register
	string external_using_string();
	float external_using_float();
	double external_using_double();
 	int external_using_int();
	long long int external_using_int64();
	long long int external_using_allints();
	double external_using_allfloats();
	double external_using_allnumbers();
	unsigned long long int external_using_alnum();

void terminate_pointers() {
    //delete[] active_script[line-1];
	//delete[] process_t;
	//delete[] vthr;
	//delete[] thread_t;
	delete[] int_var;
	delete[] double_var;
	delete[] float_var;
	delete[] int64_var;
	delete[] bool_var;
	delete[] string_var;
	delete[] chart_var;
	delete[] quantum_var;
	delete[] index_var;
	delete[] access_var;
	delete[] complex_var;
	delete[] kata_var;
	//delete[] cmd_argv;
}
void terminate_all() {
    terminate_pointers();
	exit(42);
}

string external_using_string() {
	unsigned long long int string_control_pointer;
	string_control_pointer = external_using_allints();
	return string_var[string_control_pointer];
}

float external_using_float() {
	unsigned long long int float_control_pointer;
	float_control_pointer = external_using_allints();
	return float_var[float_control_pointer];
}

double external_using_double() {
	unsigned long long int double_control_pointer;
	double_control_pointer = external_using_allints();
	return double_var[double_control_pointer];
}

long long int external_using_int64() {
	unsigned long long int int64_control_pointer;
	int64_control_pointer = external_using_allints();
	return int64_var[int64_control_pointer];
}
int external_using_int() {
		unsigned long long int int_control_pointer;
		int_control_pointer = external_using_allints();
		return int_var[int_control_pointer];
}
unsigned long long int external_using_alnum() {
	fc_getline();
	if (active_script[line-1]=="_int") {
		return int_var_alnum;
	} else if (active_script[line-1]=="_double") {
		return double_var_alnum;
	} else if (active_script[line-1]=="_float") {
		return float_var_alnum;
	} else if (active_script[line-1]=="_int64") {
		return int64_var_alnum;
	} else if (active_script[line-1]=="_bool") {
		return bool_var_alnum;
	} else if (active_script[line-1]=="_string") {
		return string_var_alnum;
	} else if (active_script[line-1]=="_chart") {
		return chart_var_alnum;
	} else if (active_script[line-1]=="_quantum") {
		return quantum_var_alnum;
	} else if (active_script[line-1]=="_complex") {
		return complex_var_alnum;
	} else if (active_script[line-1]=="_index") {
		return index_var_alnum;
	} else if (active_script[line-1]=="_access") {
		return access_var_alnum;
	} else {
		return 0;
	}
}
long long int external_using_allints() {
	fc_getline();
		if (active_script[line-1]=="_int") {
			return external_using_int();
		} else if (active_script[line-1]=="_int64") {
			return external_using_int64();
		} else {
			return atoi(active_script[line-1].c_str());
		}
}
double external_using_allfloats() {
	fc_getline();
	if (active_script[line-1]=="_double") {
		return external_using_double();
	} else if (active_script[line-1]=="_float") {
		return external_using_float();
	} else {
		return atof(active_script[line-1].c_str());
	}
}
double external_using_allnumbers() {
	fc_getline();
		if (active_script[line-1]=="_int") {
			return external_using_int();
		} else if (active_script[line-1]=="_double") {
			return external_using_double();
		} else if (active_script[line-1]=="_float") {
			return external_using_float();
		} else if (active_script[line-1]=="_int64") {
			return external_using_int64();
		} else {
			return atof(active_script[line-1].c_str());
		}
}
