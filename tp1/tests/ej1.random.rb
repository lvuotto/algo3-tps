#!/usr/bin/env ruby

r = Random.new((ARGV[0] && ARGV[0].to_i) || 0)
n = (ARGV[1] && ARGV[1].to_i) || 100
c = (ARGV[2] && ARGV[2].to_i) || (1 + r.rand((1.2*n).to_i))

$stdout << "#{n} #{c}"
1.upto(n) do 
  $stdout << " #{r.rand(2)}"
end
$stdout << "\n"

puts "0"
