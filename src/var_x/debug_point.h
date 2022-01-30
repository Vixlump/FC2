//debug stream
void debug_stream() {
    cout<<"Active Script: "<<active_file_backup<<endl;
    cout<<"Active Library: "<<active_file_controller<<endl;
    cout<<"Known Threads: "<<known_threads<<endl;
    cout<<"Adapted Threads: "<<adapted_threads<<endl;
    cout<<"Known Arguments: "<<argv_control_pointer<<endl;
	cout<<"Deprications: "<<deprications<<endl;
	cout<<"Errors: "<<error_level<<endl;
  cout<<"Error Cap:"<<error_cap<<endl;
	cout<<"Last Process: "<<active_script[line-1]<<endl;
	cout<<"Last Line: "<<line<<endl;
	cout<<"Error Locations: "<<error_trace<<endl;
}

void debug_point() {
	cout<<"Hit:{L"<<line<<"T"<<thread_label<<"}"<<endl;
}
