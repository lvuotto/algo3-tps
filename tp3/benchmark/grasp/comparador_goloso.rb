#!/usr/bin/env ruby

seed = ARGV[0]
variable_analizar = ARGV[1]
pasarle_local = ARGV[2] || false

raise 'Hay que setear la variable a inicializar' unless variable_analizar


PATH_DENSO_PESOS_DISTINTOS = 'benchmark/generadores/denso_pesos_distintos.rb SEED N K'

PATH_TMP_GRAFO = 'tmp_grafo.tmp'

def obtener_resultados(metodo)

  [output[3].to_i, output[4].to_f]
end

# n nada_tiempo nada_peso aristas_tiempo arsitas_peso conjuntos_tiempo conjuntos_peso ambos_tiempo ambos_peso
case variable_analizar
when 'x'
  desde = 2
  hasta = 15
when 'k'
  desde = 2
  hasta = 50
when 'n'
  desde = 1
  hasta = 500
end
desde.upto(hasta) do |var|
  n = 500
  k = 15
  x = 10

  case variable_analizar
  when 'x'
    x = var
  when 'k'
    k = var
  when 'n'
    next unless (var % 20).zero?
    n = var
  end

  # Genero el grafo
  path = PATH_DENSO_PESOS_DISTINTOS.gsub('SEED', seed.to_s).gsub('N', n.to_s).gsub('K', k.to_s)
  %x(#{path} > #{PATH_TMP_GRAFO})

  resultado = [var]

  if pasarle_local
    # Aleatorizar nada
    %x(bin/kpmp -g -r nada -A #{x} -C #{x} 2>&1 < #{PATH_TMP_GRAFO} >> #{PATH_TMP_GRAFO})
    output = %x(bin/kpmp -l -v mover 2>&1 < #{PATH_TMP_GRAFO}).split(' ')

    resultado << output[3]
    resultado << output[4]

    %x(#{path} > #{PATH_TMP_GRAFO})
    # Aleatorizar aristas
    %x(bin/kpmp -g -r aristas -A #{x} -C #{x} 2>&1 < #{PATH_TMP_GRAFO} >> #{PATH_TMP_GRAFO})
    output = %x(bin/kpmp -l -v mover 2>&1 < #{PATH_TMP_GRAFO}).split(' ')

    resultado << output[3]
    resultado << output[4]

    %x(#{path} > #{PATH_TMP_GRAFO})
    # Aleatorizar conjuntos
    %x(bin/kpmp -g -r conjuntos -A #{x} -C #{x} 2>&1 < #{PATH_TMP_GRAFO} >> #{PATH_TMP_GRAFO})
    output = %x(bin/kpmp -l -v mover 2>&1 < #{PATH_TMP_GRAFO}).split(' ')

    resultado << output[3]
    resultado << output[4]

    %x(#{path} > #{PATH_TMP_GRAFO})
    # Aleatorizar ambos
    %x(bin/kpmp -g -r ambos -A #{x} -C #{x} 2>&1 < #{PATH_TMP_GRAFO} >> #{PATH_TMP_GRAFO})
    output = %x(bin/kpmp -l -v mover 2>&1 < #{PATH_TMP_GRAFO}).split(' ')

    resultado << output[3]
    resultado << output[4]
  else

    # Aleatorizar Nada
    output = %x(bin/kpmp -g -r nada -A #{x} -C #{x} 2>&1 < #{PATH_TMP_GRAFO}).split(' ')

    resultado << output[3]
    resultado << output[4]

    # Aleatorizar aristas
    output = %x(bin/kpmp -g -r aristas -A #{x} -C #{x} 2>&1 < #{PATH_TMP_GRAFO}).split(' ')

    resultado << output[3]
    resultado << output[4]

    # Aleatorizar conjuntos
    output = %x(bin/kpmp -g -r conjuntos -A #{x} -C #{x} 2>&1 < #{PATH_TMP_GRAFO}).split(' ')

    resultado << output[3]
    resultado << output[4]

    # Aleatorizar ambos
    output = %x(bin/kpmp -g -r ambos -A #{x} -C #{x} 2>&1 < #{PATH_TMP_GRAFO}).split(' ')

    resultado << output[3]
    resultado << output[4]
  end

  puts resultado.join(' ')
end
