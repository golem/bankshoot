BANKSHOOT
=========

Un banquier décide d'utiliser son capital pour défendre la
banque contre divers dangers : voleurs, mafieux, clients en colère...

Objectifs
---------

Ce projet est mené dans le cadre d'un cours de C++. Nous devions réaliser
un programme en respectant le thème *banques et banquiers*, en suivant certaines contraintes :

* 7 classes ;
* 3 niveaux de hierarchie ;
* 2 fonctions virtuelles ;
* 2 surcharges d'opérateurs ;
* 2 conteneurs différents de la STL ;
* diagramme de classes UML complet ;
* commentaires du code au format Doxygen ;
* pas d'erreurs avec Valgrind ;
* utilisation d'un Makefile.

Compilation
-----------

Ce programme utilise la bibliothèque SFML (http://www.sfml-dev.org/).
Pour des raisons pratiques par rapport aux ordinateurs de l'université, nous la livrons en version binaire.

Pour compiler le programme, il faut d'abord installer quelques dépendances
(cf. http://www.sfml-dev.org/tutorials/1.6/start-linux.php), par exemple sur une Debian-based :

```
apt-get build-dep libsfml
```

Ensuite, un simple

```
make
```

devrait suffire.

**Note :** Windows n'est pas supporté.

Comment jouer ?
---------------

Pour démarrer le jeu, il faut exécuter la commande :

```
./bankshoot
```

On arrive ensuite sur un écran d'introdution, sur lequel on peut appuyer
sur *espace* pour lancer une partie, ou *échap* pour quitter le jeu.

Durant le jeu, on déplace le banquier grâce aux *touches directionnelles*
(la touche *bas* lui permet de se retourner pour tirer vers le bas).

La touche *espace* permet au banquier de tirer (ce qui diminuera son capital,
qui peut se renflouer en récupérant les sacs d'argent laissés par les ennemis tués).

Un appui sur *entrée* permet de mettre le jeu en pause, et *échap* de le quitter
(hors de l'écran de pause).

Finalement, lorsque le banquier n'a plus de vie ou de capital, on arrive sur
un écran de game over récapitulant ses performances. À partir de cet écran,
*espace* fait retourner à l'écran d'introduction, et *échap* quitte le jeu.

Un appui sur la touche F1 pendant une partie affiche/cache le compteur d'images
par seconde (ce nombre devrait être limité à 60 FPS, cf. `FRAMERATE_LIMIT` dans le fichier `constants.hpp`).

À tout moment, l'appui sur la touche *F12* permet de réaliser une capture d'écran (c'est le seul moyen pour retenir un score...).
