#include <engine.h>
#include <array>

namespace engine {
	using Marker = BoardState::Marker;
	using Location = BoardState::Location;
	using coordinateSystem = std::array<std::array<uint8_t, BoardState::systemSize>, BoardState::systemSize>;

	uint8_t BoardState::currentState(const Location &loc) const {
		auto [q, r] = loc;
		return BoardState::system[q + offset][r + offset];		
	}
	
	// TODO: add application logic and a generator for board states.
	// We need to support at least random board-generation and the fair board-generation
	// Fair board-generation is higher priority for our tests. Random board-generation is cool, but unneeded
	// For bots to learn optimization
	BoardState::BoardState(){
		// We need to the following things
		// Populate the tile details into the table
		// We need to add slope+chirality hints into render layout
		// Potentially adding POINT_PLUS, POINT_MINUS, EDGE_ALONG_Q, EDGE_ALONG_R, EDGE_ALONG_Q_MINUS_R
		// We also need to validate how port information can be populated fairly
		// PORT generation doesn't have a pattern, and has to be hardcoded
		return;
	}

	// fair board generation logic
	// hard coded port edges (assignment of type of ports to be randomized)
	// https://www.youtube.com/watch?v=5dg7AA9TYko
	// on rules for 
	// a) tile placement (I believe no rules)
	// b) number placement (I believe a fixed spiral pattern used by colonist.io and settlers-of-catan)
	// steps:
	// 1. mark and assign ports (TODO: Static method/table to access port information)
	// 2. place the tiles and do spiral number provision (enumerate the tile TABLE and then hydrate the rest of the board)
	// NOTE: number assignment must be done after tile placements so that we can simulate spiral logic with desert.
	coordinateSystem fairBoardInit(){}

	// random generation logic
	// port edges can be (6C3) because of the 6 port pieces
	// no rules on tile/number placement
	// however for pseudo-random we still put the non-adj 6/8 rule
	coordinateSystem pseudoRandomBoardInit(){}
	coordinateSystem randomBoardInit(){}
};

