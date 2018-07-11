EXE := solver
SRC := $(wildcard *.cpp)
BLD := obj
OBJ := $(SRC:%.cpp=$(BLD)/%.o)
DEP := $(OBJ:.o=.d)
CPPFLAGS := -I../include
CPPFLAGS += -MMD -MP
CXXFLAGS := -Wall -W -pedantic
LDFLAGS := -L../lib
LDLIBS := -lm
.PHONY: all clean
all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(BLD)/%.o: %.cpp | $(BLD)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<
$(BLD):
	mkdir $@
clean:
	$(RM) -r $(BLD) $(EXE)


-include $(DEP)

