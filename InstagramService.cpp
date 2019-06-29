#include <iostream>
#include <string>
#include <vector>
#include "webcurl.h"

namespace request {
	std::string get_html_body(std::vector<std::string> args) {
		std::string url = "https://www.instagram.com/" + args[0];
		try {
			std::string body = WebCurl::getPage(url);
			return body;
		}
		catch (std::exception& e) {
			std::cerr << "Request failed, error: " << e.what() << "\n";
		}
	}
}