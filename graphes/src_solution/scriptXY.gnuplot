set terminal svg enhanced background rgb 'white' size 700,600
set output "courbeXY.svg"
#set title "Portrait de phase : évolution de la population de prédateurs en fonction du nombre de proies" font ", 18"
set nokey
set grid
set xlabel "Nombre de proies" font ", 16" offset 2
set ylabel "Nombre de prédateurs" font ", 16" offset 2
#unset border
#unset xtics
#unset ytics
plot './data/resXY.dat' lt rgb "#FF4500" with lines
