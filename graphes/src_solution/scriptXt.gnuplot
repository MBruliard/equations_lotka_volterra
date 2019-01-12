set terminal svg enhanced background rgb 'white' size 700,400
set output "courbeXt.svg"
#set title "Évolution de la population de proies en fonction du temps" font ", 18"
set grid
set nokey
set xlabel "Temps" font ", 16" offset 2
set ylabel "Nombre de proies" font ", 16" offset 1
plot './data/resXt.dat' lt rgb "#FF4500" with lines
