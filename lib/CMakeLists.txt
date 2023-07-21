cmake_minimum_required(VERSION 3.00)

INCLUDE (CheckFunctionExists)
INCLUDE (CheckIncludeFiles)
CHECK_INCLUDE_FILES(histedit.h HAVE_LIBEDIT)
CHECK_FUNCTION_EXISTS(el_wset HAVE_LIBEDIT)
set(HAVE_DECL_EL_PROMPT_ESC 1)
set(HAVE_DECL_EL_REFRESH 1)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/esl_config_auto.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/esl_config_auto.h)

set(SRC_FILES
	src/cJSON.c
	src/cJSON_Utils.c
	src/getopt_long.c
	src/esl.c
	src/esl_buffer.c
	src/esl_config.c
	src/esl_event.c
	src/esl_json.c
	src/esl_threadmutex.c
	src/esl_oop.cpp
)

add_library(cli STATIC ${SRC_FILES})
target_include_directories(cli PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_compile_options(cli PUBLIC -D )
target_link_libraries(cli pthread)
