SRCDIR = ./src
OBJDIR = ./obj
OUTDIR = ./bin

LIBGUR_INC =# ../libgur/inc
LIBGUR_LIBDIR =# ../libgur/bin

SRCS = $(wildcard $(SRCDIR)/*.cpp $(SRCDIR)/**/*.cpp)

CXX = g++
CXXFLAGS = `guile-config compile` -I$(LIBGUR_INC) -std=c++14 -g

LDFLAGS = `guile-config link` -L$(LIBGUR_LIBDIR) -lgur

all: gur-guile.so

$(OBJDIR)/%.po: $(SRCDIR)/%.cpp
	$(CXX) -fPIC -c -o $@ $< $(CXXFLAGS)

OBJS := $(patsubst %.cpp, %.po, $(SRCS))
OBJS := $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(OBJS))

gur-guile.so: $(OBJS)
	$(CXX) -shared -o $(OUTDIR)/$@ $^ $(CXXFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(OUTDIR)/* $(OBJDIR)/*.po $(OBJDIR)/**/*.po
