// Copyright 2023 for the linter

#include <curl/curl.h>
#include <iostream>

#include "PostRequest.hpp"

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
#ifdef DEBUG
    CURL *curl_handle = curl_easy_init();

    // post header
    struct curl_slist *header = nullptr;
    header = curl_slist_append(header, "Content-Type: application/json");
    header = curl_slist_append(header, "Accept: application/json");

    // prepare post request
    curl_easy_setopt(curl_handle, CURLOPT_URL, end_point);
    curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, header);
    // libcurl default prints data to the stdout, only to test
    // curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, print_response);

    // send request
    int success = curl_easy_perform(curl_handle);
#endif
    PostRequest request = PostRequest(end_point);
    int success = request.sendRequest(data);
    std::cout << "Request send" << std::endl
              << "Returncode:" << success << std::endl;

    return 0;
}
