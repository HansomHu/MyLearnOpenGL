#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image/stb_image_write.h>
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include <stb_image/stb_image_resize.h>

int main(int argc, char** argv) {
    const std::string inputPath = "../../data/awesomeface.png";
    int iw, ih, n;
    
    unsigned char *idata = stbi_load(inputPath.c_str(), &iw, &ih, &n, 0);
    std::cout << "input image: w x h x n: " << iw << " x " << ih << " x " << n << std::endl;

    int ow = iw / 2;
    int oh = ih / 2;
    auto *odata = (unsigned char *) malloc(ow * oh * n);

    // this function call doesn't work as you expected, I haven't figured out why...
    stbir_resize(idata, iw, ih, 0, odata, ow, oh, 0, STBIR_TYPE_UINT8, n, STBIR_ALPHA_CHANNEL_NONE, 0,
                 STBIR_EDGE_CLAMP, STBIR_EDGE_CLAMP,
                 STBIR_FILTER_BOX, STBIR_FILTER_BOX,
                 STBIR_COLORSPACE_SRGB, nullptr);

    std::string outputPath = "awesomeface_resize.png";
    stbi_write_png(outputPath.c_str(), ow, oh, n, idata, 0);

    stbi_image_free(idata);
    stbi_image_free(odata);
    return 0;
}