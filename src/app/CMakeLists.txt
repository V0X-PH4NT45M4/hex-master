qt_add_executable(HexMaster
    hex.cpp
)

target_link_libraries(HexMaster PRIVATE Qt6::Widgets)

target_include_directories(HexMaster PRIVATE ${CMAKE_SOURCE_DIR}/include)

set_target_properties(HexMaster PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
