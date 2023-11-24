#include <sil/sil.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "random.hpp"
#include <complex>
#include <glm/gtx/matrix_transform_2d.hpp>

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
void rotate90(sil::Image image)
{
    sil::Image newImage{image.height(), image.width()};

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            int newCoordinateX = image.height() - y - 1;
            int newCoordinateY = x;
            newImage.pixel(newCoordinateX, newCoordinateY) = image.pixel(x, y);
        }
    }
    newImage.save("output/logo-rotate90.png");
}

// -------------- Exo 009 --------------
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

            if (x + 10 >= image.width())
                modele.pixel(x, y).b = image.pixel(image.width() - 1, y).b;
            else
                modele.pixel(x, y).b = image.pixel(x + 10, y).b;

            modele.pixel(x, y).g = image.pixel(x, y).g;
        }
    }
    modele.save("output/logo-split.png");
}

// -------------- Exo 010 ** --------------
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
                        std::swap(mosaicResult.pixel(coordX, coordY), mosaic.pixel(mosaic.width() - coordX - 1, coordY));
                    }
                    else if (j % 2 != 0 && i % 2 == 0)
                    {
                        std::swap(mosaic.pixel(coordX, mosaic.height() - coordY - 1), mosaicResult.pixel(coordX, coordY));
                    }
                }
            }
        }
    }
    mosaicResult.save("output/logo-mosaicMirror.png");
}

// -------------- Exo 016 ** --------------*
void glitch(sil::Image image)
{

    int nbGlich = random_int(0, 200);

    for (int k = 0; k < nbGlich; k++)
    {
        int x = random_int(0, image.width());
        int x2 = random_int(0, image.width());
        int y = random_int(0, image.height());
        int y2 = random_int(0, image.height());

        int widthGlitch = random_int(0, 50);
        int heightGlitch = random_int(0, 10);

        for (int i = 0; i < widthGlitch; i++)
        {
            for (int j = 0; j < heightGlitch; j++)
            {
                if (x + i < image.width() && y + j < image.height() && x2 + i < image.width() && y2 + j < image.height())
                    image.pixel(x + i, y + j) = image.pixel(x2 + i, y2 + j);
            }
        }
    }

    image.save("output/logo-glitch.png");
}

// -------------- Exo 017 *** --------------
void mandelbrot(sil::Image disque)
{
    const int max = 25;
    const int width = disque.width();
    const int height = disque.height();
    const float scale = 1.5;
    const float zoom = 0.5;
    const float moveX = 0.0;
    const float moveY = -0.3;
    float white = 0.1;

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)

        {
            std::complex<float> point((x - width / 1.5) / (width / 1.5) * scale - moveX, (y - height / 1.5) / (height / 1.5) * scale - moveY);
            std::complex<float> z(0, 0);
            int nb_iter = 0;
            while (abs(z) < 2 && nb_iter <= max)
            {
                z = z * z + point;
                nb_iter++;
            }
            if (nb_iter < max)
            {
                disque.pixel(x, y) = {0, 0, 0};
            }
            else
            {
                disque.pixel(x, y) = {white, white, white};
                white += 0.0001;
            }
        }
    }
    disque.save("output/mandelbrot.png");
}

// -------------- Exo 018 ***+* --------------
// WORK IN PROGRESS (pas terminé)
glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.f}} + center_of_rotation;
}
void vortex(sil::Image image)
{
    float angle = 0.f;
    float radius = 0.f;
    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            glm::vec2 center = {image.width() / 2.f, image.height() / 2.f};
            glm::vec2 point = {x, y};
            glm::vec2 rotatedPoint = rotated(point, center, angle);
        }
    }

    image.save("output/logo-vortex.png");
}

// -------------- Exo 019 ***+* --------------
void tramage(sil::Image photo)
{
    const int bayer_n = 4;
    float bayer_matrix_4x4[][bayer_n] = {
        {-0.5, 0, -0.375, 0.125},
        {0.25, -0.25, 0.375, -0.125},
        {-0.3125, 0.1875, -0.4375, 0.0625},
        {0.4375, -0.0625, 0.3125, -0.1875},
    };

    for (int x = 0; x < photo.width(); x++)
    {
        for (int y = 0; y < photo.height(); y++)
        {
            float value = bayer_matrix_4x4[y % bayer_n][x % bayer_n];
            if (photo.pixel(x, y).r > value)
            {
                photo.pixel(x, y) = {1, 1, 1};
            }
            else
            {
                photo.pixel(x, y) = {0, 0, 0};
            }
        }
    }
    photo.save("output/photo-tramage.png");
}

