#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <limine.h>

__attribute__((used, section(".limine_requests_start")))
static volatile uint64_t limine_requests_start_marker[] =
    LIMINE_REQUESTS_START_MARKER;

__attribute__((used, section(".limine_requests")))
static volatile uint64_t limine_base_revision[] =
    LIMINE_BASE_REVISION(3);

__attribute__((used, section(".limine_requests")))
static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST_ID,
    .revision = 0
};

__attribute__((used, section(".limine_requests_end")))
static volatile uint64_t limine_requests_end_marker[] =
    LIMINE_REQUESTS_END_MARKER;


static void halt(void)
{
    for (;;)
    {
        __asm__ volatile ("hlt");
    }
}


void kernel_main(void)
{
    if (!LIMINE_BASE_REVISION_SUPPORTED(limine_base_revision))
    {
        halt();
    }

    struct limine_framebuffer_response *framebuffer_response =
        framebuffer_request.response;

    if (framebuffer_response == NULL ||
        framebuffer_response->framebuffer_count == 0)
    {
        halt();
    }

    struct limine_framebuffer *framebuffer =
        framebuffer_response->framebuffers[0];

    if (framebuffer->bpp != 32)
    {
        halt();
    }

    volatile uint32_t *pixels =
        (volatile uint32_t *)framebuffer->address;

    uint64_t width = framebuffer->width;
    uint64_t height = framebuffer->height;
    uint64_t pitch = framebuffer->pitch / sizeof(uint32_t);

    /*
     * Barbie pink 🎀
     *
     * RGB: #FF69B4
     */
    uint32_t pink = 0x00FF69B4;

    for (uint64_t y = 0; y < height; y++)
    {
        for (uint64_t x = 0; x < width; x++)
        {
            pixels[y * pitch + x] = pink;
        }
    }

    halt();
}