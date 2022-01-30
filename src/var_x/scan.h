
void scan_stream() {
	//leave this while get line for stream safety reasons
	while (line <= active_script.size()) {
		line++;
		//danger do not remove while get line from this line
		//ensure this section matches fc_getline function
		//stream
		if (active_script[line - 1] == syx_v) {
			//variable
			var_stream();
			continue;
		} else if (active_script[line - 1] == syx_c) {
			//controls and conditions
			control_stream();
			continue;
		} else if (active_script[line - 1] == syx_m) {
			//math
			math_stream();
			continue;
		} else if (active_script[line - 1] == syx_f) {
			//main functions
			function_stream();
			continue;
		} else if (active_script[line - 1] == syx_x) {
			//external processes
			external_stream();
			continue;
		} else if (active_script[line - 1] == syx_cs) {
			channelswap_script();
			continue;
		} else if (active_script[line - 1] == syx_ux) {
			asignment_wrap();
			continue;
		} else if (active_script[line - 1] == syx_i) {
			//input and output
			input_stream();
			continue;
		} else if (active_script[line - 1] == syx_t) {
			//threading
			threading_stream();
			continue;
		} else if (active_script[line - 1] == syx_a) {
			//aspectu
			aspectu_stream();
			continue;
		} else if (active_script[line - 1] == syx_ap) {
			//assignments
			asignment_point();
			continue;
		} else if (active_script[line - 1] == syx_vx) {
			abreg();
			continue;
		} else if (active_script[line - 1] == syx_aw) {
			//assignments
			asignment_wrap();
			continue;
		} else if (active_script[line - 1] == syx_r) {
			//reserved functions and taps
			reserve_stream();
			continue;
		} else if (fc2_check_for_functions() == true) {
			continue;
		} else if (fc2_function_action_index() == true) {
			continue;
		} else if (active_script[line - 1] == syx_ws) {
		    //white space
            asignment_wrap();
			continue;
		} else if (active_script[line - 1] == syx_e) {
			//experimental stream
			experimental_stream();
			continue;
		} else if (active_script[line - 1] == "f") {
			//function register
			fc2_define_function();
			continue;
        } else if (active_script[line-1]==syx_br) {
            //ends scan_stream in a non safe but managable way
            break;
		} else if (active_script[line-1]==syx_nc) {
			//notations
			notation_controller();
			continue;
		} else if (active_script[line-1]==syx_dp) {
			//break point
			debug_point();
			continue;
		} else {
			error_stream();
		}
	}
}
void scan_inquire() {
    unsigned long long int string_control_pointer;
    ifstream temp_active_scan;
    string scan_process_m;
    temp_active_scan.open(active_file_backup.c_str());
    unsigned int temp_line = 0;
    while (getline(temp_active_scan, scan_process_m)) {
        if (temp_line==line_bak) {
                line_bak=line_bak+1;
            break;
        }
        temp_line = temp_line+1;
    }
			string_control_pointer = external_using_allints();
    string_var[string_control_pointer] = scan_process_m;
    temp_active_scan.close();
    return;
}
