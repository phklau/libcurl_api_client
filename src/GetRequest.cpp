#include "GetRequest.hpp"

GetRequest::GetRequest(const std::string url) {
    _curl_handle = curl_easy_init();

    _url = url;
    curl_easy_setopt(_curl_handle, CURLOPT_URL, _url.c_str());
    curl_easy_setopt(_curl_handle, CURLOPT_WRITEFUNCTION, print_response);
}


bool const GetRequest::sendRequest() {
    int error = curl_easy_perform(_curl_handle);
    if (error) {
        std::cerr<< "Request failed with code: "<< error << " \"" << curl_easy_strerror(static_cast<CURLcode>(error)) << "\"" << std::endl;
    }
    return !static_cast<bool>(error);
}
