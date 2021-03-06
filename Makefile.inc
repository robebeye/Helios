CXX = clang++
CC  = clang

MAKE = make
DEBUG = -g -O0 -DDEBUG
RELEASE = -Os


MODE = $(DEBUG)

# Base dir for BOOST, GLM, SOIL
LIBDIR = /Users/james/Dev/git/hack/Helios_lib

# Base dir for Helios
HELIOSDIR = /Users/james/Dev/git/hack/Helios


INCLUDES = -I$(LIBDIR)/boost/ -I$(LIBDIR)/glm/ -I$(HELIOSDIR)/Core/ -I$(LIBDIR)/SOIL/src/
CXXFLAGS = -stdlib=libc++ -std=c++0x -static -c $(INCLUDES) $(MODE)

OUT = libHelios.a

# Options:
#  GL32, GLES2, . . . [for future use]

RENDER = GL32
