cmake_minimum_required(VERSION 4.0)
project(cpp_curl LANGUAGES C CXX)
include(FetchContent)

set(BUILD_CURL_EXE OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(CURL_USE_LIBPSL OFF CACHE BOOL "" FORCE)

if (WIN32)
    set(CURL_USE_SCHANNEL ON CACHE BOOL "" FORCE)
endif ()

FetchContent_Declare(
        curl
        GIT_REPOSITORY https://github.com/curl/curl.git
        GIT_TAG curl-8_19_0
)
FetchContent_MakeAvailable(curl)

add_library(cpp_curl
        CurlConnection.cpp
        CurlConnection.h
        CurlGlobalInit.h
        CurlHandle.h
        CurlSList.h
)

add_library(cpp_curl::cpp_curl ALIAS cpp_curl)
target_compile_features(cpp_curl PUBLIC cxx_std_23)
target_include_directories(cpp_curl
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
target_link_libraries(cpp_curl PRIVATE libcurl)
