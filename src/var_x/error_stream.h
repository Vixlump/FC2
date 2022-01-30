void error_stream() {
    stringstream error_lineto_string;
    error_lineto_string << line;
    stringstream error_thread_labelto_string;
    error_thread_labelto_string << thread_label;
    error_level=error_level+1;
    error_trace=(error_trace+"|"+active_script[line-1]);
    error_trace=(error_trace+"[L"+error_lineto_string.str()+"]");
    error_trace=(error_trace+"[T"+error_thread_labelto_string.str()+"]");
    if (error_cap>0) {
      if (error_cap==error_level) {
        terminate_all();
      } else if (error_level>error_cap) {
        cout<<"Program is damaged contact Lumpology!"<<endl;
        terminate_all();
      }
    }
}
