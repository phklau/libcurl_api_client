#include "GetRequest.hpp"

GetRequest::GetRequest(const std::string url) {
    _curl_handle = curl_easy_init();

    _url = url;
    curl_easy_setopt(_curl_handle, CURLOPT_URL, _url.c_str());
    curl_easy_setopt(_curl_handle, CURLOPT_WRITEFUNCTION, print_response);
}


int const GetRequest::sendRequest() {
    return curl_easy_perform(_curl_handle);
}
