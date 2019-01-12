*************************************************
* PROJET D'EQUATIONS DIFFERENTIELLES ORDINAIRES *
* Etude des equations de Lotka-Volterra         *
*************************************************


Description du répertoire graphes/ :
	Répertoire contenant les différents programmes d'obtention des courbes 
	graphes/*.svg ;
	Pour obtenir le nombre de proies en fonction du temps :
		make xt
	Pour obtenir le nombre de prédateurs en fonction du temps :
	        make yt
	Pour obtenir le nombre de proies en fonction du nombre de prédateurs :
	        make xy
	Pour obtenir toutes les courbes en même temps :
	        make
	     ou make all
	Le répertoire graphes/src_solution/ contient les sources et scripts pour 
	tracer les solutions approchées du système de Lotka-Volterra. Le 
	programme app.exe peut être compilé depuis le répertoire graphes/ avec 
	la commande :
	        make app.exe
	L'exécution du programme app.exe n"cessite en argument un fichier
	comportant les paramètres suivants séparés d'un espace :
		x0 y0 alpha beta gamma sigma t_0 t_final Nombre_de_points
	Un exemple de fichier est donné : graphes/parameters.txt ;
	L'exécution de app.exe génère les données resXt.dat, resYt.dat et
	resXY.dat dans le répertoire graphes/data/ ;
	Pour obtenir les courbes manuellement (nécessite les fichiers
	graphes/data/*.dat), taper depuis le répertoire graphes/ :
	        gnuplot src_solution/scriptXt.gnuplot
	        gnuplot src_solution/scriptYt.gnuplot
	        gnuplot src_solution/scriptXY.gnuplot

	Pour obtenir le portrait de phase au format tikz, on pourra compiler le
	programme phase.exe par :
	        make phase.exe
	L'exécution se fait par :
	        ./phase.exe NB_LIGNES NB_COLONNES ALPHA BETA SIGMA GAMMA
