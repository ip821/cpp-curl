#pragma once

#include <curl/curl.h>

class CurlSList
{
    curl_slist *m_pSlist{};

public:
    CurlSList() = default;

    ~CurlSList()
    {
        if (m_pSlist)
            curl_slist_free_all(m_pSlist);
    }

    void Append(const std::string& value)
    {
        m_pSlist = curl_slist_append(m_pSlist, value.c_str());
    }

    [[nodiscard]] curl_slist *Get() const { return m_pSlist; }
};
