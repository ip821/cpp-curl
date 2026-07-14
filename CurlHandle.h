#pragma once

#include <curl/curl.h>

class CurlHandle
{
    CURL* m_pCurl{};

public:
    CurlHandle()
    {
        m_pCurl = curl_easy_init();
    }

    CurlHandle(const CurlHandle&) = delete;
    CurlHandle& operator=(const CurlHandle&) = delete;
    CurlHandle(CurlHandle&&) = delete;
    CurlHandle& operator=(CurlHandle&&) = delete;

    ~CurlHandle()
    {
        if (m_pCurl)
            curl_easy_cleanup(m_pCurl);
    }

    [[nodiscard]] CURL* Get() const { return m_pCurl; }
};
