cmake_minimum_required(VERSION 3.16)
project(BCQN_TET)

set(GOOGLETEST_VERSION 1.8.0)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xpreprocessor -fopenmp")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(VTK_COMMON_CORE /usr/local/lib/libvtkCommonCore-8.2.dylib)
set(VTK_COMMON_DATA_MODEL /usr/local/lib/libvtkCommonDataModel-8.2.dylib)
set(VTK_IO_CORE /usr/local/lib/libvtkIOCore-8.2.dylib)
set(VTK_IO_LEGACY /usr/local/lib/libvtkIOLegacy-8.2.dylib)
set(VTK_IO_XML /usr/local/lib/libvtkIOXML-8.2.dylib)

set(OPENMP /usr/local/lib/libomp.dylib)
set(INCLUDE /usr/local/include)

add_compile_definitions(CINOLIB_USES_VTK)
add_compile_definitions(CINOLIB_USES_OPENGL)
add_compile_definitions(CINOLIB_USES_QT)

include_directories(${INCLUDE} src)
include_directories(/usr/local/include/vtk-8.2)

find_package(GTest REQUIRED)

#opengl
find_package(OpenGL REQUIRED)
if(OpenGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
else()
    message(can't find opengl)
    return()
endif()

find_package(GLEW 2.1.0)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

#glfw
find_package(glfw3 3.3 REQUIRED)
if(glfw3_FOUND)
    include_directories(${GLFW3_INCLUDE_DIR})
else()
    message(can't find glfw3)
    return()
endif()

#stb_img
include_directories(/usr/local/include/stb)
link_libraries(/usr/local/lib/libstb_image.a)

include_directories(/usr/local/include)
include_directories(/usr/local/include/KHR)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)


find_package(Eigen3 3.3.0)
if (Eigen3_FOUND)
    include_directories(${EIGEN3_INCLUDE_DIR})
else ()
    message(can't find eigen3)
    return()
endif ()

if (MSVC)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _USE_MATH_DEFINES)
endif (MSVC)

add_subdirectory(external/googletest)
add_subdirectory(tests)
add_subdirectory(src/bcqn)
add_subdirectory(src/tet_reader)
