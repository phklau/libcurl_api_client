// Copyright 2023 for the linter
#ifndef GETREQUEST
#define GETREQUEST

#include <curl/curl.h>
#include <string>
#include <iostream>

// GetRequest to querry data from API
class GetRequest {
    static size_t print_response(void *buffer, size_t size, size_t nmemb, void *userp) {
    std::cout << static_cast<const char*>(buffer) << std::endl;
    return size * nmemb;
}
    private:
        CURL* _curl_handle;
        std::string _url;

    public:
        GetRequest(const std::string url);
        bool const sendRequest();
};

#endif // GETREQUEST
