# OUTCOME OF TESTS FOR PROJECT shopping1_s

As of Mar 15 2021 17:55:59

| ID | NAME | RESULT | COMMENTS |
| :----- |:------ | :---: | :---: |
| 1::1 | _01_Basics.DateTime_Constructors | PASSED | OK |
| 1::2 | _01_Basics.DateTime_Constructors | PASSED | OK |
| 2::1 | _01_Basics.DateTime_getters | PASSED | OK |
| 2::2 | _01_Basics.DateTime_getters | PASSED | OK |
| 2::3 | _01_Basics.DateTime_getters | PASSED | OK |
| 2::4 | _01_Basics.DateTime_getters | PASSED | OK |
| 2::5 | _01_Basics.DateTime_getters | PASSED | OK |
| 2::6 | _01_Basics.DateTime_getters | PASSED | OK |
| 3::1 | _01_Basics.DateTime_set | PASSED | OK |
| 4::1 | _01_Basics.Event_ConstructorBase | PASSED | OK |
| 4::2 | _01_Basics.Event_ConstructorBase | PASSED | OK |
| 5::1 | **_01_Basics.Event_Setters_getters** | **FAILED** | **"e.getDateTime().to_string().c_str()" " must have been equal to " "TODAY"** |
| 6::1 | **_01_Basics.Integration_ECommerce5** | **FAILED** | **[-Activity found: SUNDAY(0) MONDAY(0) TUESDAY(5) WEDNESDAY(0) THURSDAY(0) FRIDAY(0) SATURDAY(0) Records read: 5 Valid records: 5 Max activity: 5 Day of Max activity: TUESDAY-]** |
| 7::1 | **_01_Basics.Integration_EMPTY** | **FAILED** | **[-Activity found: SUNDAY(0) MONDAY(0) TUESDAY(0) WEDNESDAY(0) THURSDAY(0) FRIDAY(0) SATURDAY(0) Records read: 0 Valid records: 0 Max activity: 0 Day of Max activity: SUNDAY-]** |
| 8::1 | **_01_Basics.Integration_ECommerce49** | **FAILED** | **[-Activity found: SUNDAY(0) MONDAY(0) TUESDAY(49) WEDNESDAY(0) THURSDAY(0) FRIDAY(0) SATURDAY(0) Records read: 49 Valid records: 49 Max activity: 49 Day of Max activity: TUESDAY-]** |
| 9::1 | **_01_Basics.Integration_ECommerce_2019_Q4_200** | **FAILED** | **[-Activity found: SUNDAY(25) MONDAY(36) TUESDAY(32) WEDNESDAY(32) THURSDAY(25) FRIDAY(32) SATURDAY(18) Records read: 200 Valid records: 200 Max activity: 36 Day of Max activity: MONDAY-]** |
| 10::1 | **_01_Basics.Integration_ECommerce_all_all_200** | **FAILED** | **[-Activity found: SUNDAY(30) MONDAY(25) TUESDAY(29) WEDNESDAY(37) THURSDAY(33) FRIDAY(24) SATURDAY(22) Records read: 200 Valid records: 200 Max activity: 37 Day of Max activity: WEDNESDAY-]** |
| 11::1 | _02_Intermediate.DateTime_isBefore | PASSED | OK |
| 12::1 | **_02_Intermediate.DateTime_weekDay** | **FAILED** | **"4" " must have been equal to " "d.weekDay()"** |
| 13::1| **_03_Advanced.DateTime_BadValues** | **SKIPPED** | **The previous test failed** |
| 14::1| **_03_Advanced.Event_setType_Bad_Values** | **SKIPPED** | **The previous test failed** |
| 15::1| **_03_Advanced.Event_Others_Bad_Values** | **SKIPPED** | **The previous test failed** |
