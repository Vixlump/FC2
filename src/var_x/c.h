//control stream register
	void control_goto();
	void control_goto_scan(string goto_control_pointer);
	void control_if();
	void control_if_true();
	void control_if_false();
	void control_if_else();
	void control_if_elif();
	void control_if_keyinput();
	void control_if_keyinput_char();
	void control_if_keyinput_action();
	void control_if_keyinput_tool();
	void control_if_keyinput_num();
	void control_if_keyinput_symbol();
	void control_if_keyinput_any();
	void control_if_var();
	void control_if_var_equ();
	void control_if_var_int();
	void control_if_var_int_equ(unsigned long long int int_control_pointer);
	void control_if_var_int_equ_stream(unsigned long long int int_control_pointer);
	void control_if_var_int_not(unsigned long long int int_control_pointer);
	void control_if_var_int_not_stream(unsigned long long int int_control_pointer);
	void control_if_var_int_more(unsigned long long int int_control_pointer);
	void control_if_var_int_more_stream(unsigned long long int int_control_pointer);
	void control_if_var_int_less(unsigned long long int int_control_pointer);
	void control_if_var_int_less_stream(unsigned long long int int_control_pointer);
	void control_if_var_int_moe(unsigned long long int int_control_pointer);
	void control_if_var_int_moe_stream(unsigned long long int int_control_pointer);
	void control_if_var_int_loe(unsigned long long int int_control_pointer);
	void control_if_var_int_loe_stream(unsigned long long int int_control_pointer);
	void control_if_var_int_aprox();
	void control_if_var_int_aprox_stream();
	void control_if_var_double();
	void control_if_var_double_equ(unsigned long long int double_control_pointer);
	void control_if_var_double_equ_stream(unsigned long long int double_control_pointer);
	void control_if_var_double_not(unsigned long long int double_control_pointer);
	void control_if_var_double_not_stream(unsigned long long int double_control_pointer);
	void control_if_var_double_more(unsigned long long int double_control_pointer);
	void control_if_var_double_more_stream(unsigned long long int double_control_pointer);
	void control_if_var_double_less(unsigned long long int double_control_pointer);
	void control_if_var_double_less_stream(unsigned long long int double_control_pointer);
	void control_if_var_double_moe(unsigned long long int double_control_pointer);
	void control_if_var_double_moe_stream(unsigned long long int double_control_pointer);
	void control_if_var_double_loe(unsigned long long int double_control_pointer);
	void control_if_var_double_loe_stream(unsigned long long int double_control_pointer);
	void control_if_var_double_aprox();
	void control_if_var_double_aprox_stream();
	void control_if_var_float();
	void control_if_var_float_equ(unsigned long long int float_control_pointer);
	void control_if_var_float_equ_stream(unsigned long long int float_control_pointer);
	void control_if_var_float_not(unsigned long long int float_control_pointer);
	void control_if_var_float_not_stream(unsigned long long int float_control_pointer);
	void control_if_var_float_more(unsigned long long int float_control_pointer);
	void control_if_var_float_more_stream(unsigned long long int float_control_pointer);
	void control_if_var_float_less(unsigned long long int float_control_pointer);
	void control_if_var_float_less_stream(unsigned long long int float_control_pointer);
	void control_if_var_float_moe(unsigned long long int float_control_pointer);
	void control_if_var_float_moe_stream(unsigned long long int float_control_pointer);
	void control_if_var_float_loe(unsigned long long int float_control_pointer);
	void control_if_var_float_loe_stream(unsigned long long int float_control_pointer);
	void control_if_var_float_aprox();
	void control_if_var_float_aprox_stream();
	void control_if_var_int64();
	void control_if_var_int64_equ(unsigned long long int int64_control_pointer);
	void control_if_var_int64_equ_stream(unsigned long long int int64_control_pointer);
	void control_if_var_int64_not(unsigned long long int int64_control_pointer);
	void control_if_var_int64_not_stream(unsigned long long int int64_control_pointer);
	void control_if_var_int64_more(unsigned long long int int64_control_pointer);
	void control_if_var_int64_more_stream(unsigned long long int int64_control_pointer);
	void control_if_var_int64_less(unsigned long long int int64_control_pointer);
	void control_if_var_int64_less_stream(unsigned long long int int64_control_pointer);
	void control_if_var_int64_moe(unsigned long long int int64_control_pointer);
	void control_if_var_int64_moe_stream(unsigned long long int int64_control_pointer);
	void control_if_var_int64_loe(unsigned long long int int64_control_pointer);
	void control_if_var_int64_loe_stream(unsigned long long int int64_control_pointer);
	void control_if_var_int64_aprox();
	void control_if_var_int64_aprox_stream();
	void control_if_var_bool();
	void control_if_var_bool_equ(unsigned long long int bool_control_pointer);
	void control_if_var_bool_equ_stream(unsigned long long int bool_control_pointer);
	void control_if_var_string();
	void control_if_var_string_equ(unsigned long long int string_control_pointer);
	void control_if_var_string_equ_stream(unsigned long long int string_control_pointer);
	void control_if_var_string_not(unsigned long long int string_control_pointer);
	void control_if_var_string_not_stream(unsigned long long int string_control_pointer);
	void control_if_errorlevel();
	void control_if_errorlevel_equ();
	void control_if_stream();
	void control_if_stream_equ();
	void control_if_and();
	void control_if_or();
	void control_if_not();
	void control_if_xor();
	void control_if_xnor();
	void control_if_nand();
	void control_if_continue();
	void control_for();
	void control_while();
	void control_inspect();
	void control_inspect_line();
	void control_inspect_split();
	void control_inspect_parce();

	//control stream
