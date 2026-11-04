#include <engine.h>
#include <bit_state_management.h>

namespace engine {
	namespace BoardEdge {
		// EDGE = owner(3 bits) + slope(2 bits) + port(3 bits)
		Player getEdgeOwner(uint8_t state) {
			return Player(utils::extractBits(state, CHAR_BIT - 3, CHAR_BIT));
		}
	};
};
