cmake_minimum_required(VERSION 3.16)
project(darvathon LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(RAYLIB_VERSION 5.5)

if(MINGW)
    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/releases/download/${RAYLIB_VERSION}/raylib-${RAYLIB_VERSION}_win64_mingw-w64.zip
        FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)

elseif(WIN32 AND MINGW)
    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/releases/download/${RAYLIB_VERSION}/raylib-${RAYLIB_VERSION}_win32_mingw-w64.zip
        FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)
endif()

if (LINUX)
    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/releases/download/${RAYLIB_VERSION}/raylib-${RAYLIB_VERSION}_linux_amd64.tar.gz
        FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
    )
endif()

set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)



add_executable(${PROJECT_NAME}
    src/main.cpp

    src/texture.hpp src/texture.cpp
    src/entity.hpp src/entity.cpp
    src/input.hpp src/input.cpp
    src/weapon.hpp







#    src/weapon.h
    )


target_link_libraries(${PROJECT_NAME} raylib -lopengl32 -lgdi32 -lwinmm)
target_compile_options(darvathon PRIVATE -Wno-missing-braces)

include(GNUInstallDirs)
install(TARGETS darvathon
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
