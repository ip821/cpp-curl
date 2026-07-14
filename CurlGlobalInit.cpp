#include <curl/curl.h>
#include "include/cpp_curl/CurlGlobalInit.h"

CurlGlobalInit::CurlGlobalInit()
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

CurlGlobalInit::~CurlGlobalInit()
{
    curl_global_cleanup();
}
