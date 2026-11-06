#include <engine.h>
#include <array>

namespace engine {
	using Marker = BoardState::Marker;
	const Marker BoardState::renderLayout(Location loc){
		return Marker::SENTINEL;
	};
};
