void var_store();
	void var_store_int();
	void var_store_double();
	void var_store_float();
	void var_store_int64();
	void var_store_bool();
	void var_store_string();
	void var_store_complex();
	void var_store_kata();
	void var_store_action();
	void var_merge();
	void var_swap();
	void var_swap_int();
	void var_swap_double();
	void var_swap_float();
	void var_swap_int64();
	void var_swap_bool();
	void var_swap_string();
	void var_allocate();
	void var_allocate_int();
	void var_allocate_int_expand();
	void var_allocate_double();
	void var_allocate_double_expand();
	void var_allocate_float();
	void var_allocate_float_expand();
	void var_allocate_int64();
	void var_allocate_int64_expand();
	void var_allocate_bool();
	void var_allocate_bool_expand();
	void var_allocate_string();
	void var_allocate_string_expand();
	void var_allocate_chart();
	void var_allocate_chart_expand();
	void var_allocate_quantum();
	void var_allocate_quantum_expand();
	void var_allocate_access();
	void var_allocate_access_expand();
	void var_allocate_complex();
	void var_allocate_complex_expand();
	void var_allocate_kata();
	void var_allocate_kata_expand();
	void var_copy();
	void var_copy_int();
	void var_copy_double();
	void var_copy_float();
	void var_copy_int64();
	void var_copy_bool();
	void var_copy_string();
	void var_copy_kata();
	void var_convert();
	void var_convert_select(int convert_c_data, unsigned long long int int_control_pointer, unsigned long long int double_control_pointer, unsigned long long int float_control_pointer, unsigned long long int int64_control_pointer, unsigned long long int bool_control_pointer, unsigned long long int string_control_pointer);
	void var_convert_int(int convert_c, int accept_int, long long int accept_int64, double accept_double, float accept_float, bool accept_bool, string accept_string);
	void var_convert_double(int convert_c, int accept_int, long long int accept_int64, double accept_double, float accept_float, bool accept_bool, string accept_string);
	void var_convert_float(int convert_c, int accept_int, long long int accept_int64, double accept_double, float accept_float, bool accept_bool, string accept_string);
	void var_convert_int64(int convert_c, int accept_int, long long int accept_int64, double accept_double, float accept_float, bool accept_bool, string accept_string);
	void var_convert_bool(int convert_c, int accept_int, long long int accept_int64, double accept_double, float accept_float, bool accept_bool, string accept_string);
	void var_convert_string(int convert_c, int accept_int, long long int accept_int64, double accept_double, float accept_float, bool accept_bool, string accept_string);
	void var_convert_action();
	void var_clear();
    void var_clear_int();
    void var_clear_double();
    void var_clear_float();
    void var_clear_int64();
    void var_clear_bool();
    void var_clear_string();
    void var_clear_chart();
    void var_clear_quantum();
		void var_clear_kata();
    void var_delete();
		void var_locate();

//var stream
void var_stream() {
	while (true) {
		fc_getline();
		if (active_script[line-1]==syx_v_store) {
			var_store();
		} else if (active_script[line-1]==syx_v_swap) {
			var_swap();
		} else if (active_script[line-1]==syx_v_clear) {
			var_clear();
		} else if (active_script[line-1]==syx_v_delete) {
			var_delete();
		} else if (active_script[line-1]==syx_v_copy) {
			var_copy();
		} else if (active_script[line-1]==syx_v_convert) {
			var_convert();
		} else if (active_script[line-1]=="+locate") {
			var_locate();
		} else if (active_script[line-1]==syx_v_allocate) {
			var_allocate();
		} else if (active_script[line-1]==syx_v_return) {
			break;
		} else if (active_script[line-1]==syx_ap) {
			//assignments
			asignment_point();
		} else if (active_script[line-1]==syx_vx) {
			abreg();
		} else if (active_script[line-1]==syx_aw) {
			//assignments
			asignment_wrap();
        } else if (active_script[line-1]==syx_cs) {
			channelswap_script();
        } else if (active_script[line-1]==syx_ux) {
            break;
		} else if (active_script[line-1]==syx_nc) {
			//notations
			notation_controller();
		} else if (active_script[line-1]==syx_dp) {
			//break point
			debug_point();
        } else if (active_script[line-1]==syx_ws) {
		    //white space
            asignment_wrap();
		} else {
			error_stream();
		}
	}
}
//commands:
void var_store() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_int") {
			var_store_int();
		} else if (active_script[line-1]=="_double") {
			var_store_double();
		} else if (active_script[line-1]=="_float") {
			var_store_float();
		} else if (active_script[line-1]=="_int64") {
			var_store_int64();
		} else if (active_script[line-1]=="_bool") {
			var_store_bool();
		} else if (active_script[line-1]=="_string") {
			var_store_string();
		} else if (active_script[line-1]=="_kata") {
			var_store_kata();
		} else if (active_script[line - 1] == "_complex") {
			var_store_complex();
		} else if (active_script[line-1]=="_action") {
			var_store_action();
		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
			error_stream();
		}
	}
}
	//var_store commands:
	void var_store_int() {
		unsigned long long int int_control_pointer;

				int_control_pointer = external_using_allints();

			fc_getline();
			if (active_script[line-1]=="_alnum") {
				int_var [int_control_pointer] = external_using_alnum();
			} else {
				int_var [int_control_pointer] = atof(active_script[line-1].c_str());
			}
	}

	void var_store_double() {
		unsigned long long int double_control_pointer;

				double_control_pointer = external_using_allints();
				fc_getline();
					double_var [double_control_pointer] = atof(active_script[line-1].c_str());
	}

	void var_store_float() {
		unsigned long long int float_control_pointer;

				float_control_pointer = external_using_allints();

				fc_getline();
					float_var [float_control_pointer] = atof(active_script[line-1].c_str());
	}

	void var_store_int64() {
		unsigned long long int int64_control_pointer;

				int64_control_pointer =  external_using_allints();

				fc_getline();
				if (active_script[line-1]=="_alnum") {
					int64_var [int64_control_pointer] = external_using_alnum();
				} else {
					int64_var [int64_control_pointer] = atof(active_script[line-1].c_str());
				}
	}

	void var_store_bool() {
		unsigned long long int bool_control_pointer;

				bool_control_pointer = external_using_allints();

				fc_getline();
					if ((active_script[line-1]=="true") or (active_script[line-1]=="_true") or (active_script[line-1]=="1") or (active_script[line-1]=="+") or (active_script[line-1]=="yes")) {
						bool_var [bool_control_pointer] = true;
					} else {
						bool_var [bool_control_pointer] = false;
					}
	}

	void var_store_string() {
		unsigned long long int string_control_pointer;

				string_control_pointer = external_using_allints();

				fc_getline();
					string_var [string_control_pointer] = active_script[line-1];
	}

	void var_store_complex() {
        unsigned long long int complex_control_pointer;

				complex_control_pointer = external_using_allints();

				fc_getline();
                    if (active_script[line-1]=="_r") {
                        fc_getline();
                        complex_var [complex_control_pointer].real(atof(active_script[line-1].c_str()));
                    } else if (active_script[line-1]=="_i") {
                        fc_getline();
                        complex_var [complex_control_pointer].imag(atof(active_script[line-1].c_str()));
                    } else {
                        error_stream();
                    }
	}
	void var_store_kata() {
		unsigned long long int kata_control_pointer;
		kata_control_pointer = external_using_allints();
		fc_getline();
		if (active_script[line-1]=="_name") {
			fc_getline();
			kata_var [kata_control_pointer].name = active_script[line-1];
			return;
		} else if (active_script[line-1]=="_type") {
			fc_getline();
			kata_var [kata_control_pointer].idtype = abs(atof(active_script[line-1].c_str()));
			return;
		} else if (active_script[line-1]=="_stack") {
			fc_getline();
			kata_var [kata_control_pointer].idstack = abs(atof(active_script[line-1].c_str()));
			return;
		}
		kata_var [kata_control_pointer].name = active_script[line-1];
		fc_getline();
		kata_var [kata_control_pointer].idtype = abs(atof(active_script[line-1].c_str()));
		fc_getline();
		kata_var [kata_control_pointer].idstack = abs(atof(active_script[line-1].c_str()));
	}
	void var_store_action() {
		fc_getline();
		string action_control_pointer = active_script[line - 1];
		fc_getline();
		for (int i = 0; i < action_var.size(); i++) {
			if (action_var[i].name == action_control_pointer) {
				action_var[i].value = active_script[line - 1];
				return;
			}
		}
		fc2_action local_actor_maker;
		local_actor_maker.name = action_control_pointer;
		local_actor_maker.value = active_script[line - 1];
		action_var.push_back(local_actor_maker);
	}

