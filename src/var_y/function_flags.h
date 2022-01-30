#pragma once



void fc2_function_flags_selector() {
	while (true) {
		if (active_script[line - 1] == "+local") {//mark as local function

		} else if (active_script[line - 1] == "+global") {//mark as global function

		} else if (active_script[line - 1] == "+tmp") {//mark as temp function (will set function to be ignored without removing it from memory)

		} else if (active_script[line - 1] == "+mfr") {//mark function for removle (costs time based on every function in existance)

		} else if ((active_script[line - 1] == "flag*")||(active_script[line - 1] == "~~~*")) {
			break;
		} else {
			error_stream();
		}
	}
}