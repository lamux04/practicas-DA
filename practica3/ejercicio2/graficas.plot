# Título de la gráfica.

titulo = 'Potencia clásica y potencia rápida'
subtitulo = 'Tiempo en segundos frente a exponente'
set title titulo."\n".subtitulo

# Etiquetas de los ejes.

set xlabel 'n'
set ylabel 't(n)'

# Rejilla.

set xtics 8
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

plot 'prueba-1.tmp' title 'Potencia clásica'

plot 'prueba-2.tmp' title 'Potencia rápida'

plot 'prueba-1.tmp' title 'Potencia clásica', \
     'prueba-2.tmp' title 'Potencia rápida'

# Representación en PDF.

set encoding locale
set terminal pdf size 16cm,10cm linewidth 2

set linetype 1 pointsize 0.5
set linetype 2 pointsize 0.5

set output 'prueba-1-y-2.pdf'
plot 'prueba-1.tmp' title 'Potencia clásica', \
     'prueba-2.tmp' title 'Potencia rápida'

set title subtitulo

set output 'prueba-1.pdf'
plot 'prueba-1.tmp' title 'Potencia clásica' 

set output 'prueba-2.pdf'
plot 'prueba-2.tmp' title 'Potencia rápida' linetype 2
