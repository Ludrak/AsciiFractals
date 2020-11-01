
# ASCII FRACTALS


> ## Index
>
> - ##### *Compiler + executer*
> - ##### *Fractales ?*
> - ##### *Details techniques*

> ## Compiler + Executer
>
> ### I - Compiler
> ##### Pour compiler le projet, tapez simplement "make" dans le terminal. Le projet fonctionne sous Linux, des erreurs de compilation peuvent survenir lors de la compilation sous windows, dans ce cas, essayez de compiler sous le WSL2 (https://docs.microsoft.com/en-us/windows/wsl/install-win10).
>
> ### II - Executer
>> #### ./ascii_fractals 
> ##### Pour executer le projet en mode default
>> #### ./ascii_fractals res=\<number>x\<number> 
>> ##### (default is 20x20)
> ##### Pour definir la resolution de l'ecran en caracteres ascii. (notez que la taille d'un caractere standart est 2 fois plus haute que large, une resolution de 30x30 sera donc traitee comme 60x30)
> ##### Configurations recomandees: 30x30 50x50 75x75 100x75 130x90
> ###### (la libncurses etant interdite par le concours, lancez une resolution plus petite que celle de votre terminal pour eviter des erreurs d'affichage, je recommande de le lancer en fullscreen en baissant la taille de police pour utiliser les profils > 75x75 donnant de bien meilleurs resultats)
>> #### ./ascii_fractals max_iter=\<number>
>> ##### (default is 100)
> ##### Pour definir le nombre d'iterations maximum par pixel. (Voir: Fractales ?)
> ##### Iterations Recomandees: default 300 500 1000 5000 + (attention au lag !)
> 
> ##### Bien evidement, ces deux options sont combinables.


> ## Fractales ?
> 
> ##### Les fractales sont des objects mathematiques, dont la structure se repete indefiniment. Ce programe inclus 2 des plus connues d'entre elles : le Mandelbrot set et le Julia set.
> ##### Elles sont issues de l'iteration de la suite *Zn+1 = Zn^2 + c*, ou *Z0 = 0*, sur le plan complexe,
> ##### represente ici par un ecran ou Re=X et Im=Y.
> ##### Dans le mandelbrot set, C est un complexe representant la position sur le plan complexe, qui sera donc du type (x + yi).
> ##### Dans le julia set, C represente la position + une constante complexe, par consequent, le julia set peux se retrouver a de multiples reprises dans le mandelbrot.
> ##### La couleur de chaque pixel dependra du resultat de Z apres un nombre donne d'iterations. Si Z > INFINI (infini fixe a 200000), alors le pixel ne fais pas partie du set, on calcule alors la couleur grace au nombre d'iterations effectuees pour atteindre l'infini. Dans le cas ou Z depasse le nombre fixe d'iterations, le point fais partie du set et sera colore en noir. Ce sont donc ces points la qui sont les plus long a calculer car ils demandent d'atteindre le maximum d'iterations.

> ## Details Techniques
>
> ##### Le programme a ete code en pure c en utilisant aucune librairie sauf quelques fonctions indispensables de la libc.
> #### Les syscalls / fonctions utilises dans ce programme sont :
> - read ()  (Utilise pour lire une input, sur l'entree standard) 
> - write () (Utilise pour ecrire sur l'entree standart) 
> - malloc () (Allocation memoire) 
> - free () (Liberation memoire) 
> - fcntl () (Utilise pour la modification des flags de file descriptor, permettant a read() de lire sur un fd non blocant ) 
> - clock () (Utilise pour obtenir le temps de processus, et caper les FPS)
> - exit () (Utilise pour terminer le process)


> ### Informations
>
> ##### Ascii Fractals est un projet developpe pour le concours du serveur discord Le Coin Des Developpeurs
>
> ###### Author: Ludrak
> ###### Released: 31/10/2020