cmake_minimum_required(VERSION 3.20)
project(Snake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ── Output directory ──────────────────────────────────────────────────────────
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ── Sources ───────────────────────────────────────────────────────────────────
set(SOURCES
    main.cpp
    Food.cpp
    Food.h
    Game.cpp
    Game.h
    Includes.cpp
    Includes.h
    Snake.cpp
    Snake.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Headers use #include "./include/raylib.h", so the project root must be on the path.
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})

# ── Raylib ────────────────────────────────────────────────────────────────────
# Prefer a system-installed or package-manager-provided raylib.
find_package(raylib QUIET)

if(raylib_FOUND)
    message(STATUS "Using system raylib.")
    target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
else()
    # Fall back to the bundled static library in lib/.
    message(STATUS "System raylib not found – linking bundled lib/libraylib.a.")

    set(RAYLIB_BUNDLED ${CMAKE_SOURCE_DIR}/lib/libraylib.a)

    if(NOT EXISTS ${RAYLIB_BUNDLED})
        message(FATAL_ERROR "Bundled raylib not found at ${RAYLIB_BUNDLED}. "
            "Install raylib via your package manager or place libraylib.a in lib/.")
    endif()

    if(APPLE)
        target_link_libraries(${PROJECT_NAME} PRIVATE
            ${RAYLIB_BUNDLED}
            "-framework IOKit"
            "-framework Cocoa"
            "-framework OpenGL"
        )
    elseif(WIN32)
        # On Windows the bundled lib would be lib/raylib.lib
        target_link_libraries(${PROJECT_NAME} PRIVATE
            ${CMAKE_SOURCE_DIR}/lib/raylib.lib
            winmm gdi32 opengl32
        )
    else()  # Linux
        target_link_libraries(${PROJECT_NAME} PRIVATE
            ${RAYLIB_BUNDLED}
            m dl pthread
        )
    endif()
endif()

# Windows always needs these regardless of which raylib path was chosen.
if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE winmm gdi32 opengl32)
endif()

# ── Copy assets next to the executable ───────────────────────────────────────
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Graphics
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/Graphics
    COMMENT "Copying Graphics/ assets to output directory"
)

# ── Compiler warnings ─────────────────────────────────────────────────────────
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()
