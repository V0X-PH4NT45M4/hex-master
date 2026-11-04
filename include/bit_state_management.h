#pragma once
#include <cstdint>

namespace utils {
	// extract [start, end) bits (from LSB -> MSB) from the state
	uint8_t extractBits(uint8_t state, uint8_t start, uint8_t end);
};
