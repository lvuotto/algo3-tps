#!/usr/bin/env ruby

r = srand((ARGV[0] && ARGV[0].to_i) || 0)
n = (ARGV[1] && ARGV[1].to_i) || 100
m = (ARGV[2] && ARGV[2].to_i) || (1 + rand(n))

puts "#{n} #{m}"
2.upto(n) do |i|
  $stdout << "#{rand n}"
  (i + 1).upto(n) do
    $stdout << " #{rand n}"
  end
  puts
end
puts 0
