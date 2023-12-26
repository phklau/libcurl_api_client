// Copyright 2023 for the linter
#ifndef POSTREQUEST
#define POSTREQUEST

#include <curl/curl.h>
#include <string>

// PostRequest sending JSON to an API endpoint
class PostRequest {
    private:
        CURL* _curl_handle;
        struct curl_slist* _header = nullptr;
        std::string _url;

    public:
        PostRequest(const std::string url);
        int const sendRequest(const std::string& data);
};

#endif
