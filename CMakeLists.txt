cmake_minimum_required(VERSION 3.13)
project(camera_settings)

set(CMAKE_CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
        motion_camera_settings_generated.h
        main.cpp html_css_js_util.cpp html_css_js_util.hpp)

find_package(Poco REQUIRED Net Util JSON)

target_include_directories(${PROJECT_NAME} PUBLIC /usr/include/Poco)
target_link_libraries(${PROJECT_NAME} PUBLIC Poco::Net Poco::Util Poco::JSON)

target_include_directories(${PROJECT_NAME} PRIVATE external)
target_link_directories(${PROJECT_NAME} PRIVATE external)