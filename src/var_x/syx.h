//syntax defaults:
string syx ("");
string syx_ap ("*@");
string syx_vx ("%");
string syx_aw ("@*");
string syx_cs ("*~~~");
string syx_ux ("~~~*");
string syx_ws ("");
string syx_nc ("<|");
string syx_cn ("|>");
string syx_dp ("**");
//sub commands:
string syx_su_ret ("_ret");
string syx_su_int ("_int");
string syx_su_int64 ("_int64");
string syx_su_float ("_float");
string syx_su_double ("_double");
string syx_su_bool ("_bool");
string syx_su_string ("_string");
string syx_su_chart ("_chart");
string syx_su_quantum ("_quantum");
string syx_su_errorlvl ("_errorlevel");
string syx_su_group ("_group");
    //index stream:
    //var stream:
    string syx_v ("*v");
        //store var:
        string syx_v_store ("+store");
        //clear var:
        string syx_v_swap ("+swap");
        //clear var:
        string syx_v_clear ("+clear");
        //delete var:
        string syx_v_delete ("+delete");
        //copy var:
        string syx_v_copy ("+copy");
        //convert var:
        string syx_v_convert ("+convert");
        //add var:
        string syx_v_add ("+add");
        //allocate var:
        string syx_v_allocate ("+allocate");
        //return var:
        string syx_v_return ("v*");
    //control stream:
    string syx_c ("*c");
        //if control:
        string syx_c_if ("+if");
        //for control:
        string syx_c_for ("+for");
        //while control:
        string syx_c_while ("+while");
        //goto control:
        string syx_c_goto ("+goto");
        //inspect control:
        string syx_c_inspect ("+inspect");
        //return control:
        string syx_c_return ("c*");
    //math stream:
    string syx_m ("*m");
        //handle math:
        string syx_m_handle ("+handle");
        //function math:
        string syx_m_function ("+function");
        //algorithm math:
        string syx_m_algorithm ("+algorithm");
        //gen math:
        string syx_m_gen ("+gen");
        //return math:
        string syx_m_return ("m*");
    //function stream:
    string syx_f ("*f");
        //time function:
        string syx_f_time ("+time");
        //tap function:
        string syx_f_tap ("+tap");
        //numbers function:
        string syx_f_numbers ("+numbers");
        //return function:
        string syx_f_return ("f*");
    //external stream:
    string syx_x ("*x");
        //file external:
        string syx_x_file ("+file");
        //filesystem external:
        string syx_x_filesystem ("+filesystem");
        //address external:
        string syx_x_address ("+address");
        //command external:
        string syx_x_command ("+command");
        //return external:
        string syx_x_return ("x*");
    //input stream:
    string syx_i ("*i");
        //output input:
        string syx_i_output ("+output");
        //keyinput input:
        string syx_i_keyinput ("+keyinput");
        //input input:
        string syx_i_input ("+input");
        //debug input:
        string syx_i_debug ("+debug");
        //write input:
        string syx_i_write ("+write");
        //return input:
        string syx_i_return ("i*");
    //threading stream:
    string syx_t("*t");
        //return threading:
        string syx_t_return ("t*");
    //aspectu stream:
    string syx_a ("*a");
        //graphics aspectu:
        string syx_a_graphics ("+a:graphics");
        //display aspectu:
        string syx_a_display ("+a:display");
        //audio aspectu:
        string syx_a_audio ("+a:audio");
        //box aspectu:
        string syx_a_box ("+a:box");
        //compute aspectu:
        string syx_a_compute ("+a:compute");
        //pass aspectu:
        string syx_a_pass ("+a:pass");
        //port aspectu:
        string syx_a_port ("+a:port");
        //web aspectu:
        string syx_a_web ("+a:web");
        //crypt aspectu:
        string syx_a_crypt ("+a:crypt");
        //check aspectu:
        string syx_a_check ("+a:check");
        //return aspectu:
        string syx_a_return ("a*");
    //reserve stream:
    string syx_r ("*r");
        //terminate reserve:
        string syx_r_terminate ("+terminate");
        //return reserve:
        string syx_r_return ("r*");
    //experimental stream:
    string syx_e ("*e");
        //config experiment:
        string syx_e_config ("+e:config");
        //return experiment:
        string syx_e_return ("e*");
    //index break:
    string syx_br ("?*");
