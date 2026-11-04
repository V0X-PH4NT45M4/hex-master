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

		using Position = BoardState::Location;
		std::array<Position, 2> getAdjacentTiles(const Position &loc, const BoardState &boardState){	
			Slope slope = getEdgeSlope(boardState.currentState(loc));
			const auto [q, r] = loc;

			switch (slope) {
				case Slope::ALONG_Q:
					return {Position(q+1,r-2),Position(q-1,r+2)};
				case Slope::ALONG_R:
					return {Position(q+2,r-1),Position(q-2,r+1)};
				case Slope::ALONG_Q_MINUS_R:
					return {Position(q+1,r+1),Position(q-1,r-1)};
			}

			return {Position(),Position()};
		}

		std::array<Position, 4> getAdjacentEdges(const BoardState::Location &loc, const BoardState &boardState) {
			Slope slope = getEdgeSlope(boardState.currentState(loc));
			const auto [q, r] = loc;

			switch (slope) {
				case Slope::ALONG_Q:
					return {
						Position(q-1,r-1),
						Position(q+1,r+1),
						Position(q+2,r-1),
						Position(q-2,r+1),
					};
				case Slope::ALONG_R:
					return {
						Position(q-1,r-1),
						Position(q+1,r+1),
						Position(q+1,r-2),
						Position(q-1,r+2),
					};
				case Slope::ALONG_Q_MINUS_R:
					return {
						Position(q+1,r-2),
						Position(q-1,r+2),
						Position(q+2,r-1),
						Position(q-2,r+1),
					};
			}

			return {Position(), Position(), Position(), Position()};
		}

		std::array<Position, 2> getAdjacentVertices(const Position &loc, const BoardState &boardState) {
			Slope slope = getEdgeSlope(boardState.currentState(loc));
			auto [q, r] = loc;

			switch (slope) {
				case Slope::ALONG_Q:
					return {Position(q+1,r), Position(q-1,r)};
				case Slope::ALONG_R:
					return {Position(q,r+1), Position(q,r-1)};
				case Slope::ALONG_Q_MINUS_R:
					return {Position(q-1,r+1), Position(q+1,r-1)};
			}
			return {Position(), Position()};
		}
	};
};
