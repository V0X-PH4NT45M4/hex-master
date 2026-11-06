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
	BoardState::BoardState(){
		// We need to the following things
		// Populate the tile details into the table
		// We need to add slope+chirality hints into render layout
		// Potentially adding POINT_PLUS, POINT_MINUS, EDGE_ALONG_Q, EDGE_ALONG_R, EDGE_ALONG_Q_MINUS_R
		// We also need to validate how port information can be populated fairly
		return;
	}
};

