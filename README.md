# Workshop - Image Manipulation
Workshop de : [Jules Fouchy](https://github.com/JulesFouchy) <br>
Une semaine de workshop en binôme pour apprendre à coder des effets sur des images et première introduction à certains concepts de synthèse d'image.<br>
👉 [Consignes & Exercices](https://dsmte.github.io/Learn--cpp_programming/Workshop)

## Attendus

Liste d'exercices, plus ou moins difficiles et le but est d'en faire le maximum. 
- Mini-soutenance optionnelle (exercice de vulgarisation) et mini-rapport à rendre
- Le rendu se fera par groupes de 2

## Sommaire
✨ [Filtres](https://github.com/AM-XIX/workshop-image-manipulation/blob/main/README.md#filtres)<br>
✨ [Effets Customs](https://github.com/AM-XIX/workshop-image-manipulation/blob/main/README.md#effets-customs)
<br><br>
# Filtres
> [!NOTE]
> Le nombre d'émoji indique la complexité du filtre, allant de 1 à 6.

## 001 - Ne garder que le vert 🥑
Retire le bleu et le rouge de chaque couleur présente sur l'image.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/cb5763a9-eb28-4450-9cf0-84705c4efc08" style="width:200px">

**Code**
```c++
for (glm::vec3 &color : image.pixels())
{
    color.b = 0.f;
    color.r = 0.f;
}
```

## 002 - Échanger les canaux 🥑
Échange les valeurs de bleu et les valeurs de rouge de l'image grâce à la fonction swap.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/950f26f5-8b92-4e97-9292-fe73c00686d6" style="width:200px">

**Code**
```c++
for (glm::vec3 &color : image.pixels())
{
    std::swap(color.r, color.b);
}
```

## 003 - Noir & Blanc 🥑
Transforme les couleurs en nuances de gris.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/bc3f0fb1-cec1-42a9-ab86-4c72052d43a9" style="width:200px">

**Code**
```c++
for (glm::vec3 &color : image.pixels())
{
    float greyLevel = (color.r + color.g + color.b) / 3;
    glm::vec3 newcolor(greyLevel);
    color = newcolor;
}
```

## 004 - Négatif 🥑
Inverse les valeurs des couleurs.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/37ddfc6c-21c6-4be7-9ce1-1a99746f7fb0" style="width:200px">

**Code**
```c++
for (glm::vec3 &color : image.pixels())
{
    color.r = 1.f - color.r;
    color.g = 1.f - color.g;
    color.b = 1.f - color.b;
}
```

## 005 - Dégradé 🥑
Crée un dégradé de noir à blanc sur une image vide.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/3d7a6a69-0cf9-4caa-a1ea-928bdfed2a0d" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/2ba19127-9cb2-453b-8a9f-e4f2227c4ebc" style="width:200px">

**Code**
```c++
for (int x = 0; x < image.width(); x++)
{
    for (int y = 0; y < image.height(); y++)
    {
        float value = static_cast<float>(x) / static_cast<float>(image.width());
        image.pixel(x, y) = glm::vec3(value);
    }
}
```

## 006 - Miroir 🥑🥑
Inverse les pixels de l'image.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/6d71067b-d5ef-449c-b721-228f2b52271a" style="width:200px">
<br><br>
## 007 - Image bruitée 🥑🥑
Crée du bruit aléatoire sur l'image.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/ea7f77c0-1e66-44d7-a005-7b80da8f1360" style="width:200px">

> [!NOTE]
> Cette fonction nous a permis d'appréhender la notion de <b>random</b> donc nous avons dû lire la documentation pour bien la maitriser et ainsi bruiter l'image. Il ne fallait pas bruiter chaque pixel donc il a fallu définir un nombre de pixel à modifier, ici on a choisi de prendre la moitié des pixels.<br>

> [!TIP]
> <b>Importer</b>
```#include "random.hpp"```

## 008 - Rotation de 90° 🥑🥑
Réecrit les pixels de l'image comme s'ils subissaient une rotation à 90° sur une nouvelle image au correct format.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/708fd598-f43f-4452-b847-e01be4b18641" style="height:200px">

> [!NOTE]
> Cette modification d'image semble simple en théorie mais on a tatonné avant d'y parvenir. En effet, au départ nous pensions juste que les x devenaient des y et vice versa mais ce n'était pas le cas, pour la réussir nous avons dû dessiner plusieurs exemples sur **papier** et cela nous a beaucoup aidées à visualiser les changements à opérer.

## 009 - RGB Split 🥑🥑
Modifie chaque pixel de sorte qu'il prenne le rouge du pixel à sa droite, garde son propre vert, et prenne le bleu du pixel à sa gauche.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/ebcf971c-bcea-49bd-b5be-876bfe1d6826" style="width:200px">
<br><br>
## 010 - Luminosité 🥑🥑
Augmente la luminosité de l'image.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/f020e48f-3b44-4492-bbfe-fe51211c7b5b" style="width:300px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/351e1d51-6bef-4616-879b-d8acf2ffc5a6" style="width:300px">

> [!NOTE]
> Nous avons choisi de multiplier chaque valeur de couleur par 1.5. Une autre méthode utilisable est d'utiliser les puissances grâce à la fonction ```pow()```

## 011 - Disque 🥑🥑
Crée d'un disque blanc sur fond noir.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/af84390d-0a96-4470-a0d6-bee282559599" style="width:300px">
> [!TIP]
> 1) Enregistrer les coordonnées du centre de l'image.
> 2) Tracer un cercle d'un rayon r en entrée.
> 3) Consulter chaque pixel de l'image. S'il se trouve dans la zone du cercle, le peindre en blanc.

## 012 - Cercle 🥑🥑
Créé un cercle blanc sur fond noir<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6dcdaf4-e9f4-43ff-b209-61ffed38902d" style="width:300px">
> [!NOTE]
> Nous avons répété l'opération de l'exercice 012 en ne peignant en blanc que le périmètre du cercle, dont l'épaisseur est définie par une nouvelle variable en entrée : `thickness`

> [!TIP]
> Faire de la fonction `createCircle()` une fonction **réutilisable** plusieurs fois sur la même image. Ce sera très important pour notre exercice 013 👇

## 013 - Rosace 🥑🥑🥑
Crée une succession de cercles formant une rosace.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/867ca484-2b49-40f4-a036-b98a561b2f2a" style="width:300px">
> [!NOTE]
> Nous avons fait appel à `M_PI` pour calculer l'angle de chaque cercle puis les fonctions `cos(angle)` et `sin(angle)` pour en stocker les position x et y. Notre fonction prend trois variable en entrée : l'image, le rayon r commun à tous les cercles, et le nombre n de cercles _(sur l'exemple, 6 cercles sont tracés)._

```c++
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
```

## 014 - Mosaïque 🥑🥑
Crée la mosaïque de l'image.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/5d6d2c23-811c-4fde-809a-4b00fae0dddf" style="width:200px">
> [!NOTE]
> Pour créer cette mosaïque, il fallait parcourir tous les pixels puis **séparer l'image finale** en fonction du nombre choisi. Au départ, c'était assez facile mais la difficulté a augmenté au fur et à mesure des boucles car il fallait raisonner à la fois en global et en spécifique pour chaque image. On s'est perdues plusieurs fois mais en posant à plat nos idées, on a pu avoir plus de recul et réussir à produire le résultat final.

## 015 - Mosaïque miroir 🥑🥑🥑
Inverse une image sur deux sur le résultat de la mosaïque.<br><br>
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/5d6d2c23-811c-4fde-809a-4b00fae0dddf" style="width:200px">
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/3ffc6596-fd15-427e-88c2-be1692505daf" style="width:200px">

## 016 - Glitch 🥑🥑🥑
Ajoute du glitch sur l'image de manière random.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/31482a8c-8e4b-4cf5-a7e2-290ffb6b8015" style="width:200px">
> [!NOTE]
> Pour cet effet, la fonction `random_int();` a été utilisée plusieurs fois pour produire un glitch le plus aléatoire possible : à la fois pour le nombre de glitch, pour les coordonnées des pixels qu'on modifie mais aussi pour la taille et la hauteur de chaque glitch.

## 017 - Fractale de Mandelbrot 🥑🥑🥑
Génère une fractale de Mandelbrot, un concept mathématique découvert par Gaston Julia et Pierre Fatou.<br><br>
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/50ffee54-c054-4ed5-bee8-9281f1c30fcf" style="width:300px">
> [!NOTE]
> Pour générer une fractale, nous nous servons de 2 nombres complexes : `c` et `z`. c réfère à la position d'un pixel) et z à notre point de départ que l'on itère en `z = z * z + c` jusqu'à ce que `std::abs(z) > 2`. Nous pouvons ensuite préciser la fractale avec de nombreux paramètres.

**Exemple de paramètres :**
```c++
const int max = 25;
const int width = disque.width();
const int height = disque.height();
const float scale = 1.5;
const float zoom = 0.5;
const float moveX = 0.0;
const float moveY = -0.3;
float white = 0.1;
```
> [!TIP]
> <b>Importer</b>
`#include <complex>`

## 018 - Vortex 🥑🥑🥑(🥑)
<i>Pas terminée</i>

## 019 - Tramage 🥑🥑🥑(🥑)
Génère un tramage de la photo.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/f020e48f-3b44-4492-bbfe-fe51211c7b5b" style="width:300px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/ad790dd8-f065-44cc-9607-53beabf6f4c7" style="width:300px">

> [!NOTE]
> Nous avons tramé cette photo grâce à une **matrice Bayer** de niveau 1 (4x4). La Bayer ne détecte que la luminosité des pixels, ce qui rendra l'image tramée bien plus lumineuse que son original.

**Matrice Bayer 4x4**
```c++
const int bayer_n = 4;
float bayer_matrix_4x4[][bayer_n] = {
    {-0.5, 0, -0.375, 0.125},
    {0.25, -0.25, 0.375, -0.125},
    {-0.3125, 0.1875, -0.4375, 0.0625},
    {0.4375, -0.0625, 0.3125, -0.1875},
};
```
> [!TIP]
> <b>Importer</b>
`#include <glm/gtx/matrix_transform_2d.hpp>`

## 020 - Normalisation de l'histogramme 🥑🥑🥑(🥑)
Modifie chaque pixel en fonction du pixel le plus lumineux de l'image et le moins lumineux, améliore le contratse d'une image.<br><br>
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/563e9d62-caa8-482a-afd2-afb6a377f47a" style="width:200px">
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/e671d759-0058-4988-bc30-167e9c956968" style="width:200px">
<br><br>
## 021 - Convolutions 🥑🥑🥑🥑
Transforme l'image en lui appliquant une convolution, c'est-à-dire une opération qui va ajouter un effet sur l'image en fonction d'un kernel donné.<br><br>
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/79d4f2e4-5b22-4046-a1e1-e8cda6b8e5ed" style="width:200px">
> [!NOTE]
> La difficulté de l'exercice a résidé dans la compréhension du fonctionnement du kernel car il y avait de nombreuses erreurs (dépassement de l'image, pixels en double etc.) donc il a fallu se replonger dans les matrices. Finalement, après avoir fait en sorte que cela marche pour 1 matrice de 3 par 3, il y a eu de nombreuses itérations pour adapter le code à toutes les tailles.

**Kernel en 3x3**
```c++
float kernelBlur[3][3] = {
    {1.f / 9.f, 1.f / 9.f, 1.f / 9.f},
    {1.f / 9.f, 1.f / 9.f, 1.f / 9.f},
    {1.f / 9.f, 1.f / 9.f, 1.f / 9.f}};
```

## 022 - Netteté, Contours, etc. 🥑
Applique différents kernels pour avoir plusieurs effets.<br>
Dans l'ordre : Emboss, Ouline, Sharpen.<br><br>
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/35effe97-acaa-44e7-aa96-82f41e17f6ef" style="width:200px">
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/abf5d8e2-7f18-4b20-b67d-132fc8408ab5" style="width:200px">
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/8dd47b15-3dab-40c1-b9b3-fd56f695966c" style="width:200px">

## 024 - Différence de gaussiennes 🥑🥑
Soustrait deux images auxquelles on a appliqué deux filtres gaussiens différents pour mettre en avant la différence d'échelle. Le résultat a ensuite été passé en noir et blanc.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/cfaf9c5e-b7fa-4eb0-aeaf-fb43dc7cd611" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/8f3ee4a9-f55c-4574-b4c1-67c952f0be5b" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/0a696ec3-11a0-4fd6-9559-f23e51d9517e" style="width:200px">

> [!NOTE]
> Pour cet algorithme, nous avons beaucoup tatonné car nous avions récupéré la formule de la [vidéo](https://www.youtube.com/live/8rrHTtUzyZA?si=wy1fDYzmzKQ49n3U&t=72) et le résultat était loin de celui attendu. Après avoir réécrit le code de différentes façons, nous avons finalement joué avec ce paramètre avant de réaliser que le souci venait de là, le code était bon et après l'avoir passée en **noir et blanc** on a enfin eu un résultat similaire.

## 025 - Tri de pixels 🥑🥑🥑🥑
Tri chaque colonne de l'image pour créer une image en fonction de la luminosité des pixels, du plus au moins lumineux.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/2c2717ad-a5e4-4628-bb38-d613deb021f3" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/702b0361-fbdb-4389-9bfb-991e128854e6" style="width:200px">

> [!NOTE]
> Cet algorithme a nécessité l'utilisation de tableaux pour pouvoir trier les pixels par la suite : on utilise des tableaux de tableaux ce qui était un peu tricky pour accéder aux bonnes valeurs au bon moment. Nous avons bloqué un petit moment sur eux car nous avions oublié de vider le tableau entre chaque étape, ce qui faisait que chaque itération du tableau contenait tous les pixels de la ligne en plus des lignes précédentes : les opérations étaient longues et le résultat était donc le même qu'en entrée. En ajoutant l'étape de vidage, tout fonctionnait comme nous le souhaitions !

**Gestion et vidage du tableau**
```c++
for (int x = 0; x < image.width(); x++)
{
    for (int y = 0; y < image.height(); y++)
    {
        pixels.push_back(image.pixel(x, y));
    }
    sortedPixels.push_back(pixels);
    pixels.clear();
}
```

## 026 - Filtre de Kuwahara 🥑🥑🥑🥑🥑
Ajoute un filtre peinture à l'huile à l'image en récupérant les 3 pixels autour de chaque pixel, en les divisant en **4 zones** et en prenant la moyenne de la zone avec la variance la plus faible.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/dc8002de-87ed-49f6-bcb0-3133b7426f8e" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/b3c1928c-7f7d-4774-a1aa-23fe93afa3b4" style="width:200px">

> [!NOTE]
> Nous avons eu beaucoup de difficultés avec ce filtre, en effet nous avons tout supprimé et tout recommencé plusieurs fois chacune de notre côté. On se perdait souvent dans les boucles car pour chaque pixel, il fallait prendre les 9 autour et dans ces 9, les séparer en deux 5x5 pour pouvoir les parcourir et faire les calculs. De plus, nous avons quelques difficultés en maths donc au départ nous avions fait la moyenne et non la variance, on avait emmelé nos pinceaux. On avait également oublié de réinitialiser les valeurs ce qui faussait tous nos résultats mais nous avons fini par trouver cette erreur et déterminer où il fallait le faire car il y avait plusieurs boucles donc sa place était capitale.

**Formule de la variance pour chaque carré**
```c++
for (int k = -2; k <= 2; k++)
{
    for (int l = -2; l <= 2; l++)
    {
        if (x + i + k >= 0 && x + i + k < image.width() && y + j + l >= 0 && y + j + l < image.height())
        {
            variance += (image.pixel(x + i + k, y + j + l).r + image.pixel(x + i + k, y + j + l).g + image.pixel(x + i + k, y + j + l).b) / 3.f - moyenne;
            variance = variance * variance;
        }
    }
}
variance = variance / 25.f;
```

## 027 - K-means🥑🥑🥑🥑🥑
Créé une image en fontion des k couleurs les plus représentatives de l'image. Ici 2, 3 et 16 couleurs.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/aa2171dc-849e-49a7-99ac-c78d6b2f6db7" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/51b2c47b-2157-4051-bafa-991269f2d86d" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/be008e2b-ee64-4b87-a90d-0cbb6304d1a2" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/e4364644-a082-4510-9c44-84ff147b8f5e" style="width:200px">


# 🎨 Effets customs

## ✨ Fun Color
Prend une image, la simplifie avec un système de seuil et la décline en 3 couleurs (r, g, b) en style Pop Art.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/9e2e9a65-09e8-4a6b-85dc-efd2474316ea" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/09d78b87-b3b2-49ef-926c-0a616e593518" style="width:600px">

**Traitement en fonction du seuil de rouge**
```c++
if (image.pixel(x, y).r <= seuil)
{
    result.pixel(x, y) = {0, 0, 0.9};
    result.pixel(x + image.width(), y) = {0.9, 0, 0};
    result.pixel(x + image.width()*2, y) = {0, 0.9, 0};
}
```

## ✨ Circle Wave
Génère une série de vagues à partir d'un cercle et de ses arctangentes.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/2494ec40-a616-4825-9854-87f56920c85d" style="width:300px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/bd4cd90d-2945-45c2-8f41-5bc784e4d37f" style="width:300px">

> [!NOTE]
> À gauche, on divise le PI utilisé pour chaque angle par 6. À droite, on ne les divise pas.

## ✨ Fringe
Alterne les colonnes de pixel pour les décaler vers le haut ou vers le bas en alternance. Pourrait être aussi à l'horizontal, vers la gauche et vers la droite.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c0a35231-835a-4dcd-b6cb-cb80c63489c0" style="width:200px">

**Code**
```c++
int width = image.width();
int height = image.height();
sil::Image glitched{width, height};
for (int x = 0; x < width; x++)
{
    int offset = random_int(-20, 20);
    for (int y = 0; y < height; y++)
    {
        if (x + offset < width && x + offset >= 0)
        {
            glitched.pixel(x, y) = image.pixel(x + offset, y);
        }
        else
        {
            glitched.pixel(x, y) = image.pixel(x, y);
        }
    }
}
```

## ✨ Pixelate
Pixelise l'image sélectionnée au degré souhaité.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/f020e48f-3b44-4492-bbfe-fe51211c7b5b" style="width:300px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/fb8798e8-59c1-4334-86f9-35217e4a6cd8" style="width:300px">

> [!NOTE]
> Nous réalisons une moyenne des pixels pour rendre leurs couleurs de plus en plus approximatives.

**Exemple d'une boucle :**
```c++
for (int y = 0; y < sizeH; y++)
{
    int coordX = x + (i * sizeW);
    int coordY = y + (j * sizeH);

    moyenneR += image.pixel(coordX, coordY).r;
    moyenneG += image.pixel(coordX, coordY).g;
    moyenneB += image.pixel(coordX, coordY).b;
    nbPixel++;
}
```
