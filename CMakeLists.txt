cmake_minimum_required(VERSION 3.10)

# Project
project(SandSimulation)

# Sources
file(GLOB_RECURSE SOURCES sources/*.cpp)
file(GLOB_RECURSE HEADERS includes/*.hpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# C++ 17
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

# Includes
target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_include_directories(${PROJECT_NAME} PUBLIC sources)

# Libraries
target_link_libraries(SandSimulation PRIVATE sfml-graphics sfml-audio)
target_compile_features(SandSimulation PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET SandSimulation
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:SandSimulation>
        VERBATIM)
endif()

install(TARGETS SandSimulation)
