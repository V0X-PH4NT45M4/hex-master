#include <engine.h>
#include <bit_state_management.h>
#include <array>

namespace engine {
	namespace BoardVertex {
		bool getVertexChirality(uint8_t state) {
			return bool(utils::extractBits(state, 0, 1));
		}

		Port getVertexPort(uint8_t state) {
			return Port(utils::extractBits(state, 1, 4));
		}

		Building getVertexBuilding(uint8_t state) {
			return Building(utils::extractBits(state, 4, 5));
		}

		Player getVertexOwner(uint8_t state) {
			return Player(utils::extractBits(state, 5, 8));
		}

		using Location = BoardState::Location;
		std::array<Location, 3> getAdjacentEdges(const Location &loc, bool chirality) {
			auto [q, r] = loc;
			if (chirality) {
				return {Location(q+1,r), Location(q,r-1), Location(q-1,r+1)};
			}

			return {Location(q-1,r), Location(q,r+1), Location(q+1,r-1)};
		}

		std::array<Location, 3> getAdjacentTiles(const Location &loc, bool chirality) {
			auto [q, r] = loc;
			if (!chirality) {
				return {Location(q+1,r), Location(q,r-1), Location(q+1,r-1)};
			}

			return {Location(q-1,r), Location(q,r+1), Location(q+1,r-1)};
		}

		std::array<Location, 3> getAdjacentVertices(const Location &loc, bool chirality) {
			auto [q, r] = loc;
			if (chirality) {
				return {LOcation(q+2,r), Location(q,r-2), Location(q+2,r-2)};
			}

			return {Location(q-2,r), Location(q,r+2), Location(q+2,r-2)};
		}
	};
};
