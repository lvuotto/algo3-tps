#!/usr/bin/env ruby

r = Random.new((ARGV[0] && ARGV[0].to_i) || 0)
n = (ARGV[1] && ARGV[1].to_i) || 100
h = (ARGV[2] && ARGV[2].to_i) || (1 + r.rand(2*n))
w = (ARGV[3] && ARGV[3].to_i) || (1 + r.rand(3*n))

puts "#{n}"
1.upto(n) do
  pd = r.rand(w)
  pi = r.rand(w)
  until pi != pd do
    pd = r.rand(w)
    pi = r.rand(w)
  end
  if pi > pd then
    pi, pd = pd, pi
  end

  puts "#{pi} #{1 + r.rand(h)} #{pd}"
end
puts "0"
