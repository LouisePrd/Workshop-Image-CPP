#include <sil/sil.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "random.hpp"

// -------------- Exo 001 * --------------
void greenImage(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        color.b = 0.f;
        color.r = 0.f;
    }
    image.save("output/logo-vert.png");
}

// -------------- Exo 002 * --------------
void swapRedandBlue(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        std::swap(color.r, color.b);
    }
    image.save("output/logo-swap.png");
}

// -------------- Exo 003 * --------------
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

// -------------- Exo 004 * --------------
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

// -------------- Exo 005 * --------------
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

// -------------- Exo 006 ** --------------
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

// -------------- Exo 007 ** --------------
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

// -------------- Exo 008 --------------
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

// -------------- Exo 009 ** --------------
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

// -------------- Exo 011 ** --------------
void createDisc(sil::Image disque, int r)
{
    int x0 = disque.width() / 2;
    int y0 = disque.height() / 2;
    for (int x = 0; x < disque.width(); x++)
    {
        for (int y = 0; y < disque.height(); y++)
        {
            int dx = x - x0;
            int dy = y - y0;
            if (dx * dx + dy * dy <= r * r)
            {
                disque.pixel(x, y) = {1, 1, 1};
            }
        }
    }
    disque.save("output/disque.png");
}

// -------------- Exo 012 * --------------
sil::Image createCircle(sil::Image disque, int x0, int y0, int r, int thickness)
{
    // int x0 = disque.width() / 2;
    // int y0 = disque.height() / 2;

    for (int x = 0; x < disque.width(); x++)
    {
        for (int y = 0; y < disque.height(); y++)
        {
            int dx = x - x0;
            int dy = y - y0;
            if (dx * dx + dy * dy <= (r + thickness) * (r + thickness) && dx * dx + dy * dy >= (r - thickness) * (r - thickness))
            {
                disque.pixel(x, y) = {1, 1, 1};
            }
        }
    }
    // --- if you want to draw a single circle :
    // disque.save("output/disque.png");
    return disque;
}

// -------------- Exo 013 *** --------------
void rosace(sil::Image disque, int r, int n)
{
    int x0 = disque.width() / 2;
    int y0 = disque.height() / 2;
    for (int i = 0; i < n; i++)
    {
        float angle = 2 * M_PI * i / n;
        int x = x0 + r * cos(angle);
        int y = y0 + r * sin(angle);
        disque = createCircle(disque, x, y, 130, 3);
    }
    disque.save("output/rosace.png");
}

// -------------- Exo 014 *** --------------
sil::Image mosaic(sil::Image modele, int value)
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
    return mosaicResult;
    return mosaicResult;
}

// -------------- Exo 015 ** --------------*
void mosaicMirror(sil::Image mosaic, int nbMosaic)
{
    sil::Image mosaicResult{mosaic.width(), mosaic.height()};
    int sizeW = mosaic.width() / nbMosaic;
    int sizeH = mosaic.height() / nbMosaic;

    for (int i = 0; i < nbMosaic; i++)
    {
        for (int j = 0; j < nbMosaic; j++)
        {
            for (int x = 0; x < sizeW; x++)
            {
                for (int y = 0; y < sizeH; y++)
                {
                    int coordX = x + (i * sizeW);
                    int coordY = y + (j * sizeH);

                    if (j % 2 != 0)
                    {
                        mosaicResult.pixel(coordX, coordY) = mosaic.pixel(sizeW - x - 1, sizeH - y - 1);
                        if (i % 2 == 0)
                        {
                            mosaicResult.pixel(coordX, coordY) = mosaic.pixel(sizeW - x - 1, sizeH - y - 1);
                        }
                    }
                    else
                        mosaicResult.pixel(coordX, coordY) = mosaic.pixel(coordX, coordY);

                    if (j % 2 == 0 && i % 2 != 0)
                    {
                        std::swap(mosaicResult.pixel(coordX, coordY), mosaic.pixel((mosaic.width() - 1) - coordX, coordY));
                    }
                    else if (j % 2 != 0 && i % 2 == 0)
                    {
                        std::swap(mosaic.pixel(coordX, (mosaic.height() - 1) - coordY), mosaicResult.pixel(coordX, coordY));
                    }
                }
            }
        }
    }
    mosaicResult.save("output/logo-mosaicMirror2.png");
}

// -------------- Exo 019 ***+* --------------
void trimage(sil::Image image)
{
const int bayer_n = 6;
float bayer_matrix_4x4[][bayer_n] = {
    {    -0.5,       0,  -0.375,   0.125 },
    {    0.25,   -0.25,   0.375, - 0.125 },
    { -0.3125,  0.1875, -0.4375,  0.0625 },
    {  0.4375, -0.0625,  0.3125, -0.1875 },
};

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            float value = bayer_matrix_4x4[y % bayer_n][x % bayer_n];
            if (image.pixel(x, y).r > value)
            {
                image.pixel(x, y) = {1, 1, 1};
            }
            else
            {
                image.pixel(x, y) = {0, 0, 0};
            }
        }
    }
    image.save("output/logo-trimage.png");
}

// ==== MAIN ====
int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image imageNoire{300, 200};
    sil::Image image90deg{345, 300};
    sil::Image disque{500, 500};
    // greenImage(image);
    // swapRedandBlue(image);
    // blackAndWhite(image);
    // negativeImage(image);
    // mirrorImage(image);
    // gradient(imageNoire);
    // imageBruitee(image);
    // imageLuminosity(image);
    // rgbSplit(image);
    // createDisc(disque, 130);
    // createCircle(disque, 130, 5);
    rosace(disque, 100, 6);
    // mosaic(image, 5);
    // trimage(image);
    // mosaicMirror(mosaic(image, 5), 5);
}