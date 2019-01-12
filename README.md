# PROJET D'EQUATIONS DIFFERENTIELLES ORDINAIRES
# Etude des equations de Lotka-Volterra


## Présentation
Les équations de Lotka-Volterra constituent un système de deux équations couplées visant à modéliser l'évolution d'une population de proies et de prédateurs. Ce projet a pour but de présenter les principaux résultats théoriques inhérents aux solutions de ce système. Les travaux peuvent être trouvés dans les documents `lotka_volterra.pdf` et `diapositives.pdf` du répertoire courant. Du code C est également fourni afin de générer les courbes approchant ces solutions.

## Génération des courbes
Les solutions des équations de Lotka-Volterra peuvent être approchées par le programme se trouvant dans le répertoire `graphes/`. Les paramètres du système d'équations sont à renseigner dans le fichier `parametres.txt` du répertoire `graphes/`, de la façon suivante :
```
X0 Y0 ALPHA BETA GAMMA SIGMA A B N
```
- `X0` est la proportion initiale de proies ;
- `Y0` est la proportion initiale de prédateurs ;
- `ALPHA`, `BETA`, `GAMMA`, `SIGMA` sont les coefficients "alpha", "beta", "gamma" et "sigma" décrits dans le rapport ;
- `A` est le temps auquel commence la résolution ;
- `B` est le temps auquel termine la résolution ;
- `N` est le nombre de points de discrétisation en temps ;

Pour générer la courbe représentant l'évolution des proies en fonction du temps (respectivement des prédateurs en fonction du temps, ou des prédateurs en fonction des proies), on pourra à partir du répertoire `graphes/` saisir la commande `make xt` (respectivement `make yt` ou `make xy`). Pour tracer les trois courbes en même temps, la commade `make all` peut être utilisée.
