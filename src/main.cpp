#include <sil/sil.hpp>

void greenImage(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        color.b = 0.f;
        color.r = 0.f;
    }
    image.save("output/logo-vert.png");
}

void swapRedandBlue(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        std::swap(color.r, color.b);
    }
    image.save("output/logo-swap.png");
}

void blackAndWhite(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        float greyLevel = (color.r + color.g + color.b) / 3;
        //color = greyLevel;
    }
    image.save("output/logo-nb.png");
}

int main()
{
    sil::Image image{"images/logo.png"};
    // greenImage(image);
    //blackAndWhite(image);
    swapRedandBlue(image);
}