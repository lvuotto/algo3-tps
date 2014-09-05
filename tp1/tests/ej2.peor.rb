#!/usr/bin/env ruby

r = srand((ARGV[0] && ARGV[0].to_i) || 0)
n = (ARGV[1] && ARGV[1].to_i) || 100

puts "#{n}"
a = []
1.upto(n) do |h|
  a << h
end
a.shuffle!
0.upto(n-1) do |i|
  pd = 2*n - i
  pi = i + 1
  puts "#{pi} #{a[i]} #{pd}"
end
puts "0"
