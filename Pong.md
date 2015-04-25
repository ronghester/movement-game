# Introduction #

Cette page me sert de brouillon pour Pong, qui sera je l'espère le premier jeu fonctionnel.


# Élements du jeu #

D'un point de vue de joueur :

  * Les joueurs (en fait deux rectangles) ;
  * La balle ;
  * Un éventuel affichage du score.

D'un point de vue développeur :

  * Les éléments graphiques, 2D, dessinés : les joueurs et la balle ;
  * Le "plateau" de jeu, _i.e_ le widget qui contient l'aire de jeu ;
  * La fenêtre principale.

# Analyse #

  * **Le plateau de jeu** : C'est le widget prinicpal, qui contient les autres. C'est dans ce widget que se "cognent" la balle et les joueurs, c'est à dire dans ce widget qu'on calcule les collisions.
  * **Les joueurs** : Représentés par un rectangle, un joueur intervient avec les touches UP et DOWN. Il faudra donc connecter ses rectangles au clavier, pour les déplacer de façon appropriée.
  * **La balle** : Représentée par un cercle, elle doit se déplacer constamment en fonction du temps (_i.e_ se déplacer à une vitesse donnée), selon un axe X et un axe Y. Il faut qu'elle implémente une fonction pour trouver une collision ou voir si elle est hors du plateau.

# Technique #
**Widgets :**
  * **Plateau** : QWidget actuellement, mais le widget approprié semble être[QGraphisScene](http://doc.trolltech.com/4.2/graphicsview.html#the-graphics-view-architecture).
  * **Joueurs et balle**: QWidget implémentant un QPainter.
  * **Timer** : QTimer (pour la balle)

**Pseudo-Code :**
```
tant que (balle dans le plateau):
     calculer_coordonnées();
     si (collision_joueur()):
         inverser axe X;
     sinon si (collision plateau()):
         inverse axe Y;
     sinon:
         timer++;
         update_all()
     fin si;
fin tant que; // La balle est sortie du plateau
assigner_points();
```