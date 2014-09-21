n = ARGV[0].to_i
k = ARGV[1].to_i

puts "#{n} #{k}"

1.upto(k) do |i|
  puts "#{rand(n) + 1} #{rand(n)+1}"
end
