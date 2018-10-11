#include <stdlib.h>
#include "../highwayhash/highwayhash/c_bindings.h"

void highwayhash_seed_state_smhasher_test(int in_bits, const void *seed, void *state) {
	// TODO: Wasn't sure what to do here, nothing seems to be necessary.
}

void highwayhash_hash_with_state_smhasher_test(const void *key, int len, const void *state, void *out) {
	uint8_t *k = (uint8_t*)key;
	uint64_t * st = (uint64_t*)state;
	size_t l = len;
	*(uint64_t*)out = (uint64_t)HighwayHash64(st, k, l);
}

void highwayhash64_test(const void *key, int len, const void *state, void *out) {
	highwayhash_hash_with_state_smhasher_test(key, len, state, out);
}

/*

// TODO: Finish this when the tests are done in Google's version.
void highwayhash128_hash_with_state_smhasher_test(const void *key, int len, const void *state, void *out) {
	uint8_t *k = (uint8_t*)key;
	uint64_t * st = (uint64_t*)state;
	size_t l = len;
	*(uint64_t*)out = (uint64_t)HighwayHash128(st, k, l);
}

void highwayhash256_hash_with_state_smhasher_test(const void *key, int len, const void *state, void *out) {
	uint8_t *k = (uint8_t*)key;
	uint64_t * st = (uint64_t*)state;
	size_t l = len;
	*(uint64_t*)out = (uint64_t)HighwayHash128(st, k, l);
}


void highwayhash128_test(const void *key, int len, const void *state, void *out) {
	highwayhash128_hash_with_state_smhasher_test(key, len, state, out);
}
void highwayhash256_test(const void *key, int len, const void *state, void *out) {
	highwayhash64_hash_with_state_smhasher_test(key, len, state, out);
}
*/
