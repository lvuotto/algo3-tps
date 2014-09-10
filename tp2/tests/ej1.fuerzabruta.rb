#!/usr/bin/ruby

Vuelo = Struct.new(:id, :origen, :destino, :salida, :llegada)

class Array
  def powerset
    if empty?
      [[]]
    else
      ps = self[1..-1].powerset
      ps.map{|i| self[0,1] + i} + ps
    end
  end
end

def viaje_valido?(vuelos, origen, destino)
  vs = vuelos.dup

  return false if vs.empty? || vs.first.origen != origen || vs.last.destino != destino

  anterior = vs.shift

  vs.each do |v|
    return false if anterior.destino != v.origen || anterior.llegada > v.salida - 2

    anterior = v
  end

  true
end


origen_inicial, destino_final, cant_vuelos = STDIN.readline.chomp.split(' ')

vuelos = (1..cant_vuelos.to_i).map do |i|
  origen, destino, ini, fin = STDIN.readline.chomp.split(' ')
  Vuelo.new(i, origen, destino, ini.to_i, fin.to_i)
end


caminos_completos = vuelos.powerset.map do |vuelos|
  vuelos.sort_by! { |v| v.llegada }

  vuelos if viaje_valido?(vuelos, origen_inicial, destino_final)
end.compact

camino_optimo = caminos_completos.sort_by { |vuelos| vuelos.last.llegada }.first

if camino_optimo
  puts "#{camino_optimo.last.llegada} #{camino_optimo.size} #{camino_optimo.map(&:id).join(' ')}"
else
  puts 'no'
end
