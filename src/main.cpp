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
        glm::vec3 newcolor(greyLevel);
        color = newcolor;
    }
    image.save("output/logo-nb.png");
}

void negativeImage(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        color.r = 1.f - color.r;
        color.g = 1.f - color.g;
        color.b = 1.f - color.b;
    }
    image.save("output/logo-neg.png");
}

void mirrorImage(sil::Image image)
{
    for (int i = 0; i < image.height(); i++)
    {
        for (int j = 0; j < image.width() / 2; j++)
        {
            glm::vec3 &color1 = image.pixel(j, i);
            glm::vec3 &color2 = image.pixel(image.width() - j - 1, i);
            std::swap(color1, color2);
        }
    }
    image.save("output/logo-mirror.png");
}

int main()
{
    sil::Image image{"images/logo.png"};
    // greenImage(image);
    //swapRedandBlue(image);
    // blackAndWhite(image);
    // negativeImage(image);
    // mirrorImage(image);
}