#include <stdexcept>
#include <string>
#include <iostream>
#include <curl/curl.h>
#include "webcurl.h"

size_t WebCurl::writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{
	//callback must have this declaration
	//buf is a pointer to the data that curl has for us
	//size*nmemb is the size of the buffer
	((std::string*)up)->append((char*)buf, size * nmemb);
	return size * nmemb; //tell curl how many bytes we handled
}

std::string WebCurl::getPage(std::string& url) {

	CURLcode code;
	CURL* curl;
	curl_global_init(CURL_GLOBAL_DEFAULT);
	std::string readBuffer;
	curl = curl_easy_init();
	if (curl == NULL)
		throw std::runtime_error("Failed to create CURL connection");

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &WebCurl::writeCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

	code = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	std::cout << code << " < code \n";
	if (code != CURLE_OK)
		throw std::runtime_error("Failed to retrieve web page");
	return readBuffer;
}