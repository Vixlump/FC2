//function stream register
	void function_time();
	void function_time_day();
	void function_time_month();
	void function_time_second();
	void function_time_year();
	void function_time_hour();
	void function_time_minute();
	void function_numbers();
	void function_string();
	void function_string_replace();
	void function_string_resize();
	void function_string_removelast();
	void function_string_delete();
	void function_string_add();
	void function_string_find();
	void function_string_insert();
	void function_args();
	void function_kata();
	void reserve_tap();

	//function stream
void function_stream() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="+time") {
			function_time();
        } else if (active_script[line-1]=="+tap") {
					//deprications=deprications+1;
					reserve_tap();
        } else if (active_script[line-1]=="+string") {
            function_string();
				} else if (active_script[line-1]=="+kata") {
						function_kata();
        } else if (active_script[line-1]=="+numbers") {
            function_numbers();
        } else if (active_script[line-1]=="+args") {
            function_args();
		} else if (active_script[line-1]=="f*") {
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

//function stream
void function_time() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_day") {
			function_time_day();
		} else if (active_script[line-1]=="_month") {
			function_time_month();
		} else if (active_script[line-1]=="_year") {
			function_time_year();
		} else if (active_script[line-1]=="_hour") {
			function_time_hour();
		} else if (active_script[line-1]=="_minute") {
			function_time_minute();
		} else if (active_script[line-1]=="_second") {
			function_time_second();
		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
			error_stream();
		}
	}
}
	//function_time commands:
	void function_time_day() {
		
	}
	void function_time_month() {
		
	}
	void function_time_second() {
		
	}
	void function_time_year() {
		
	}
	void function_time_hour() {
		
	}
	void function_time_minute() {
		
	}

void function_numbers() {
    void function_numbers_int();
    void function_numbers_float();
    void function_numbers_double();
    void function_numbers_int64();
    /*
        Numbers to be stored.
        _max
        _min
        _centre
        _inf
        _i
    */
    while (true) {
		fc_getline();
        if (active_script[line-1]=="_int") {
            function_numbers_int();
        } else if (active_script[line-1]=="_float") {
            function_numbers_float();
        } else if (active_script[line-1]=="_double") {
            function_numbers_double();
        } else if (active_script[line-1]=="_int64") {
            function_numbers_int64();
        } else if (active_script[line-1]=="_ret") {
            break;
        } else {
            error_stream();
        }
    }
}
    //function numbers commands:
    void function_numbers_int() {
        unsigned long long int int_control_pointer;
							int_control_pointer = external_using_allints();
            fc_getline();
            if (active_script[line-1]=="_max") {
                int_var[int_control_pointer]=INT_MAX;
            } else if (active_script[line-1]=="_min") {
                int_var[int_control_pointer]=INT_MIN;
            } else if ((active_script[line-1]=="_center")or(active_script[line-1]=="_centre")) {
                int_var[int_control_pointer]=0;
            } else if (active_script[line-1]=="_inf") {
                int_var[int_control_pointer]= std::numeric_limits<int>::infinity();
						} else if (active_script[line-1]=="_alnum") {
							int_var[int_control_pointer] = external_using_alnum();
            } else {
                error_stream();
            }
    }
    void function_numbers_float() {
        unsigned long long int float_control_pointer;
							float_control_pointer = external_using_allints();
            fc_getline();
            if (active_script[line-1]=="_max") {
                //float_var[float_control_pointer]=FLOAT_MAX;
            } else if (active_script[line-1]=="_min") {
                //float_var[float_control_pointer]=FLOAT_MIN;
            } else if ((active_script[line-1]=="_center")or(active_script[line-1]=="_centre")) {
                float_var[float_control_pointer]=0;
            } else if (active_script[line-1]=="_inf") {
                float_var[float_control_pointer]= std::numeric_limits<float>::infinity();
            } else {
                error_stream();
            }
    }
    void function_numbers_double() {
        //unsigned long long int double_control_pointer;
    }
    void function_numbers_int64() {
        //unsigned long long int int64_control_pointer;
				unsigned long long int int64_control_pointer;
							int64_control_pointer = external_using_allints();
            fc_getline();
            if (active_script[line-1]=="_max") {
                int64_var[int64_control_pointer]=INT_MAX;
            } else if (active_script[line-1]=="_min") {
                int64_var[int64_control_pointer]=INT_MIN;
            } else if ((active_script[line-1]=="_center")or(active_script[line-1]=="_centre")) {
                int64_var[int64_control_pointer]=0;
            } else if (active_script[line-1]=="_inf") {
                int64_var[int64_control_pointer]= std::numeric_limits<long long int>::infinity();
						} else if (active_script[line-1]=="_alnum") {
							int64_var[int64_control_pointer] = external_using_alnum();
            } else {
                error_stream();
            }
    }

