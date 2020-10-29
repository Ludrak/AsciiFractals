    ___                    _     _            ______                          __             __        
   /   |   _____  _____   (_)   (_)          / ____/   _____  ____ _  _____  / /_  ____ _   / /   _____
  / /| |  / ___/ / ___/  / /   / /          / /_      / ___/ / __ `/ / ___/ / __/ / __ `/  / /   / ___/
 / ___ | (__  ) / /__   / /   / /          / __/     / /    / /_/ / / /__  / /_  / /_/ /  / /   (__  ) 
/_/  |_|/____/  \___/  /_/   /_/          /_/       /_/     \__,_/  \___/  \__/  \__,_/  /_/   /____/  

*=====================================================================================================*

### Ascii fractals est un projet developpe dans le cadre du concours du serveur discord 
### Le Coin des Developpeurs.

#   -> Qu'est ce que c'est ?
### Ascii fractals est un programme qui vous permettera de generer des fractales 
### (Actuellement le Mandelbrot set et le Julia set) et d'effectuer 
### une colorisation + des zooms.

#   -> Fractales ?
### Si vous ne conaissez pas les fractales, ce sont les algorithmes mathematiques bases sur 
### l'iteration d'une suite complexe. L'ecran represente le plan complexe et chaque couleur 
### de pixel est definie grace a l'iteration de la suite :
### {
###   Z0 = 0
###   Zn+1 = Zn^2 + c
### }
### (plus d'infos sur : https://en.wikipedia.org/wiki/Mandelbrot_set)

### Notez que generer des fractales est couteux en ressources du fait des nombreuses iterations par pixel
### indispensables a la generation de celles ci. Si le programme est trop lent, il est possible de changer le
### nombre d'iterations max en le lancant avec ./ascii_fractals max_it=<max-iterations>, de base, le maximum 
### d'iterations par pixel est de 10000, vous pouvez l'augmenter pour gagner de la precision, ou le baisser pour 
### gagner desFPS, mais cela baissera votre qualite de rendu (je recommande de ne jamais aller en dessous de 1000 iterations)
### Si vous voyez le rendu se "pixeliser" apres un fort zoom, cela veux dire que le nombre d'iterations
### est trop bas par rapport au zoom effectue.
### Vous pouvez aussi augmenter vos FPS en changeant la resolution de l'ecran avec ./ascii_fractals res=<sx>x<sy>, ### mais l'ecran etant en ASCII cela risque de vite baisser la precision. (un caractere etant 2x plus haut que 
### large, la resolution 30x30 sera en realite egale a 60x30. cela est pris en compte par le programme.)
### Du fait des restrictions de libs pour le projet, ncurses n'a pas pu etre utilise pour un rendu plus propre,
### je recommande donc de lancer le programme dans un terminal assez grand (fullscreen recommande) pour un 
### affichage correct.
### Resolutions recomandees: 40x40 (default), 80x80, 150x80

#   -> Requirements
### Le programme a besoin des packages suivants pour fonctionner : gcc ; make
### Et a ete programme pour fonctionner sur Linux (de preference x64)
### Je recommande de le lancer sur un PC ayant une certaine puissance de calcul
### Pour obtenir des resultats satisfaisants.
### Ma config :
### - i5 5700k, 16G ram

#   -> How to use
### Pour la compilation, tapez : make (ce qui va creer un executable ascii_fractals)
### Il suffit de lancer le programme (./ascii_fractals), choisir sa fractale avec les 
### options 1 et 2 (Mandelbrot ou Julia) et de choisir un preset de colorisation. 
### Pour arreter la simulations, faites Ctrl+C et ca vous affichera un menu,
### vous demandant si vous voulez quitter le programme, ou executer une autre fractale.

#   -> Quelques tips !
### Ici je vais vous parler de mes presets favoris et surtout comment en tirer tout leur potentiel :)
### Pour tout les preset a zoom statique, vous pouvez utiliser une resolution assez faible (~100)
### ce qui va monter grandement vos FPS tout en gardant la qualite car on ne zoom pas sur l'image.
### (Surtout pour le preset 3 du Julia set a tester absolument.)
### pour le mandelbrot, je trouve interessant de le charger en mode paysage avec une resolution de
### 100x80 a 160x80 si vous n'avez pas peur du lag :_

#   -> Details techniques
### Le programme a ete code en pure C en utilisant aucune lib externe. Les seuls fonction/syscalls utilises 
### sont celles ci :
### - read   (syscall: lire un fd (dans ce cas stdin) )
### - write  (syscall: ecrire sur un fd (dans ce cas stdout) )
### - malloc (syscall: allocation memoire)
### - free   (syscall: liberation memoire)
### - signal (syscall: catch un signal (Utilise uniquement dans le but de catch "Ctrl+C") )
### - clock  (function: recupere les donnees du temps, au moment du call (Utilise pour capper les FPS) )

##### Note: L'utilisation de signal n'etais pas voulue au depart mais c'etais l'option la plus bas niveau
##### qui existe car rendre read() non blocant necessite les fonctions fork() fcntl() select() ou poll().
