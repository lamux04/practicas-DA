# Título de la gráfica.

titulo = 'Ordenación por fusión y ordenación rápida'
subtitulo = 'Tiempo en segundos frente a número de elementos'
set title titulo."\n".subtitulo

# Etiquetas de los ejes.

set xlabel 'n'
set ylabel 't(n)'

# Formato exponencial para el eje de abscisas.

set format x '%.0t·10^{%T}'

# Rejilla.

set xtics 100000
set grid linestyle -1

# Posición de la leyenda.

set key left top

# Estilo.

set style data linespoints

set linetype 1 linecolor rgb 'red' pointtype 7
set linetype 2 linecolor rgb 'blue' pointtype 7

# Representación gráfica.

set terminal qt size 1920,1080 title titulo linewidth 4 persist

set linetype 1 pointsize 2
set linetype 2 pointsize 2

plot 'prueba-1.tmp' title 'Ordenación por fusión', \
     'prueba-2.tmp' title 'Ordenación rápida'

# Representación en PDF.

set encoding locale
set terminal pdf size 16cm,10cm linewidth 2
set output 'prueba.pdf'

set linetype 1 pointsize 0.5
set linetype 2 pointsize 0.5

replot
