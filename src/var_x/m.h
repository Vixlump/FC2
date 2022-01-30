//math stream register
	void math_handle();
	void math_handle_double(double val1, string opr, double val2);
	void math_handle_int(int var1, string opr, int val2);
	void math_handle_float(float val1, string opr, float val2);
	void math_handle_int64(long long int val1, string opr, long long int val2);
	void math_handle_cont_int();
	void math_handle_cont_double();
	void math_handle_cont_float();
	void math_handle_cont_int64();
	void math_trig();
	void math_function();
	void math_function_int64();
	void math_function_int();
	void math_function_double();
	void math_function_float();
	void math_gen();
	void math_gen_random();
	void math_gen_random_int();
	void math_gen_random_double();
	void math_gen_random_float();
	void math_gen_random_int64();
	void math_gen_random_bool();
	void math_gen_random_string();

	//math stream
void math_stream() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="+function") {
			math_function();
		} else if (active_script[line-1]=="+gen") {
			math_gen();
		} else if (active_script[line-1]=="+handle") {
			deprications = deprications+1;
			math_handle();
		} else if (active_script[line-1]=="+algorithm") {
			//not working yet!
			error_stream();
		} else if ((active_script[line-1]=="+trig")or(active_script[line-1]=="+trigonometry")) {
			math_trig();
		} else if (active_script[line-1]=="m*") {
			break;
		} else if (active_script[line-1]==syx_ap) {
			//assignments
			asignment_point();
		} else if (active_script[line-1]==syx_vx) {
			abreg();
		} else if (active_script[line-1]=="@*") {
			//assignments
			asignment_wrap();
        } else if (active_script[line-1]=="*~~~") {
			channelswap_script();
        } else if (active_script[line-1]=="~~~*") {
            break;
		} else if (active_script[line-1]==syx_nc) {
			//notations
			notation_controller();
		} else if (active_script[line-1]=="**") {
			//break point
			debug_point();
        } else if (active_script[line-1]=="") {
		    //white space
            asignment_wrap();
		} else {
			error_stream();
		}
	}
}

//handlers
void math_handle() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_int") {
			math_handle_cont_int();
		} else if (active_script[line-1]=="_double") {
			math_handle_cont_double();
		} else if (active_script[line-1]=="_float") {
			math_handle_cont_float();
		} else if (active_script[line-1]=="_int64") {
			math_handle_cont_int64();
		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
			error_stream();
		}
	}
}

void math_handle_cont_int() {
	unsigned long long int int_control_pointer;
	unsigned long long int int_control_pointer_dule;
	string int_opr_i;
		//get first var
			int_control_pointer = external_using_allints();
		fc_getline();
			//get operator
			if (active_script[line-1]=="_string") {
				int_opr_i = external_using_string();
			} else {
				int_opr_i = active_script[line-1];
			}
				//get second var
					int_control_pointer_dule = external_using_allints();
				//start calculator
				math_handle_int(int_var[int_control_pointer], int_opr_i, int_var[int_control_pointer_dule]);
}
void math_handle_cont_double() {
	unsigned long long int double_control_pointer;
	unsigned long long int double_control_pointer_dule;
	string double_opr_i;
		//get first var
			double_control_pointer = external_using_allints();
		fc_getline();
			//get operator
			if (active_script[line-1]=="_string") {
				double_opr_i = external_using_string();
			} else {
				double_opr_i = active_script[line-1];
			}
				//get second var
					double_control_pointer_dule = external_using_allints();
				//start calculator
				math_handle_double(double_var[double_control_pointer], double_opr_i, double_var[double_control_pointer_dule]);
}
void math_handle_cont_float() {
	unsigned long long int float_control_pointer;
	unsigned long long int float_control_pointer_dule;
	string float_opr_i;
		//get first var
			float_control_pointer = external_using_allints();
		fc_getline();
			//get operator
			if (active_script[line-1]=="_string") {
				float_opr_i = external_using_string();
			} else {
				float_opr_i = active_script[line-1];
			}
				//get second var
					float_control_pointer_dule = external_using_allints();
				//start calculator
				math_handle_float(float_var[float_control_pointer], float_opr_i, float_var[float_control_pointer_dule]);
}
void math_handle_cont_int64() {
	unsigned long long int int64_control_pointer;
	unsigned long long int int64_control_pointer_dule;
	string int64_opr_i;
		//get first var
			int64_control_pointer = external_using_allints();
		fc_getline();
			//get operator
			if (active_script[line-1]=="_string") {
				int64_opr_i = external_using_string();
			} else {
				int64_opr_i = active_script[line-1];
			}
				//get second var
					int64_control_pointer_dule = external_using_allints();
				//start calculator
				math_handle_int64(int64_var[int64_control_pointer], int64_opr_i, int64_var[int64_control_pointer_dule]);
}

