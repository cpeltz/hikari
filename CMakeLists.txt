project(hikari)
cmake_minimum_required(VERSION 2.6)

set(Boost_Libs boost_filesystem-mt boost_program_options-mt)
set(Boost_Test_Libs boost_filesystem-mt boost_unit_test_framework-mt)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

file(GLOB SRC_FILES src/*.cpp)
add_executable(hikari ${SRC_FILES})
target_link_libraries(hikari ${Boost_Libs} crypto++ pthread ossp-uuid++)

install(TARGETS hikari RUNTIME DESTINATION bin)
