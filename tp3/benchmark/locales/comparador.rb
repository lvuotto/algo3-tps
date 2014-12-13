#!/usr/bin/env ruby

seed = ARGV[0] || 1
sobre_k = ARGV[1] || false


PATH_DENSO_PESOS_DISTINTOS = 'benchmark/generadores/denso_pesos_distintos.rb SEED N K'

PATH_TMP_GRAFO = 'tmp_grafo.tmp'

def obtener_resultados(metodo)
  output = %x(bin/kpmp -l -v #{metodo} 2>&1 < #{PATH_TMP_GRAFO}).split(' ')
  [output[3].to_i, output[4].to_f]
end

# n random_mover_tiempo random_mover_peso random_intercambiar_tiempo random_intercambiar_peso goloso_mover_tiempo goloso_mover_peso goloso_intercambiar_tiempo goloso_intercambiar_peso
if sobre_k
  desde = 2
  hasta = 50
else
  desde = 1
  hasta = 500
end
desde.upto(hasta) do |n|
  if sobre_k
    k = n
    n = 200
  else
    next unless (n % 20).zero?
    k = 10
  end

  # Genero el grafo
  path = PATH_DENSO_PESOS_DISTINTOS.gsub('SEED', seed.to_s).gsub('N', n.to_s).gsub('K', k.to_s)
  %x(#{path} > #{PATH_TMP_GRAFO})

  # Agrego la solución random
  %x(bin/kpmp -g -r conjuntos -C #{k} < #{PATH_TMP_GRAFO} >> #{PATH_TMP_GRAFO})

  resultado = [n]
  resultado[0] = k if sobre_k

  resultado += obtener_resultados('mover')
  resultado += obtener_resultados('intercambiar')

  # Genero el grafo
  path = PATH_DENSO_PESOS_DISTINTOS.gsub('SEED', seed.to_s).gsub('N', n.to_s).gsub('K', k.to_s)
  %x(#{path} > #{PATH_TMP_GRAFO})

  # Agrego la solución golosa sin random
  %x(bin/kpmp -g -r nada < #{PATH_TMP_GRAFO} >> #{PATH_TMP_GRAFO})

  resultado += obtener_resultados('mover')
  resultado += obtener_resultados('intercambiar')

  puts resultado.join(' ')
end
