#include <bit_state_management.h>
#include <cstdint>
#include <limits.h>

namespace utils {
	uint8_t extractBits(uint8_t state, uint8_t start, uint8_t end) {
		// we need to extract [start, end) bits
		// if state = 0b11001010
		// extractBits(state, 0, 8) = state
		// extractBits(state, 2, 5) = 0b (110 | 010 | 10) = 0b010
		
		// step 1: remove LSBs until start
		state >>= start;

		// step 2: generate mask to extract (end - start) LSB
		uint8_t mask = (1 << (end - start)) - 1;

		// step 3: return masked result
		return state & mask;
	}
};
