# Generated 2022-09-08 14:14:43

cmake_minimum_required(VERSION 2.8.7)
set(TARGET TopMain)
project(${TARGET})

# require location of supporting RTS
if (NOT UMLRTS_ROOT)
  if (DEFINED ENV{UMLRTS_ROOT})
    set(UMLRTS_ROOT $ENV{UMLRTS_ROOT})
  else ()
    set(UMLRTS_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/umlrt.rts)
  endif ()
endif ()

# setup primary envars - provides tooling config
include(${UMLRTS_ROOT}/build/buildenv.cmake)

# model sources
set(SRCS TopMain.cc AdapterInterfaceToSimulatorProtocol.cc SimulationParams.cc SimulationResults.cc TeamState.cc TacticList.cc AdapterInterface.cc Coordinate.cc Formation.cc TeamConfiguration.cc SimulatorToForwardTargetSensor.cc ForwardTargetSensor.cc Top.cc TopControllers.cc RandomSeed.cc Threat.cc RealEnvironment.cc Sensor.cc TargetSensor.cc DeterministicTargetSensor.cc LongRangeSensorParams.cc DownwardLookingSensorParams.cc ThreatParams.cc )

# specify target
add_executable(${TARGET} ${SRCS})

# setup lib dependency support after defining TARGET
include(${UMLRTS_ROOT}/build/rtslib.cmake)

# compiler parameters
set_target_properties(${TARGET} PROPERTIES COMPILE_OPTIONS "${COPTS}")
set_target_properties(${TARGET} PROPERTIES COMPILE_DEFINITIONS "${CDEFS}")
include_directories(${INCS})

# linker parameters
set_target_properties(${TARGET} PROPERTIES CMAKE_EXE_LINKER_FLAGS "${LOPTS}")
target_link_libraries(${TARGET} ${LIBS})

