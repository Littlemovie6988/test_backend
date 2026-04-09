cmake_minimum_required(VERSION 3.10)
project(your_first_drogon_app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_PREFIX_PATH "/opt/homebrew" ${CMAKE_PREFIX_PATH})

find_package(Drogon REQUIRED)
find_package(jsoncpp REQUIRED)
find_package(Threads REQUIRED)

file(GLOB CONTROLLER_SOURCES "controllers/*.cc")

add_executable(${PROJECT_NAME}
    main.cc
    ${CONTROLLER_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Drogon::Drogon
    ${jsoncpp_LIBRARIES}   # вместо просто jsoncpp
    Threads::Threads
)

target_include_directories(${PROJECT_NAME} PRIVATE ${jsoncpp_INCLUDE_DIRS})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/config.json
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/config.json
)