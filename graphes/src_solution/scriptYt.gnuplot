set terminal svg enhanced background rgb 'white' size 700,400
set output "courbeYt.svg"
#set title "Évolution de la population de prédateurs en fonction du temps" font ", 18"
set grid
set nokey
set xlabel "Temps" font ", 16" offset 2
set ylabel "Nombre de prédateurs" font ", 16" offset 2
plot './data/resYt.dat' lt rgb "#FF4500" with lines
