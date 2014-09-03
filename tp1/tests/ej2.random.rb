#!/usr/bin/env ruby

r = srand((ARGV[0] && ARGV[0].to_i) || 0)
n = (ARGV[1] && ARGV[1].to_i) || 100
h = (ARGV[2] && ARGV[2].to_i) || (1 + rand(2*n))
w = (ARGV[3] && ARGV[3].to_i) || (1 + rand(3*n))

puts "#{n}"
1.upto(n) do
  pd = rand(w)
  pi = rand(w)
  until pi != pd do
    pd = rand(w)
    pi = rand(w)
  end
  if pi > pd then
    pi, pd = pd, pi
  end

  puts "#{pi} #{1 + rand(h)} #{pd}"
end
puts "0"
