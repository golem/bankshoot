BANKSHOOT
=========

Un banquier décide d'utiliser son capital pour défendre la banque contre divers dangers : voleurs, mafieux, clients en colère...

Objectif
--------

Ce projet est mené dans le cadre d'un cours de C++. Nous devions réaliser un programme en respectant le thème *banques et banquiers*, en suivant certaines contraintes :

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

Ce programme utilise la bibliothèque SFML (http://www.sfml-dev.org/). Pour des raisons pratiques par rapport aux ordinateurs de l'université, nous la livrons en version binaire.

Pour compiler le programme, il faut d'abord installer quelques dépendances (cf. apt-get build-dep libsfml), par exemple sur une Debian-based :

```
apt-get build-dep libsfml
```

Ensuite, un simple

```
make
```

devrait suffire.

**Note :** Windows n'est pas supporté.