// -------------- Exo 020 ***+* --------------
void normalizeHisto(sil::Image image)
{
    glm::vec3 max = {0, 0, 0};
    glm::vec3 min = {1, 1, 1};

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            glm::vec3 color = image.pixel(x, y);
            float moyenne = (color.r + color.g + color.b) / 3;
            float moyenneMin = (min.r + min.g + min.b) / 3;
            float moyenneMax = (max.r + max.g + max.b) / 3;
            if (moyenne < moyenneMin)
            {
                min = color;
            }
            if (moyenne > moyenneMax)
            {
                max = color;
            }
        }
    }

    for (glm::vec3 &color : image.pixels())
    {
        float moyenne = (color.r + color.g + color.b) / 3;
        color = (color - min) / (max - min);
    }

    image.save("output/photo-normalizeHisto.png");
}

// -------------- Exo 021 ***+* --------------
void convolutions(sil::Image image)
{
    sil::Image newImage{image.width(), image.height()};

    float kernelBlur[3][3] = {
        {1.f / 9.f, 1.f / 9.f, 1.f / 9.f},
        {1.f / 9.f, 1.f / 9.f, 1.f / 9.f},
        {1.f / 9.f, 1.f / 9.f, 1.f / 9.f}};

    float kernelBlurGauss[5][5] = {
        {1.f / 256.f, 4.f / 256.f, 6.f / 256.f, 4.f / 256.f, 1.f / 256.f},
        {4.f / 256.f, 16.f / 256.f, 24.f / 256.f, 16.f / 256.f, 4.f / 256.f},
        {6.f / 256.f, 24.f / 256.f, 36.f / 256.f, 24.f / 256.f, 6.f / 256.f},
        {4.f / 256.f, 16.f / 256.f, 24.f / 256.f, 16.f / 256.f, 4.f / 256.f},
        {1.f / 256.f, 4.f / 256.f, 6.f / 256.f, 4.f / 256.f, 1.f / 256.f}};

    // -------------- Exo 022 ***+* --------------
    // 3 kernels for emboss, outline and sharpen
    float kernelEmboss[3][3] = {
        {-2.f, -1.f, 0.f},
        {-1.f, 1.f, 1.f},
        {0.f, 1.f, 2.f}};

    float kernelOutline[3][3] = {
        {-1.f, -1.f, -1.f},
        {-1.f, 8.f, -1.f},
        {-1.f, -1.f, -1.f}};

    float kernelSharpen[3][3] = {
        {0.f, -1.f, 0.f},
        {-1.f, 5.f, -1.f},
        {0.f, -1.f, 0.f}};

    int kernelSizeX = sizeof(kernelBlur) / sizeof(kernelBlur[0]);
    int kernelSizeY = sizeof(kernelBlur[0]) / sizeof(kernelBlur[0][0]);

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            if (x == 0 || y == 0 || x == image.width() - 1 || y == image.height() - 1)
            {
                newImage.pixel(x, y) = image.pixel(x, y);
            }
            else
            {
                for (int i = 0; i < kernelSizeX; i++)
                {
                    for (int j = 0; j < kernelSizeY; j++)
                    {
                        if (x + i - 1 < image.width() && y + j - 1 < image.height() && x + i - 1 >= 0 && y + j - 1 >= 0)
                            newImage.pixel(x, y) += image.pixel(x + i - 1, y + j - 1) * kernelBlur[i][j];
                    }
                }
            }
        }
    }
    newImage.save("output/convolutions/logo-blur.png");
}

// -------------- Exo 024 ***+* --------------
sil::Image contrast(sil::Image photoFaible, float seuil)
{
    for (glm::vec3 &color : photoFaible.pixels())
    {
        float greyLevel = (color.r + color.g + color.b) / 3;
        if (greyLevel < seuil)
        {
            color = {0, 0, 0};
        }
        else
        {
            color = {1, 1, 1};
        }
    }

    return photoFaible;
}
void differencesGauss(sil::Image imageBlur, sil::Image imageBlur2)
{
    sil::Image resultGauss{imageBlur.width(), imageBlur.height()};
    float tau = 5.f;

    for (int x = 0; x < imageBlur.width(); ++x)
    {
        for (int y = 0; y < imageBlur.height(); ++y)
        {
            glm::vec3 pixel1 = imageBlur.pixel(x, y);
            glm::vec3 pixel2 = imageBlur2.pixel(x, y);
            glm::vec3 resultPixel = (1.f + tau) * pixel2 - pixel1 * tau;

            resultGauss.pixel(x, y) = resultPixel;
        }
    }

    resultGauss = contrast(resultGauss, 0.25f);
    resultGauss.save("output/convolutions/diffGauss.png");
}

