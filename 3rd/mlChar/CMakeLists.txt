
set(_project_name mlChar)

if(_test)
	aux_add_exe(
		${_project_name} "test"
		)
else()
	aux_add_lib(
		${_project_name} "3rd" 
		"include/${_project_name}"
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
