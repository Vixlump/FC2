//input stream register
	void input_input();
	void input_output();
	void input_output_var();
	void input_output_var_int();
	void input_output_var_int_location();
	void input_output_var_double();
	void input_output_var_double_location();
	void input_output_var_float();
	void input_output_var_float_location();
	void input_output_var_int64();
	void input_output_var_int64_location();
	void input_output_var_bool();
	void input_output_var_bool_location();
	void input_output_var_string();
	void input_output_var_string_location();
	void input_output_var_chart();
	void input_output_var_chart_location();
	void input_output_var_quantum();
	void input_output_var_quantum_location();
	void input_output_var_kata();
	void input_output_var_kata_location();
	void input_output_var_action();
	void input_output_var_action_location();
	void input_output_group();
	void input_output_line();
	void input_output_break();
	void input_output_write();

//input stream:
void input_stream() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="+output") {
			input_output();
		} else if (active_script[line-1]=="+keyinput") {
			//keyboard, mouse, other controllers
		} else if (active_script[line-1]=="+input") {
			input_input();
		} else if (active_script[line-1]=="+debug") {
			debug_stream();
		} else if (active_script[line-1]=="+write") {
			input_output_write();
		} else if (active_script[line-1]=="i*") {
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
    } else if (active_script[line-1]=="+errorlevel") {
			error_level=error_level+1;
			if (error_cap>0) {
	      if (error_cap==error_level) {
	        terminate_all();
	      } else if (error_level>error_cap) {
	        cout<<"Program is damaged!"<<endl;
	        terminate_all();
	      }
	    }
    } else if (active_script[line-1]=="+deprications") {
      deprications=deprications+1;
    } else if (active_script[line-1]=="") {
		  //white space
      asignment_wrap();
		} else {
			error_stream();
		}
	}
}

