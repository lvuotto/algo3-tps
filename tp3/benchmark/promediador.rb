#!/usr/bin/ruby

lines = STDIN.readlines

lines.each_slice(5) do |a, b, c, d, e|
  a, b, c, d, e = a.split(' '), b.split(' '), c.split(' '), d.split(' '), e.split(' ')
  tiempos = [a[3].to_f, b[3].to_f, c[3].to_f, d[3].to_f, e[3].to_f]
  pesos = [a[4].to_f, b[4].to_f, c[4].to_f, d[4].to_f, e[4].to_f]
  STDOUT.write "#{a[0]} #{a[1]} #{a[2]} #{tiempos.inject(0.0, &:+) / tiempos.size} #{pesos.inject(0.0, &:+) / pesos.size}\n"
end