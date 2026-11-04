#include <engine.h>
#include <bit_state_management.h>
#include <array>

namespace engine {
	namespace BoardTile {
		// TILE: digit(4 bits) + variant(3 bits) + robber(1 bit)
		bool isTileBlocked(uint8_t state) {
			return bool(utils::extractBits(state, 0, 1));
		}
		
		Variant getTileVariant(uint8_t state) {
			return Variant(utils::extractBits(state, 1, 4));
		}

		uint8_t getTileDigit(uint8_t state) {
			return utils::extractBits(state, 4, 8);
		}

		using Location = BoardState::Location;
		std::array<Location, 6> getAdjacentVertices(const Location &loc) {
			auto [q, r] = loc;
			return {
				Location(q+2,r),
				Location(q,r+2),
				Location(q+2,r-2),
				Location(q-2,r),
				Location(q,r-2),
				Location(q-2,r+2),
			};
		}

		std::array<Location, 6> getAdjacentTiles(const Location &loc) {
			auto [q, r] = loc;
			return {
				Location(q+4,r-2),
				Location(q+2,r+2),
				Location(q-2,r-2),
				Location(q+2,r-4),
				Location(q-2,r+4),
				Location(q-4,r+2),
			};
		}
		std::array<Location, 6> getAdjacentEdges(const Location &loc) {
			auto [q, r] = loc;
			return {
				Location(q+2,r-1),
				Location(q+1,r+1),
				Location(q-1,r-1),
				Location(q+1,r-2),
				Location(q-1,r+2),
				Location(q-2,r+1),
			};
		}


	};
};
