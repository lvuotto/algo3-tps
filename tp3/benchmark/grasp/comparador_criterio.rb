#!/usr/bin/env ruby

PATH_DENSO_PESOS_DISTINTOS = 'benchmark/generadores/denso_pesos_distintos.rb SEED N K'
PATH_COMPLETO = 'benchmark/generadores/completo.rb SEED N K'

PATH_TMP_GRAFO = 'tmp_grafo.tmp'


# n repetir_tiempo repetir_peso mejor_tiempo mejor_peso
desde = 1
hasta = 50

n = 200
k = 15
x = 10
r = 'aristas'
v = 'mover'

desde.upto(hasta) do |var|

  resultado = [var, 0, 0.0, 0, 0.0]

  1.upto(15).each do |seed|
    # Genero el grafo
    path = PATH_DENSO_PESOS_DISTINTOS.gsub('SEED', seed.to_s).gsub('N', n.to_s).gsub('K', k.to_s)
    %x(#{path} > #{PATH_TMP_GRAFO})

    output = %x(bin/kpmp -G -r #{r} -A #{x} -v #{v} -c mejor_luego_de_x_veces -R #{var} 2>&1 < #{PATH_TMP_GRAFO}).split(' ')

    resultado[1] += output[3].to_i
    resultado[2] += output[4].to_f

    output = %x(bin/kpmp -G -r #{r} -A #{x} -v #{v} -c cuando_el_mejor_se_repita_x_veces -R #{var} 2>&1 < #{PATH_TMP_GRAFO}).split(' ')

    resultado[3] += output[3].to_i
    resultado[4] += output[4].to_f
  end

  1.upto(15).each do |seed|
    # Genero el grafo
    path = PATH_COMPLETO.gsub('SEED', seed.to_s).gsub('N', (n - seed * 5).to_s).gsub('K', k.to_s)
    %x(#{path} > #{PATH_TMP_GRAFO})

    output = %x(bin/kpmp -G -r #{r} -A #{x} -v #{v} -c mejor_luego_de_x_veces -R #{var} 2>&1 < #{PATH_TMP_GRAFO}).split(' ')

    resultado[1] += output[3].to_i
    resultado[2] += output[4].to_f

    output = %x(bin/kpmp -G -r #{r} -A #{x} -v #{v} -c cuando_el_mejor_se_repita_x_veces -R #{var} 2>&1 < #{PATH_TMP_GRAFO}).split(' ')

    resultado[3] += output[3].to_i
    resultado[4] += output[4].to_f
  end

  puts resultado.join(' ')
end
