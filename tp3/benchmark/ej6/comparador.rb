#!/usr/bin/env ruby

k = ARGV[0]
tipo_grafo = ARGV[1]

raise 'Tenes que poner k y tipo_grafo' unless tipo_grafo && k

PATH_TMP_GRAFO = 'tmp_grafo.tmp'

MEJOR = "bin/kpmp -G -r aristas -A 10 -v mover -c cuando_el_mejor_se_repita_x_veces -R 34 2>&1 < #{PATH_TMP_GRAFO}"
EXACTO = "bin/kpmp -e 2>&1 < #{PATH_TMP_GRAFO}"
GOLOSO = "bin/kpmp -g -r nada 2>&1 < #{PATH_TMP_GRAFO}"
GRASP_AMBOS = "bin/kpmp -G -r ambos -A 10 -C 10 -v mover -c cuando_el_mejor_se_repita_x_veces -R 34 2>&1 < #{PATH_TMP_GRAFO}"
GRASP_INTERCAMBIAR = "bin/kpmp -G -r aristas -A 10 -v intercambiar -c cuando_el_mejor_se_repita_x_veces -R 34 2>&1 < #{PATH_TMP_GRAFO}"
GRASP_OTRO_CRITERIO = "bin/kpmp -G -r aristas -A 10 -v mover -c mejor_luego_de_x_veces -R 47 2>&1 < #{PATH_TMP_GRAFO}"


PATH_DENSO_PESOS_DISTINTOS = 'benchmark/generadores/denso_pesos_distintos.rb SEED N K'
PATH_DENSO_PESOS_IGUALES = 'benchmark/generadores/denso_pesos_iguales.rb SEED N K'
PATH_COMPLETO = 'benchmark/generadores/completo.rb SEED N K'
PATH_ARBOL = 'benchmark/generadores/arbol.rb SEED N K'



# 1: n
# 2: mejor_tiempo
# 3: mejor_peso
# 4: exacto_tiempo
# 5: exacto_peso
# 6: goloso_tiempo
# 7: goloso_peso
# 8: grasp_ambos_tiempo
# 9: grasp_ambos_peso
# 10: grasp_intercambiar_tiempo
# 11: grasp_intercambiar_peso
# 12: grasp_otro_criterio_tiempo
# 13: grasp_otro_criterio_peso

grafo = Object.const_get "PATH_#{tipo_grafo.upcase}"

1.upto(50) do |n|

  resultado = [n, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0]

  1.upto(15).each do |seed|
    # Genero el grafo
    path = grafo.gsub('SEED', seed.to_s).gsub('N', n.to_s).gsub('K', k.to_s)
    %x(#{path} > #{PATH_TMP_GRAFO})

    output = %x(#{MEJOR}).split(' ')

    resultado[1] += output[3].to_i
    resultado[2] += output[4].to_f

    if n < 17
      output = %x(#{EXACTO}).split(' ')

      if n > 16
        resultado[3] = '-'
      else
        resultado[3] += output[3].to_i
      end
      resultado[4] += output[4].to_f
    else
      resultado[3] = '-'
      resultado[4] = '-'
    end

    output = %x(#{GOLOSO}).split(' ')

    resultado[5] += output[3].to_i
    resultado[6] += output[4].to_f

    output = %x(#{GRASP_AMBOS}).split(' ')

    resultado[7] += output[3].to_i
    resultado[8] += output[4].to_f

    output = %x(#{GRASP_INTERCAMBIAR}).split(' ')

    resultado[9] += output[3].to_i
    resultado[10] += output[4].to_f

    output = %x(#{GRASP_OTRO_CRITERIO}).split(' ')

    resultado[11] += output[3].to_i
    resultado[12] += output[4].to_f
  end

  puts resultado.join(' ')
end
