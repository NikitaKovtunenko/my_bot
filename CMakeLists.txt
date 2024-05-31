cmake_minimum_required(VERSION 3.10.2)
project(echobot)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(Boost_USE_MULTITHREADED ON)

#подключаем библиотеки для tgbot
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)
include_directories(/usr/local/include ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR})

if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    add_definitions(-DHAVE_CURL)
endif()

#определяем переменные
get_filename_component(PROJECT_DIR "${CMAKE_SOURCE_DIR}" ABSOLUTE)
message("Текущий путь до директории проекта: ${PROJECT_DIR}")

add_definitions(-DVERSION1 )
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Программа выполняется в режиме Debug.")
    add_definitions(-DBUILD_MODE_DEBUG)
    #опдключаем тесты
    add_subdirectory(test)
    enable_testing()
    add_test(NAME tests COMMAND tests)
else()
    add_definitions(-DBUILD_MODE_RELEASE)
    message("Программа выполняется в режиме Release.")
endif()

#Конфигурируем файл с переменными
configure_file(src/config.h.in config.h)

add_executable(echobot src/main.cpp
        src/BotHandler.cpp
        src/BotHandler.h
        src/Logger.cpp
        src/Logger.h
        src/config.h.in)

target_link_libraries(echobot /Users/kiton/Library/tgbot-cpp/libTgBot.a ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${CURL_LIBRARIES})


