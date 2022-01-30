void reserve_terminate();
	void reserve_tap();
	void reserve_tap_define();
	void reserve_tap_system();
	void reserve_tap_interupt();
	void reserve_tap_process();
	void reserve_tap_cycle();


//reserve stream
void reserve_stream() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="+terminate") {
			reserve_terminate();
		} else if (active_script[line-1]=="+unset") {
		    terminate_pointers();
		} else if (active_script[line-1]=="r*") {
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

//reserved stream

void reserve_terminate() {
	fc_getline();
		if (active_script[line-1]=="_clean") {
			terminate_all();
		} else if (active_script[line-1]=="_debug") {
			debug_stream();
			terminate_all();
		} else if (active_script[line-1]=="_crash") {
			exit(42);
		} else if (active_script[line-1]=="_keyout") {
		    deprications = deprications+1;
			system("pause");
			terminate_all();
		} else if (active_script[line-1]=="_keynul") {
		    deprications = deprications+1;
		    system("pause>nul");
		    terminate_all();
		} else {
			terminate_all();
		}
}

void reserve_tap() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="_define") {
			reserve_tap_define();
		} else if (active_script[line-1]=="_system") {
			reserve_tap_system();
		} else if (active_script[line-1]=="_process") {
			reserve_tap_process();
		} else if (active_script[line-1]=="_cycle") {
			reserve_tap_cycle();
		} else if (active_script[line-1]=="_interrupt") {
			reserve_tap_interupt();
		} else if (active_script[line-1]=="_ret") {
			break;
		} else {
			error_stream();
		}
	}
}
	//tap commands:
	void reserve_tap_define() {

	}
	void reserve_tap_system() {
		string systemcommand_controller;
		unsigned long long int string_control_pointer;
		while (true) {
			fc_getline();
			if (active_script[line-1]=="_string") {
						string_control_pointer = external_using_allints();
          systemcommand_controller = systemcommand_controller + string_var[string_control_pointer];
			} else if (active_script[line-1]=="_ret") {
				break;
			} else {
			systemcommand_controller = systemcommand_controller + active_script[line-1];
			}
		}
		system(systemcommand_controller.c_str());
	}
	void reserve_tap_interupt() {
	    fc_getline();
            if (active_script[line-1]=="_nano") {
										long long int sleepforinput;
											sleepforinput = external_using_allints();
                    sleep_for(nanoseconds(sleepforinput));
            } else if (active_script[line-1]=="_micro") {
                    long long int sleepforinput;
											sleepforinput = external_using_allints();
                    sleep_for(microseconds(sleepforinput));
            } else if (active_script[line-1]=="_milli") {
                    long long int sleepforinput;
											sleepforinput = external_using_allints();
                    sleep_for(milliseconds(sleepforinput));
            } else if (active_script[line-1]=="_sec") {
                    long long int sleepforinput;
											sleepforinput = external_using_allints();
                    sleep_for(seconds(sleepforinput));
            } else if (active_script[line-1]=="_min") {
                    long long int sleepforinput;
											sleepforinput = external_using_allints();
                    sleep_for(minutes(sleepforinput));
            } else if (active_script[line-1]=="_hour") {
                    long long int sleepforinput;
											sleepforinput = external_using_allints();
                    sleep_for(hours(sleepforinput));
            } else if (active_script[line-1]=="_day") {
                //not yet working! Update to full c++ 17 needed
                error_stream();
            } else {
                error_stream();
            }
	}
	void reserve_tap_process() {

	}
	void reserve_tap_cycle() {
		fc_getline();
			if (active_script[line-1]=="_loop") {
				kill_cycle = false;
				debug_kill_cycle = false;
			} else if (active_script[line-1]=="_kill") {
				kill_cycle = true;
				debug_kill_cycle = false;
			} else if (active_script[line-1]=="_debug") {
				kill_cycle = false;
				debug_kill_cycle = true;
			} else if (active_script[line-1]=="_hidecon") {
			    //ShowWindow(GetConsoleWindow(), SW_HIDE);
      } else if (active_script[line-1]=="_showcon") {
          //ShowWindow(GetConsoleWindow(), SW_RESTORE);
			} else if (active_script[line-1]=="_errorcap") {
						error_cap = external_using_allints();
			} else {
				error_stream();
			}
	}
