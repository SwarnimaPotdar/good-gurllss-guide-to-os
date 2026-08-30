#include <stdint.h>

__attribute__((used, section(".limine_requests_start")))
static volatile uint64_t limine_requests_start_marker[] = {
    0xc7b1dd30df4c8b88,
    0x0a82e883a9d0f3c9
};

__attribute__((used, section(".limine_requests_end")))
static volatile uint64_t limine_requests_end_marker[] = {
    0x0
};