#!/usr/bin/ruby

seed = ARGV[0].to_i
pcs = ARGV[1].to_i
costo_maximo = ARGV[2].to_i

srand(seed)

enlaces = []
(1..(pcs / 2)).each do |i|
  (1..(pcs / 2)).each do |j|
    enlaces << [i, j] if i < j
  end
end

((pcs / 2 + 1)..pcs).each do |i|
  ((pcs / 2 + 1)..pcs).each do |j|
    enlaces << [i, j] if i < j
  end
end

enlaces.shuffle!


puts "#{pcs} #{enlaces.count}"

enlaces.each do |enlace|
  pc1, pc2 = enlace
  puts "#{pc1} #{pc2} #{rand(costo_maximo)}"
end
