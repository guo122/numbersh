
set(_project_name goblin)

link_libraries(
	pugixml
	mlTime
	)

aux_add_exe(${_project_name} "Numbersh")

target_include_directories(
	${_project_name}
	PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/include
	)

