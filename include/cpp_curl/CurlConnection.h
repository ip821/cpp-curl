#pragma once
#include <expected>
#include <string>
#include <optional>

struct Success
{
    std::string responseBody;
};

struct Error
{
    std::string message;
    std::string responseBody;
};

using HttpResult = std::expected<Success, Error>;

class CurlConnection
{
public:
    CurlConnection() = default;
    ~CurlConnection() = default;

    [[nodiscard]] HttpResult HttpGet(const std::string& url, const std::optional<std::string>& authorizationHeaderValue) const;
    static std::string GetHttpStatusMessage(long code);
};
