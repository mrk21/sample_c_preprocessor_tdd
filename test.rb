require 'minitest'
require 'minitest/autorun'

class TestPreprocessor < MiniTest::Test
  CPP_CODE = <<-CPP
    #include "preprocessor.hpp"
  CPP
  
  def format(cpp_code)
    cpp_code.gsub(/^\s+/,'').gsub(/\s+$/,'').gsub(/\s+/,' ').strip
  end
  
  def test_STRINGIFIABLE_ENUM_NAME_LIST
    assert_equal format(<<-SUBJECT_CPP), format(<<-EXPECTED_CPP)
      STRINGIFIABLE_ENUM_NAME_LIST(my_enum,
        a,
        b,
        c
      )
    SUBJECT_CPP
      {my_enum::a, "a"},
      {my_enum::b, "b"},
      {my_enum::c, "c"},
    EXPECTED_CPP
  end
end
