#!/usr/bin/env ruby

srand(ARGV[0] ? ARGV[0].to_i : 1)
n = ARGV[1] ? ARGV[1].to_i : 1 + rand(100)
m = ARGV[2] ? ARGV[2].to_i : 1 + rand(100)
k = ARGV[3] ? ARGV[3].to_i : 1 + rand(100)
cant_componentes = ARGV[4] ? ARGV[4].to_i : 1 + rand(100)

peso_maximo = 15_000

componentes = 1.upto(n).each_slice(cant_componentes).to_a

aristas = []

componentes.each do |componente|
  componente[1..-1].each_with_index do |vertice, index|
    aristas << [componente[index - 2], vertice, rand(peso_maximo) / 100.0]
  end
end

p aristas