void function_string() {
    while (true) {
		fc_getline();
        if (active_script[line-1]=="_replace") {
            function_string_replace();
        } else if (active_script[line-1]=="_resize") {
            function_string_resize();
        } else if (active_script[line-1]=="_removelast") {
            function_string_removelast();
        } else if (active_script[line-1]=="_delete") {
            function_string_delete();
        } else if (active_script[line-1]=="_add") {
            function_string_add();
				} else if (active_script[line-1]=="_insert") {
						function_string_insert();
        } else if (active_script[line-1]=="_find") {
            //first of
            //last of
            //first absence of
            //last absence of
            function_string_find();
        } else if (active_script[line-1]=="_ret") {
            break;
        } else {
            error_stream();
        }
    }
}
    //function string commands:
    void function_string_replace() {
			unsigned long long int string_control_pointer;
			unsigned int int_control_factor;
			unsigned int int_control_factor_dule;
			string string_control_factor;
				string_control_pointer = external_using_allints();
				int_control_factor = external_using_allints();
				int_control_factor_dule = external_using_allints();
			fc_getline();
			if (active_script[line-1]=="_string") {
				string_control_factor = external_using_string();
			} else {
				string_control_factor = active_script[line-1];
			}
			string_var[string_control_pointer].replace(int_control_factor,int_control_factor_dule,string_control_factor);
    }
    void function_string_resize() {
			unsigned long long int string_control_pointer;
			unsigned int int_control_factor;
				string_control_pointer = external_using_allints();
				int_control_factor = external_using_allints();
			string_var[string_control_pointer].resize(int_control_factor);
    }
    void function_string_removelast() {
			unsigned long long int string_control_pointer;
				string_control_pointer = external_using_allints();
			string_var[string_control_pointer].pop_back();
    }
    void function_string_delete() {
			unsigned long long int string_control_pointer;
			unsigned int int_control_factor;
			unsigned int int_control_factor_dule;
				string_control_pointer = external_using_allints();
				int_control_factor = external_using_allints();
				int_control_factor_dule = external_using_allints();
			string_var [string_control_pointer].erase(int_control_factor,int_control_factor_dule);
    }
    void function_string_add() {
			unsigned long long int string_control_pointer;
			unsigned long long int string_control_pointer_dule;
				string_control_pointer = external_using_allints();
			fc_getline();
			if (active_script[line-1]=="_var") {
				string_control_pointer_dule = external_using_allints();
			} else if (active_script[line-1]=="_stream") {
				string_var [string_control_pointer] = string_var [string_control_pointer]+active_script[line-1];
				return;
			} else {
				string_control_pointer_dule = atof(active_script[line-1].c_str());
			}
			string_var [string_control_pointer] = string_var [string_control_pointer]+string_var [string_control_pointer_dule];
    }
		void function_string_insert() {
			unsigned long long int string_control_pointer;
			unsigned int int_control_factor;
			string string_control_factor;
				string_control_pointer = external_using_allints();
				int_control_factor = external_using_allints();
			fc_getline();
			if (active_script[line-1]=="_string") {
				string_control_factor = external_using_string();
			} else {
				string_control_factor = active_script[line-1];
			}
			string_var[string_control_pointer].insert(int_control_factor,string_control_factor);
		}
    void function_string_find() {
			/*
			unsigned long long int string_control_pointer;
			unsigned long long int int_control_pointer;
			unsigned int numbercount_control_factor;
			string input_control_factor;
			string string_control_factor;
				string_control_pointer = external_using_allints();
			fc_getline();
			if (active_script[line-1]=="_string") {
				string_control_factor = external_using_string();
			} else {
				string_control_factor = active_script[line-1];
			}
				int_control_pointer = external_using_allints();
			numbercount_control_factor = 0;
			input_control_factor = string_var[string_control_pointer];
			for (int int_control_factor = 0; int_control_factor<input_control_factor.size(); int_control_factor++)
				if (input_control_factor[int_control_factor] == string_control_factor) numbercount_control_factor++;
			int_var[int_control_pointer] = numbercount_control_factor;
			*/
    }

		void function_kata() {
			//+kata
			//(kata id)
			//_fill
			//(string id)
			//(int id)
			unsigned long long int kata_control_pointer;
			unsigned long long int string_control_pointer;
			unsigned long long int int_control_pointer;
			kata_control_pointer = external_using_allints();
			while (true) {
				fc_getline();
				if (active_script[line-1]=="_fill") {
					fc_getline();
					if (active_script[line-1]=="_name") {
						string_control_pointer = external_using_allints();
						kata_var [kata_control_pointer].name = string_var [string_control_pointer];
					} else if (active_script[line-1]=="_type") {
						int_control_pointer = external_using_allints();
						kata_var [kata_control_pointer].idtype = abs(int_var [int_control_pointer]);
					} else if (active_script[line-1]=="_stack") {
						int_control_pointer = external_using_allints();
						kata_var [kata_control_pointer].idstack = abs(int_var [int_control_pointer]);
					} else {
						error_stream();
					}
				} else if (active_script[line-1]=="_fetch") {
					fc_getline();
					if (active_script[line-1]=="_name") {
						string_control_pointer = external_using_allints();
						string_var [string_control_pointer] = kata_var [kata_control_pointer].name;
					} else if (active_script[line-1]=="_type") {
						int_control_pointer = external_using_allints();
						int_var [int_control_pointer] = kata_var [kata_control_pointer].idtype;
					} else if (active_script[line-1]=="_stack") {
						int_control_pointer = external_using_allints();
						int_var [int_control_pointer] = kata_var [kata_control_pointer].idstack;
					} else {
						error_stream();
					}
				} else if (active_script[line-1]=="_ret") {
					break;
				} else {
					error_stream();
				}
			}
		}

    void function_args() {
        unsigned long long int string_control_pointer;
        unsigned short int args_control_pointer;
            string_control_pointer = external_using_allints();
							args_control_pointer = external_using_allints();
            if (args_control_pointer>=128) {
                error_stream();
            } else {
                string_var [string_control_pointer] = cmd_argv [args_control_pointer];
            }
    }
