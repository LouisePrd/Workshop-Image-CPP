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

int main()
{
    sil::Image image{"images/logo.png"};
    greenImage(image);
}