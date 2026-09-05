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

	// Board owns the G(V, E) that represents the game state
	// Represent each vertex as a BIT_MASK
	// TILE = (4 bits: number) + (3 bits: resource)
	// for the number part, 1-12: number, 0: port, 15: desert
	// Each vertex has 3 TILEs, and (settle, city) x #players so that's 3 bits again.
	// so total each vertex is 3 TILES + 3 = 21 + 3 = 24
	// we have 54 vertices so we can index them in 8 bits
	// so a vertex should have 32 bits! That's an integer!
	// 4 more bits required. 
	// Potentially use static map, or iterate over rules that masking and packing might work.
	// It is really beneficial for the board state to be minimal because we will be running decision
	// trees

	


}
