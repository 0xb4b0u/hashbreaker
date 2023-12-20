# Hash Breaker

Un "hash breaker" est un outil ou un programme conçu pour décrypter ou casser des fonctions de hachage. 
Les fonctions de hachage sont des algorithmes qui transforment des données en une chaîne de caractères unique et apparemment aléatoire, appelée "hash". 
Ces hashes sont souvent utilisés pour stocker de manière sécurisée des mots de passe ou vérifier l'intégrité des données.

La valeur d'un hash breaker réside dans sa capacité à compromettre la sécurité de ces systèmes en inversant le processus de hachage, révélant ainsi le contenu original des données. 
Cela peut être utilisé de manière éthique, par exemple, pour tester la robustesse des systèmes de sécurité, mais peut aussi être exploité de manière malveillante pour accéder à des informations sensibles. 

En somme, un hash breaker souligne l'importance de choisir des algorithmes de hachage robustes et de mettre en place des mesures de sécurité supplémentaires pour protéger les données sensibles.

### Prérequis

Pour exécuter ce projet, vous aurez besoin des outils suivants installés sur votre machine :

- [CMake](https://cmake.org/download/) : un outil de génération de build multiplateforme. Vous pouvez le télécharger et l'installer à partir du site officiel.
- [GCC](https://gcc.gnu.org/install/index.html) : le compilateur GNU. Il est généralement préinstallé sur la plupart des distributions Linux. Pour les utilisateurs de macOS, vous pouvez l'installer via [Homebrew](https://brew.sh/) avec la commande `brew install gcc`.
- [OpenSSL](https://www.openssl.org/source/) : une bibliothèque robuste, commerciale de qualité, pleine de fonctionnalités, Open Source Toolkit mettant en œuvre le protocole Secure Sockets Layer (SSL v2/v3) et Transport Layer Security (TLS v1) ainsi qu'une bibliothèque de cryptographie à usage général. Vous pouvez le télécharger et l'installer à partir du site officiel.

### Installation et Déploiement

Pour cloner ce projet sur votre machine locale, ouvrez un terminal et exécutez la commande suivante :
```bash
git clone https://github.com/0xb4b0u/hashbreaker.git
```

Ensuite, vous pouvez compiler le projet en exécutant les commandes suivantes :
```bash
cd hashbreaker
make all
```

## Construit Avec

* [CLion](https://www.jetbrains.com/clion/) - L'IDE utilisé
* [CMake](https://cmake.org/) - Système de construction

## Auteurs

* **Baptiste Oger** - *Travail initial* - [0xb4b0u](https://github.com/0xb4b0u)
* **Alexandre Bousard** - *Travail initial* - [AlexGalaxis](https://github.com/AlexGalaxis)

Voir aussi la liste des [contributeurs](https://github.com/0xb4b0u/hashbreaker/graphs/contributors) qui ont participé à ce projet.

## Licence

Ce projet est sous licence MIT - voir le fichier [LICENSE.md](LICENSE.md) pour plus de détails

## Remerciements

* Notre professeur de développement, Monsieur DUVILLIE Guillerme.
* Tous les autres membres de l'équipe professorale de l'IESN.