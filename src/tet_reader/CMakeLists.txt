project(tet_reader)

aux_source_directory(. SRC)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME}
        ${VTK_COMMON_CORE} ${VTK_COMMON_DATA_MODEL} ${VTK_IO_CORE} ${VTK_IO_LEGACY} ${VTK_IO_XML}
        )