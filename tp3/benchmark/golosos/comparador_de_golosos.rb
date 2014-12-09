#!/usr/bin/env ruby

seed = ARGV[0]

cantidad_veces_mejor_resultado = Hash.new(Hash.new(Hash.new(Hash.new(Hash.new(Hash.new(Hash.new([])))))))

generadores = %i(denso_pesos_iguales denso_pesos_distintos completo arbol)

# cantidad_veces_mejor_resultado[generador][n][m][k][a][c]

PATH_DENSO_PESOS_DISTINTOS = 'generadores/denso_pesos_distintos.rb SEED N K'
PATH_DENSO_PESOS_IGUALES = 'generadores/denso_pesos_iguales.rb SEED N K'
PATH_COMPLETO = 'generadores/completo.rb SEED N K'
PATH_ARBOL = 'generadores/arbol.rb SEED N K'
PATH_BIPARTITO = 'generadores/bipartito.rb SEED N M K'

PATH_TMP_GRAFO = '/tmp/grafo.txt'

def obtener_peso(grafo, random_method, random_aristas, random_conjuntos)
  %x(bin/kpmp -g -r #{random_method} -A #{random_aristas} -C #{random_conjuntos} 2>&1 < #{PATH_TMP_GRAFO}).split(' ')[4].to_f
end

1.upto(100).each do |n|
  max_m = n * (n - 1) / 2
  0.upto(1).each do |m|
    2.upto(15).each do |k|
      generadores.each do |generador|
        next if m > 0 && generador != :bipartito

        if seed
          seeds = [seed]
        else
          seeds = 1.upto(5)
        end

        seeds.each do |seed|
          path = Object.const_get("path_#{generador}".upcase).gsub('SEED', seed.to_s).gsub('N', n.to_s).gsub('K', k.to_s).gsub('M', m.to_s)
          grafo = %x(#{File.expand_path File.dirname(__FILE__)}/#{path} > #{PATH_TMP_GRAFO})

          puts "#{generador},#{n},#{m},#{k},-1,-1,sin_random,#{obtener_peso(grafo, 'nada', 0, 0)}"

          2.upto(10).each do |a|
            puts "#{generador},#{n},#{m},#{k},#{a},-1,aristas,#{obtener_peso(grafo, 'aristas', a, 0)}"

            2.upto(10).each do |c|
              puts "#{generador},#{n},#{m},#{k},-1,#{c},conjuntos,#{obtener_peso(grafo, 'conjuntos', 0, c)}"
              puts "#{generador},#{n},#{m},#{k},#{a},#{c},ambos,#{obtener_peso(grafo, 'ambos', a, c)}"

              STDERR.write "n: #{n} m: #{m} k: #{k} g: #{generador} s: #{seed} a: #{a} c: #{c}\n"
            end
          end
        end
      end
    end
  end
end