void control_stream() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="+if") {
			control_if();
		} else if (active_script[line-1]=="+goto") {
			control_goto();
		} else if (active_script[line-1]=="+inspect") {
			control_inspect();
        } else if (active_script[line-1]=="+for") {
			control_for();
		} else if (active_script[line-1]=="+while") {
			control_while();
		} else if (active_script[line-1]=="c*") {
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

//control stream
void control_if() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_var") {
			control_if_var();
		} else if (active_script[line-1]=="_goto") {
			control_goto();
		} else if ((active_script[line-1]=="_ret")or(active_script[line-1]=="@*")) {
			break;
        } else if (active_script[line-1]=="_errorlevel") {
			control_if_errorlevel();
		} else {
			control_if_stream();
		}
	}
}
	//control_if commands:
	void control_if_true() {
		fc_getline();
			if (active_script[line-1]=="_goto") {
				control_goto();
			} else if (active_script[line-1]=="_skip") {
                //not working!
                error_stream();
			} else {
				error_stream();
			}
	}
	void control_if_false() {
		// skip two lines start
		fc_getline();
		fc_getline();
		// skip two lines end
		while (true) {
			fc_getline();
			if (active_script[line-1]=="_else") {
				while (true) {
					fc_getline();
					if (active_script[line-1]=="_goto") {
						control_goto();
					} else if (active_script[line-1]=="_skip") {
                        //not working!
                        error_stream();
					} else if (active_script[line-1]=="_ret") {
						break;
					} else {
						error_stream();
					}
					break;
				}
			} else if ((active_script[line-1]=="_ret")or(active_script[line-1]=="_elif")or(active_script[line-1]=="elseif")) {
				break;
			} else {
				error_stream();
			}
			break;
		}
	}
	void control_if_var() {
		fc_getline();
			if (active_script[line-1]=="_int") {
				control_if_var_int();
			} else if (active_script[line-1]=="_double") {
				control_if_var_double();
			} else if (active_script[line-1]=="_float") {
				control_if_var_float();
			} else if (active_script[line-1]=="_int64") {
				control_if_var_int64();
			} else if (active_script[line-1]=="_bool") {
				control_if_var_bool();
			} else if (active_script[line-1]=="_string") {
				control_if_var_string();
			} else {
				error_stream();
			}
		}
	void control_if_var_equ() {

	}
	void control_if_var_int() {
		unsigned long long int int_control_pointer;
				int_control_pointer = external_using_allints();

			fc_getline();
				if ((active_script[line-1]=="==") or (active_script[line-1]=="_equ") or (active_script[line-1]=="≡")) {
					control_if_var_int_equ(int_control_pointer);
				} else if ((active_script[line-1]=="!=") or (active_script[line-1]=="_not") or (active_script[line-1]=="≠")) {
					control_if_var_int_not(int_control_pointer);
				} else if ((active_script[line-1]==">") or (active_script[line-1]=="_more")) {
					control_if_var_int_more(int_control_pointer);
				} else if ((active_script[line-1]=="<") or (active_script[line-1]=="_less")) {
					control_if_var_int_less(int_control_pointer);
				} else if ((active_script[line-1]==">=") or (active_script[line-1]=="_moe") or (active_script[line-1]=="≥")) {
					control_if_var_int_moe(int_control_pointer);
				} else if ((active_script[line-1]=="<=") or (active_script[line-1]=="_loe") or (active_script[line-1]=="≤")) {
					control_if_var_int_loe(int_control_pointer);
				} else if ((active_script[line-1]=="~=") or (active_script[line-1]=="_aprox") or (active_script[line-1]=="≈")) {
					control_if_var_int_aprox();
				} else {
					error_stream();
				}
	}
	void control_if_var_int_equ(unsigned long long int int_control_pointer) {
		unsigned long long int int_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_int_equ_stream(int_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					int_control_pointer_dule = external_using_allints();
				} else {
					int_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (int_var[int_control_pointer]==int_var[int_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_int_equ_stream(unsigned long long int int_control_pointer) {
		fc_getline();
			if (int_var[int_control_pointer] == atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_int_not(unsigned long long int int_control_pointer){
		unsigned long long int int_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_int_not_stream(int_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					int_control_pointer_dule = external_using_allints();
				} else {
					int_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (int_var[int_control_pointer]!=int_var[int_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_int_not_stream(unsigned long long int int_control_pointer){
		fc_getline();
			if (int_var[int_control_pointer]!=atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_int_more(unsigned long long int int_control_pointer){
		unsigned long long int int_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_int_more_stream(int_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					int_control_pointer_dule = external_using_allints();
				} else {
					int_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (int_var[int_control_pointer]>int_var[int_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_int_more_stream(unsigned long long int int_control_pointer){
		fc_getline();
			if (int_var[int_control_pointer]>atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_int_less(unsigned long long int int_control_pointer){
		unsigned long long int int_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_int_less_stream(int_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					int_control_pointer_dule = external_using_allints();
				} else {
					int_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (int_var[int_control_pointer]<int_var[int_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_int_less_stream(unsigned long long int int_control_pointer){
		fc_getline();
			if (int_var[int_control_pointer]<atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_int_moe(unsigned long long int int_control_pointer){
		unsigned long long int int_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_int_moe_stream(int_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					int_control_pointer_dule = external_using_allints();
				} else {
					int_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (int_var[int_control_pointer]>=int_var[int_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_int_moe_stream(unsigned long long int int_control_pointer){
		fc_getline();
			if (int_var[int_control_pointer]>=atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_int_loe(unsigned long long int int_control_pointer){
		unsigned long long int int_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_int_loe_stream(int_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					int_control_pointer_dule = external_using_allints();
				} else {
					int_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (int_var[int_control_pointer]<=int_var[int_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_int_loe_stream(unsigned long long int int_control_pointer){
		fc_getline();
			if (int_var[int_control_pointer]<=atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_int_aprox(){
	}
	void control_if_var_int_aprox_stream(){
	}

	void control_if_var_double() {
		unsigned long long int double_control_pointer;
				double_control_pointer = external_using_allints();
			fc_getline();
				if ((active_script[line-1]=="==") or (active_script[line-1]=="_equ") or (active_script[line-1]=="≡")) {
					control_if_var_double_equ(double_control_pointer);
				} else if ((active_script[line-1]=="!=") or (active_script[line-1]=="_not") or (active_script[line-1]=="≠")) {
					control_if_var_double_not(double_control_pointer);
				} else if ((active_script[line-1]==">") or (active_script[line-1]=="_more")) {
					control_if_var_double_more(double_control_pointer);
				} else if ((active_script[line-1]=="<") or (active_script[line-1]=="_less")) {
					control_if_var_double_less(double_control_pointer);
				} else if ((active_script[line-1]==">=") or (active_script[line-1]=="_moe") or (active_script[line-1]=="≥")) {
					control_if_var_double_moe(double_control_pointer);
				} else if ((active_script[line-1]=="<=") or (active_script[line-1]=="_loe") or (active_script[line-1]=="≤")) {
					control_if_var_double_loe(double_control_pointer);
				} else if ((active_script[line-1]=="~=") or (active_script[line-1]=="_aprox") or (active_script[line-1]=="≈")) {
					control_if_var_double_aprox();
				} else {
					error_stream();
				}
	}
	void control_if_var_double_equ(unsigned long long int double_control_pointer) {
		unsigned long long int double_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_double_equ_stream(double_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					double_control_pointer_dule = external_using_allints();
				} else {
					double_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (double_var[double_control_pointer]==double_var[double_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_double_equ_stream(unsigned long long int double_control_pointer) {
		fc_getline();
			if (double_var[double_control_pointer]==atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_double_not(unsigned long long int double_control_pointer) {
		unsigned long long int double_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_double_not_stream(double_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					double_control_pointer_dule = external_using_allints();
				} else {
					double_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (double_var[double_control_pointer]!=double_var[double_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_double_not_stream(unsigned long long int double_control_pointer) {
		fc_getline();
			if (double_var[double_control_pointer]!=atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_double_more(unsigned long long int double_control_pointer) {
		unsigned long long int double_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_double_more_stream(double_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					double_control_pointer_dule = external_using_allints();
				} else {
					double_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (double_var[double_control_pointer]>double_var[double_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_double_more_stream(unsigned long long int double_control_pointer) {
		fc_getline();
			if (double_var[double_control_pointer]>atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_double_less(unsigned long long int double_control_pointer) {
		unsigned long long int double_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_double_less_stream(double_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					double_control_pointer_dule = external_using_allints();
				} else {
					double_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (double_var[double_control_pointer]<double_var[double_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_double_less_stream(unsigned long long int double_control_pointer) {
		fc_getline();
			if (double_var[double_control_pointer]<atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_double_moe(unsigned long long int double_control_pointer) {
		unsigned long long int double_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_double_moe_stream(double_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					double_control_pointer_dule = external_using_allints();
				} else {
					double_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (double_var[double_control_pointer]>=double_var[double_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_double_moe_stream(unsigned long long int double_control_pointer) {
		fc_getline();
			if (double_var[double_control_pointer]>=atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_double_loe(unsigned long long int double_control_pointer) {
		unsigned long long int double_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_double_loe_stream(double_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					double_control_pointer_dule = external_using_allints();
				} else {
					double_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (double_var[double_control_pointer]<=double_var[double_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_double_loe_stream(unsigned long long int double_control_pointer) {
		fc_getline();
			if (double_var[double_control_pointer]<=atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_double_aprox() {
	}
	void control_if_var_double_aprox_stream() {
	}

	void control_if_var_float() {
		unsigned long long int float_control_pointer;
				float_control_pointer = external_using_allints();
			fc_getline();
				if ((active_script[line-1]=="==") or (active_script[line-1]=="_equ") or (active_script[line-1]=="≡")) {
					control_if_var_float_equ(float_control_pointer);
				} else if ((active_script[line-1]=="!=") or (active_script[line-1]=="_not") or (active_script[line-1]=="≠")) {
					control_if_var_float_not(float_control_pointer);
				} else if ((active_script[line-1]==">") or (active_script[line-1]=="_more")) {
					control_if_var_float_more(float_control_pointer);
				} else if ((active_script[line-1]=="<") or (active_script[line-1]=="_less")) {
					control_if_var_float_less(float_control_pointer);
				} else if ((active_script[line-1]==">=") or (active_script[line-1]=="_moe") or (active_script[line-1]=="≥")) {
					control_if_var_float_moe(float_control_pointer);
				} else if ((active_script[line-1]=="<=") or (active_script[line-1]=="_loe") or (active_script[line-1]=="≤")) {
					control_if_var_float_loe(float_control_pointer);
				} else if ((active_script[line-1]=="~=") or (active_script[line-1]=="_aprox") or (active_script[line-1]=="≈")) {
					control_if_var_float_aprox();
				} else {
					error_stream();
				}
	}
	void control_if_var_float_equ(unsigned long long int float_control_pointer) {
		unsigned long long int float_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_float_equ_stream(float_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					float_control_pointer_dule = external_using_allints();
				} else {
					float_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (float_var[float_control_pointer]==float_var[float_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_float_equ_stream(unsigned long long int float_control_pointer) {
		fc_getline();
			if (float_var[float_control_pointer]==atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_float_not(unsigned long long int float_control_pointer) {
		unsigned long long int float_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_float_not_stream(float_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					float_control_pointer_dule = external_using_allints();
				} else {
					float_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (float_var[float_control_pointer]!=float_var[float_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_float_not_stream(unsigned long long int float_control_pointer) {
		fc_getline();
			if (float_var[float_control_pointer]!=atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_float_more(unsigned long long int float_control_pointer) {
		unsigned long long int float_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_float_more_stream(float_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					float_control_pointer_dule = external_using_allints();
				} else {
					float_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (float_var[float_control_pointer]>float_var[float_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_float_more_stream(unsigned long long int float_control_pointer) {
		fc_getline();
			if (float_var[float_control_pointer]>atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_float_less(unsigned long long int float_control_pointer) {
		unsigned long long int float_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_float_less_stream(float_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					float_control_pointer_dule = external_using_allints();
				} else {
					float_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (float_var[float_control_pointer]<float_var[float_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_float_less_stream(unsigned long long int float_control_pointer) {
		fc_getline();
			if (float_var[float_control_pointer]<atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_float_moe(unsigned long long int float_control_pointer) {
		unsigned long long int float_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_float_moe_stream(float_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					float_control_pointer_dule = external_using_allints();
				} else {
					float_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (float_var[float_control_pointer]>=float_var[float_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_float_moe_stream(unsigned long long int float_control_pointer) {
		fc_getline();
			if (float_var[float_control_pointer]>=atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_float_loe(unsigned long long int float_control_pointer) {
		unsigned long long int float_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_float_loe_stream(float_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					float_control_pointer_dule = external_using_allints();
				} else {
					float_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (float_var[float_control_pointer]<=float_var[float_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_float_loe_stream(unsigned long long int float_control_pointer) {
		fc_getline();
			if (float_var[float_control_pointer]<=atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_float_aprox() {
	}
	void control_if_var_float_aprox_stream() {
	}

	void control_if_var_int64() {
		unsigned long long int int64_control_pointer;
				int64_control_pointer = external_using_allints();
			fc_getline();
				if ((active_script[line-1]=="==") or (active_script[line-1]=="_equ") or (active_script[line-1]=="≡")) {
					control_if_var_int64_equ(int64_control_pointer);
				} else if ((active_script[line-1]=="!=") or (active_script[line-1]=="_not") or (active_script[line-1]=="≠")) {
					control_if_var_int64_not(int64_control_pointer);
				} else if ((active_script[line-1]==">") or (active_script[line-1]=="_more")) {
					control_if_var_int64_more(int64_control_pointer);
				} else if ((active_script[line-1]=="<") or (active_script[line-1]=="_less")) {
					control_if_var_int64_less(int64_control_pointer);
				} else if ((active_script[line-1]==">=") or (active_script[line-1]=="_moe") or (active_script[line-1]=="≥")) {
					control_if_var_int64_moe(int64_control_pointer);
				} else if ((active_script[line-1]=="<=") or (active_script[line-1]=="_loe") or (active_script[line-1]=="≤")) {
					control_if_var_int64_loe(int64_control_pointer);
				} else if ((active_script[line-1]=="~=") or (active_script[line-1]=="_aprox") or (active_script[line-1]=="≈")) {
					control_if_var_int_aprox();
				} else {
					error_stream();
				}
	}
	void control_if_var_int64_equ(unsigned long long int int64_control_pointer) {
		unsigned long long int int64_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_int64_equ_stream(int64_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					int64_control_pointer_dule = external_using_allints();
				} else {
					int64_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (int64_var[int64_control_pointer]==int64_var[int64_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_int64_equ_stream(unsigned long long int int64_control_pointer) {
		fc_getline();
			if (int64_var[int64_control_pointer]==atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_int64_not(unsigned long long int int64_control_pointer) {
		unsigned long long int int64_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_int64_not_stream(int64_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					int64_control_pointer_dule = external_using_allints();
				} else {
					int64_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (int64_var[int64_control_pointer]!=int64_var[int64_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_int64_not_stream(unsigned long long int int64_control_pointer) {
		fc_getline();
			if (int64_var[int64_control_pointer]!=atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_int64_more(unsigned long long int int64_control_pointer) {
		unsigned long long int int64_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_int64_more_stream(int64_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					int64_control_pointer_dule = external_using_allints();
				} else {
					int64_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (int64_var[int64_control_pointer]>int64_var[int64_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_int64_more_stream(unsigned long long int int64_control_pointer) {
		fc_getline();
			if (int64_var[int64_control_pointer]>atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_int64_less(unsigned long long int int64_control_pointer) {
		unsigned long long int int64_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_int64_less_stream(int64_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					int64_control_pointer_dule = external_using_allints();
				} else {
					int64_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (int64_var[int64_control_pointer]<int64_var[int64_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_int64_less_stream(unsigned long long int int64_control_pointer) {
		fc_getline();
			if (int64_var[int64_control_pointer]<atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_int64_moe(unsigned long long int int64_control_pointer) {
		unsigned long long int int64_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_int64_moe_stream(int64_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					int64_control_pointer_dule = external_using_allints();
				} else {
					int64_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (int64_var[int64_control_pointer]>=int64_var[int64_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_int64_moe_stream(unsigned long long int int64_control_pointer) {
		fc_getline();
			if (int64_var[int64_control_pointer]>=atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_int64_loe(unsigned long long int int64_control_pointer) {
		unsigned long long int int64_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_int64_loe_stream(int64_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					int64_control_pointer_dule = external_using_allints();
				} else {
					int64_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (int64_var[int64_control_pointer]<=int64_var[int64_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_int64_loe_stream(unsigned long long int int64_control_pointer) {
		fc_getline();
			if (int64_var[int64_control_pointer]<=atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_int64_aprox() {
	}
	void control_if_var_int64_aprox_stream() {
	}

	void control_if_var_bool() {
		unsigned long long int bool_control_pointer;
				bool_control_pointer = external_using_allints();
			fc_getline();
				if ((active_script[line-1]=="==") or (active_script[line-1]=="_equ") or (active_script[line-1]=="≡")) {
					control_if_var_bool_equ(bool_control_pointer);
				} else {
					error_stream();
				}
	}
	void control_if_var_bool_equ(unsigned long long int bool_control_pointer) {
		unsigned long long int bool_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_bool_equ_stream(bool_control_pointer);
			} else {
				if (active_script[line-1]=="_var") {
					bool_control_pointer_dule = external_using_allints();
				} else {
					bool_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (bool_var[bool_control_pointer]==bool_var[bool_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_bool_equ_stream(unsigned long long int bool_control_pointer) {
		fc_getline();
			if (bool_var[bool_control_pointer]==atof(active_script[line-1].c_str())) {
				control_if_true();
			} else {
				control_if_false();
			}
	}

	void control_if_var_string() {
		unsigned long long int string_control_pointer;
				string_control_pointer = external_using_allints();
			fc_getline();
				if ((active_script[line-1]=="==") or (active_script[line-1]=="_equ") or (active_script[line-1]=="≡")) {
					control_if_var_string_equ(string_control_pointer);
				} else if ((active_script[line-1]=="!=") or (active_script[line-1]=="_not") or (active_script[line-1]=="≠")) {
					control_if_var_string_not(string_control_pointer);
				} else if ((active_script[line-1]=="~=") or (active_script[line-1]=="_aprox") or (active_script[line-1]=="≈")) {

				} else {
					error_stream();
				}
	}
	void control_if_var_string_equ(unsigned long long int string_control_pointer) {
		unsigned long long int string_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_string_equ_stream(string_control_pointer);
			} else if (active_script[line-1]=="_number") {
				/*if (isdigit(string_var[string_control_pointer].c_str())==true) {
					control_if_true();
				} else {
					control_if_false();
				}
				*/
			} else {
				if (active_script[line-1]=="_var") {
					string_control_pointer_dule = external_using_allints();
				} else {
					string_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (string_var[string_control_pointer]==string_var[string_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_string_equ_stream(unsigned long long int string_control_pointer) {
		fc_getline();
			if (string_var[string_control_pointer]==active_script[line-1]) {
				control_if_true();
			} else {
				control_if_false();
			}
	}
	void control_if_var_string_not(unsigned long long int string_control_pointer) {
		unsigned long long int string_control_pointer_dule;
		fc_getline();
			if (active_script[line-1]=="_stream") {
				control_if_var_string_not_stream(string_control_pointer);
			} else if (active_script[line-1]=="_number") {
				/*if (isdigit(string_var[string_control_pointer].c_str())==true) {
					control_if_false();
				} else {
					control_if_true();
				}
				*/
			} else {
				if (active_script[line-1]=="_var") {
					string_control_pointer_dule = external_using_allints();
				} else {
					string_control_pointer_dule = atof(active_script[line-1].c_str());
				}
				if (string_var[string_control_pointer]!=string_var[string_control_pointer_dule]) {
					control_if_true();
				} else {
					control_if_false();
				}
			}
	}
	void control_if_var_string_not_stream(unsigned long long int string_control_pointer) {
		fc_getline();
			if (string_var[string_control_pointer]!=active_script[line-1]) {
				control_if_true();
			} else {
				control_if_false();
			}
	}

	void control_if_errorlevel() {
		unsigned long long int errorlevel_control_pointer;
		while (true) {
				errorlevel_control_pointer = external_using_allints();
			if (errorlevel_control_pointer<=error_level) {
				terminate_all();
			} else {
				break;
			}
		}
	}
	void control_if_errorlevel_equ() {

	}
	void control_if_stream() {

	}
	void control_if_stream_equ() {

	}
	void control_if_else() {

	}
	void control_if_elif() {

	}
	void control_if_and() {

	}
	void control_if_or() {

	}
	void control_if_not() {

	}
	void control_if_xor() {

	}
	void control_if_xnor() {

	}
	void control_if_nand() {

	}
	void control_if_continue() {

	}


void control_for() {
	//for every
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_int") {
			error_stream();
		} else if (active_script[line-1]=="_double") {
			error_stream();
		} else if (active_script[line-1]=="_float") {
			error_stream();
		} else if (active_script[line-1]=="_int64") {
			error_stream();
		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
			error_stream();
		}
	}
}

void control_while() {
    void control_while_int();
    void control_while_double();
    void control_while_float();
    void control_while_int64();
    void control_while_bool();
    void control_while_string();
    while (true) {
		fc_getline();
        if (active_script[line-1]=="_int") {

        } else if (active_script[line-1]=="_double") {

        } else if (active_script[line-1]=="_float") {

        } else if (active_script[line-1]=="_int64") {

        } else if (active_script[line-1]=="_bool") {

        } else if (active_script[line-1]=="_string") {

        } else if (active_script[line-1]=="_ret") {
            break;
        } else {
            error_stream();
        }

    }
}

void control_inspect() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_line") {
			control_inspect_line();
		} else if (active_script[line-1]=="_split") {
            control_inspect_split();
		} else if (active_script[line-1]=="_parce") {
			control_inspect_parce();
		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
			error_stream();
		}
	}
}
	//control_cycle_commands:
	void control_inspect_line() {
		unsigned long long int chart_control_pointer;
		unsigned long long int string_control_pointer;
				chart_control_pointer = external_using_allints();
				string_control_pointer = external_using_allints();
				getline(chart_var [chart_control_pointer], string_var [string_control_pointer]);
	}
	void control_inspect_split() {
        unsigned long long int string_control_pointer;
        unsigned long long int string_control_pointer_dule;
        unsigned long long int string_control_pointer_triple;
				string_control_pointer = external_using_allints();
				string_control_pointer_dule = external_using_allints();
        string string_split = string_var [string_control_pointer];
        string delimiter = string_var [string_control_pointer_dule];
        size_t split_pos = 0;
        string split_token;
        while ((split_pos = string_split.find(delimiter)) != std::string::npos) {
            split_token = string_split.substr(0, split_pos);
								string_control_pointer_triple = external_using_allints();
                string_var [string_control_pointer_triple]=split_token;
            string_split.erase(0, split_pos + delimiter.length());
        }
						string_control_pointer_triple = external_using_allints();
            string_var [string_control_pointer_triple]=string_split;
        return;
	}
	void control_inspect_parce() {
		unsigned long long int string_control_pointer;
		unsigned long long int string_control_pointer_dule;
		string delimiter;
			string_control_pointer = external_using_allints();
			fc_getline();
			if (active_script[line-1]=="_string") {
				delimiter = external_using_string();
			} else {
				delimiter = active_script[line-1];
			}
					string_control_pointer_dule = external_using_allints();
					string_var [string_control_pointer_dule] = string_var[string_control_pointer].substr(0, string_var[string_control_pointer].find(delimiter));
	}

void control_goto() {
	string goto_control_pointer = ("0");
	fc_getline();
		goto_control_pointer = active_script[line-1];
		//active_file.clear();
		//active_file.seekg(0, std::ios::beg);
		line=0;
		control_goto_scan(goto_control_pointer);
}
	//control_goto commands:
	void control_goto_scan(string goto_control_pointer) {
		bool goto_found_location = false;
		while (true) {
			fc_getline();
			if (active_script[line-1]=="*@") {
				fc_getline();
					if (active_script[line-1]==goto_control_pointer) {
						goto_found_location = true;
					}
			} else if (goto_found_location==true) {
				goto_found_location = false;
				break;
			}
		}
	}
