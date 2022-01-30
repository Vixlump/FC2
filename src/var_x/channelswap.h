//changeswap script
void channelswap_script() {
    fc_getline();
		if (active_script[line - 1] =="_string") {
            unsigned long long int string_control_pointer;
							string_control_pointer = external_using_allints();
                //active_file_backup = (string_var[string_control_pointer]+".fc2");
                active_file_controller = (string_var[string_control_pointer]+".fc2");
                active_file.clear();
                active_file.seekg(0, std::ios::beg);
                line=0;
                active_file.close();
                active_file.open(string_var[string_control_pointer]+".fc2");
                load_new_script();
		} else if (active_script[line - 1] =="*<") {
		    fc_getline();
                active_file_backup = active_file_controller;
                active_file_controller = (active_script[line - 1] +".fc2");
                active_file.clear();
                active_file.seekg(0, std::ios::beg);
                line_bak=line;
                active_file.close();
                active_file.open(active_script[line - 1] +".fc2");
                line = 0;
                load_new_script();
		} else if (active_script[line - 1] ==">*") {
            line=0;
            active_file_controller = active_file_backup;
            active_file.clear();
            active_file.seekg(0, std::ios::beg);
            active_file.close();
            active_file.open(active_file_controller.c_str());
            load_new_script();
            while (true) {
                fc_getline();
                if (line==line_bak) {
                    break;
                } else if (line==0) {
                    cout<<"Warning!"<<endl<<"Program Is Damaged Please Report This Message To Lumpology Development Team"<<endl;
                    terminate_all();
                } else if (line>line_bak) {
                    terminate_all();
                }
            }
		} else if (active_script[line - 1] =="+scan") {
		    scan_inquire();
		} else {
		//active_file_backup = (active_script[line-1]+".fc2");
		active_file_controller = (active_script[line - 1] +".fc2");
		active_file.clear();
		active_file.seekg(0, std::ios::beg);
		line=0;
		active_file.close();
		active_file.open(active_script[line - 1] +".fc2");
        load_new_script();
        }
}