void var_locate() {
	unsigned long long int any_control_pointer;
	unsigned long long int anyint_control_pointer;
	long long int address_control_pointer;
		any_control_pointer = external_using_allints();
		fc_getline();
		if (active_script[line-1]=="_int") {
			address_control_pointer = reinterpret_cast<long long int>(&int_var[any_control_pointer]);
		} else if (active_script[line-1]=="_double") {
			address_control_pointer = reinterpret_cast<long long int>(&double_var[any_control_pointer]);
		} else if (active_script[line-1]=="_float") {
			address_control_pointer = reinterpret_cast<long long int>(&float_var[any_control_pointer]);
		} else if (active_script[line-1]=="_int64") {
			address_control_pointer = reinterpret_cast<long long int>(&int64_var[any_control_pointer]);
		} else if (active_script[line-1]=="_bool") {
			address_control_pointer = reinterpret_cast<long long int>(&bool_var[any_control_pointer]);
		} else if (active_script[line-1]=="_string") {
			address_control_pointer = reinterpret_cast<long long int>(&string_var[any_control_pointer]);
		} else if (active_script[line-1]=="_chart") {
			address_control_pointer = reinterpret_cast<long long int>(&chart_var[any_control_pointer]);
		} else if (active_script[line-1]=="_quantum") {
			address_control_pointer = reinterpret_cast<long long int>(&quantum_var[any_control_pointer]);
		} else if (active_script[line-1]=="_kata") {
			address_control_pointer = reinterpret_cast<long long int>(&kata_var[any_control_pointer]);
		} else if (active_script[line-1]=="_complex") {
			address_control_pointer = reinterpret_cast<long long int>(&complex_var[any_control_pointer]);
		} else if (active_script[line-1]=="_access") {
			address_control_pointer = reinterpret_cast<long long int>(&access_var[any_control_pointer]);
		} else {
			error_stream();
		}
		fc_getline();
		if (active_script[line-1]=="_int") {
			anyint_control_pointer = external_using_allints();
			int_var [anyint_control_pointer] = address_control_pointer;
		} else if (active_script[line-1]=="_int64") {
			anyint_control_pointer = external_using_allints();
			int64_var [anyint_control_pointer] = address_control_pointer;
		} else {
			error_stream();
		}
}

