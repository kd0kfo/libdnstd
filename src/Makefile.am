lib_LIBRARIES = libdnstd.a
libdnstd_adir = $(libdir)
libdnstd_a_SOURCES = Binary.cpp Complex.cpp DavidException.cpp Double.cpp DRandom.cpp StringTokenizer.cpp NumericalIntegration.cpp utils.cpp XMLNode.cpp XMLParser.cpp version.cpp
libdnstd_a_CPPFLAGS = -Wall
libdnstd_a_includedir = $(includedir)/libdnstd
libdnstd_a_include_HEADERS = Binary.h Complex.h DavidException.h Double.h DRandom.h StringTokenizer.h NumericalIntegration.h MersenneTwister.h RBTree.h utils.h XMLNode.h XMLParser.h version.h

if BUILD_WITH_ZLIB
libdnstd_a_SOURCES += Zipper.cpp
libdnstd_a_include_HEADERS += Zipper.h
endif

version.cpp: 
	git rev-parse HEAD | awk ' BEGIN {print "#include \"version.h\""} {print "const char * libdnstd::build_git_sha = \"" $$0"\";"} END {}' > version.cpp
	date | awk 'BEGIN {} {print "const char * libdnstd::build_git_time = \""$$0"\";"} END {} ' >> version.cpp

.PHONY: version.cpp