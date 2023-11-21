#include <sil/sil.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "random.hpp"

// Exo 001 *
void greenImage(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        color.b = 0.f;
        color.r = 0.f;
    }
    image.save("output/logo-vert.png");
}

// Exo 002 *
void swapRedandBlue(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        std::swap(color.r, color.b);
    }
    image.save("output/logo-swap.png");
}

// Exo 003 *
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

// Exo 004 *
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

// Exo 005 *
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

// Exo 006 **
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

// Exo 007 **
void imageBruitee(sil::Image image)
{
    int size = (image.width() * image.height()) / 2;
    for (int i = 0; i <= size; i++)
    {
        int x = random_int(0, image.width());
        int y = random_int(0, image.height());
        image.pixel(x, y) = image.pixel(random_int(0, image.width()), random_int(0, image.height()));
    }
    image.save("output/logo-bruit.png");
}

// Exo 008
void rgbSplit(sil::Image image)
{
    sil::Image modele{image.width(), image.height()};

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            if (x < 20)
                modele.pixel(x, y).r = image.pixel(0, y).r;
            else
                modele.pixel(x, y).r = image.pixel(x - 20, y).r;

            if (x + 20 >= image.width())
                modele.pixel(x, y).b = image.pixel(image.width() - 1, y).b;
            else
                modele.pixel(x, y).b = image.pixel(x + 20, y).b;

            modele.pixel(x, y).g = image.pixel(x, y).g;
        }
    }
    modele.save("output/logo-split.png");
}

// Exo 009 **
void imageLuminosity(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        color.r = color.r * 1.5f;
        color.g = color.g * 1.5f;
        color.b = color.b * 1.5f;
    }
    image.save("output/logo-luminosity.png");
}

// Exo 014 **
void mosaic(sil::Image modele, int value)
{
    int height = modele.height();
    int width = modele.width();
    sil::Image mosaicResult{width, height};

    for (int i = 0; i < value; i++)
    {
        for (int j = 0; j < value; j++)
        {
            for (int x = 0; x < mosaicResult.width() / value; x++)
            {
                for (int y = 0; y < mosaicResult.height() / value; y++)
                {
                    int x2 = value * x;
                    int y2 = value * y;
                    mosaicResult.pixel(x + (i * mosaicResult.width() / value), y + (j * mosaicResult.height() / value)) = (modele.pixel(x2, y2) + modele.pixel(x2 + 1, y2 + 1) + modele.pixel(x2 + 1, y2) + modele.pixel(x2, y2 + 1)) / 4.f;
                }
            }
        }
    }

    mosaicResult.save("output/logo-mosaic.png");
}

// Exo 015 **
void mosaicMirror(sil::Image modele, int value)
{
    sil::Image mosaicResult{modele.height(), modele.height()};
}

// ==== MAIN ====
int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image imageNoire{300, 200};
    sil::Image image90deg{345, 300};
    // greenImage(image);
    // swapRedandBlue(image);
    // blackAndWhite(image);
    // egativeImage(image);
    // mirrorImage(image);
    // gradient(imageNoire);
    // imageBruitee(image);
    // imageLuminosity(image);
    // rgbSplit(image);
    mosaic(image, 5);
}