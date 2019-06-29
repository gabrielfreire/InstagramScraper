// InstagramScraperCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "ArgParser.h"
#include "InstagramService.h"
#include "BodyParser.h"

int main(int argc, char* argv[])
{
	std::vector<std::string> _args = parse_args(argc, argv);
	if (_args.size() > 0) {
		std::string html_body = request::get_html_body(_args);
		std::string content = html_parser::parse(html_body);
		content = content.substr(0, content.find(' ', 0));
		std::cout << "Profile: " << _args[0] << "\n";
		std::cout << "Follower Count: " << content << "\n";
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
