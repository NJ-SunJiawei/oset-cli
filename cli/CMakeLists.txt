cmake_minimum_required(VERSION 3.00)

set(SRC_FILES
	sset-cli.c
)

add_executable(openCLI ${SRC_FILES})
target_include_directories(openCLI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${OSET_ESL_INCLUDE_DIRS})
target_link_libraries(openCLI cli)

install(TARGETS openCLI
		RUNTIME DESTINATION ${SSET_CLI_INSTALL_PATH}
		COMPONENT sset)
install(TARGETS openCLI
		RUNTIME DESTINATION bin
		COMPONENT sset)
install(FILES  ${CMAKE_CURRENT_SOURCE_DIR}/sset_cli.conf  DESTINATION ${SSET_CLI_INSTALL_PATH})

