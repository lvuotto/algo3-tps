#!/usr/bin/env ruby

srand(ARGV[0] ? ARGV[0].to_i : 1)
n = ARGV[1] ? ARGV[1].to_i : 1 + rand(100)
k = ARGV[2] ? ARGV[2].to_i : 1 + rand(100)

peso_maximo = 15_000
puts "#{n} #{n - 1} #{k}"
2.upto(n) do |v|
  begin
    puts "1 #{v} #{rand(peso_maximo) / 100.0}"
  rescue Errno::EPIPE
    exit(74)
  end
end
