// Copyright 2023 for the linter
#include "PostRequest.hpp"

PostRequest::PostRequest(const std::string url) {
    _curl_handle = curl_easy_init();

    _url = url;
    curl_easy_setopt(_curl_handle, CURLOPT_URL, _url.c_str());

    _header = curl_slist_append(_header, "Content-Type: application/json");
    _header = curl_slist_append(_header, "Accept: application/json");
    curl_easy_setopt(_curl_handle, CURLOPT_HTTPHEADER, _header);
}

int const PostRequest::sendRequest(const std::string& data) {
    curl_easy_setopt(_curl_handle, CURLOPT_POSTFIELDS, data.c_str());
    return curl_easy_perform(_curl_handle);
}
