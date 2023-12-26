// Copyright 2023 for the linter

#include <curl/curl.h>
#include <iostream>

#include "PostRequest.hpp"
#include "GetRequest.hpp"

const char* end_point = "http://localhost:8080/api/measurement";
const char* data = "{\"sensor\":\"puls\",\"value\":112,\"timestamp\":\"12:12\"}";
size_t print_response(void *buffer, size_t size, size_t nmemb, void *userp) {
    std::cout << static_cast<const char*>(buffer) << std::endl;
    return size;
}

int main() {
    // set up curl global
    curl_global_init(CURL_GLOBAL_ALL);

    // get handle
    CURL *curl_handle = curl_easy_init();

    // return codes:      0 --> no error
    //               others --> see https://curl.se/libcurl/c/libcurl-errors.html
    PostRequest post_request = PostRequest(end_point);
    int post_success = post_request.sendRequest(data);
    std::cout << "Request send" << std::endl
              << "Returncode:" << post_success << std::endl;

    GetRequest get_request = GetRequest(end_point);
    int get_success = get_request.sendRequest();
    std::cout << "Request send" << std::endl
              << "Returncode:" << get_success << std::endl;

    return 0;
}