//input output stream
void input_output() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_var") {
			input_output_var();
		} else if (active_script[line-1]=="_group") {
			input_output_group();
		} else if (active_script[line-1]=="_line") {
			input_output_line();
		} else if (active_script[line-1]=="_break") {
			input_output_break();
		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
			error_stream();
		}
	}
}
	//intput_output commands:
	void input_output_var() {
		fc_getline();
			if (active_script[line-1]=="_int") {
				input_output_var_int();
			} else if (active_script[line-1]=="_double") {
				input_output_var_double();
			} else if (active_script[line-1]=="_float") {
				input_output_var_float();
			} else if (active_script[line-1]=="_int64") {
				input_output_var_int64();
			} else if (active_script[line-1]=="_bool") {
				input_output_var_bool();
			} else if (active_script[line-1]=="_string") {
				input_output_var_string();
			} else if (active_script[line-1]=="_action") {
				input_output_var_action();
			} else if (active_script[line-1]=="_chart") {
                error_stream();
			} else if (active_script[line-1]=="_kata") {
				input_output_var_kata();
			} else if (active_script[line-1]=="_quantum") {
			    error_stream();
			} else {
				error_stream();
			}
	}
	void input_output_var_action() {
		fc_getline();
		if (active_script[line - 1] == "_location") {
			input_output_var_action_location();
			return;
		}
		for (int i = 0; i < action_var.size(); i++) {
			if (action_var[i].name == active_script[line - 1]) {
				cout << action_var[i].value;
				return;
			}
		}
		error_stream();
	}
	void input_output_var_action_location() {

	}

	void input_output_var_int() {
		fc_getline();
      if (active_script[line-1]=="_location") {
        input_output_var_int_location();
        return;
      }
      unsigned long long int int_control_pointer;
			if (active_script[line-1]=="_var") {
				int_control_pointer = external_using_allints();
			} else {
				int_control_pointer = atof(active_script[line-1].c_str());
			}
			cout << int_var [int_control_pointer];
	}
	void input_output_var_int_location() {
	  unsigned long long int int_control_pointer;
							int_control_pointer = external_using_allints();
			cout << &int_var [int_control_pointer];
	}

	void input_output_var_double() {
		fc_getline();
            if (active_script[line-1]=="_location") {
                input_output_var_double_location();
                return;
            }
            unsigned long long int double_control_pointer;
						if (active_script[line-1]=="_var") {
							double_control_pointer = external_using_allints();
						} else {
							double_control_pointer = atof(active_script[line-1].c_str());
						}
			cout << double_var [double_control_pointer];
	}
	void input_output_var_double_location() {
	    unsigned long long int double_control_pointer;
				double_control_pointer = external_using_allints();
			cout << &double_var [double_control_pointer];
	}

	void input_output_var_float() {
		fc_getline();
            if (active_script[line-1]=="_location") {
                input_output_var_float_location();
                return;
            }
            unsigned long long int float_control_pointer;
						if (active_script[line-1]=="_var") {
							float_control_pointer = external_using_allints();
						} else {
							float_control_pointer = atof(active_script[line-1].c_str());
						}
			cout << float_var [float_control_pointer];
	}
	void input_output_var_float_location() {
	    unsigned long long int float_control_pointer;
				float_control_pointer = external_using_allints();
			cout << &float_var [float_control_pointer];
	}

	void input_output_var_int64() {
		fc_getline();
            if (active_script[line-1]=="_location") {
                input_output_var_int64_location();
                return;
            }
            unsigned long long int int64_control_pointer;
						if (active_script[line-1]=="_var") {
							int64_control_pointer = external_using_allints();
						} else {
							int64_control_pointer = atof(active_script[line-1].c_str());
						}
			cout << int64_var [int64_control_pointer];
	}
	void input_output_var_int64_location() {
	    unsigned long long int int64_control_pointer;
				int64_control_pointer = external_using_allints();
			cout << &int64_var [int64_control_pointer];
	}

	void input_output_var_bool() {
		fc_getline();
            if (active_script[line-1]=="_location") {
                input_output_var_bool_location();
                return;
            }
            unsigned long long int bool_control_pointer;
						if (active_script[line-1]=="_var") {
							bool_control_pointer = external_using_allints();
						} else {
							bool_control_pointer = atof(active_script[line-1].c_str());
						}
			cout << bool_var [bool_control_pointer];
	}
	void input_output_var_bool_location() {
	    unsigned long long int bool_control_pointer;
				bool_control_pointer = external_using_allints();
			cout << &bool_var [bool_control_pointer];
	}

	void input_output_var_string() {
		fc_getline();
            if (active_script[line-1]=="_location") {
                input_output_var_string_location();
                return;
            }
            unsigned long long int string_control_pointer;
						if (active_script[line-1]=="_var") {
							string_control_pointer = external_using_allints();
						} else {
							string_control_pointer = atof(active_script[line-1].c_str());
						}
			cout << string_var [string_control_pointer];
	}
	void input_output_var_string_location() {
	    unsigned long long int string_control_pointer;
				string_control_pointer = external_using_allints();
			cout << &string_var [string_control_pointer];
	}
	void input_output_var_kata() {
		fc_getline();
            if (active_script[line-1]=="_location") {
                input_output_var_kata_location();
                return;
            }
            unsigned long long int kata_control_pointer;
						if (active_script[line-1]=="_var") {
							kata_control_pointer = external_using_allints();
						} else {
							kata_control_pointer = atof(active_script[line-1].c_str());
						}
			cout << "["<<kata_var [kata_control_pointer].name<<"]["<<kata_var [kata_control_pointer].idtype<<"]["<<kata_var [kata_control_pointer].idstack<<"]";
	}
	void input_output_var_kata_location() {
		unsigned long long int kata_control_pointer;
			kata_control_pointer = external_using_allints();
		cout << &kata_var [kata_control_pointer];
	}

	void input_output_var_chart() {

	}
	void input_output_var_chart_location() {
	}

	void input_output_var_quantum() {

	}
	void input_output_var_quantum_location() {
	}

	void input_output_group() {
		while (true) {
			fc_getline();
			if (active_script[line-1]=="_ret") {
				break;
			} else if (active_script[line-1]=="_break") {
				cout << endl;
            } else if (active_script[line-1]=="_var") {
                input_output_var();
            } else if (active_script[line-1]=="_line") {
                input_output_line();
            } else if (active_script[line-1]=="_error") {
                cout << error_level;
            } else if (active_script[line-1]=="_deprications") {
                cout << deprications;
            } else if (active_script[line-1]=="_debug") {
                debug_stream();
			} else {
				cout << active_script[line-1];
			}

		}
	}

	void input_output_line() {
		fc_getline();
			cout << active_script[line-1] << endl;
	}

	void input_output_break() {
		cout << endl;
	}

void input_input() {
	unsigned long long int string_control_pointer;
			string_control_pointer = external_using_allints();
		cin >> string_var [string_control_pointer];
}

void input_output_write() {
	unsigned long long int quantum_control_pointer;
	unsigned long long int string_control_pointer;
			quantum_control_pointer = external_using_allints();
		while (true) {
			fc_getline();
			if (active_script[line-1]=="_line") {
				fc_getline();
					quantum_var[quantum_control_pointer] << active_script[line-1].c_str();
			} else if (active_script[line-1]=="_string") {
						string_control_pointer = external_using_allints();
					quantum_var[quantum_control_pointer] << string_var[string_control_pointer].c_str();
			} else if (active_script[line-1]=="_break") {
				quantum_var[quantum_control_pointer] << endl;
			} else if (active_script[line-1]=="_ret") {
				break;
			} else {
				error_stream();
			}
		}
}
