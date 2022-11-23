# link cudart
if(NOT BUILD_CUDA_VERSION)
    set(BUILD_CUDA_VERSION "10.1" CACHE STRING "build cuda version: 10.1")
else(NOT BUILD_CUDA_VERSION)
    set(BUILD_CUDA_VERSION ${BUILD_CUDA_VERSION} CACHE STRING "build cuda version: 10.1")
endif(NOT BUILD_CUDA_VERSION)
message("BUILD_CUDA_VERSION = ${BUILD_CUDA_VERSION}")
find_path(LIBCUDART_LINK_PATH
    libcudart_static.a
    /usr/local/cuda-${BUILD_CUDA_VERSION}/lib64
)
if(NOT LIBCUDART_LINK_PATH)
    message(FATAL_ERROR "ERROR: No support cudart ${BUILD_CUDA_VERSION}")
else(NOT LIBCUDART_LINK_PATH)
    set(LIBCUDART_FILENAME ${LIBCUDART_LINK_PATH}/libcudart_static.a)
endif(NOT LIBCUDART_LINK_PATH)

get_filename_component(LIBCUDART_PATH ${LIBCUDART_LINK_PATH} DIRECTORY)
get_filename_component(LIBCUDART_PATH "${LIBCUDART_PATH}" REALPATH)
message("LIBCUDART_PATH = ${LIBCUDART_PATH}")
message("LIBCUDART_LINK_PATH = ${LIBCUDART_LINK_PATH}")
add_library(cudart INTERFACE IMPORTED GLOBAL)
target_link_libraries(
        cudart
        INTERFACE ${LIBCUDART_FILENAME}
        INTERFACE ${CMAKE_DL_LIBS}
        INTERFACE rt
)
set_target_properties(
        cudart PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${LIBCUDART_PATH}/include
)

# link cuda_drive
add_library(cuda_drive SHARED IMPORTED GLOBAL)
find_library(CUDA_DRIVE_FILENAME libcuda.so)
message("CUDA_DRIVE_FILENAME = ${CUDA_DRIVE_FILENAME}")
if (NOT CUDA_DRIVE_FILENAME)
    message(WARNING "lib cuda not found")
else ()
    message("cuda-include=${CUDA_DRIVE_FILENAME}/include")
    set_target_properties(
        cuda_drive PROPERTIES
        IMPORTED_LOCATION ${CUDA_DRIVE_FILENAME}
        INTERFACE_INCLUDE_DIRECTORIES ${LIBCUDART_PATH}/include
    IMPORTED_NO_SONAME TRUE
)
endif ()

# combine cudart and cuda_drive and others into cuda_suite
add_library(cuda_suite INTERFACE IMPORTED GLOBAL)
target_link_libraries(
    cuda_suite
    INTERFACE cudart
    INTERFACE cuda_drive
)

set_target_properties(
    cuda_suite PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${LIBCUDART_PATH}/include
)

