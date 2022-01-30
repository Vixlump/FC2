thread_local vector <string> abreg_tokens;
atomic <bool> abreg_synker;
//void abreg();

void abreg_mem() {
  unsigned long long int any_control_pointer;unsigned long long int any_control_pointer_dule;bool abreg_switch=false;
  any_control_pointer = atof(abreg_tokens[2].c_str());
  if (abreg_tokens[3]=="mem") {any_control_pointer_dule=abs(atof(abreg_tokens[4].c_str()));abreg_switch=true;}

  if (abreg_tokens[1]=="int") {
    if (any_control_pointer+1 > int_var_alnum) {int_var = new int [any_control_pointer+1]; int_var_alnum = any_control_pointer+1;}
    if (abreg_switch==true) {int_var[any_control_pointer]=int_var[any_control_pointer_dule];} else {int_var[any_control_pointer] = atof(abreg_tokens[3].c_str());}
  } else if (abreg_tokens[1]=="double") {
    if (any_control_pointer+1 > double_var_alnum) {double_var = new double [any_control_pointer+1]; double_var_alnum = any_control_pointer+1;}
    if (abreg_switch==true) {double_var[any_control_pointer]=double_var[any_control_pointer_dule];} else {double_var[any_control_pointer] = atof(abreg_tokens[3].c_str());}
  } else if (abreg_tokens[1]=="float") {
    if (any_control_pointer+1 > float_var_alnum) {float_var = new float [any_control_pointer+1]; float_var_alnum = any_control_pointer+1;}
    if (abreg_switch==true) {float_var[any_control_pointer]=float_var[any_control_pointer_dule];} else {float_var[any_control_pointer] = atof(abreg_tokens[3].c_str());}
  } else if (abreg_tokens[1]=="int64") {
    if (any_control_pointer+1 > int64_var_alnum) {int64_var = new long long int [any_control_pointer+1]; int64_var_alnum = any_control_pointer+1;}
    if (abreg_switch==true) {int64_var[any_control_pointer]=int64_var[any_control_pointer_dule];} else {int64_var[any_control_pointer] = atof(abreg_tokens[3].c_str());}
  } else if (abreg_tokens[1]=="bool") {
    if (any_control_pointer+1 > bool_var_alnum) {bool_var = new bool [any_control_pointer+1]; bool_var_alnum = any_control_pointer+1;}
    if (abreg_switch==true) {bool_var[any_control_pointer]=bool_var[any_control_pointer_dule];} else {bool_var[any_control_pointer] = atof(abreg_tokens[3].c_str());}
  } else if (abreg_tokens[1]=="string") {
    if (any_control_pointer+1 > string_var_alnum) {string_var = new string [any_control_pointer+1]; string_var_alnum = any_control_pointer+1;}
    if (abreg_switch==true) {string_var[any_control_pointer]=string_var[any_control_pointer_dule];} else {string_var[any_control_pointer] = abreg_tokens[3];}
  } else if (abreg_tokens[1]=="kata") {
    if (any_control_pointer+1 > kata_var_alnum) {kata_var = new kata [any_control_pointer+1]; kata_var_alnum = any_control_pointer+1;}
    if (abreg_switch==true) {kata_var[any_control_pointer]=kata_var[any_control_pointer_dule];} else {
      kata_var[any_control_pointer].name = abreg_tokens[3];
      kata_var[any_control_pointer].idtype = abs(atof(abreg_tokens[4].c_str()));
      kata_var[any_control_pointer].idstack = abs(atof(abreg_tokens[5].c_str()));}
  } else if (abreg_tokens[1]=="chart") {
    if (any_control_pointer+1 > chart_var_alnum) {chart_var = new ifstream [any_control_pointer+1]; chart_var_alnum = any_control_pointer+1;}
    if (abreg_switch==true) {error_stream();} else {chart_var [any_control_pointer].open(abreg_tokens[3]);}
  } else if (abreg_tokens[1]=="quantum") {
    if (any_control_pointer+1 > quantum_var_alnum) {quantum_var = new ofstream [any_control_pointer+1]; quantum_var_alnum = any_control_pointer+1;}
    if (abreg_switch==true) {error_stream();} else {quantum_var [any_control_pointer].open(abreg_tokens[3]);}
  } else {
    error_stream();
  }
}

void abreg_contex_errorlevel() {
  if (abreg_tokens[2]=="limit") {
    error_cap = abs(atof(abreg_tokens[3].c_str()));
  } else if (abreg_tokens[2]=="add") {
    error_level = error_level+atof(abreg_tokens[3].c_str());
  } else if (abreg_tokens[2]=="set") {
    error_level = abs(atof(abreg_tokens[3].c_str()));
  } else if (abreg_tokens[2]=="enforce") {
    error_stream();
  } else {

  }
}

