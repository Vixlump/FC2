double funcx_math(double x);
double funcx_math_x(double x);
double funcx_math_number(double x);
double funcx_math_func(double funcx_return_func, double x);
double funcx_math_trig(double funcx_return_trig, double x);
double funcx_math_values(double funcx_return_values, double x);

double funcx_math(double x) {
		double funcx_return = 0;
		while (true) {
			fc_getline();
				if (active_script[line-1]=="x") {
						if (isnan(funcx_return)==false) {
								funcx_return = x;
						} else {
								funcx_return = funcx_return*x;
						}
				} else if ((active_script[line-1]=="^")or (active_script[line-1]=="_power")) {
						funcx_return = pow(funcx_return, funcx_math_number(x));
				} else if (active_script[line-1]=="*") {
						funcx_return = funcx_return * funcx_math_number(x);
				} else if (active_script[line-1]=="+") {
						funcx_return = funcx_return + funcx_math_number(x);
				} else if (active_script[line-1]=="-") {
						funcx_return = funcx_return - funcx_math_number(x);
				} else if ((active_script[line-1]=="/")or(active_script[line-1]=="÷")) {
						funcx_return = funcx_return / funcx_math_number(x);
				} else if (active_script[line-1]=="(") {
						funcx_return = funcx_return * funcx_math(x);
				} else if (active_script[line-1]=="_var") {
						funcx_return = funcx_return * external_using_allnumbers();
				} else if (active_script[line-1]=="_index") {
						scan_stream();
				} else if (active_script[line-1]=="_values") {
						funcx_return = funcx_math_values(funcx_return, x);
				} else if (active_script[line-1]=="_func") {
						funcx_return = funcx_math_func(funcx_return, x);
				} else if (active_script[line-1]=="_trig") {
						funcx_return = funcx_math_trig(funcx_return, x);
				} else if ((active_script[line-1]=="]")or(active_script[line-1]==")")) {
						return funcx_return;
				} else if (active_script[line-1]=="_hyper") {

				} else if ((active_script[line-1]=="_exp")or(active_script[line-1]=="_log")) {

				} else {
						funcx_return = funcx_return + atof(active_script[line-1].c_str());
				}
		}
return funcx_return;
}
double funcx_math_number(double x) {
		fc_getline();
		if (active_script[line-1]=="x") {
				return x;
		} else if (active_script[line-1]=="(") {
				return funcx_math(x);
		} else if (active_script[line-1]=="_var") {
				return external_using_allnumbers();
		} else {
				return atof(active_script[line-1].c_str());
		}
}
double funcx_math_x(double x) {
		return x;
}
void funcx_math_add() {
}
void funcx_math_sub() {
}
void funcx_math_mult() {
}
void funcx_math_div() {
}
void funcx_math_power() {
}
void funcx_math_bracket() {
}
double funcx_math_values(double funcx_return_values, double x) {
		fc_getline();
		if ((active_script[line-1]=="_pi")or(active_script[line-1]=="π")) {
				funcx_return_values = 3.14159265359;
		} else if ((active_script[line-1]=="e")) {
				funcx_return_values = 2.71828182845;
		} else if (active_script[line-1]=="x") {
				funcx_return_values = x;
		} else if (active_script[line-1]=="y") {
				funcx_return_values = funcx_return_values;
		} else if ((active_script[line-1]=="_gr")or(active_script[line-1]=="φ")) {
				funcx_return_values = 1.61803398874;
		} else if ((active_script[line-1]=="_theta")or(active_script[line-1]=="θ")) {
				funcx_return_values = x;
		} else if ((active_script[line-1]=="Sn")or(active_script[line-1]=="_ratios")) {
				funcx_return_values = funcx_return_values;
		} else if (active_script[line-1]=="q") {
				funcx_return_values = 1.787231650;
		} else if (active_script[line-1]=="c") {
				funcx_return_values = 0.64341054629;
		} else if (active_script[line-1]=="G") {
				funcx_return_values = 0.8346268;
		} else if ((active_script[line-1]=="_omega")or(active_script[line-1]=="Ω")) {
				funcx_return_values = 0.56714329040;
		} else if ((active_script[line-1]=="_inf")or(active_script[line-1]=="∞")) {
				funcx_return_values = numeric_limits<double>::infinity();
		} else if (active_script[line-1]=="_nan") {
				funcx_return_values = NAN;
		} else {
				funcx_return_values = funcx_return_values * atof(active_script[line-1].c_str());
		}
		return funcx_return_values;
}
double funcx_math_func(double funcx_return_func, double x) {
		fc_getline();
		if ((active_script[line-1]=="_power")or(active_script[line-1]=="^")) {
				funcx_return_func = pow(funcx_math_number(x),funcx_math_number(x));
		} else if ((active_script[line-1]=="_sqrt")or(active_script[line-1]=="√")) {
				funcx_return_func = sqrt(funcx_math_number(x));
		} else if ((active_script[line-1]=="_cbrt")or(active_script[line-1]=="3√")) {
				funcx_return_func = cbrt(funcx_math_number(x));
		} else if (active_script[line-1]=="_hypot") {
				funcx_return_func = hypot(funcx_math_number(x),funcx_math_number(x));
		} else if ((active_script[line-1]=="_ln")or(active_script[line-1]=="_loge")) {
				funcx_return_func = log(funcx_math_number(x));
		} else if ((active_script[line-1]=="_log")or(active_script[line-1]=="_log10")) {
				funcx_return_func = log10(funcx_math_number(x));
		} else if ((active_script[line-1]=="_abs")or(active_script[line-1]=="|")) {
				funcx_return_func = abs(funcx_math_number(x));
		} else {
				funcx_return_func = funcx_return_func * atof(active_script[line-1].c_str());
		}
		return funcx_return_func;
}

double funcx_math_trig(double funcx_return_trig, double x) {
		fc_getline();
		if (active_script[line-1]=="_sin") {
				funcx_return_trig = sin(funcx_math_number(x));
		} else if (active_script[line-1]=="_cos") {
				funcx_return_trig = cos(funcx_math_number(x));
		} else if (active_script[line-1]=="_tan") {
				funcx_return_trig = tan(funcx_math_number(x));
		} else if (active_script[line-1]=="_arcsin") {
				funcx_return_trig = asin(funcx_math_number(x));
		} else if (active_script[line-1]=="_arccos") {
				funcx_return_trig = acos(funcx_math_number(x));
		} else if (active_script[line-1]=="_arctan") {
				funcx_return_trig = atan(funcx_math_number(x));
		} else {
				funcx_return_trig = funcx_return_trig * atof(active_script[line-1].c_str());
		}
		return funcx_return_trig;
}
		void funcx_math_trig_cos() {
		}
		void funcx_math_trig_arccos() {
		}
		void funcx_math_trig_sin() {
		}
		void funcx_math_trig_arcsin() {
		}
		void funcx_math_trig_tan() {
		}
		void funcx_math_trig_arctan() {
		}
		void funcx_math_trig_arctan2() {
		}
void funcx_math_hyper() {
}
		void funcx_math_hyper_cosh() {
		}
		void funcx_math_hyper_sinh() {
		}
		void funcx_math_hyper_tan() {
		}
		void funcx_math_hyper_acosh() {
		}
		void funcx_math_hyper_asinh() {
		}
		void funcx_math_hyper_atanh() {
		}
