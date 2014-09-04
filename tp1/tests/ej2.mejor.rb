#!/usr/bin/env ruby

n = ARGV[0].to_i

puts "#{n}"

puts "1 10 #{n*2+2}"

1.upto(n - 1) do |i|
  puts "#{i*2 + 1} 1 #{i*2 + 2}"
end

puts "0"
