CXX      = g++
CXXFLAGS = -c $(LDFLAGS)
LD       = $(CXX) $(LDFLAGS)
LDFLAGS  = -Wall

ROOTDIR := .
OBJDIR  := obj
BINDIR  := bin
SRCDIR  := src
INCDIR  := inc

INC  := -I$(ROOTDIR) -I$(INCDIR)
SRC  := $(wildcard $(SRCDIR)/*.cc)
OBJ  := $(patsubst $(SRCDIR)/%.cc, $(OBJDIR)/%.o, $(SRC))
EXEC := cmprsr

all: $(EXEC)

$(EXEC): $(OBJ) | dir
	$(CXX) $(CXXFLAGS) $(INC) main.cc -o $(OBJDIR)/main.o
	$(LD) -o $(BINDIR)/$@ $(OBJ) $(OBJDIR)/main.o

dir:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)

clean:
	rm -f $(OBJDIR)/* 2>/dev/null || true
	rm -f $(BINDIR)/* 2>/dev/null || true

diff:
	git diff --stat

rebuild: clean $(EXEC)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc | dir
	$(CXX) $(CXXFLAGS) $(INC) $< -o $@
