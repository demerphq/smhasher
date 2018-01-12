#ifndef HIGHWAY_TEST_H
#define HIGHWAY_TEST_H

#ifdef __cplusplus  
extern "C" {
#endif

void highwayhash_seed_state_smhasher_test(int in_bits, const void *seed, void *state) ;

void highwayhash_hash_with_state_smhasher_test(const void *key, int len, const void *state, void *out);

void highwayhash64_test(const void *key, int len, const void *state, void *out);

#ifdef __cplusplus  
}  
#endif
#endif
