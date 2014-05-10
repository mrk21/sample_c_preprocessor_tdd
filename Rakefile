CXX = ENV['CXX'] || 'g++'
CXXFLAGS = [ENV['CXXFLAGS'], '-Wno-invalid-pp-token -E -P -x c++'].compact.join(' ')

task :default do
  sh "#{CXX} #{CXXFLAGS} test.rb | ruby - -v"
end
