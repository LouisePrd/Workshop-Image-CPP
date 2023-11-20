#include <sil/sil.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "random.hpp"

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

void gradient(sil::Image &image)
{
    for (int x = 0; x < image.width(); x++)

    {
        for (int y = 0; y < image.height(); y++)

        {
            float value = static_cast<float>(x) / static_cast<float>(image.width());
            image.pixel(x, y) = glm::vec3(value);
        }
    }
    image.save("output/logo-gradient.png");
}

void imageBruitee(sil::Image image)
{
    int size = (image.width()*image.height()) / 2;
    for (int i = 0; i <= size; i++)
    {
        int x = random_int(0, image.width());
        int y = random_int(0, image.height());
        image.pixel(x, y) = image.pixel(random_int(0, image.width()), random_int(0, image.height()));
    }
    image.save("output/logo-bruit.png");
}


int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image imageNoire{300, 200};
    // greenImage(image);
    // swapRedandBlue(image);
    // blackAndWhite(image);
    // egativeImage(image);
    // mirrorImage(image);
    // gradient(imageNoire);
    imageBruitee(image);
}