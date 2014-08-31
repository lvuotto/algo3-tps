#!/usr/bin/env ruby

r = Random.new((ARGV[0] && ARGV[0].to_i) || 0)
n = (ARGV[1] && ARGV[1].to_i) || 100
m = (ARGV[2] && ARGV[2].to_i) || r.rand(1..n)

puts "#{n} #{m}"
2.upto(n) do |i|
  $stdout << "#{r.rand n}"
  (i + 1).upto(n) do
    $stdout << " #{r.rand n}"
  end
  puts
end
puts 0