// -------------- Exo 025 ***** --------------
void triPixel(sil::Image image)
{
    sil::Image sorted{image.width(), image.height()};

    std::vector<glm::vec3> pixels = {};
    std::vector<std::vector<glm::vec3>> sortedPixels = {};

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            pixels.push_back(image.pixel(x, y));
        }
        sortedPixels.push_back(pixels);
        pixels.clear();
    }

    for (int i = 0; i < sortedPixels.size(); i++)
    {
        for (int j = 0; j < sortedPixels[i].size(); j++)
        {
            float brightness = (sortedPixels[i][j].r + sortedPixels[i][j].g + sortedPixels[i][j].b) / 3;
            std::sort(sortedPixels[i].begin(), sortedPixels[i].end(), [brightness](glm::vec3 a, glm::vec3 b)
            { return (a.r + a.g + a.b) / 3 < (b.r + b.g + b.b) / 3; });
        }
    }

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            sorted.pixel(x, y) = sortedPixels[x][y];
        }
    }

    sorted.save("output/triPixel.png");
}

// -------------- Exo 027 ***** --------------
void kmeans(sil::Image image, int k)
{
    // Get image dimensions
    int width = image.width();
    int height = image.height();

    // Initialize centroids
    std::vector<glm::vec3> centroids(k);
    for (int i = 0; i < k; i++)
    {
        centroids[i] = image.pixel(random_int(0, width), random_int(0, height));
    }

    // Iterate until convergence
    bool converged = false;
    while (!converged)
    {
        // Assign pixels to clusters
        std::vector<std::vector<glm::vec3>> clusters(k);
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                glm::vec3 pixel = image.pixel(x, y);
                int closestCentroid = 0;
                float minDistance = glm::distance(pixel, centroids[0]);
                for (int i = 1; i < k; i++)
                {
                    float distance = glm::distance(pixel, centroids[i]);
                    if (distance < minDistance)
                    {
                        closestCentroid = i;
                        minDistance = distance;
                    }
                }
                clusters[closestCentroid].push_back(pixel);
            }
        }

        // Update centroids
        converged = true;
        for (int i = 0; i < k; i++)
        {
            glm::vec3 sum(0.f);
            for (const glm::vec3 &pixel : clusters[i])
            {
                sum += pixel;
            }
            glm::vec3 newCentroid = sum / static_cast<float>(clusters[i].size());
            if (newCentroid != centroids[i])
            {
                centroids[i] = newCentroid;
                converged = false;
            }
        }
    }

    // Assign new colors to pixels
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            glm::vec3 pixel = image.pixel(x, y);
            int closestCentroid = 0;
            float minDistance = glm::distance(pixel, centroids[0]);
            for (int i = 1; i < k; i++)
            {
                float distance = glm::distance(pixel, centroids[i]);
                if (distance < minDistance)
                {
                    closestCentroid = i;
                    minDistance = distance;
                }
            }
            image.pixel(x, y) = centroids[closestCentroid];
        }
    }

    image.save("output/photo-kmeans.png");
}

// ==== MAIN ====
int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image photo{"images/photo.jpg"};
    sil::Image photoFaible{"images/photo_faible_contraste.jpg"};
    sil::Image photoBlurV1{"output/convolutions/photo-kernel5.png"};
    sil::Image photoBlurV2{"output/convolutions/photo-blur1.png"};
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
    // rotate90(image);
    // rgbSplit(image);
    // createDisc(disque, 130);
    // createCircle(disque, 130, 5);
    // rosace(disque, 100, 6);
    // mosaic(image, 5);
    // tramage(photo);
    // normalizeHisto(photoFaible);
    // mosaicMirror(mosaic(image, 5), 5); PERFECTIBLE
    // glitch(image);
    // mandelbrot(disque); // PERFECTIBLE
    // vortex(image); WORK IN PROGRESS
    // convolutions(image);
    // differencesGauss(photoBlurV1, photoBlurV2);
    // kmeans(photo, 2); // could be 2, 3, or 16
    triPixel(image);
}