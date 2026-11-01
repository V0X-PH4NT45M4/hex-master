#pragma once
#include <array>
#include <cstdint>
#include <iostream>

namespace engine {
	const size_t resourceTypes = 5;
	enum struct Resource {
		ORE,
		WHEAT,
		BRICK,
		WOOD,
		SHEEP,
	};

	const size_t devCardTypes = 5;
	enum struct DevCard {
		KNIGHT,
		ROAD_BUILDER,
		MONOPOLY,
		VICTORY_POINT,
		YEAR_OF_PLENTY,
	};

	const size_t portTypes = 7;
	enum struct Port {
		ORE,
		WHEAT,
		BRICK,
		WOOD,
		SHEEP,
		WILD,
		NONE,
	};
	
	// players can be 2, 3 or 4
	const size_t maxPlayers = 4;
	enum struct Player {
		BLINKY,
		INKY,
		PINKY,
		CLYDE,
	};

	using resourceLedger = std::array<uint8_t, resourceTypes>;
	using devCardLedger = std::array<uint8_t, devCardTypes>;

	// Balance owns the validation of resource and dev balances
	struct Balance {
		resourceLedger resBalance = {};
		devCardLedger devBalance = {};
		
		enum struct State {
			POSITIVE, 
			NEGATIVE,
		};
		// if balance goes negative, we return false, caller is responsible 
		// for rolling back the transaction. The request is subtracted from the
		// Balance. A negative request means we are adding to the Balance.
		bool resourceTransaction(resourceLedger request);
		
		Balance (); // to be used by the player
		Balance (resourceLedger& startingRes, devCardLedger& startingDevs); // to be used by the bank
	};

	struct BoardState {
		// we will be using a 21 by 21 matrix to store game state
		const static size_t systemSize = 21;

		// our co-ordinate system, for symmetry, can go negative, this offset
		// is to be used to translate the matrix indices to coordinates
		// Location respects the contract of handling requests that are signed
		const static size_t offset = 10;
		struct Location {
			int8_t q;
			int8_t r;
		};
		// system (short for coordinate system) stores information
		// to render board efficiently, currentState is the helper that applies
		// offsets on Location and then fetches currentState from system
		std::array<std::array<uint8_t, systemSize>, systemSize> system; 
		uint8_t currentState(Location loc);

		// markers for system layout (for UI rendering)
		// more details @scripts/hex_coordinates.py
		// layout is to be used by UI rendering to understand board state
		enum struct Marker: uint8_t {
			SENTINEL,
			POINT,
			EDGE,
			TILE,
			TABLE,
		};
		const static Marker renderLayout(Location loc);

		// API to return rolled resources efficiently
		std::array<std::array<uint8_t, resourceTypes>, maxPlayers> rolledResources(uint8_t diceRoll);

		// place city/settle (decides which one by checking if player owns a settle on the requested spot)
		bool placeCityOrSettle(Player owner, Location loc);

		// place road (checks connectivity for player on requested spot, updates longest road)
		bool placeRoad(Player owner, Location loc);

		// place robber (just update the TILE's state, evaluates friendly robber)
		bool placeRobber(Location loc);

		// evaluate who currently has the longest road
		// there are only 2 disconnected graphs, one extra scan required on connection
		Player longestRoad();

		// TODO: helper methods to interpret states for TILE, POINT, EDGE and fetching adj. Markers)
		// TILE: digit(4 bits) + variant(3 bits) + robber(1 bit)
		// POINT: owner(3 bits) + city/settle(1 bit) + port(3 bits) + chirality(1 bit)
		// EDGE: owner(3 bits) + slope(2 bits)
	};

}
