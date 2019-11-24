
set(_project_name mlTime)

if(_test)
	aux_add_exe(
		${_project_name} "test"
		)
else()
	aux_add_lib(
		${_project_name} "3rd" 
		"include/mlTime"
		"source"
		)
endif()

target_include_directories(
    ${_project_name}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include/${_project_name}
    )

target_include_directories(
    ${_project_name}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    )
