# Solveur_Casse-tetes
Ce programme peut résoudre différents problèmes à satisfaction de contraintes, autrement dit résoudre différents casse-têtes. Pour ce faire, ce programme implémente une intelligence artificielle de type backtrack.

**Énigme 1, le petit sudoku :**
Ce petit exemple me permettra de vous expliquer simplement le fonctionnement du programme.
<p align="center">
  <img src="https://github.com/ClaireGouessant/Solveur_Casse-tetes/blob/master/DocREADME/SudokuVierge.PNG" width="350"/>
</p>
Ce sudoku est décrit dans le fichier pb1.txt.
Il est rédigé dans un document en 2 parties, d’une façon compréhensible par l’ordinateur. En première partie, il y figure le nombre de variables, puis ces variables et les valeurs qu’elles peuvent prendre. Dans ce problème il y a 16 variables qui correspondent aux 16 cases de la grille dans le sens de lecture. Sur chaque ligne une variable est décrite, certaines cases ne peuvent prendre qu’une valeur écrite juste après quand d’autre peuvent en prendre 4 : 1, 2, 3 et 4.  En deuxième partie, il y figure des contraintes à respecter pour satisfaire les règles du problème. Ici il est noté que les valeurs des cases des colonnes doivent être différentes entre elles, les cases des lignes et les packs doivent également l’être.
Lorsqu’on lance le programme, l’ordinateur affiche le problème original puis sa solution, si elle existe.
Ici l’ordinateur donne donc la solution :
<p align="center">
  <img src="https://github.com/ClaireGouessant/Solveur_Casse-tetes/blob/master/DocREADME/PB1.PNG" width="350"/>
  <img src="https://github.com/ClaireGouessant/Solveur_Casse-tetes/blob/master/DocREADME/SudokuRésolu.PNG" width="350"/>
</p>

**Énigme 2, le problème des 4 dames :**
Il s’agit de placer 4 dames sur un damier 4x4. Les dames ne doivent n’y être sur la même ligne, ni sur la même colonne ni dans la même diagonale.
Solution proposée par le programme :
<p align="center">
  <img src="https://github.com/ClaireGouessant/Solveur_Casse-tetes/blob/master/DocREADME/PB2.PNG" width="350"/>
  <img src="https://github.com/ClaireGouessant/Solveur_Casse-tetes/blob/master/DocREADME/Dames.PNG" width="350"/>
</p>
*Dans la modélisation de ce problème, les dames sont représentées par les variables x1 à x4. Les variables x5 à x17 ne sont que des variables utilisées pour la modélisation du problème.*

**Énigme 3, coloriage de carte à 3 couleurs :**
Il s’agit ici de colorier les arrondissements de la ville de Paris avec 3 couleurs différentes. Deux couleurs identiques ne doivent pas se toucher.
<p align="center">
  <img src="https://github.com/ClaireGouessant/Solveur_Casse-tetes/blob/master/DocREADME/paris.png" width="350"/>
</p>
Le programme nous affiche :
<p align="center">
  <img src="https://github.com/ClaireGouessant/Solveur_Casse-tetes/blob/master/DocREADME/PB3.PNG" width="350"/>
</p>
En effet, la carte ne peut être colorée par 3 couleurs uniquement.

**Énigme 4, coloriage de carte à 4 couleurs :**
Même problème que précédemment, avec 4 couleurs :
<p align="center">
  <img src="https://github.com/ClaireGouessant/Solveur_Casse-tetes/blob/master/DocREADME/PB4.PNG" width="350"/>
  <img src="https://github.com/ClaireGouessant/Solveur_Casse-tetes/blob/master/DocREADME/pairsM.png" width="350"/>
</p>
