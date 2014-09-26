#!/usr/bin/ruby

seed = ARGV[0].to_i
n = ARGV[1].to_i
k = ARGV[2].to_i

srand(seed)

puts "#{n} #{k}"

1.upto(k) do |i|
  puts "#{rand(n) + 1} #{rand(n)+1}"
end
