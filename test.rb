require 'minitest'
require 'minitest/autorun'

class TestPreprocessor < MiniTest::Test
  CPP_CODE = <<-CPP
    #include "preprocessor.hpp"
  CPP
  
  def cxxpp(cpp_code)
    cpp_code.gsub(/^\s+/,'').gsub(/\s+$/,'').gsub(/\s+/,' ').strip
  end
  
  def test_HOGE
    assert_equal cxxpp(<<-CPP), 'hoge'
      HOGE
    CPP
  end
  
  def test_INITIALIZER_LIST
    assert_equal cxxpp(<<-CPP), '{ {type::a, "a"}, {type::b, "b"}, {type::c, "c"} }'
      INITIALIZER_LIST(a,b,c)
    CPP
  end
end
