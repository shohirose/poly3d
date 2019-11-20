# ---------------------------------------------------------------------------
# FILE: makefile
# DATE: June, 1993
# BY:   Andrew L. Thomas
#-----------------------------
# UPDATED: July 18, 1994 for compatibility with Silicon Graphics system
# BY:	   Michele L. Cooke
# UPDATED: August 2015 to reduce optimization
# BY:	   Robert Sare 
#
# This UNIX makefile can be used to compile and link the source code 
# for the C-language program Poly3D.  If invoked using the command
#
#                                   make
#
# it will build the program Poly3D, depositing the executable file, poly3d,
# in BINDIR.  The command
#
#                                 make clean
#
# will then remove the unneeded object files from the source directory.
#
# The constants CC and CFLAGS are set here for the *** ANSI-C
# compiler by Silicon Graphics.
# ---------------------------------------------------------------------------

# Source Files
SOURCES  = poly3d.cpp infcoeff.cpp matrix.cpp safetan.cpp getwords.cpp getoptPoly3D.cpp elastic.cpp nr.cpp nrutil.cpp
# Object Files
OBJECTS  = $(SOURCES:.c=.o)
# Include Files
INCLUDES = infcoeff.h matrix.h safetan.h getwords.h getoptPoly3D.h elastic.h nr.h nrutil.h pi.h
# Options (Flags) to be used by the C compiler
CFLAGS   = -ansi -O2 -I.
# Directory in which to place the executable file newpoly3d
BINDIR   = .
# Name of the C compiler to be used
CC       = g++

# ------------------------
# Build the program poly3d
# ------------------------
newpoly3d:	$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -lm -o $(BINDIR)/poly3d


# ----------------------------
# Delete unneeded object files
# ----------------------------
clean:
	rm -f $(OBJECTS)


# ---------------
# Dependency Tree
# ---------------

poly3d.o: poly3d.cpp $(INCLUDES)

infcoeff.o: infcoeff.cpp infcoeff.h safetan.h pi.h

matrix.o: matrix.cpp matrix.h nr.h nrutil.h

safetan.o: safetan.cpp safetan.h pi.h

getwords.o: getwords.cpp getwords.h

getoptPoly3D.o: getoptPoly3D.cpp getoptPoly3D.h

elastic.o: elastic.cpp elastic.h matrix.h

nrutil.o: nrutil.cpp nrutil.h

nr.o: nr.cpp nr.h
