# Workshop - Image Manipulation

Une semaine de workshop en binôme pour apprendre à coder des effets sur des images et première introduction à certains concepts de synthèse d'image.
<br>Repo des consignes et exercices : https://dsmte.github.io/Learn--cpp_programming/Workshop

## Attendus

Liste d'exercices, plus ou moins difficiles et le but est d'en faire le maximum. 
- Mini-soutenance optionnelle (exercice de vulgarisation) et mini-rapport à rendre
- Le rendu se fera par groupes de 2

# Filtres
> [!NOTE]
> Le nombre d'émoji indique la complexité du filtre, allant de 1 à 6.

## 001 - Ne garder que le vert 🥑
Retire le bleu et le rouge de chaque couleur présente sur l'image.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/cb5763a9-eb28-4450-9cf0-84705c4efc08" style="width:200px">
<br><br>
## 002 - Échanger les canaux 🥑
Échange les valeurs de bleu et les valeurs de rouge de l'image grâce à la fonction swap.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/950f26f5-8b92-4e97-9292-fe73c00686d6" style="width:200px">
<br><br>
## 003 - Noir & Blanc 🥑
Transforme les couleurs en nuances de gris.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/bc3f0fb1-cec1-42a9-ab86-4c72052d43a9" style="width:200px">
<br><br>
## 004 - Négatif 🥑
Inverse les valeurs des couleurs.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/37ddfc6c-21c6-4be7-9ce1-1a99746f7fb0" style="width:200px">
<br><br>
## 005 - Dégradé 🥑
Crée un dégradé de noir à blanc sur une image vide.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/3d7a6a69-0cf9-4caa-a1ea-928bdfed2a0d" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/2ba19127-9cb2-453b-8a9f-e4f2227c4ebc" style="width:200px">
<br><br>
## 006 - Miroir 🥑🥑
Inverse les pixels de l'image.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/6d71067b-d5ef-449c-b721-228f2b52271a" style="width:200px">
<br><br>
## 007 - Image bruitée 🥑🥑
Crée du bruit aléatoire sur l'image.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/ea7f77c0-1e66-44d7-a005-7b80da8f1360" style="width:200px">
<br><br>
<i>Remarque</i> : Cette fonction nous a permis d'appréhender la notion de random donc nous avons dû lire la documentation pour bien la maitriser et ainsi bruiter l'image. Il ne fallait pas bruiter chaque pixel donc il a fallu définir un nombre de pixel à modifier, ici on a choisi de prendre la moitié des pixels.
<br><br>
## 008 - Rotation de 90° 🥑🥑
Réecris les pixels de l'image comme s'ils subissaient une rotation à 90° sur une nouvelle image au format correct.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/708fd598-f43f-4452-b847-e01be4b18641" style="height:200px">
<br><br>
<i>Remarque</i> : Cette modification d'image semble simple en théorie mais on a tatonné avant d'y parvenir. En effet, au départ nous pensions juste que les x devenaient des y et vice versa mais ce n'était pas le cas, pour la réussir nous avons dû dessiner plusieurs exemples sur papier et cela nous a beaucoup aidées à visualiser les changements à opérer.
<br><br>
## 009 - RGB Split 🥑🥑
Modifie chaque pixel de sorte qu'il prenne le rouge du pixel à sa droite, garde son propre vert, et prenne le bleu du pixel à sa gauche.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/ebcf971c-bcea-49bd-b5be-876bfe1d6826" style="width:200px">
<br><br>
## 010 - Luminosité 🥑🥑
Augmente la luminosité de l'image.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/f020e48f-3b44-4492-bbfe-fe51211c7b5b" style="width:300px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/351e1d51-6bef-4616-879b-d8acf2ffc5a6" style="width:300px">
<br><br>
## 011 - Disque 🥑🥑
Création d'un disque blanc sur fond noir<br><br>
<i>à ajouter</i>
<br><br>
## 012 - Cercle 🥑🥑
Créé un cercle blanc sur fond noir<br><br>
<i>à ajouter</i>
<br><br>
## 012 - Cercle 🥑🥑
Créé un cercle blanc sur fond noir<br><br>
<i>à ajouter</i>
<br><br>
## 013 - Rosace 🥑🥑🥑
Créé une succession de cercles formant une rosace.<br><br>
<i>à ajouter</i>
<br><br>
## 014 - Mosaïque 🥑🥑
Créé la mosaïque de l'image.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/5d6d2c23-811c-4fde-809a-4b00fae0dddf" style="width:200px">
<br><br>
<i>Remarque</i> : Pour créer cette mosaïque, il fallait parcourir tous les pixels puis séparer l'image finale en fonction du nombre choisi. Au départ, c'était assez facile mais la difficulté a augmenté au fur et à mesure des boucles car il fallait raisonner à la fois en global et en spécifique pour chaque image. On s'est perdues plusieurs fois mais en posant à plat nos idées, on a pu avoir plus de recul et réussir à produire le résultat final.
<br><br>
## 015 - Mosaïque miroir 🥑🥑🥑
Inverse une image sur deux sur le résultat de la mosaïque.<br><br>
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/5d6d2c23-811c-4fde-809a-4b00fae0dddf" style="width:200px">
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/3ffc6596-fd15-427e-88c2-be1692505daf" style="width:200px">
<br><br>
## 016 - Glitch 🥑🥑🥑
Ajoute du glitch sur l'image de manière random.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/79641014/c6d09cd4-92ce-4eb0-810c-ea96e6ab4f73" style="width:200px">
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/31482a8c-8e4b-4cf5-a7e2-290ffb6b8015" style="width:200px">
<br><br>
## 017 - Fractale de Mandelbrot 🥑🥑🥑
Génère une fractale de Mandelbrot, un concept mathématique découvert par Gaston Julia et Pierre Fatou.<br><br>
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/50ffee54-c054-4ed5-bee8-9281f1c30fcf" style="width:300px">
<br><br>
## 018 - Vortex 🥑🥑🥑(🥑)
<i>Pas terminée</i>
<br><br>
## 019 - Tramage 🥑🥑🥑(🥑)
<i>à ajouter</i>
<br><br>
## 020 - Normalisation de l'histogramme 🥑🥑🥑(🥑)
Modifie chaque pixel en fonction du pixel le plus lumineux de l'image et le moins lumineux, améliore le contratse d'une image.<br><br>
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/563e9d62-caa8-482a-afd2-afb6a377f47a" style="width:200px">
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/e671d759-0058-4988-bc30-167e9c956968" style="width:200px">
<br><br>
## 021 - Convolutions 🥑🥑🥑🥑
Transforme l'image en lui appliquant une convolution, c'est-à-dire une opération qui va ajouter un effet sur l'image en fonction d'un kernel donné.<br><br>
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/79d4f2e4-5b22-4046-a1e1-e8cda6b8e5ed" style="width:200px">
<br><br>
<i>Remarque</i> : La difficulté de l'exercice a résidé dans la compréhension du fonctionnement du kernel car il y avait de nombreuses erreurs (dépassement de l'image, pixels en double etc.) donc il a fallu se replonger dans les matrices. Finalement, après avoir fait en sorte que cela marche pour 1 matrice de 3 par 3, il y a eu de nombreuses itérations pour adapter le code à toutes les tailles.
<br><br>
## 022 - Netteté, Contours, etc. 🥑
Applique différents kernels pour avoir plusieurs effets.<br>
Dans l'ordre : Emboss, Ouline, Sharpen.<br><br>
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/35effe97-acaa-44e7-aa96-82f41e17f6ef" style="width:200px">
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/abf5d8e2-7f18-4b20-b67d-132fc8408ab5" style="width:200px">
<img src="https://github.com/LouisePrd/Workshop-Image-CPP/assets/77757761/8dd47b15-3dab-40c1-b9b3-fd56f695966c" style="width:200px">
<br><br>
## 024 - Différence de gaussiennes 🥑🥑
Soustrait deux images auxquelles on a appliqué deux filtres gaussiens différents pour mettre en avant la différence d'échelle. Le résultat a ensuite été passé en noir et blanc.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/cfaf9c5e-b7fa-4eb0-aeaf-fb43dc7cd611" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/8f3ee4a9-f55c-4574-b4c1-67c952f0be5b" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/0a696ec3-11a0-4fd6-9559-f23e51d9517e" style="width:200px">
<br><br>
<i>Remarque</i> : Pour cet algorithme, nous avons beaucoup tatonné car nous avions récupéré la formule de la vidéo et le résultat était loin de celui attendu. Après avoir réécrit le code de différentes façons, nous avons finalement joué avec ce paramètre avant de réaliser que le souci venait de là, le code était bon et après l'avoir passée en noir et blanc on a enfin eu un résultat similaire.
<br><br>
## 025 - Tri de pixels 🥑🥑🥑🥑
Tri chaque colonne de l'image pour créer une image en fonction de la luminosité des pixels, du plus au moins lumineux.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/2c2717ad-a5e4-4628-bb38-d613deb021f3" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/702b0361-fbdb-4389-9bfb-991e128854e6" style="width:200px">
<br><br>
Cet algorithme a nécessité l'utilisation de tableaux pour pouvoir trier les pixels par la suite : on utilise des tableaux de tableaux ce qui était un peu tricky pour accéder aux bonnes valeurs au bon moment. Nous avons bloqué un petit moment sur eux car nous avions oublié de vider le tableau entre chaque étape, ce qui faisait que chaque itération du tableau contenait tous les pixels de la ligne en plus des lignes précédentes : les opérations étaient longues et le résultat était donc le même qu'en entrée. En ajoutant l'étape de vidage, tout fonctionnait comme nous le souhaitions !
<br><br>
## 026 - Filtre de Kuwahara 🥑🥑🥑🥑🥑
<i>Pas terminée</i>
<br><br>
## 027 - K-means🥑🥑🥑🥑🥑
Créé une image en fontion des k couleurs les plus représentatives de l'image. Ici 2, 3 et 16 couleurs.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/aa2171dc-849e-49a7-99ac-c78d6b2f6db7" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/51b2c47b-2157-4051-bafa-991269f2d86d" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/be008e2b-ee64-4b87-a90d-0cbb6304d1a2" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/e4364644-a082-4510-9c44-84ff147b8f5e" style="width:200px"><br><br>


# Effets customs

## Fun Color
Prend une image, la simplifie avec un système de seuil et la décline en 3 couleurs (r, g, b) en style Pop Art.<br><br>
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/9e2e9a65-09e8-4a6b-85dc-efd2474316ea" style="width:200px">
<img src="https://github.com/AM-XIX/workshop-image-manipulation/assets/77757761/09d78b87-b3b2-49ef-926c-0a616e593518" style="width:600px">
