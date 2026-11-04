#include <engine.h>
#include <bit_state_management.h>
#include <array>

namespace engine {
	namespace BoardEdge {
		// EDGE = owner(3 bits) + slope(2 bits) + port(3 bits)
		Player getEdgeOwner(uint8_t state) {
			return Player(utils::extractBits(state, 5, 8));
		}

		Slope getEdgeSlope(uint8_t state) {
			return Slope(utils::extractBits(state, 3, 5));
		}

		Port getEdgePort(uint8_t state) {
			return Port(utils::extractBits(state, 0, 3));
		}

		using Location = BoardState::Location;
		std::array<Location, 2> getAdjacentTiles(const Location &loc, Slope slope){	
			const auto [q, r] = loc;

			switch (slope) {
				case Slope::ALONG_Q:
					return {Location(q+1,r-2), Location(q-1,r+2)};
				case Slope::ALONG_R:
					return {Location(q+2,r-1), Location(q-2,r+1)};
				case Slope::ALONG_Q_MINUS_R:
					return {Location(q+1,r+1), Location(q-1,r-1)};
			}

			return {Location(), Location()};
		}

		std::array<Location, 4> getAdjacentEdges(const BoardState::Location &loc, Slope slope) {
			const auto [q, r] = loc;

			switch (slope) {
				case Slope::ALONG_Q:
					return {
						Location(q-1,r-1),
						Location(q+1,r+1),
						Location(q+2,r-1),
						Location(q-2,r+1),
					};
				case Slope::ALONG_R:
					return {
						Location(q-1,r-1),
						Location(q+1,r+1),
						Location(q+1,r-2),
						Location(q-1,r+2),
					};
				case Slope::ALONG_Q_MINUS_R:
					return {
						Location(q+1,r-2),
						Location(q-1,r+2),
						Location(q+2,r-1),
						Location(q-2,r+1),
					};
			}

			return {Location(), Location(), Location(), Location()};
		}

		std::array<Location, 2> getAdjacentVertices(const Location &loc, Slope slope) {
			auto [q, r] = loc;

			switch (slope) {
				case Slope::ALONG_Q:
					return {Location(q+1,r), Location(q-1,r)};
				case Slope::ALONG_R:
					return {Location(q,r+1), Location(q,r-1)};
				case Slope::ALONG_Q_MINUS_R:
					return {Location(q-1,r+1), Location(q+1,r-1)};
			}
			return {Location(), Location()};
		}
	};
};
