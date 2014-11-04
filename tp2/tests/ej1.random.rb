#!/usr/bin/ruby

seed = ARGV[0].to_i
ciudades = ARGV[1].to_i
vuelos = ARGV[2].to_i
max_horario = ARGV[3].to_i

srand(seed)

puts "0 1 #{vuelos}"

(1..vuelos).each do
  ini = rand(max_horario)
  fin = ini + 1 + rand(5)
  begin
    puts "#{rand(ciudades)} #{rand(ciudades)} #{ini} #{fin}"
  rescue Errno::EPIPE
    exit(74)
  end
end
