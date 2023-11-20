#include <sil/sil.hpp>

void greenImage()
{
}

int main()
{
    sil::Image image{"images/logo.png"};

    for (glm::vec3 &color : image.pixels())
    {
        color.b = 0.f;
        color.r = 0.f;
    }

    image.save("output/logo-vert.png");
}