void var_swap() {
	while (true) {
			fc_getline();
		if (active_script[line-1]=="_int") {
			var_swap_int();
		} else if (active_script[line-1]=="_double") {
			var_swap_double();
		} else if (active_script[line-1]=="_float") {
			var_swap_float();
		} else if (active_script[line-1]=="_int64") {
			var_swap_int64();
		} else if (active_script[line-1]=="_bool") {
			var_swap_bool();
		} else if (active_script[line-1]=="_string") {
			var_swap_string();
		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
			error_stream();
		}
	}
}
	//var_swap commands:
	void var_swap_int() {
		unsigned long long int int_control_pointer;
		unsigned long long int int_control_pointer_dule;

				int_control_pointer = external_using_allints();

				int_control_pointer_dule = external_using_allints();
				int_var [int_control_pointer] = int_var [int_control_pointer_dule];
	}

	void var_swap_double() {
		unsigned long long int double_control_pointer;
		unsigned long long int double_control_pointer_dule;

				double_control_pointer = external_using_allints();

				double_control_pointer_dule = external_using_allints();

				double_var [double_control_pointer] = double_var [double_control_pointer_dule];
	}

	void var_swap_float() {
		unsigned long long int float_control_pointer;
		unsigned long long int float_control_pointer_dule;

				float_control_pointer = external_using_allints();

				float_control_pointer_dule = external_using_allints();

				float_var [float_control_pointer] = float_var [float_control_pointer_dule];
	}

	void var_swap_int64() {
		unsigned long long int int64_control_pointer;
		unsigned long long int int64_control_pointer_dule;

				int64_control_pointer = external_using_allints();

				int64_control_pointer_dule = external_using_allints();

				int64_var [int64_control_pointer] = int64_var [int64_control_pointer_dule];
	}

	void var_swap_bool() {
		unsigned long long int bool_control_pointer;
		unsigned long long int bool_control_pointer_dule;

				bool_control_pointer = external_using_allints();

				bool_control_pointer_dule = external_using_allints();

				bool_var [bool_control_pointer] = bool_var [bool_control_pointer_dule];
	}

	void var_swap_string() {
		unsigned long long int string_control_pointer;
		unsigned long long int string_control_pointer_dule;

				string_control_pointer = external_using_allints();

					string_control_pointer_dule = external_using_allints();

				string_var [string_control_pointer] = string_var [string_control_pointer_dule];
	}

void var_clear() {
    while (true) {
		fc_getline();
        if (active_script[line-1]=="_int") {
            var_clear_int();
        } else if (active_script[line-1]=="_double") {
            var_clear_double();
        } else if (active_script[line-1]=="_float") {
            var_clear_float();
        } else if (active_script[line-1]=="_int64") {
            var_clear_int64();
        } else if (active_script[line-1]=="_bool") {
            var_clear_bool();
        } else if (active_script[line-1]=="_string") {
            var_clear_string();
        } else if (active_script[line-1]=="_chart") {
            var_clear_chart();
        } else if (active_script[line-1]=="_quantum") {
            var_clear_quantum();
				} else if (active_script[line-1]=="_kata") {
						var_clear_kata();
        } else if (active_script[line-1]=="_complex") {

        } else if (active_script[line-1]=="_ret") {
            break;
        } else {
            error_stream();

        }
    }
}
    //var_clear commands:
    void var_clear_int() {
        unsigned long long int int_control_pointer;
							int_control_pointer = external_using_allints();
            int_var [int_control_pointer] = 0;
    }
    void var_clear_double() {
        unsigned long long int double_control_pointer;

							double_control_pointer = external_using_allints();

            double_var [double_control_pointer] = 0;
    }
    void var_clear_float() {
        unsigned long long int float_control_pointer;

							float_control_pointer = external_using_allints();

            float_var [float_control_pointer] = 0;
    }
    void var_clear_int64() {
        unsigned long long int int64_control_pointer;

							int64_control_pointer = external_using_allints();

            int64_var [int64_control_pointer] = 0;
    }
    void var_clear_bool() {
        unsigned long long int bool_control_pointer;

							bool_control_pointer = external_using_allints();

            bool_var [bool_control_pointer] = false;
    }
    void var_clear_string() {
        unsigned long long int string_control_pointer;

							string_control_pointer = external_using_allints();

            string_var [string_control_pointer] = nullptr;
    }
    void var_clear_chart() {
        unsigned long long int chart_control_pointer;

							chart_control_pointer = external_using_allints();

            chart_var [chart_control_pointer].close();
    }
    void var_clear_quantum() {
        unsigned long long int quantum_control_pointer;

							quantum_control_pointer = external_using_allints();

            quantum_var [quantum_control_pointer].close();
    }
		void var_clear_kata() {
			unsigned long long int kata_control_pointer;

					kata_control_pointer = external_using_allints();

					kata_var [kata_control_pointer].name = nullptr;
					kata_var [kata_control_pointer].idtype = 0;
		}

void var_delete() {
        fc_getline();
        if (active_script[line-1]=="_int") {
            delete[] int_var;
        } else if (active_script[line-1]=="_double") {
            delete[] double_var;
        } else if (active_script[line-1]=="_float") {
            delete[] float_var;
        } else if (active_script[line-1]=="_int64") {
            delete[] int64_var;
        } else if (active_script[line-1]=="_bool") {
            delete[] bool_var;
        } else if (active_script[line-1]=="_string") {
            delete[] string_var;
        } else if (active_script[line-1]=="_chart") {
            delete[] chart_var;
        } else if (active_script[line-1]=="_quantum") {
            delete[] quantum_var;
        } else if (active_script[line-1]=="_complex") {
            delete[] complex_var;
				} else if (active_script[line-1]=="_access") {
						delete[] access_var;
				} else if (active_script[line-1]=="_kata") {
						delete[] kata_var;
        } else {
            error_stream();
        }
}


