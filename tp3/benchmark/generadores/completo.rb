#!/usr/bin/env ruby

srand(ARGV[0] ? ARGV[0].to_i : 1)
n = ARGV[1] ? ARGV[1].to_i : 1 + rand(100)
k = ARGV[2] ? ARGV[2].to_i : 1 + rand(100)


aristas = []
(1..n).each do |i|
  (1..n).each do |j|
    aristas << [i, j] if i < j
  end
end

aristas.shuffle!

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
