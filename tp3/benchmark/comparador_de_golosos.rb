#!/usr/bin/env ruby

seed = ARGV[0] ? ARGV[0].to_i : 1

sin_random_mejor = 0
aristas_mejor = 0
conjuntos_mejor = 0
ambos_mejor = 0

1.upto(100) do |n|
  1.upto(10) do |k|
    sin_random = %x(benchmark/denso_pesos_distintos.rb #{seed} #{n} #{k} | bin/kpmp -g 2>&1).split(' ')[4].to_f
    aristas = %x(benchmark/denso_pesos_distintos.rb #{seed} #{n} #{k} | bin/kpmp -g -r aristas 2>&1).split(' ')[4].to_f
    conjuntos = %x(benchmark/denso_pesos_distintos.rb #{seed} #{n} #{k} | bin/kpmp -g -r conjuntos 2>&1).split(' ')[4].to_f
    ambos = %x(benchmark/denso_pesos_distintos.rb #{seed} #{n} #{k} | bin/kpmp -g -r ambos 2>&1).split(' ')[4].to_f

    min = [sin_random, aristas, conjuntos, ambos].min

    sin_random_mejor += 1 if sin_random == min
    aristas_mejor += 1 if aristas == min
    conjuntos_mejor += 1 if conjuntos == min
    ambos_mejor += 1 if ambos == min
  end
end

puts sin_random_mejor
puts aristas_mejor
puts conjuntos_mejor
puts ambos_mejor