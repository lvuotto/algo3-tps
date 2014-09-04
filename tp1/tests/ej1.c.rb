#!/usr/bin/env ruby

srand((ARGV[0] && ARGV[0].to_i) || 0)
c = (ARGV[1] && ARGV[1].to_i) || (1 + rand((1.2*10000).to_i))

$stdout << "10000 #{c}"
1.upto(10000) do 
  $stdout << " #{rand(2)}"
end
$stdout << "\n"

puts "0"
