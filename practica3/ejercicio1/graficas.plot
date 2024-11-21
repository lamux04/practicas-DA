# Variables con los nombres de los ficheros.

if (!exists("datos")) datos='potencia-rapida.txt'
if (!exists("graficas")) graficas='potencia-rapida.pdf'

# Título de la gráfica.

titulo = 'Algoritmo de potencia rápida'
subtitulo = 'Productos matriciales frente a exponentes'
set title titulo."\n".subtitulo

# Etiquetas de los ejes.

set xlabel 'n'
set ylabel 't(n)'

# Rejilla.

set xtics 8
set ytics 3
set grid linestyle -1

# Posición de la leyenda.

set key left top

# Logaritmo binario.

lg(n) = log(n) / log(2)

# Estilo.

set style data linespoints

set linetype 1 linecolor rgb 'red'
set linetype 2 linecolor rgb 'blue' pointtype 7
set linetype 3 linecolor rgb 'dark-green'

# Representación gráfica.

set terminal qt size 1920,1080 title titulo linewidth 4 persist

set linetype 2 pointsize 2

plot [n=1:64] 2 * lg(n + 1) - 2 title '2·lg(n+1) - 2',      \
              datos using 1:4 title 't(n)', \
	      lg(n) title 'lg n'

# Representación en PDF.

set encoding locale
set terminal pdf size 16cm,10cm linewidth 2
set output graficas

set linetype 2 pointsize 0.5

replot
