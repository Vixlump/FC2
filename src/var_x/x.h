    //file presets
	void external_file();
	void external_file_openfile();
	void external_file_closefile();
	void external_file_resetfile();
	void external_file_edit();
	void external_file_unedit();
    //address presets
	void external_address();
	void external_address_int8();
	void external_address_uint8();
	void external_address_int16();
	void external_address_uint16();
	void external_address_int32();
	void external_address_uint32();
	void external_address_int64();
	void external_address_uint64();
	void external_address_float();
	void external_address_double();
	void external_address_char();
		//cast memory into var
	void external_cast();
	void external_cast_int();
	void external_cast_string();
		//filesystem
	void external_filesystem();
	void external_filesystem_copydir();
	void external_filesystem_copyfile();
	void external_filesystem_cutfile();
	void external_filesystem_cutcir();
	void external_filesystem_makedir();
	void external_filesystem_makefile();
	void external_filesystem_renamefile();
	void external_filesystem_renamedir();
	void external_filesystem_deletefile();
	void external_filesystem_deletedir();

//external stream
void external_stream() {
	while (true) {
		fc_getline();
		if (active_script[line-1]==syx_x_file) {
				external_file();
    } else if (active_script[line-1]==syx_x_address) {
    		external_address();
		} else if (active_script[line-1]=="+cast") {
				external_cast();
		} else if (active_script[line-1]==syx_x_filesystem) {
				error_stream();
    } else if (active_script[line-1]==syx_x_command) {
    		error_stream();
		} else if (active_script[line-1]==syx_x_return) {
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

void external_cast() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_int") {
			external_cast_int();
		} else if (active_script[line-1]=="_int64") {
			error_stream();
		} else if (active_script[line-1]=="_string") {
			external_cast_string();
		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
				error_stream();
		}
	}
}

void external_cast_int() {
	unsigned long long int address_control_pointer;
	unsigned long long int int_control_pointer;
	address_control_pointer = external_using_allints();
	int_control_pointer = external_using_allints();
	int * getcast_pointer;
	getcast_pointer = reinterpret_cast<int*>(address_control_pointer);
	int_var [int_control_pointer] = *getcast_pointer;
}
void external_cast_string() {
	unsigned long long int address_control_pointer;
	unsigned long long int string_control_pointer;
	address_control_pointer = external_using_allints();
	string_control_pointer = external_using_allints();
	string * getcast_pointer;
	getcast_pointer = reinterpret_cast<string*>(address_control_pointer);
	string_var [string_control_pointer] = *getcast_pointer;
}

void external_address() {
    while (true) {
			fc_getline();
			if (active_script[line-1]=="_int8") {
				external_address_int8();
			} else if (active_script[line-1]=="_uint8") {
				external_address_uint8();
			} else if (active_script[line-1]=="_int16") {
				external_address_int16();
			} else if (active_script[line-1]=="_uint16") {
				external_address_uint16();
			} else if (active_script[line-1]=="_int32") {
				external_address_int32();
			} else if (active_script[line-1]=="_uint32") {
				external_address_uint32();
			} else if (active_script[line-1]=="_int64") {
				external_address_int64();
			} else if (active_script[line-1]=="_uint64") {
				external_address_uint64();
			} else if (active_script[line-1]=="_float") {
				external_address_float();
			} else if (active_script[line-1]=="_double") {
				external_address_double();
			} else if (active_script[line-1]=="_char") {
				external_address_char();
			} else if (active_script[line-1]=="_ret") {
				break;
			} else {
				error_stream();
			}
			//\/\/\/ not a command for this stream for two commands below \/\/\/
			//*(volatile uint8_t*)address_control_pointer = int_var [int_control_pointer];
			//int_var[int_control_pointer] = *(volatile uint8_t*)address_control_pointer;
    }
}
    //external address commands:
    void external_address_int8() {
        unsigned long long int int_control_pointer;
        unsigned long long int address_control_pointer;
            		int_control_pointer = external_using_allints();
							address_control_pointer = external_using_allints();
        //*reinterpret_cast<int*>(address_control_pointer) = int_var [int_control_pointer];
        //int_var [int_control_pointer] = (int*)address_control_pointer;
        *(volatile int8_t*)address_control_pointer = int_var [int_control_pointer];
    }
		void external_address_uint8() {
			unsigned long long int int_control_pointer;
			unsigned long long int address_control_pointer;
							int_control_pointer = external_using_allints();
						address_control_pointer = external_using_allints();
			*(volatile uint8_t*)address_control_pointer = int_var [int_control_pointer];
		}
		void external_address_int16() {
			unsigned long long int int_control_pointer;
			unsigned long long int address_control_pointer;
							int_control_pointer = external_using_allints();
						address_control_pointer = external_using_allints();
			*(volatile int16_t*)address_control_pointer = int_var [int_control_pointer];
		}
		void external_address_uint16() {
			unsigned long long int int_control_pointer;
			unsigned long long int address_control_pointer;
							int_control_pointer = external_using_allints();
						address_control_pointer = external_using_allints();
			*(volatile uint16_t*)address_control_pointer = int_var [int_control_pointer];
		}
		void external_address_int32() {
			unsigned long long int int_control_pointer;
			unsigned long long int address_control_pointer;
							int_control_pointer = external_using_allints();
						address_control_pointer = external_using_allints();
			*(volatile int32_t*)address_control_pointer = int_var [int_control_pointer];
		}
		void external_address_uint32() {
			unsigned long long int int_control_pointer;
			unsigned long long int address_control_pointer;
							int_control_pointer = external_using_allints();
						address_control_pointer = external_using_allints();
			*(volatile uint32_t*)address_control_pointer = int_var [int_control_pointer];
		}
		void external_address_int64() {
			unsigned long long int int64_control_pointer;
			unsigned long long int address_control_pointer;
							int64_control_pointer = external_using_allints();
						address_control_pointer = external_using_allints();
			*(volatile int64_t*)address_control_pointer = int64_var [int64_control_pointer];
		}
		void external_address_uint64() {
			unsigned long long int int64_control_pointer;
			unsigned long long int address_control_pointer;
							int64_control_pointer = external_using_allints();
						address_control_pointer = external_using_allints();
			*(volatile uint64_t*)address_control_pointer = int64_var [int64_control_pointer];
		}
		void external_address_float() {
			unsigned long long int float_control_pointer;
			unsigned long long int address_control_pointer;
							float_control_pointer = external_using_allints();
						address_control_pointer = external_using_allints();
			*(volatile float*)address_control_pointer = float_var [float_control_pointer];
		}
		void external_address_double() {
			unsigned long long int double_control_pointer;
			unsigned long long int address_control_pointer;
							double_control_pointer = external_using_allints();
						address_control_pointer = external_using_allints();
			*(volatile double*)address_control_pointer = double_var [double_control_pointer];
		}
		void external_address_char() {
			unsigned long long int char_control_pointer;
			unsigned long long int address_control_pointer;
							char_control_pointer = external_using_allints();
						address_control_pointer = external_using_allints();
			//*reinterpret_cast<int*>(address_control_pointer) = int_var [int_control_pointer];
			//int_var [int_control_pointer] = (int*)address_control_pointer;
			*(volatile char*)address_control_pointer = int_var [char_control_pointer];
		}