void var_copy() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_int") {
			var_copy_int();
		} else if (active_script[line-1]=="_double") {
			var_copy_double();
		} else if (active_script[line-1]=="_float") {
			var_copy_float();
		} else if (active_script[line-1]=="_int64") {
			var_copy_int64();
		} else if (active_script[line-1]=="_bool") {
			var_copy_bool();
		} else if (active_script[line-1]=="_string") {
			var_copy_string();
		} else if (active_script[line-1]=="_kata") {
			var_copy_kata();
		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
			error_stream();
		}
	}
}
	//var_copy commands:
	void var_copy_int() {
		unsigned long long int int_control_pointer;
		unsigned long long int int_control_pointer_dule;

				int_control_pointer = external_using_allints();

					int_control_pointer_dule = external_using_allints();

				int_var [int_control_pointer_dule] = int_var [int_control_pointer];
	}
	void var_copy_int64() {
		unsigned long long int int64_control_pointer;
		unsigned long long int int64_control_pointer_dule;

				int64_control_pointer = external_using_allints();

					int64_control_pointer_dule = external_using_allints();

				int64_var [int64_control_pointer_dule] = int64_var [int64_control_pointer];
	}
	void var_copy_double() {
		unsigned long long int double_control_pointer;
		unsigned long long int double_control_pointer_dule;

				double_control_pointer = external_using_allints();

					double_control_pointer_dule = external_using_allints();

				double_var [double_control_pointer_dule] = double_var [double_control_pointer];
	}
	void var_copy_float() {
		unsigned long long int float_control_pointer;
		unsigned long long int float_control_pointer_dule;

				float_control_pointer = external_using_allints();

					float_control_pointer_dule = external_using_allints();

				float_var [float_control_pointer_dule] = float_var [float_control_pointer];
	}
	void var_copy_bool() {
		unsigned long long int bool_control_pointer;
		unsigned long long int bool_control_pointer_dule;

				bool_control_pointer = external_using_allints();

					bool_control_pointer_dule = external_using_allints();

				bool_var [bool_control_pointer_dule] = bool_var [bool_control_pointer];
	}
	void var_copy_string() {
		unsigned long long int string_control_pointer;
		unsigned long long int string_control_pointer_dule;

				string_control_pointer = external_using_allints();

					string_control_pointer_dule = external_using_allints();

				string_var [string_control_pointer_dule] = string_var [string_control_pointer];
	}
	void var_copy_kata() {
		unsigned long long int kata_control_pointer;
		unsigned long long int kata_control_pointer_dule;

				kata_control_pointer = external_using_allints();

					kata_control_pointer_dule = external_using_allints();

				kata_var [kata_control_pointer_dule] = kata_var [kata_control_pointer];
	}


