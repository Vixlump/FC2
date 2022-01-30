//threading stream register
void threading_stream();
	void threading_test();
	void threading_new();
    void threading_wait();
    void threading_end();
    void threading_adapt();
    void threading_command(string process_t_m);

//threading stream
void threading_stream() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="+new") {
            threading_new();
		} else if (active_script[line-1]=="+wait") {
            threading_wait();
		} else if (active_script[line-1]=="+end") {
            threading_end();
		} else if (active_script[line-1]=="+signal") {

		} else if (active_script[line-1]=="+adapt") {
            threading_adapt();
		} else if (active_script[line-1]=="+confirm") {

		} else if (active_script[line-1]=="+test") {
            threading_test();
		} else if (active_script[line-1]==syx_t_return) {
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

//threading stream
void threading_test() {
    void threading_test2();
		thread t1 (threading_test2);
        std::this_thread::sleep_for(std::chrono::seconds(10));
				fc_getline();
				cout<<"first thread: "<<active_script[line-1]<<endl;
		t1.join();
}
void threading_test2() {
	active_file.close();
	active_file.open("script2.fc2");
	load_new_script();
	fc_getline();
	cout<<"second thread: "<<active_script[line-1]<<endl;
}
void threading_new() {
    fc_getline();
		if (active_script[line-1]=="_string") {
            unsigned long long int string_control_pointer;
									string_control_pointer=external_using_allints();
                known_threads = known_threads+1;
                adapted_threads = adapted_threads+1;
                thread t1(threading_command,string_var[string_control_pointer]);
								t1.detach();
		} else {
            known_threads = known_threads+1;
            adapted_threads = adapted_threads+1;
            thread t1(threading_command,active_script[line-1]);
						t1.detach();
						return;
		}
}
void threading_command(string process_t_m) {
    active_file_backup = (process_t_m+".fc2");
    active_file_controller = (process_t_m+".fc2");
    line=0;
    active_file.close();
    active_file.open(process_t_m+".fc2");
	load_new_script();
    thread_label = adapted_threads;
    //std::this_thread::get_id();
    scan_stream();
    known_threads = known_threads-1;
    return;
}
void threading_wait() {
}
void threading_end() {
    known_threads = known_threads-1;
    //~thread();
}
void threading_adapt() {
    adapted_threads = adapted_threads+1;
}
