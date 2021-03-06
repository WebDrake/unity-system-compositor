# Copyright © 2015 Canonical Ltd.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 3 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Authored by: Alexandros Frantzis <alexandros.frantzis@canonical.com>

include_directories(
 ${CMAKE_SOURCE_DIR}
 ${CMAKE_BINARY_DIR}
 ${MIRSERVER_INCLUDE_DIRS}
 ${DBUS_INCLUDE_DIRS}
)

add_executable(
  usc_test_helper_wait_for_signal
  usc_test_helper_wait_for_signal.c
)

add_executable(
  usc_integration_tests

  run_command.cpp
  dbus_bus.cpp
  dbus_client.cpp
  spin_wait.cpp
  unity_display_dbus_client.cpp
  unity_input_dbus_client.cpp
  test_dbus_event_loop.cpp
  test_unity_display_service.cpp
  test_unity_input_service.cpp
  test_unity_power_button_event_sink.cpp
  test_unity_services.cpp
  test_unity_user_activity_event_sink.cpp
  test_external_spinner.cpp
)

target_link_libraries(
   usc_integration_tests

   usc
   ${GTEST_BOTH_LIBRARIES}
   ${GMOCK_LIBRARY}
   ${GMOCK_MAIN_LIBRARY}
)

add_test(usc_integration_tests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/usc_integration_tests)

add_dependencies(usc_integration_tests GMock)
add_dependencies(usc_integration_tests usc_test_helper_wait_for_signal)