void var_convert() {
	unsigned long long int int_control_pointer;
	unsigned long long int double_control_pointer;
	unsigned long long int float_control_pointer;
	unsigned long long int int64_control_pointer;
	unsigned long long int bool_control_pointer;
	unsigned long long int string_control_pointer;
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_int") {

				int_control_pointer = external_using_allints();

			var_convert_select(0, int_control_pointer, 0, 0, 0, 0, 0);
		} else if (active_script[line-1]=="_double") {

				double_control_pointer = external_using_allints();

			var_convert_select(2, 0, double_control_pointer, 0, 0, 0, 0);
		} else if (active_script[line-1]=="_float") {

				float_control_pointer = external_using_allints();

			var_convert_select(3, 0, 0, float_control_pointer, 0, 0, 0);
		} else if (active_script[line-1]=="_int64") {

				int64_control_pointer = external_using_allints();

			var_convert_select(1, 0, 0, 0, int64_control_pointer, 0, 0);
		} else if (active_script[line-1]=="_bool") {

				bool_control_pointer = external_using_allints();

			var_convert_select(4, 0, 0, 0, 0, bool_control_pointer, 0);
		} else if (active_script[line - 1] == "_string") {

			string_control_pointer = external_using_allints();

			var_convert_select(5, 0, 0.0, 0.0, 0, 0, string_control_pointer);
			//	var_convert_select();
		} else if (active_script[line-1]=="_action") {
			var_convert_action();
			continue;
		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
			error_stream();
		}
	}
}
	//var_convert commands:
	void var_convert_select(int convert_c_data,unsigned long long int int_control_pointer, unsigned long long int double_control_pointer, unsigned long long int float_control_pointer, unsigned long long int int64_control_pointer, unsigned long long int bool_control_pointer, unsigned long long int string_control_pointer) {
		fc_getline();
			//convert to one of these:
			if (active_script[line-1]=="_int") {
				if (convert_c_data==0) {
					//int
					var_convert_int(convert_c_data, int_var[int_control_pointer], 0, 0.0, 0.0, false, "NUL");
				} else if (convert_c_data==1) {
					//int64
					var_convert_int(convert_c_data, 0, int64_var[int64_control_pointer], 0.0, 0.0, false, "NUL");
				} else if (convert_c_data==2) {
					//double
					var_convert_int(convert_c_data, 0, 0, double_var[double_control_pointer], 0.0, false, "NUL");
				} else if (convert_c_data==3) {
					//float
					var_convert_int(convert_c_data, 0, 0, 0.0, float_var[float_control_pointer], false, "NUL");
				} else if (convert_c_data==4) {
					//bool
					var_convert_int(convert_c_data, 0, 0, 0.0, 0.0, bool_var[bool_control_pointer], "NUL");
				} else if (convert_c_data==5) {
					//string
					var_convert_int(convert_c_data, 0, 0, 0.0, 0.0, false, string_var[string_control_pointer]);
				} else {
					error_stream();
				}
			} else if (active_script[line-1]=="_int64") {
				if (convert_c_data==0) {
					//int
					var_convert_int64(convert_c_data, int_var[int_control_pointer], 0, 0.0, 0.0, false, "NUL");
				} else if (convert_c_data==1) {
					//int64
					var_convert_int64(convert_c_data, 0, int64_var[int64_control_pointer], 0.0, 0.0, false, "NUL");
				} else if (convert_c_data==2) {
					//double
					var_convert_int64(convert_c_data, 0, 0, double_var[double_control_pointer], 0.0, false, "NUL");
				} else if (convert_c_data==3) {
					//float
					var_convert_int64(convert_c_data, 0, 0, 0.0, float_var[float_control_pointer], false, "NUL");
				} else if (convert_c_data==4) {
					//bool
					var_convert_int64(convert_c_data, 0, 0, 0.0, 0.0, bool_var[bool_control_pointer], "NUL");
				} else if (convert_c_data==5) {
					//string
					var_convert_int64(convert_c_data, 0, 0, 0.0, 0.0, false, string_var[string_control_pointer]);
				} else {
					error_stream();
				}
			} else if (active_script[line-1]=="_double") {
				if (convert_c_data==0) {
					//int
					var_convert_double(convert_c_data, int_var[int_control_pointer], 0, 0.0, 0.0, false, "NUL");
				} else if (convert_c_data==1) {
					//int64
					var_convert_double(convert_c_data, 0, int64_var[int64_control_pointer], 0.0, 0.0, false, "NUL");
				} else if (convert_c_data==2) {
					//double
					var_convert_double(convert_c_data, 0, 0, double_var[double_control_pointer], 0.0, false, "NUL");
				} else if (convert_c_data==3) {
					//float
					var_convert_double(convert_c_data, 0, 0, 0.0, float_var[float_control_pointer], false, "NUL");
				} else if (convert_c_data==4) {
					//bool
					var_convert_double(convert_c_data, 0, 0, 0.0, 0.0, bool_var[bool_control_pointer], "NUL");
				} else if (convert_c_data==5) {
					//string
					var_convert_double(convert_c_data, 0, 0, 0.0, 0.0, false, string_var[string_control_pointer]);
				} else {
					error_stream();
				}
			} else if (active_script[line-1]=="_float") {
				if (convert_c_data==0) {
					//int
					var_convert_float(convert_c_data, int_var[int_control_pointer], 0, 0.0, 0.0, false, "NUL");
				} else if (convert_c_data==1) {
					//int64
					var_convert_float(convert_c_data, 0, int64_var[int64_control_pointer], 0.0, 0.0, false, "NUL");
				} else if (convert_c_data==2) {
					//double
					var_convert_float(convert_c_data, 0, 0, double_var[double_control_pointer], 0.0, false, "NUL");
				} else if (convert_c_data==3) {
					//float
					var_convert_float(convert_c_data, 0, 0, 0.0, float_var[float_control_pointer], false, "NUL");
				} else if (convert_c_data==4) {
					//bool
					var_convert_float(convert_c_data, 0, 0, 0.0, 0.0, bool_var[bool_control_pointer], "NUL");
				} else if (convert_c_data==5) {
					//string
					var_convert_float(convert_c_data, 0, 0, 0.0, 0.0, false, string_var[string_control_pointer]);
				} else {
					error_stream();
				}
			} else if (active_script[line-1]=="_bool") {
				if (convert_c_data==0) {
					//int
					var_convert_bool(convert_c_data, int_var[int_control_pointer], 0, 0.0, 0.0, false, "NUL");
				} else if (convert_c_data==1) {
					//int64
					var_convert_bool(convert_c_data, 0, int64_var[int64_control_pointer], 0.0, 0.0, false, "NUL");
				} else if (convert_c_data==2) {
					//double
					var_convert_bool(convert_c_data, 0, 0, double_var[double_control_pointer], 0.0, false, "NUL");
				} else if (convert_c_data==3) {
					//float
					var_convert_bool(convert_c_data, 0, 0, 0.0, float_var[float_control_pointer], false, "NUL");
				} else if (convert_c_data==4) {
					//bool
					var_convert_bool(convert_c_data, 0, 0, 0.0, 0.0, bool_var[bool_control_pointer], "NUL");
				} else if (convert_c_data==5) {
					//string
					var_convert_bool(convert_c_data, 0, 0, 0.0, 0.0, false, string_var[string_control_pointer]);
				} else {
					error_stream();
				}
			} else if (active_script[line-1]=="_string") {
				if (convert_c_data==0) {
					//int
					var_convert_string(convert_c_data, int_var[int_control_pointer], 0, 0.0, 0.0, false, "NUL");
				} else if (convert_c_data==1) {
					//int64
					var_convert_string(convert_c_data, 0, int64_var[int64_control_pointer], 0.0, 0.0, false, "NUL");
				} else if (convert_c_data==2) {
					//double
					var_convert_string(convert_c_data, 0, 0, double_var[double_control_pointer], 0.0, false, "NUL");
				} else if (convert_c_data==3) {
					//float
					var_convert_string(convert_c_data, 0, 0, 0.0, float_var[float_control_pointer], false, "NUL");
				} else if (convert_c_data==4) {
					//bool
					var_convert_string(convert_c_data, 0, 0, 0.0, 0.0, bool_var[bool_control_pointer], "NUL");
				} else if (convert_c_data==5) {
					//string
					var_convert_string(convert_c_data, 0, 0, 0.0, 0.0, false, string_var[string_control_pointer]);
				} else {
					error_stream();
				}
			} else {
				error_stream();
			}
	}
	void var_convert_action() {
		fc_getline();
		string local_recive_action_value = fc2_action_value(active_script[line - 1]);
		fc_getline();
		short int local_selected_type;
		if (active_script[line - 1] == "_int") {
			local_selected_type = 1;
		} else if (active_script[line - 1] == "_double") {
			local_selected_type = 2;
		} else if (active_script[line - 1] == "_float") {
			local_selected_type = 3;
		} else if (active_script[line - 1] == "_int64") {
			local_selected_type = 4;
		} else if (active_script[line - 1] == "_bool") {
			local_selected_type = 5;
		} else if (active_script[line - 1] == "_string") {
			local_selected_type = 6;
		} else if (active_script[line-1]=="_access") {
			local_selected_type = 7;
		} else {
			local_selected_type = 0;
		}
		fc_getline();
		unsigned int any_control_pointer = external_using_allints();
		switch (local_selected_type) {
			case 1:
				int_var[any_control_pointer] = atoi(local_recive_action_value.c_str());
				break;
			case 2:
				double_var[any_control_pointer] = atof(local_recive_action_value.c_str());
				break;
			case 3:
				float_var[any_control_pointer] = atof(local_recive_action_value.c_str());
				break;
			case 4:
				int64_var[any_control_pointer] = atoi(local_recive_action_value.c_str());
				break;
			case 5:
				if (local_recive_action_value == "true"
					&& local_recive_action_value == "_true"
					&& local_recive_action_value == "True") {
					bool_var[any_control_pointer] = true;
					break;
				} else if (local_recive_action_value == "false"
					&& local_recive_action_value == "_false"
					&& local_recive_action_value == "false") {
					bool_var[any_control_pointer] = false;
					break;
				}
				bool_var[any_control_pointer] = atoi(local_recive_action_value.c_str());
				break;
			case 6:
				string_var[any_control_pointer] = local_recive_action_value;
				break;
			case 7:
				access_var[any_control_pointer] = local_recive_action_value.front();
				break;
			case 0:
				error_stream();
				break;
			default:
				break;
		}
	}
	void var_convert_int(int convert_c, int accept_int, long long int accept_int64, double accept_double, float accept_float, bool accept_bool, string accept_string) {
		unsigned long long int int_control_pointer;
		if (convert_c==0) {
			//int

				int_control_pointer = external_using_allints();

			int_var [int_control_pointer] = accept_int;
		} else if (convert_c==1) {
			//int64

				int_control_pointer = external_using_allints();

			int_var [int_control_pointer] = accept_int64;
		} else if (convert_c==2) {
			//double

				int_control_pointer = external_using_allints();

			int_var [int_control_pointer] = accept_double;
		} else if (convert_c==3) {
			//float

				int_control_pointer = external_using_allints();
			int_var [int_control_pointer] = accept_float;
		} else if (convert_c==4) {
			//bool

				int_control_pointer = external_using_allints();

			int_var [int_control_pointer] = accept_bool;
		} else if (convert_c==5) {
			//string

				int_control_pointer = external_using_allints();
			int_var [int_control_pointer] = atof(accept_string.c_str());
		} else {
			error_stream();
		}
	}
	void var_convert_double(int convert_c, int accept_int, long long int accept_int64, double accept_double, float accept_float, bool accept_bool, string accept_string) {
		unsigned long long int double_control_pointer;
		if (convert_c==0) {
			//int

				double_control_pointer = external_using_allints();

			double_var [double_control_pointer ] = accept_int;
		} else if (convert_c==1) {
			//int64

				double_control_pointer = external_using_allints();

			double_var [double_control_pointer] = accept_int64;
		} else if (convert_c==2) {
			//double

				double_control_pointer = external_using_allints();

			double_var [double_control_pointer] = accept_double;
		} else if (convert_c==3) {
			//float

				double_control_pointer = external_using_allints();

			double_var [double_control_pointer] = accept_float;
		} else if (convert_c==4) {
			//bool

				double_control_pointer = external_using_allints();

			double_var [double_control_pointer] = accept_bool;
		} else if (convert_c==5) {
			//string

				double_control_pointer = external_using_allints();

			double_var [double_control_pointer] = atof(accept_string.c_str());
		} else {
			error_stream();
		}
	}
	void var_convert_float(int convert_c, int accept_int, long long int accept_int64, double accept_double, float accept_float, bool accept_bool, string accept_string) {
		unsigned long long int float_control_pointer;
		if (convert_c==0) {
			//int

				float_control_pointer = external_using_allints();

			float_var [float_control_pointer] = accept_int;
		} else if (convert_c==1) {
			//int64

				float_control_pointer = external_using_allints();

			float_var [float_control_pointer] = accept_int64;
		} else if (convert_c==2) {
			//double

				float_control_pointer = external_using_allints();

			float_var [float_control_pointer] = accept_double;
		} else if (convert_c==3) {
			//float

				float_control_pointer = external_using_allints();

			float_var [float_control_pointer] = accept_float;
		} else if (convert_c==4) {
			//bool

				float_control_pointer = external_using_allints();

			float_var [float_control_pointer] = accept_bool;
		} else if (convert_c==5) {
			//string

				float_control_pointer = external_using_allints();

			float_var [float_control_pointer] = atof(accept_string.c_str());
		} else {
			error_stream();
		}
	}
	void var_convert_int64(int convert_c, int accept_int, long long int accept_int64, double accept_double, float accept_float, bool accept_bool, string accept_string) {
		unsigned long long int int64_control_pointer;
		if (convert_c==0) {
			//int

				int64_control_pointer = external_using_allints();

			int64_var [int64_control_pointer] = accept_int;
		} else if (convert_c==1) {
			//int64

				int64_control_pointer = external_using_allints();

			int64_var [int64_control_pointer] = accept_int64;
		} else if (convert_c==2) {
			//double

				int64_control_pointer = external_using_allints();

			int64_var [int64_control_pointer] = accept_double;
		} else if (convert_c==3) {
			//float

				int64_control_pointer = external_using_allints();

			int64_var [int64_control_pointer] = accept_float;
		} else if (convert_c==4) {
			//bool

				int64_control_pointer = external_using_allints();

			int64_var [int64_control_pointer] = accept_bool;
		} else if (convert_c==5) {
			//string

				int64_control_pointer = external_using_allints();

			int64_var [int64_control_pointer] = atof(accept_string.c_str());
		} else {
			error_stream();
		}
	}
	void var_convert_bool(int convert_c, int accept_int, long long int accept_int64, double accept_double, float accept_float, bool accept_bool, string accept_string) {
		unsigned long long int bool_control_pointer;
		if (convert_c==0) {
			//int

				bool_control_pointer = external_using_allints();

				if (accept_int>0) {
					bool_var [bool_control_pointer] = true;
				} else if (accept_int<=0) {
					bool_var [bool_control_pointer] = false;
				}
		} else if (convert_c==1) {
			//int64

				bool_control_pointer = external_using_allints();

				if (accept_int64>0) {
					bool_var [bool_control_pointer] = true;
				} else if (accept_int64<=0) {
					bool_var [bool_control_pointer] = false;
				}
		} else if (convert_c==2) {
			//double

				bool_control_pointer = external_using_allints();

				if (accept_double>0) {
					bool_var [bool_control_pointer] = true;
				} else if (accept_double<=0) {
					bool_var [bool_control_pointer] = false;
				}
		} else if (convert_c==3) {
			//float

				bool_control_pointer = external_using_allints();

				if (accept_float>0) {
					bool_var [bool_control_pointer] = true;
				} else if (accept_float<=0) {
					bool_var [bool_control_pointer] = false;
				}
		} else if (convert_c==4) {
			//bool

				bool_control_pointer = external_using_allints();

				if (accept_bool==true) {
					bool_var [bool_control_pointer] = true;
				} else if (accept_bool==false) {
					bool_var [bool_control_pointer] = false;
				}
		} else if (convert_c==5) {
			//string

				bool_control_pointer = external_using_allints();

				if (accept_string=="true") {
					bool_var [bool_control_pointer] = true;
				} else if (accept_string=="True") {
					bool_var [bool_control_pointer] = true;
				} else if (accept_string=="1") {
					bool_var [bool_control_pointer] = true;
				} else if (accept_string=="+") {
					bool_var [bool_control_pointer] = true;
				} else if (accept_string=="_true") {
					bool_var [bool_control_pointer] = true;
				} else {
					bool_var [bool_control_pointer] = false;
				}
		} else {
			error_stream();
		}
	}
	void var_convert_string(int convert_c, int accept_int, long long int accept_int64, double accept_double, float accept_float, bool accept_bool, string accept_string) {
		unsigned long long int string_control_pointer;
		if (convert_c==0) {
			//int
			ostringstream convert_tostring;
			convert_tostring << accept_int;
				string_control_pointer = external_using_allints();

			string_var [string_control_pointer] = convert_tostring.str();
		} else if (convert_c==1) {
			//int64
			ostringstream convert_tostring;
			convert_tostring << accept_int64;

				string_control_pointer = external_using_allints();

			string_var [string_control_pointer] = convert_tostring.str();
		} else if (convert_c==2) {
			//double
			ostringstream convert_tostring;
			convert_tostring << accept_double;

				string_control_pointer = external_using_allints();

			string_var [string_control_pointer] = convert_tostring.str();
		} else if (convert_c==3) {
			//float
			ostringstream convert_tostring;
			convert_tostring << accept_float;

				string_control_pointer = external_using_allints();

			string_var [string_control_pointer] = convert_tostring.str();
		} else if (convert_c==4) {
			//bool
			ostringstream convert_tostring;
			convert_tostring << accept_bool;

				string_control_pointer = external_using_allints();

			string_var [string_control_pointer] = convert_tostring.str();
		} else if (convert_c==5) {
			//string

				string_control_pointer = external_using_allints();

			string_var [string_control_pointer] = accept_string;
		} else {
			error_stream();
		}
	}


