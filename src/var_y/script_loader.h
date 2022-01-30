#pragma once
void load_new_script() {
	string loader_process_m;
	active_script.clear();
	while (getline(active_file, loader_process_m)) {
		active_script.push_back(loader_process_m);
	}
}