void external_file() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_open") {
			external_file_openfile();
		} else if (active_script[line-1]=="_close") {
			external_file_closefile();
		} else if (active_script[line-1]=="_reset") {
			external_file_resetfile();
		} else if (active_script[line-1]=="_edit") {
			external_file_edit();
		} else if (active_script[line-1]=="_unedit") {
			external_file_unedit();
		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
			error_stream();
		}
	}
}

void external_file_openfile() {
	unsigned long long int chart_control_pointer;
	string openfile_control_pointer;
	fc_getline();
		if (active_script[line-1]=="_string") {
			openfile_control_pointer = (external_using_string());
		} else {
			openfile_control_pointer = (active_script[line-1]);
		}
				chart_control_pointer = external_using_allints();
			chart_var [chart_control_pointer].open (openfile_control_pointer);
}

void external_file_closefile() {
	unsigned long long int chart_control_pointer;
			chart_control_pointer = external_using_allints();
		chart_var [chart_control_pointer].close();
}

void external_file_resetfile() {
	unsigned long long int chart_control_pointer;
			chart_control_pointer = external_using_allints();
		chart_var [chart_control_pointer].seekg(0, ios::beg);
}

void external_file_edit() {
	unsigned long long int quantum_control_pointer;
			quantum_control_pointer = external_using_allints();
		fc_getline();
			if (active_script[line-1]=="_string") {
				quantum_var [quantum_control_pointer].open(external_using_string());
			} else {
				quantum_var [quantum_control_pointer].open(active_script[line-1]);
			}
}

void external_file_unedit() {
	unsigned long long int quantum_control_pointer;
			quantum_control_pointer = external_using_allints();
		quantum_var [quantum_control_pointer].close();
}

void external_filesystem() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_copydir") {
			external_filesystem_copydir();
		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
			error_stream();
		}
	}
}

void external_filesystem_copydir() {
	string string_copy_dir_1;
	string string_copy_dir_2;
	fc_getline();
		if (active_script[line-1]=="_string") {
			external_using_string();
		} else {
			string_copy_dir_1 = active_script[line-1];
		}
	fc_getline();
		if (active_script[line-1]=="_string") {
			external_using_string();
		} else {
			string_copy_dir_2 = active_script[line-1];
		}
	//std::experimental::filesystem::copy(string_copy_dir_1, string_copy_dir_2/*, fs::copy_options::recursive*/);
}
void external_filesystem_copyfile() {

}
void external_filesystem_cutfile(){

}
void external_filesystem_cutcir(){

}
void external_filesystem_makedir(){

}
void external_filesystem_makefile(){

}
void external_filesystem_renamefile(){

}
void external_filesystem_renamedir(){

}
void external_filesystem_deletefile(){

}
void external_filesystem_deletedir(){

}
