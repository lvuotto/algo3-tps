#!/usr/bin/ruby

seed = ARGV[0].to_i
ciudades = ARGV[1].to_i
vuelos = ARGV[2].to_i

srand(seed)

puts "0 1 #{vuelos}"

(1..vuelos).each do
  ini = rand(vuelos * 10)
  fin = ini + 5
  puts "#{rand(ciudades)} #{rand(ciudades)} #{ini} #{fin}"
end
