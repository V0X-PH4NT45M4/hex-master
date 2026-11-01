qt_add_executable(hex_master
	game_board.cpp game_board.h
	# player_menu.cpp player_menu.h
	# trade_offer.cpp trade_offer.h
	# trade_menu.cpp trade_menu.h
	# dice_roll.cpp dice_roll.h
	main.cpp
)

target_link_libraries(hex_master PRIVATE Qt6::Widgets)
target_include_directories(hex_master PRIVATE ${CMAKE_SOURCE_DIR}/include)

set_target_properties(hex_master PROPERTIES
	WIN32_EXECUTABLE ON
	MACOSX_BUNDLE ON
)