void var_merge() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_int") {

		} else if (active_script[line-1]=="_double") {

		} else if (active_script[line-1]=="_float") {

		} else if (active_script[line-1]=="_int64") {

		} else if (active_script[line-1]=="_string") {

		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
			error_stream();
		}
	}
}
	//var_merge commands:
	void var_merge_int() {
	}
	void var_merge_double() {
	}
	void var_merge_float() {
	}
	void var_merge_int64() {
	}
	void var_merge_string() {
	}

void var_allocate() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_int") {
			var_allocate_int();
		} else if (active_script[line-1]=="_double") {
			var_allocate_double();
		} else if (active_script[line-1]=="_float") {
			var_allocate_float();
		} else if (active_script[line-1]=="_int64") {
			var_allocate_int64();
		} else if (active_script[line-1]=="_bool") {
			var_allocate_bool();
		} else if (active_script[line-1]=="_string") {
			var_allocate_string();
		} else if (active_script[line-1]=="_chart") {
			var_allocate_chart();
		} else if (active_script[line-1]=="_quantum") {
			var_allocate_quantum();
		} else if (active_script[line-1]=="_kata") {
			var_allocate_kata();
		} else if (active_script[line-1]=="_complex") {
		    var_allocate_complex();
		} else if (active_script[line-1]=="_access") {
		    var_allocate_access();
		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
			error_stream();
			terminate_all();
		}
	}
}
	//var_allocate commands:
	void var_allocate_int() {
		unsigned long long int int_control_pointer;
		fc_getline();
			if (active_script[line-1]=="_var") {
                int_control_pointer = external_using_allints();
			} else if (active_script[line-1]=="_expand") {
                var_allocate_int_expand();
                return;
			} else {
				int_control_pointer = atof(active_script[line-1].c_str());
			}
			delete[] int_var;
			int_var = new int [int_control_pointer];
			int_var_alnum = int_control_pointer;
	}
	void var_allocate_int_expand() {
			unsigned long long int int_control_pointer;
        int_control_pointer = external_using_allints();
			int_var = new int [int_var_alnum+int_control_pointer];
			int_var_alnum = int_var_alnum+int_control_pointer;
	}

	void var_allocate_double() {
		fc_getline();
			unsigned long long int double_control_pointer;
			if (active_script[line-1]=="_var") {
                double_control_pointer = external_using_allints();
			} else if (active_script[line-1]=="_expand") {
                var_allocate_double_expand();
                return;
			} else {
				double_control_pointer = atof(active_script[line-1].c_str());
			}
			delete[] double_var;
			double_var = new double [double_control_pointer];
			double_var_alnum = double_control_pointer;
	}
	void var_allocate_double_expand() {
			unsigned long long int double_control_pointer;
        double_control_pointer = external_using_allints();
			double_var = new double [double_var_alnum+double_control_pointer];
			double_var_alnum = double_var_alnum+double_control_pointer;
	}

	void var_allocate_float() {
		fc_getline();
			unsigned long long int float_control_pointer;
			if (active_script[line-1]=="_var") {
        float_control_pointer = external_using_allints();
			} else if (active_script[line-1]=="_expand") {
                var_allocate_float_expand();
                return;
			} else {
				float_control_pointer = atof(active_script[line-1].c_str());
			}
			delete[] float_var;
			float_var = new float [float_control_pointer];
			float_var_alnum = float_control_pointer;
	}
	void var_allocate_float_expand() {
			unsigned long long int float_control_pointer;
                float_control_pointer = external_using_allints();
			float_var = new float [float_var_alnum+float_control_pointer];
			float_var_alnum = float_var_alnum+float_control_pointer;
	}

	void var_allocate_int64() {
		fc_getline();
			unsigned long long int int64_control_pointer;
			if (active_script[line-1]=="_var") {
        int64_control_pointer = external_using_allints();
			} else if (active_script[line-1]=="_expand") {
                var_allocate_int64_expand();
                return;
			} else {
				int64_control_pointer = atof(active_script[line-1].c_str());
			}
			delete[] int64_var;
			int64_var = new long long int [int64_control_pointer];
			int64_var_alnum = int64_control_pointer;
	}
	void var_allocate_int64_expand() {
			unsigned long long int int64_control_pointer;
        int64_control_pointer = external_using_allints();
			int64_var = new long long int [int64_var_alnum+int64_control_pointer];
			int64_var_alnum = int64_var_alnum+int64_control_pointer;
	}

	void var_allocate_bool() {
		fc_getline();
			unsigned long long int bool_control_pointer;
			if (active_script[line-1]=="_var") {
        bool_control_pointer = external_using_allints();
			} else if (active_script[line-1]=="_expand") {
                var_allocate_bool_expand();
                return;
			} else {
				bool_control_pointer = atof(active_script[line-1].c_str());
			}
			delete[] bool_var;
			bool_var = new bool [bool_control_pointer];
			bool_var_alnum = bool_control_pointer;
	}
	void var_allocate_bool_expand() {
			unsigned long long int bool_control_pointer;
        bool_control_pointer = external_using_allints();
			bool_var = new bool [bool_var_alnum+bool_control_pointer];
			bool_var_alnum = bool_var_alnum+bool_control_pointer;
	}

	void var_allocate_string() {
		fc_getline();
			unsigned long long int string_control_pointer;
			if (active_script[line-1]=="_var") {
        string_control_pointer = external_using_allints();
			} else if (active_script[line-1]=="_expand") {
                var_allocate_string_expand();
                return;
			} else {
				string_control_pointer = atof(active_script[line-1].c_str());
			}
			delete[] string_var;
			string_var = new string [string_control_pointer];
			string_var_alnum = string_control_pointer;
	}
	void var_allocate_string_expand() {
			unsigned long long int string_control_pointer;
        string_control_pointer =  external_using_allints();
			string_var = new string [string_var_alnum+string_control_pointer];
			string_var_alnum = string_var_alnum+string_control_pointer;
	}

	void var_allocate_complex() {
	    fc_getline();
			unsigned long long int complex_control_pointer;
			if (active_script[line-1]=="_var") {
                complex_control_pointer = external_using_allints();
			} else if (active_script[line-1]=="_expand") {
                var_allocate_complex_expand();
                return;
			} else {
				complex_control_pointer = atof(active_script[line-1].c_str());
			}
			delete[] complex_var;
			complex_var = new complex<double> [complex_control_pointer];
			complex_var_alnum = complex_control_pointer;
	}
	void var_allocate_complex_expand() {
			unsigned long long int complex_control_pointer;
                complex_control_pointer = external_using_allints();
			complex_var = new complex<double> [complex_var_alnum+complex_control_pointer];
			complex_var_alnum = complex_var_alnum+complex_control_pointer;
	}

	void var_allocate_chart() {
		fc_getline();
			unsigned long long int chart_control_pointer;
			if (active_script[line-1]=="_var") {
                chart_control_pointer = external_using_allints();
			} else if (active_script[line-1]=="_expand") {
                var_allocate_chart_expand();
                return;
			} else {
				chart_control_pointer = atof(active_script[line-1].c_str());
			}
			delete[] chart_var;
			chart_var = new ifstream [chart_control_pointer];
			chart_var_alnum = chart_control_pointer;
	}
	void var_allocate_chart_expand() {
			unsigned long long int chart_control_pointer;
                chart_control_pointer = external_using_allints();
			chart_var = new ifstream [chart_var_alnum+chart_control_pointer];
			chart_var_alnum = chart_var_alnum+chart_control_pointer;
	}

	void var_allocate_quantum() {
		fc_getline();
			unsigned long long int quantum_control_pointer;
			if (active_script[line-1]=="_var") {
                quantum_control_pointer = external_using_allints();
			} else if (active_script[line-1]=="_expand") {
				var_allocate_quantum_expand();
				return;
			} else {
				quantum_control_pointer = atof(active_script[line-1].c_str());
			}
			delete[] quantum_var;
			quantum_var = new ofstream [quantum_control_pointer];
			quantum_var_alnum = quantum_control_pointer;
	}
	void var_allocate_quantum_expand() {
			unsigned long long int quantum_control_pointer;
        quantum_control_pointer = external_using_allints();
			quantum_var = new ofstream [quantum_var_alnum+quantum_control_pointer];
			quantum_var_alnum = quantum_var_alnum+quantum_control_pointer;
	}

	void var_allocate_access() {
	    fc_getline();
			unsigned long long int access_control_pointer;
			if (active_script[line-1]=="_var") {
                access_control_pointer = external_using_allints();
			} else if (active_script[line-1]=="_expand") {
				var_allocate_access_expand();
				return;
			} else {
				access_control_pointer = atof(active_script[line-1].c_str());
			}
			delete[] access_var;
			access_var = new char [access_control_pointer];
			access_var_alnum = access_control_pointer;
	}
	void var_allocate_access_expand() {
			unsigned long long int access_control_pointer;
        access_control_pointer = external_using_allints();
			access_var = new char [access_var_alnum+access_control_pointer];
			access_var_alnum = access_var_alnum+access_control_pointer;
	}
	void var_allocate_kata() {
		fc_getline();
			unsigned long long int kata_control_pointer;
			if (active_script[line-1]=="_var") {
        kata_control_pointer = external_using_allints();
			} else if (active_script[line-1]=="_expand") {
				var_allocate_kata_expand();
				return;
			} else {
				kata_control_pointer = atof(active_script[line-1].c_str());
			}
			delete[] kata_var;
			kata_var = new kata [kata_control_pointer];
			kata_var_alnum = kata_control_pointer;
	}
	void var_allocate_kata_expand() {
		unsigned long long int kata_control_pointer;
			kata_control_pointer = external_using_allints();
		kata_var = new kata [kata_var_alnum+kata_control_pointer];
		kata_var_alnum = kata_var_alnum+kata_control_pointer;
	}
