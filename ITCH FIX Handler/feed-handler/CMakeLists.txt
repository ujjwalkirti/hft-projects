cmake_minimum_required(VERSION 3.20)
project(feed_handler)

set(CMAKE_CXX_STANDARD 20)

add_executable(feed_handler
    src/main.cpp
    src/utils/mmap_reader.cpp
    src/itch/itch_parser.cpp
    src/itch/itch_messages_generator.cpp
)

target_include_directories(feed_handler PRIVATE src)
