lib_LIBRARIES = libdnstd.a
libdnstd_adir = $(libdir)
libdnstd_a_SOURCES = DNode.cpp DList.cpp DTree.cpp Binary.cpp Character.cpp Complex.cpp DArray.cpp DavidException.cpp DHashMap.cpp Double.cpp DRandom.cpp DStack.cpp DString.cpp StringTokenizer.cpp NumericalIntegration.cpp 
libdnstd_a_CPPFLAGS = -Wall
libdnstd_a_includedir = $(includedir)/libdnstd
libdnstd_a_include_HEADERS = DNode.h DList.h DTree.h Binary.h Character.h Complex.h DArray.h DavidException.h DHashMap.h Double.h DRandom.h DStack.h DString.h StringTokenizer.h NumericalIntegration.h 


if BUILD_WITH_FFTW3
libdnstd_a_SOURCES += fft.cpp
libdnstd_a_CPPFLAGS += -I $(FFTW3_PATH)/include
libdnstd_a_include_HEADERS += fft.h
endif