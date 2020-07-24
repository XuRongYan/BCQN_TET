project(BCQN_TET)

add_compile_definitions(CINOLIB_USES_VTK)

aux_source_directory(. SRC)

include_directories(../../../external/bcqn-data/)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME}
        ${OPENMP}
        ${VTK_COMMON_CORE} ${VTK_COMMON_DATA_MODEL} ${VTK_IO_CORE} ${VTK_IO_LEGACY} ${VTK_IO_XML}
        ${OPENGL_LIBRARIES} glfw GLEW::GLEW
        Qt5::Widgets Qt5::Core Qt5::Gui Qt5::OpenGL
        )