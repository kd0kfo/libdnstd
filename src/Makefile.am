lib_LIBRARIES = libdnstd.a
libdnstd_adir = $(libdir)
libdnstd_a_SOURCES = Binary.cpp Complex.cpp DavidException.cpp Double.cpp DRandom.cpp StringTokenizer.cpp NumericalIntegration.cpp utils.cpp
libdnstd_a_CPPFLAGS = -Wall
libdnstd_a_includedir = $(includedir)/libdnstd
libdnstd_a_include_HEADERS = Binary.h Complex.h DavidException.h Double.h DRandom.h StringTokenizer.h NumericalIntegration.h MersenneTwister.h RBTree.h utils.h

if BUILD_WITH_FFTW3
libdnstd_a_SOURCES += fft.cpp
libdnstd_a_CPPFLAGS += -I $(FFTW3_PATH)/include
libdnstd_a_include_HEADERS += fft.h
endif