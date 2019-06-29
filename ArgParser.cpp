#include <iostream>
#include <string>
#include <vector>

void show_arguments(int argc, char* argv[]) {
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << "\n";
	}
}
void show_usage() {

	std::cout << "Usage: \n";
	std::cout << "\tInstagramScraper <profile_name>";

}
std::vector<std::string> parse_args(int argc, char* argv[]) {
	std::vector<std::string> args{};

	if (argc <= 1) {
		show_usage();
		return args;
	}

	for (int i = 1; i < argc; i++) {
		args.push_back(argv[i]);
	}
	return args;
}