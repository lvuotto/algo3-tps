#!/usr/bin/env ruby

srand(ARGV[0] ? ARGV[0].to_i : 1)
n = ARGV[1] ? ARGV[1].to_i : 1 + rand(100)
k = ARGV[2] ? ARGV[2].to_i : 1 + rand(100)


nodos = 1.upto(n).to_a.shuffle
nodos_agregados = []
aristas = []

nodos.each do |nodo|
  if nodos_agregados.size > 0
    aristas << [nodo, nodos_agregados.shuffle.first]
  end

  nodos_agregados << nodo
end

peso_maximo = 15_000

puts "#{n} #{aristas.size} #{k}"

(1..aristas.size).each do
  vertice1, vertice2 = aristas.pop
  begin
    puts "#{vertice1} #{vertice2} #{rand(peso_maximo) / 100.0}"
  rescue Errno::EPIPE
    exit(74)
  end
end
