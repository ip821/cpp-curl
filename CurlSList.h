#pragma once

#include <curl/curl.h>
#include <new>
#include <string>

class CurlSList
{
    curl_slist* m_pSlist{};

public:
    CurlSList() = default;

    CurlSList(const CurlSList&) = delete;
    CurlSList& operator=(const CurlSList&) = delete;
    CurlSList(CurlSList&&) = delete;
    CurlSList& operator=(CurlSList&&) = delete;

    ~CurlSList()
    {
        if (m_pSlist)
            curl_slist_free_all(m_pSlist);
    }

    void Append(const std::string& value)
    {
        auto* newList = curl_slist_append(m_pSlist, value.c_str());
        if (!newList)
            throw std::bad_alloc();

        m_pSlist = newList;
    }

    [[nodiscard]] curl_slist* Get() const { return m_pSlist; }
};
