Vasseur François
Favé Jonathan
Rey Maxime
Boucard Romain


Règles du jeu claires : https://www.jeuxdenim.be/download/CourseDesTortues_regle.pdf

Lien github : https://github.com/EC-Nantes/tp-note-2-vasseur-fave-rey-boucard.git


ESSENTIEL !
Pour avoir la lib googletest :

git submodule update 


Pour pouvoir (re)build le projet avec les tests CMake est necessaire : 

https://cmake.org/install/

LINUX :

Recompiler le projet : 

cmake . 

make all


Lancer l'executable :

cd src/

./tpn2_run

Nous avons laissé un executable de la dernière version disponible.


WINDOWS :

Recompiler le projet :

cmake -G"MinGW Makefiles"

Lancer l'executable :

cd src/

./tpn2_run
