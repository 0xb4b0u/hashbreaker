# hash breaker

<img src="https://img.shields.io/github/languages/top/0xb4b0u/hashbreaker?style&color=5D6D7E" alt="GitHub top language" />
<img src="https://img.shields.io/github/languages/code-size/0xb4b0u/hashbreaker?style&color=5D6D7E" alt="GitHub code size in bytes" />
<img src="https://img.shields.io/github/commit-activity/m/0xb4b0u/hashbreaker?style&color=5D6D7E" alt="GitHub commit activity" />
<img src="https://img.shields.io/github/license/0xb4b0u/hashbreaker?style&color=5D6D7E" alt="GitHub license" />

---

## 📒 Table des matières

- [hash breaker](#hash-breaker)
  - [📒 Table des matières](#-table-des-matières)
  - [👾 Un hash breaker ?](#-un-hash-breaker-)
  - [📂 Structure du projet](#-structure-du-projet)
  - [🧩 Prérequis](#-prérequis)
  - [🚀 Installation et Utilisation](#-installation-et-utilisation)
  - [🔨 Améliorations possibles](#-améliorations-possibles)
  - [🤝 Auteurs](#-auteurs)
  - [📄 License](#-license)
  - [👏 Remerciements](#-remerciements)

---

## 👾 Un hash breaker ?

Un "hash breaker" est un outil ou un programme conçu pour décrypter ou casser des fonctions de hachage.
Les fonctions de hachage sont des algorithmes qui transforment des données en une chaîne de caractères unique et apparemment aléatoire, appelée "hash".
Ces hashes sont souvent utilisés pour stocker de manière sécurisée des mots de passe ou vérifier l'intégrité des données.

La valeur d'un hash breaker réside dans sa capacité à compromettre la sécurité de ces systèmes en inversant le processus de hachage, révélant ainsi le contenu original des données.
Cela peut être utilisé de manière éthique, par exemple, pour tester la robustesse des systèmes de sécurité, mais peut aussi être exploité de manière malveillante pour accéder à des informations sensibles.

En somme, un hash breaker souligne l'importance de choisir des algorithmes de hachage robustes et de mettre en place des mesures de sécurité supplémentaires pour protéger les données sensibles.

---

## 📂 Structure du projet

```bash
+-- LICENSE.md
+-- Makefile
+-- README.md
+-- client
│   \-- client.c
+-- docs
|   +-- Ennonce.pdf
|   \-- Rapport.pdf
+-- lib
│   +-- comlib.c
│   +-- comlib.h
│   +-- hashlib.c
│   +-- hashlib.h
│   +-- loglib.c
│   +-- loglib.h
│   +-- stringslib.c
│   \-- stringslib.h
\-- server
    \-- server.c
```

---

## 🧩 Prérequis

Pour exécuter ce projet, vous aurez besoin des outils suivants installés sur votre machine :

- [Make](https://www.gnu.org/software/make/) : un outil qui contrôle la génération de programmes exécutables et d'autres tâches non liées à la compilation de fichiers source. Il est généralement préinstallé sur la plupart des distributions Linux.
- [GCC](https://gcc.gnu.org/install/index.html) : le compilateur GNU. Il est généralement préinstallé sur la plupart des distributions Linux.
- [OpenSSL](https://www.openssl.org/source/) : une bibliothèque robuste, commerciale de qualité, pleine de fonctionnalités, Open Source Toolkit mettant en œuvre le protocole Secure Sockets Layer (SSL v2/v3) et Transport Layer Security (TLS v1) ainsi qu'une bibliothèque de cryptographie à usage général.

---

## 🚀 Installation et Utilisation

Pour cloner ce projet sur votre machine locale, ouvrez un terminal et exécutez la commande suivante :

```bash
git clone https://github.com/0xb4b0u/hashbreaker.git
```

Ensuite, vous pouvez compiler le projet en exécutant les commandes suivantes :

```bash
cd hashbreaker
make all
```

Pour lancer le serveur, exécutez la commande suivante :

```bash
cd server
./server -i <IP> -p <PORT> -h <hash_list_path>
```

Pour lancer le client, exécutez la commande suivante :

```bash
cd client
./client -i <IP> -p <PORT>
```

⚠️ le serveur doit être lancé avant le client ⚠️

Le hash breaker prend en compte des hash dans ces formats :

- MD5
- SHA1
- SHA256
- SHA512

---

## 🔨 Améliorations possibles

> - [X] `ℹ️  Implémenter le choix du système de hashage`
> - [ ] `ℹ️  Implémenter un système de logs`
> - [ ] `ℹ️  Utilisation de threads afin d'améliorer les performances`
> - [ ] `ℹ️ ...`

---

## 🤝 Auteurs

- **Baptiste Oger** - *Travail initial* - [0xb4b0u](https://github.com/0xb4b0u)
- **Alexandre Bousard** - *Travail initial* - [AlexGalaxis](https://github.com/AlexGalaxis)

Voir aussi la liste des [contributeurs](https://github.com/0xb4b0u/hashbreaker/graphs/contributors) qui ont participé à ce projet.

---

## 📄 License

Ce projet est sous licence MIT - voir le fichier [LICENSE.md](LICENSE.md) pour plus de détails

---

## 👏 Remerciements

- Notre professeur de développement, Monsieur DUVILLIE Guillerme.
- Tous les autres membres de l'équipe professorale de l'IESN.
