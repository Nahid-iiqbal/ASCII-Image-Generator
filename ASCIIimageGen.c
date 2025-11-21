#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb/stb_image_resize2.h"

const char ASCII_CHARS[] = " `^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
const int CHAR_LEN = 66;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <image> [-w <width>]\n", argv[0]);
        return 1;
    }

    // initiating image path from command line argument
    int width, height, pixel_size;
    unsigned char *img = stbi_load(argv[1], &width, &height, &pixel_size, 0);

    if (img == NULL)
    {
        fprintf(stderr, "Error in loading the image\n");
        return 1;
    }

    // adjusting width and height based on aspect ratio
    int new_width = width, new_height = height;
    if (argc > 3 && strcmp(argv[2], "-w") == 0)
    {
        new_width = atoi(argv[3]);
    }
    else
    {
        new_width = width;
    }
    float aspect_ratio = (float)height / (float)width;
    new_height = (int)(new_width * aspect_ratio * 0.55);

    // // compressing image according to new width and height
    unsigned char *resized_img = (unsigned char *)malloc(new_width * new_height * pixel_size);
    if (resized_img == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        stbi_image_free(img);
        return 1;
    }

    stbir_resize_uint8_linear(img, width, height, 0,
                              resized_img, new_width, new_height, 0,
                              pixel_size);

    // printing ASCII characters based on pixel brightness

    unsigned char *ptr = resized_img;
    for (int row_index = 0; row_index < new_height; row_index++)
    {
        for (int col_index = 0; col_index < new_width; col_index++)
        {
            unsigned char r, g, b;
            r = *ptr++;
            g = *ptr++;
            b = *ptr++;
            if (pixel_size >= 4)
                ptr++;
            float gray = (r + g + b) / 3.0f;
            int char_index = (int)(CHAR_LEN * (gray / 255.0f));
            putchar(ASCII_CHARS[char_index]);
        }
        putchar('\n');
    }
    stbi_image_free(img);
    free(resized_img);
    return 0;
}
