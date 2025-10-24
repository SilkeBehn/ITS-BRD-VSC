# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/TI-Labor/git/ITS-BRD-VSC_Projekte/ITS-BRD-VSC-meinFork/Programs/GSP_Aufgabe2_Drehgeber/tmp/GSP_Aufgabe2_Drehgeber.Debug+ITSboard"
  "C:/TI-Labor/git/ITS-BRD-VSC_Projekte/ITS-BRD-VSC-meinFork/Programs/GSP_Aufgabe2_Drehgeber/tmp/1"
  "C:/TI-Labor/git/ITS-BRD-VSC_Projekte/ITS-BRD-VSC-meinFork/Programs/GSP_Aufgabe2_Drehgeber/tmp/GSP_Aufgabe2_Drehgeber.Debug+ITSboard"
  "C:/TI-Labor/git/ITS-BRD-VSC_Projekte/ITS-BRD-VSC-meinFork/Programs/GSP_Aufgabe2_Drehgeber/tmp/GSP_Aufgabe2_Drehgeber.Debug+ITSboard/tmp"
  "C:/TI-Labor/git/ITS-BRD-VSC_Projekte/ITS-BRD-VSC-meinFork/Programs/GSP_Aufgabe2_Drehgeber/tmp/GSP_Aufgabe2_Drehgeber.Debug+ITSboard/src/GSP_Aufgabe2_Drehgeber.Debug+ITSboard-stamp"
  "C:/TI-Labor/git/ITS-BRD-VSC_Projekte/ITS-BRD-VSC-meinFork/Programs/GSP_Aufgabe2_Drehgeber/tmp/GSP_Aufgabe2_Drehgeber.Debug+ITSboard/src"
  "C:/TI-Labor/git/ITS-BRD-VSC_Projekte/ITS-BRD-VSC-meinFork/Programs/GSP_Aufgabe2_Drehgeber/tmp/GSP_Aufgabe2_Drehgeber.Debug+ITSboard/src/GSP_Aufgabe2_Drehgeber.Debug+ITSboard-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/TI-Labor/git/ITS-BRD-VSC_Projekte/ITS-BRD-VSC-meinFork/Programs/GSP_Aufgabe2_Drehgeber/tmp/GSP_Aufgabe2_Drehgeber.Debug+ITSboard/src/GSP_Aufgabe2_Drehgeber.Debug+ITSboard-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/TI-Labor/git/ITS-BRD-VSC_Projekte/ITS-BRD-VSC-meinFork/Programs/GSP_Aufgabe2_Drehgeber/tmp/GSP_Aufgabe2_Drehgeber.Debug+ITSboard/src/GSP_Aufgabe2_Drehgeber.Debug+ITSboard-stamp${cfgdir}") # cfgdir has leading slash
endif()
