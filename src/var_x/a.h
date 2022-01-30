//aspectu stream register
    void aspectu_test();
    void aspectu_gl();
    void aspectu_audio();
    void aspectu_display_driver();
    void aspectu_display_mode();
    void aspectu_window_setup();
    void aspectu_window_destroy();
    void aspectu_option_enableord(bool settinged);
    void aspectu_display_driver_exitloop();
    void aspectu_display_ortho();
    void aspectu_display_perspective();
    void aspectu_display_viewport();
    //gl aspectu register
    void aspectu_display_driver_vertex_4d();
    void aspectu_display_driver_vertex_3d();
    void aspectu_display_driver_vertex_2d();
    void aspectu_display_driver_vertex();
    void aspectu_display_driver_colour3();
    void aspectu_display_driver_clear();
    void aspectu_display_driver_clearcolor();
    void aspectu_display_driver_redo();
    void aspectu_display_driver_draw();
    void aspectu_display_driver_scale();
    void aspectu_display_driver_translate();
    void aspectu_display_driver_rotate();
    void aspectu_display_driver_matrix();
    void aspectu_display_driver_pixels();
    void aspectu_display_driver_depth();
    void aspectu_display_driver_cleardepth();
    void aspectu_display_driver_depthfunc();
    void aspectu_display_driver_depthrange();
    void aspectu_display_driver_depthmask();
    void aspectu_display_driver_camera();
    void aspectu_display_driver_camera_lookat();
    void aspectu_display_driver_normal();
    void aspectu_display_driver_material();
    void aspectu_display_driver_material_ambient();
    void aspectu_display_driver_material_diffuse();
    void aspectu_display_driver_texcoord();
    void aspectu_display_driver_texcoord_2();
    void aspectu_display_driver_texcoord_3();
    void aspectu_display_driver_texcoord_4();
    void aspectu_display_driver_light();
    void aspectu_display_driver_light_position();
    void aspectu_display_driver_light_diffuse();
    //aspectu fx register
    void aspectu_fx();
    void aspectu_fx_xy();
    void aspectu_fx_xyz();
    void aspectu_fx_xy_redo();
    void aspectu_fx_define();
    void aspectu_fx_xy_redraw();
    void aspectu_fx_xy_key(unsigned char c, int x, int y);
    void aspectu_fx_xy_reshape(int w, int h);
    void aspectu_fx_xy_idle();
    void aspectu_fx_xy_draw(float (* func)(float x), float x1, float x2, float y1, float y2, int N);
    float aspectu_fx_xy_funcx(float x);

    void aspectu_fx_xy_prop();
    float fx_xy_colour_r = 0;
    float fx_xy_colour_g = 0;
    float fx_xy_colour_b = 0;

    int fx_win_x = 400;
    int fx_win_y = 400;
    //float in_val = 0;
    //float x1_var;
    //float x2_var;
    //float y1_var;
    //float y2_var;
    //int n_var;


    //aspectu stream
void aspectu_stream() {
	while (true) {
		fc_getline();
		if (active_script[line-1]=="+a:box") {

		} else if (active_script[line-1]=="a*") {
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