void math_handle_double(double val1, string opr, double val2) {
	unsigned long long int double_control_pointer;
	unsigned long long int double_control_pointer_dule;
	stringstream math_cvt;
	stringstream math_cvt_dule;
	string math_cvted = "NUL";
	double mathout_double = 0;
	double mathout_double_dule = 0;
	if (opr=="+") {
		//addition
		mathout_double = val1 + val2;
					//equals
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if (opr=="-") {
		//subtration
		mathout_double = val1 - val2;
					//equals
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if ((opr=="*")or(opr=="x")) {
		//multiplication
		mathout_double = val1 * val2;
					//equals
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if ((opr=="/")or(opr=="÷")) {
		//division
		if (val1==0) {
			mathout_double = val2;
		} else if (val2==0) {
			mathout_double = val1;
		} else {
		mathout_double = val1 / val2;
		}
					//equals
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if ((opr=="^")or(opr=="_pow")) {
		//power
		if (val1==0 && val2==0) {
			mathout_double = 1;
		} else {
		mathout_double = pow (val1, val2);
		}
					//equals
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if ((opr=="`")or(opr=="√")) {
		//square root
		val1 = abs(val1);
		mathout_double = sqrt (val1);
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
    } else if (opr=="log") {
        //log
		if (val1==0) {
			mathout_double = 0;
		} else {
		mathout_double = log10 (val1);
		}
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if ((opr=="3`")or(opr=="3√")) {
        //cube root
		val1 = abs(val1);
		mathout_double = cbrt (val1);
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if (opr=="?") {

	} else if ((opr=="+-")or(opr=="±")) {
		//plus minus
				double_control_pointer_dule = external_using_allints();
			mathout_double = val1 + val2;
			mathout_double_dule = val1 - val2;
			double_var[double_control_pointer_dule] = mathout_double_dule;
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if (opr=="-+") {
		//minus plus
				double_control_pointer_dule = external_using_allints();
			mathout_double = val1 - val2;
			mathout_double_dule = val1 + val2;
			double_var[double_control_pointer_dule] = mathout_double_dule;
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if (opr=="++") {
		//increment
		mathout_double = val1++;
		mathout_double_dule = ++val2;
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if (opr=="--") {
		//deincrement
		mathout_double = val1--;
		mathout_double_dule = --val2;
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if (opr==">") {
		//push right
		math_cvt.str("");
		//math_cvt_dule.str("");
		math_cvt << val1;
		//math_cvt_dule << val2;
		math_cvted = "0."+math_cvt.str();
		mathout_double = atof(math_cvted.c_str());
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if (opr=="<") {
		//push left
		math_cvt.str("");
		//math_cvt_dule.str("");
		math_cvt << val1;
		//math_cvt_dule << val2;
		math_cvted = math_cvt.str()+".0";
		mathout_double = atof(math_cvted.c_str());
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if (opr=="|") {
		//absolute value
		mathout_double = abs(val1);
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if (opr=="-|") {
		//inverse absolute value
		mathout_double = abs(val1)/-1;
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if (opr=="!") {
		//factoral

	} else if (opr=="$") {
		//generate number with decimal
		math_cvt.str("");
		math_cvt_dule.str("");
		math_cvt << val1;
		math_cvt_dule << val2;
		math_cvted = math_cvt.str()+"."+math_cvt_dule.str();
		mathout_double = atof(math_cvted.c_str());
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if (opr=="@") {
		//generate average between two numbers

	} else if (opr=="#") {
		//generate average between number and zero
		if (val1>0) {

		} else if (val1<0) {

		} else if (val1==0) {
			mathout_double = 0;
		}
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	} else if (opr=="~") {
		//invert and combine two numbers
		if (val1==0) {
			if (val2==0) {

			} else {
				val2 = val2/-1;
			}
		} else if (val2==0) {
			val1 = val1/-1;
		} else {
			val1 = val1/-1;
			val2 = val2/-1;
		}
		math_cvt.str("");
			math_cvt_dule.str("");
			math_cvt << val1;
			math_cvt_dule << val2;
			math_cvted = math_cvt.str()+math_cvt_dule.str();
			mathout_double = atof(math_cvted.c_str());
						double_control_pointer = external_using_allints();
					double_var[double_control_pointer] = mathout_double;
	}
}

void math_handle_int(int val1, string opr, int val2) {
	unsigned long long int int_control_pointer;
	unsigned long long int int_control_pointer_dule;
	int mathout_int = 0;
	int mathout_int_dule = 0;
	stringstream math_cvt;
	stringstream math_cvt_dule;
	string math_cvted = "NUL";
		if (opr=="+") {
		//addition
		mathout_int = val1 + val2;
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if (opr=="-") {
		//subtration
		mathout_int = val1 - val2;
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if ((opr=="*")or(opr=="x")) {
		//multiplication
		mathout_int = val1 * val2;
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if ((opr=="/")or(opr=="÷")) {
		//division
		if (val1==0) {
			mathout_int = val2;
		} else if (val2==0) {
			mathout_int = val1;
		} else {
		mathout_int = val1 / val2;
		}
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if (opr=="^") {
		//power
		if (val1==0 && val2==0) {
			mathout_int = 1;
		} else {
		mathout_int = pow (val1, val2);
		}
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if ((opr=="`")or(opr=="√")) {
		//square root
		val1 = abs(val1);
		mathout_int = sqrt (val1);
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
    } else if (opr=="log") {
        //log
		if (val1==0) {
			mathout_int = 0;
		} else {
		mathout_int = log10 (val1);
		}
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
    } else if ((opr=="3`")or(opr=="3√")) {
        //cube root
		val1 = abs(val1);
		mathout_int = cbrt (val1);
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if (opr=="?") {

	} else if ((opr=="+-")or(opr=="±")) {
		//plus minus
				int_control_pointer_dule = external_using_allints();
			mathout_int = val1 + val2;
			mathout_int_dule = val1 - val2;
			int_var[int_control_pointer_dule] = mathout_int_dule;
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if (opr=="-+") {
		//minus plus
				int_control_pointer_dule = external_using_allints();
			mathout_int = val1 - val2;
			mathout_int_dule = val1 + val2;
			int_var[int_control_pointer_dule] = mathout_int_dule;
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if (opr=="++") {
		//increment
		mathout_int = val1++;
		mathout_int_dule = ++val2;
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if (opr=="--") {
		//deincrement
		mathout_int = val1--;
		mathout_int_dule = --val2;
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if (opr==">") {
		//push right
		math_cvt.str("");
		math_cvt_dule.str("");
		math_cvt << val1;
		math_cvt_dule << val2;
		math_cvted = "0."+math_cvt.str()+math_cvt_dule.str();
		mathout_int = atof(math_cvted.c_str());
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if (opr=="<") {
		//push left
		math_cvt.str("");
		math_cvt_dule.str("");
		math_cvt << val1;
		math_cvt_dule << val2;
		math_cvted = math_cvt.str()+math_cvt_dule.str()+".0";
		mathout_int = atof(math_cvted.c_str());
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if (opr=="|") {
		//absolute value
		mathout_int = abs(val1);
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if (opr=="-|") {
		//inverse absolute value
		mathout_int = abs(val1)/-1;
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if (opr=="!") {
		//factoral

	} else if (opr=="$") {
		//generate number with decimal
		math_cvt.str("");
		math_cvt_dule.str("");
		math_cvt << val1;
		math_cvt_dule << val2;
		math_cvted = math_cvt.str()+"."+math_cvt_dule.str();
		mathout_int = atof(math_cvted.c_str());
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if (opr=="@") {
		//generate average between two numbers

	} else if (opr=="#") {
		//generate average between number and zero
		if (val1>0) {

		} else if (val1<0) {

		} else if (val1==0) {
			mathout_int = 0;
		}
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	} else if (opr=="~") {
		//invert and combine two numbers
		if (val1==0) {
			if (val2==0) {

			} else {
				val2 = val2/-1;
			}
		} else if (val2==0) {
			val1 = val1/-1;
		} else {
			val1 = val1/-1;
			val2 = val2/-1;
		}
		math_cvt.str("");
			math_cvt_dule.str("");
			math_cvt << val1;
			math_cvt_dule << val2;
			math_cvted = math_cvt.str()+math_cvt_dule.str();
			mathout_int = atof(math_cvted.c_str());
						int_control_pointer = external_using_allints();
					int_var[int_control_pointer] = mathout_int;
	}
}

void math_handle_float(float val1, string opr, float val2) {
	unsigned long long int float_control_pointer;
	unsigned long long int float_control_pointer_dule;
	stringstream math_cvt;
	stringstream math_cvt_dule;
	string math_cvted = "NUL";
	float mathout_float = 0;
	float mathout_float_dule = 0;
	if (opr=="+") {
		//addition
		mathout_float = val1 + val2;
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if (opr=="-") {
		//subtration
		mathout_float = val1 - val2;
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if ((opr=="*")or(opr=="x")) {
		//multiplication
		mathout_float = val1 * val2;
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if ((opr=="/")or(opr=="÷")) {
		//division
		if (val1==0) {
			mathout_float = val2;
		} else if (val2==0) {
			mathout_float = val1;
		} else {
		mathout_float = val1 / val2;
		}
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if (opr=="^") {
		//power
		if (val1==0 && val2==0) {
			mathout_float = 1;
		} else {
		mathout_float = pow (val1, val2);
		}
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if ((opr=="`")or(opr=="√")) {
		//square root
		val1 = abs(val1);
		mathout_float = sqrt (val1);
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
    } else if (opr=="log") {
        //log
		if (val1==0) {
			mathout_float = 0;
		} else {
		mathout_float = log10 (val1);
		}
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
    } else if ((opr=="3`")or(opr=="3√")) {
        //cube root
		val1 = abs(val1);
		mathout_float = cbrt (val1);
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if (opr=="?") {

	} else if ((opr=="+-")or(opr=="±")) {
		//plus minus
				float_control_pointer_dule = external_using_allints();
			mathout_float = val1 + val2;
			mathout_float_dule = val1 - val2;
			float_var[float_control_pointer_dule] = mathout_float_dule;
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if (opr=="-+") {
		//minus plus
				float_control_pointer_dule = external_using_allints();
			mathout_float = val1 - val2;
			mathout_float_dule = val1 + val2;
			float_var[float_control_pointer_dule] = mathout_float_dule;
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if (opr=="++") {
		//increment
		mathout_float = val1++;
		mathout_float_dule = ++val2;
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if (opr=="--") {
		//deincrement
		mathout_float = val1--;
		mathout_float_dule = --val2;
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if (opr==">") {
		//push right
		math_cvt.str("");
		math_cvt_dule.str("");
		math_cvt << val1;
		math_cvt_dule << val2;
		math_cvted = "0."+math_cvt.str()+math_cvt_dule.str();
		mathout_float = atof(math_cvted.c_str());
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if (opr=="<") {
		//push left
		math_cvt.str("");
		math_cvt_dule.str("");
		math_cvt << val1;
		math_cvt_dule << val2;
		math_cvted = math_cvt.str()+math_cvt_dule.str()+".0";
		mathout_float = atof(math_cvted.c_str());
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if (opr=="|") {
		//absolute value
		mathout_float = abs(val1);
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if (opr=="-|") {
		//inverse absolute value
		mathout_float = abs(val1)/-1;
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if (opr=="!") {
		//factoral

	} else if (opr=="$") {
		//generate number with decimal
		math_cvt.str("");
		math_cvt_dule.str("");
		math_cvt << val1;
		math_cvt_dule << val2;
		math_cvted = math_cvt.str()+"."+math_cvt_dule.str();
		mathout_float = atof(math_cvted.c_str());
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if (opr=="@") {
		//generate average between two numbers

	} else if (opr=="#") {
		//generate average between number and zero
		if (val1>0) {

		} else if (val1<0) {

		} else if (val1==0) {
			mathout_float = 0;
		}
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	} else if (opr=="~") {
		//invert and combine two numbers
		if (val1==0) {
			if (val2==0) {

			} else {
				val2 = val2/-1;
			}
		} else if (val2==0) {
			val1 = val1/-1;
		} else {
			val1 = val1/-1;
			val2 = val2/-1;
		}
		math_cvt.str("");
			math_cvt_dule.str("");
			math_cvt << val1;
			math_cvt_dule << val2;
			math_cvted = math_cvt.str()+math_cvt_dule.str();
			mathout_float = atof(math_cvted.c_str());
						float_control_pointer = external_using_allints();
					float_var[float_control_pointer] = mathout_float;
	}
}

void math_handle_int64(long long int val1, string opr, long long int val2) {
	unsigned long long int int64_control_pointer;
	unsigned long long int int64_control_pointer_dule;
	stringstream math_cvt;
	stringstream math_cvt_dule;
	string math_cvted = "NUL";
	long long int mathout_int64 = 0;
	long long int mathout_int64_dule = 0;
	if (opr=="+") {
		//addition
		mathout_int64 = val1 + val2;
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if (opr=="-") {
		//subtration
		mathout_int64 = val1 - val2;
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if ((opr=="*")or(opr=="x")) {
		//multiplication
		mathout_int64 = val1 * val2;
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if ((opr=="/")or(opr=="÷")) {
		//division
		if (val1==0) {
			mathout_int64 = val2;
		} else if (val2==0) {
			mathout_int64 = val1;
		} else {
		mathout_int64 = val1 / val2;
		}
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if (opr=="^") {
		//power
		if (val1==0 && val2==0) {
			mathout_int64 = 1;
		} else {
		mathout_int64 = pow (val1, val2);
		}
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if ((opr=="`")or(opr=="√")) {
		//square root
		val1 = abs(val1);
		mathout_int64 = sqrt (val1);
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
    } else if (opr=="log") {
        //log
		if (val1==0) {
			mathout_int64 = 0;
		} else {
		mathout_int64 = log10 (val1);
		}
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
    } else if ((opr=="3`")or(opr=="3√")) {
        //cube root
		val1 = abs(val1);
		mathout_int64 = cbrt (val1);
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if (opr=="?") {

	} else if ((opr=="+-")or(opr=="±")) {
		//plus minus
				int64_control_pointer_dule = external_using_allints();
			mathout_int64 = val1 - val2;
			mathout_int64_dule = val1 + val2;
			int64_var[int64_control_pointer_dule] = mathout_int64_dule;
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if (opr=="-+") {
		//minus plus
		mathout_int64 = val1 - val2;
		mathout_int64_dule = val1 + val2;
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if (opr=="++") {
		//increment
		mathout_int64 = val1++;
		mathout_int64_dule = ++val2;
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if (opr=="--") {
		//deincrement
		mathout_int64 = val1--;
		mathout_int64_dule = --val2;
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if (opr==">") {
		//push right
		math_cvt.str("");
		math_cvt_dule.str("");
		math_cvt << val1;
		math_cvt_dule << val2;
		math_cvted = "0."+math_cvt.str()+math_cvt_dule.str();
		mathout_int64 = atof(math_cvted.c_str());
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if (opr=="<") {
		//push left
		math_cvt.str("");
		math_cvt_dule.str("");
		math_cvt << val1;
		math_cvt_dule << val2;
		math_cvted = math_cvt.str()+math_cvt_dule.str()+".0";
		mathout_int64 = atof(math_cvted.c_str());
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if (opr=="|") {
		//absolute value
		mathout_int64 = abs(val1);
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if (opr=="-|") {
		//inverse absolute value
		mathout_int64 = abs(val1)/-1;
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if (opr=="!") {
		//factoral

	} else if (opr=="$") {
		//generate number with decimal
		math_cvt.str("");
		math_cvt_dule.str("");
		math_cvt << val1;
		math_cvt_dule << val2;
		math_cvted = math_cvt.str()+"."+math_cvt_dule.str();
		mathout_int64 = atof(math_cvted.c_str());
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if (opr=="@") {
		//generate average between two numbers

	} else if (opr=="#") {
		//generate average between number and zero
		if (val1>0) {

		} else if (val1<0) {

		} else if (val1==0) {
			mathout_int64 = 0;
		}
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	} else if (opr=="~") {
		//invert and combine two numbers
		if (val1==0) {
			if (val2==0) {

			} else {
				val2 = val2/-1;
			}
		} else if (val2==0) {
			val1 = val1/-1;
		} else {
			val1 = val1/-1;
			val2 = val2/-1;
		}
		math_cvt.str("");
			math_cvt_dule.str("");
			math_cvt << val1;
			math_cvt_dule << val2;
			math_cvted = math_cvt.str()+math_cvt_dule.str();
			mathout_int64 = atof(math_cvted.c_str());
						int64_control_pointer = external_using_allints();
					int64_var[int64_control_pointer] = mathout_int64;
	}
}

//Trigonometry
void math_trig() {
    void math_trig_cos();
        void math_trig_cos_int();
        void math_trig_cos_int64();
        void math_trig_cos_double();
        void math_trig_cos_float();
    void math_trig_sin();
        void math_trig_sin_int();
        void math_trig_sin_int64();
        void math_trig_sin_double();
        void math_trig_sin_float();
    void math_trig_tan();
        void math_trig_tan_int();
        void math_trig_tan_int64();
        void math_trig_tan_double();
        void math_trig_tan_float();
    void math_trig_acos();
        void math_trig_acos_int();
        void math_trig_acos_int64();
        void math_trig_acos_double();
        void math_trig_acos_float();
    void math_trig_asin();
        void math_trig_asin_int();
        void math_trig_asin_int64();
        void math_trig_asin_double();
        void math_trig_asin_float();
    void math_trig_atan();
        void math_trig_atan_int();
        void math_trig_atan_int64();
        void math_trig_atan_double();
        void math_trig_atan_float();
    void math_trig_atan2();
        void math_trig_atan2_int();
        void math_trig_atan2_int64();
        void math_trig_atan2_double();
        void math_trig_atan2_float();
    void math_trig_cosh();
        void math_trig_cosh_int();
        void math_trig_cosh_int64();
        void math_trig_cosh_double();
        void math_trig_cosh_float();
    void math_trig_sinh();
        void math_trig_sinh_int();
        void math_trig_sinh_int64();
        void math_trig_sinh_double();
        void math_trig_sinh_float();
    void math_trig_tanh();
        void math_trig_tanh_int();
        void math_trig_tanh_int64();
        void math_trig_tanh_double();
        void math_trig_tanh_float();
    void math_trig_acosh();
        void math_trig_acosh_int();
        void math_trig_acosh_int64();
        void math_trig_acosh_double();
        void math_trig_acosh_float();
    void math_trig_asinh();
        void math_trig_asinh_int();
        void math_trig_asinh_int64();
        void math_trig_asinh_double();
        void math_trig_asinh_float();
    void math_trig_atanh();
        void math_trig_atanh_int();
        void math_trig_atanh_int64();
        void math_trig_atanh_double();
        void math_trig_atanh_float();
    while (true) {
        fc_getline();
        if (active_script[line-1]=="_cos") {

        } else if (active_script[line-1]=="_sin") {

        } else if (active_script[line-1]=="_tan") {

        } else if ((active_script[line-1]=="_arccos")or(active_script[line-1]=="_acos")) {

        } else if ((active_script[line-1]=="_arcsin")or(active_script[line-1]=="_asin")) {

        } else if ((active_script[line-1]=="_arctan")or(active_script[line-1]=="_atan")) {

        } else if ((active_script[line-1]=="_arctan2")or(active_script[line-1]=="_atan2")) {

        } else if (active_script[line-1]=="_cosh") {

        } else if (active_script[line-1]=="_sinh") {

        } else if (active_script[line-1]=="_tanh") {

        } else if ((active_script[line-1]=="_arccosh")or(active_script[line-1]=="_acosh")) {

        } else if ((active_script[line-1]=="_arcsinh")or(active_script[line-1]=="_asinh")) {

        } else if ((active_script[line-1]=="_arctanh")or(active_script[line-1]=="_atanh")) {

        } else if (active_script[line-1]=="_ret") {

        } else {
            error_stream();
        }
    }
}


//math funcations
void math_function() {
    while (true) {
        fc_getline();
        //Trignonometric functions
        if (active_script[line-1]=="_float") {
						unsigned long long int float_control_pointer;
							float_control_pointer = external_using_allints();
            fc_getline();
            if ((active_script[line-1]=="[")or(active_script[line-1]=="(")) {float_var [float_control_pointer] = funcx_math(float_var [float_control_pointer]);}
				} else if (active_script[line-1]=="_double") {
					unsigned long long int double_control_pointer;
						double_control_pointer = external_using_allints();
					fc_getline();
					if ((active_script[line-1]=="[")or(active_script[line-1]=="(")) {double_var [double_control_pointer] = funcx_math(double_var [double_control_pointer]);}
				} else if (active_script[line-1]=="_int") {
					unsigned long long int int_control_pointer;
						int_control_pointer = external_using_allints();
					fc_getline();
					if ((active_script[line-1]=="[")or(active_script[line-1]=="(")) {int_var [int_control_pointer] = funcx_math(int_var [int_control_pointer]);}
				} else if (active_script[line-1]=="_int64") {
					unsigned long long int int64_control_pointer;
						int64_control_pointer = external_using_allints();
					fc_getline();
					if ((active_script[line-1]=="[")or(active_script[line-1]=="(")) {int64_var [int64_control_pointer] = funcx_math(int64_var [int64_control_pointer]);}
        } else if (active_script[line-1]=="_ret") {
            break;
        } else {
            error_stream();
        }
    }
}

//math generator
void math_gen() {
    while (true) {
        fc_getline();
        if (active_script[line-1]=="_random") {
            math_gen_random();
        } else if (active_script[line-1]=="_ret") {
            break;
        } else {
            error_stream();
        }
    }
}

void math_gen_random() {
    fc_getline();
        if (active_script[line-1]=="_int") {
            math_gen_random_int();
        } else if (active_script[line-1]=="_double") {
            math_gen_random_double();
        } else if (active_script[line-1]=="_float") {
            math_gen_random_float();
        } else if (active_script[line-1]=="_int64") {
            math_gen_random_int64();
        } else if (active_script[line-1]=="_bool") {
            math_gen_random_bool();
        } else {
            error_stream();
        }
}

void math_gen_random_double() {
	unsigned long long int double_control_pointer;
	unsigned long long int double_control_pointer_dule;
				double_control_pointer = external_using_allints();
				srand(double_control_pointer);
				double_control_pointer_dule = external_using_allints();
				double_var[double_control_pointer_dule] = rand() /*/ double(RAND_MAX)*/;
}

void math_gen_random_int() {
	unsigned long long int int_control_pointer;
	unsigned long long int int_control_pointer_dule;
				int_control_pointer = external_using_allints();
				srand(int_control_pointer);
				int_control_pointer_dule = external_using_allints();
				int_var[int_control_pointer_dule] = rand();
}

void math_gen_random_int64() {
	unsigned long long int int64_control_pointer;
	unsigned long long int int64_control_pointer_dule;
				int64_control_pointer = external_using_allints();
				srand(int64_control_pointer);
				int64_control_pointer_dule = external_using_allints();
				int64_var[int64_control_pointer_dule] = rand();
}

void math_gen_random_float() {
	unsigned long long int float_control_pointer;
	unsigned long long int float_control_pointer_dule;
				float_control_pointer = external_using_allints();
				srand(float_control_pointer);
				float_control_pointer_dule = external_using_allints();
				float_var[float_control_pointer_dule] = rand();
}

void math_gen_random_bool() {

}
