#!/usr/bin/env ruby

r = srand((ARGV[0] && ARGV[0].to_i) || 0)
n = (ARGV[1] && ARGV[1].to_i) || 100

puts "#{n}"
1.upto(n) do |h|
  pd = 20
  pi = 1
  puts "#{pi} #{h} #{pd}"
end
puts "0"
