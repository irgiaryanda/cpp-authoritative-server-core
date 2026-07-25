add_test([=[MovementValidatorTest.ValidMovement]=]  C:/Users/irgia/OneDrive/Dokumen/VassagoLabs_Projects/cpp-authoritative-server-core/build/tests/Debug/server_tests.exe [==[--gtest_filter=MovementValidatorTest.ValidMovement]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MovementValidatorTest.ValidMovement]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\irgia\OneDrive\Dokumen\VassagoLabs_Projects\cpp-authoritative-server-core\tests\validation_tests.cpp:5]==]
    WORKING_DIRECTORY [==[C:/Users/irgia/OneDrive/Dokumen/VassagoLabs_Projects/cpp-authoritative-server-core/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[MovementValidatorTest.SpeedhackBlocked]=]  C:/Users/irgia/OneDrive/Dokumen/VassagoLabs_Projects/cpp-authoritative-server-core/build/tests/Debug/server_tests.exe [==[--gtest_filter=MovementValidatorTest.SpeedhackBlocked]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MovementValidatorTest.SpeedhackBlocked]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\irgia\OneDrive\Dokumen\VassagoLabs_Projects\cpp-authoritative-server-core\tests\validation_tests.cpp:21]==]
    WORKING_DIRECTORY [==[C:/Users/irgia/OneDrive/Dokumen/VassagoLabs_Projects/cpp-authoritative-server-core/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(server_tests_TESTS [==[MovementValidatorTest.ValidMovement]==] [==[MovementValidatorTest.SpeedhackBlocked]==])
