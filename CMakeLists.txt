cmake_minimum_required(VERSION 3.0.0)
project(tweetcli VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(tweetcli
  src/main.cpp
  src/utils/api.cpp
  src/utils/string_util.cpp
  src/utils/config.hpp
  src/models/tweet.cpp
)
find_package(unofficial-curlpp CONFIG REQUIRED)
target_link_libraries(tweetcli PRIVATE unofficial::curlpp::curlpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