void abreg_contex_thread() {
  if (abreg_tokens[2]=="synk") {
    abreg_synker = false;
    while(abreg_synker!=true);
  } else if (abreg_tokens[2]=="check") {
    abreg_synker = true;
  } else {
    error_stream();
  }
}
void abreg_contex_loop_jump() {
    if (abreg_tokens[2] == "up") {
        while (line <= active_script.size()&& line > 0) {
            line--;
            if (active_script[line - 1] == "*@") {
                line++;
                if (active_script[line - 1] == abreg_tokens[3]) {
                    return;
                } else {
                    line --;
                }
            }
        }
    } else if (abreg_tokens[2] == "down") {
        while (line <= active_script.size()) {
            line++;
            if (active_script[line - 1] == "*@") {
                line++;
                if (active_script[line - 1] == abreg_tokens[3]) {
                    return;
                }
            }
        }
    } else if (abreg_tokens[2] == "top") {
        line = 0;
        while (line <= active_script.size()) {
            line++;
            if (active_script[line - 1] == "*@") {
                line++;
                if (active_script[line - 1] == abreg_tokens[3]) {
                    return;
                }
            }
        }
    } else if (abreg_tokens[2] == "bottom") {
        line = active_script.size();
        while (line <= active_script.size() && line > 0) {
            line--;
            if (active_script[line - 1] == "*@") {
                line++;
                if (active_script[line - 1] == abreg_tokens[3]) {
                    return;
                } else {
                    line --;
                }
            }
        }
    } else if (abreg_tokens[2] == "dynamic") {
        unsigned int local_line_top = 0;
        unsigned int local_line_bottom = active_script.size();
        while (local_line_top <= active_script.size() && local_line_bottom > 0) {
            local_line_top++;
            local_line_bottom--;
            if (active_script[local_line_top - 1] == "*@" || active_script[local_line_bottom - 1] == "*@") {
                local_line_top++;
                local_line_bottom++;
                if (active_script[local_line_top - 1] == abreg_tokens[3] || active_script[local_line_bottom - 1] == abreg_tokens[3]) {
                    return;
                } else {
                    local_line_bottom --;
                }
            }
        }

    } else {
        error_stream();
    }
}
void control_goto_scan(string goto_control_pointer);
void abreg_contex_loop() {
  if (abreg_tokens[2]=="at") {
  	line=0;
  	control_goto_scan(abreg_tokens[3]);
  } else if (abreg_tokens[2]=="for") {

  } else if (abreg_tokens[2]=="set") {
    line = abs(atof(abreg_tokens[3].c_str()));
  } else {
    error_stream();
  }
}

void abreg_contex_case() {
  if (abreg_tokens[2]=="int") {

  } else if (abreg_tokens[2]=="double") {

  } else if (abreg_tokens[2]=="float") {

  } else if (abreg_tokens[2]=="int64") {

  } else if (abreg_tokens[2]=="bool") {

  } else if (abreg_tokens[2]=="string") {

  } else if (abreg_tokens[2]=="kata") {

  } else {
    error_stream();
  }
}

void abreg_contex() {
  if (abreg_tokens[1]=="thread") {
    abreg_contex_thread();
  } else if (abreg_tokens[1] == "jump") {
      abreg_contex_loop_jump();
  } else if (abreg_tokens[1]=="loop") {
    abreg_contex_loop();
  } else if (abreg_tokens[1]=="case") {
    abreg_contex_case();
  } else if (abreg_tokens[1]=="error") {
    abreg_contex_errorlevel();
  } else {
    error_stream();
  }
}

void abreg_patch_pragma() {
  bool is_pragma_true = false;
  if (abreg_tokens[2]=="main") {
    if (active_file_controller==original_active_file) {is_pragma_true = true;}
  } else if (abreg_tokens[2]=="lib") {
    if (active_file_controller!=active_file_backup) {is_pragma_true = true;}
  } else if (abreg_tokens[2]=="thread") {
    if (thread_label>1) {is_pragma_true = true;}
  } else if (abreg_tokens[2]=="script") {
    if (active_file_controller==active_file_backup) {is_pragma_true = true;}
  } else if (abreg_tokens[2]=="notmain") {
    if (active_file_controller!=original_active_file) {is_pragma_true = true;}
  } else if (abreg_tokens[2]=="notthread") {
    if (thread_label==1) {is_pragma_true = true;}
  } else {
    error_stream();
  }
  if ((is_pragma_true==false)and(abreg_tokens[abreg_tokens.size()-1]=="safe")) {
    error_stream();
  } else if ((is_pragma_true==false)and(abreg_tokens[abreg_tokens.size()-1]=="debug")) {
    error_stream();
    debug_stream();
    terminate_all();
  } else if (is_pragma_true==false) {
    error_stream();
    terminate_all();
  } else {
    return;
  }
}

void abreg_patch() {
  if (abreg_tokens[1]=="pragma") {
    abreg_patch_pragma();
  } else if (abreg_tokens[1]=="patchwork") {

  } else {
    error_stream();
  }
}

void abreg_finder() {
  if (abreg_tokens[0]=="adr") {//address

  } else if (abreg_tokens[0]=="mem") {
    if (abreg_tokens.size()>=4) {abreg_mem();}
  } else if (abreg_tokens[0]=="contex") {//context
    if (abreg_tokens.size()>=3) {abreg_contex();}
  } else if (abreg_tokens[0]=="reg") {//register

  } else if (abreg_tokens[0]=="exp") {//expression

  } else if (abreg_tokens[0]=="abstract") {//abstract staitment

  } else if (abreg_tokens[0]=="patch") {//program fix integrator
    if (abreg_tokens.size()>=3) {abreg_patch();}
  } else {
    error_stream();
  }
}

void abreg() {
  fc_getline();
  stringstream check_list(active_script[line-1]);
  string intermediate;
  abreg_tokens.clear();
  while (getline(check_list, intermediate, ';')) {
    abreg_tokens.push_back(intermediate);
  }
  //for (int i = 0; i < abreg_tokens.size(); i++)
    //cout<<"abreg:"<<i<<":"<<abreg_tokens[i]<<endl;
  if (abreg_tokens.size()>0) {
    abreg_finder();
  }
}
