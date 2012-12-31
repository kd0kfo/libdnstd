cmake_minimum_required(VERSION 2.8)

project(DNSTD CXX)
set(DNSTD_MAJOR_VERSION 2)
set(DNSTD_MINOR_VERSION 3)
set(DNSTD_REVISION 1)
set(AUTHOR_EMAIL david@davecoss.com)

option(ZLIB_DIR "Include tar/gzip in library" OFF)
if(ZLIB_DIR)
	set(BUILD_WITH_ZLIB 1)
	set(ZLIB_EXTRA_SOURCE Zipper.c)
	set(ZLIB_EXTRA_HEADER Zipper.h)
	message("USING ZLIB")
else()
	message("Not USING ZLIB")
endif(ZLIB_DIR)

configure_file("${PROJECT_SOURCE_DIR}/config.h.in" "${PROJECT_SOURCE_DIR}/config.h")

execute_process(COMMAND git rev-parse HEAD OUTPUT_FILE ${PROJECT_BINARY_DIR}/build_git_sha.out)
file(STRINGS ${PROJECT_BINARY_DIR}/build_git_sha.out BUILD_GIT_SHA)
execute_process(COMMAND date OUTPUT_FILE ${PROJECT_BINARY_DIR}/build_time.out)
file(STRINGS ${PROJECT_BINARY_DIR}/build_time.out BUILD_TIME)
configure_file("${PROJECT_SOURCE_DIR}/src/version.cpp.in" "${PROJECT_SOURCE_DIR}/src/version.cpp")

add_library(dnstd src/Binary.cpp src/Complex.cpp src/DavidException.cpp src/Double.cpp src/DRandom.cpp src/StringTokenizer.cpp src/NumericalIntegration.cpp src/utils.cpp src/XMLNode.cpp src/XMLParser.cpp src/version.cpp src/${ZLIB_EXTRA_SOURCE})

install(TARGETS dnstd DESTINATION lib)
FILE(GLOB headers "${PROJECT_SOURCE_DIR}/src/*.h")
install(FILES ${headers} DESTINATION include/libdnstd)
