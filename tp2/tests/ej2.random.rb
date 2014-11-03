#!/usr/bin/ruby

seed = ARGV[0].to_i
n = ARGV[1].to_i
k = ARGV[2].to_i

srand(seed)

puts "#{n} #{k}"

1.upto(k) do |i|
  begin
    puts "#{rand(n) + 1} #{rand(n)+1}"
  rescue Errno::EPIPE
    exit(74)
  end
end
