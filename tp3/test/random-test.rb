#!/usr/bin/env ruby

srand(ARGV[0] ? ARGV[0].to_i : 1)
n = ARGV[1] ? ARGV[1].to_i : 1 + rand(100)
m = ARGV[2] ? ARGV[2].to_i : 1 + rand(100)
k = ARGV[3] ? ARGV[3].to_i : 1 + rand(100)

peso = [n, m].max
puts "#{n} #{m} #{k}"
1.upto(m) do
  puts "#{1 + rand(n)} #{1 + rand(n)} #{peso * rand()}"
end
