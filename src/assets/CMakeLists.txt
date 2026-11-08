add_library(lib_assets
        scripts/CameraBehaviour.cpp
        scripts/CameraBehaviour.h
)

target_include_directories(lib_assets PUBLIC .)
target_link_libraries(lib_assets PUBLIC lib_engine pugixml sfml-graphics tgui)