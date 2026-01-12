cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project( ControlStructuresTest )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( APP_EXECUTABLE ControlStructuresTest )

include_directories( inc )

ADD_EXECUTABLE(ControlStructures "src/ControlStructures.cpp")

ADD_EXECUTABLE( ${APP_EXECUTABLE} "src/ControlStructures.cpp"  "src/ControlStructuresTest.cpp")

target_compile_definitions(ControlStructuresTest PRIVATE TESTING)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT ${APP_EXECUTABLE} )

include (CTest)
add_test(${APP_EXECUTABLE}_testChoice1 ${APP_EXECUTABLE} 1)
add_test(${APP_EXECUTABLE}_testChoice2 ${APP_EXECUTABLE} 2)
add_test(${APP_EXECUTABLE}_testChoice3 ${APP_EXECUTABLE} 3)
add_test(${APP_EXECUTABLE}_testChoice4 ${APP_EXECUTABLE} 4)
add_test(${APP_EXECUTABLE}_testChoice5 ${APP_EXECUTABLE} 5)

find_program(VALGRIND "valgrind")
if(VALGRIND)
	add_custom_target(valgrind
    COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes --error-exitcode=1 $<TARGET_FILE:${APP_EXECUTABLE}>)
endif()