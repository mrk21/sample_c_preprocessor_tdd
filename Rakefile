CXX = ENV['CXX'] || 'g++'

task :default => :test

task :test do
  sh "#{CXX} -std=gnu++11 -E -P -Wno-invalid-pp-token -x c++ test.rb | ruby - -v"
end

task :main do
  sh "#{CXX} -std=gnu++11 main.cpp && ./a.out"
end
