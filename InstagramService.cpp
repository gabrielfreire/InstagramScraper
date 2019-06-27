#include <iostream>
#include <string>
#include <vector>
#include "webcurl.h"

std::string get_html_body(std::vector<std::string> args) {
	std::string url = "https://www.instagram.com/" + args[0];
	// std::cout << url << "\n";
	try {
		// std::cout << "Will make request" << "\n";
		std::string body = WebCurl::getPage(url);
		// std::cout << body << "\n";
		return body;
	}
	catch (std::exception& e) {
		std::cerr << "Request failed, error: " << e.what() << "\n";
	}
}