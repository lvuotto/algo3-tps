#!/usr/bin/ruby

seed = ARGV[0].to_i
pcs = ARGV[1].to_i
enlaces_maximos = ARGV[2].to_i
costo_maximo = ARGV[3].to_i

srand(seed)

enlaces = []
(1..pcs).each do |i|
  (1..pcs).each do |j|
    enlaces << [i, j] if i < j
  end
end

enlaces.shuffle!

enlaces_maximos = [enlaces.count, enlaces_maximos].min

puts "#{pcs} #{pcs - 1 + enlaces_maximos}"
1.upto(pcs - 1) do |i|
  puts "#{i} #{i + 1} #{rand(costo_maximo)}"
end

(1..enlaces_maximos).each do
  pc1, pc2 = enlaces.pop
  begin
    puts "#{pc1} #{pc2} #{rand(costo_maximo)}"
  rescue Errno::EPIPE
    exit(74)
  end
end
