CXX = g++
CXXFLAGS = -Wall -std=c++20

BIN = raytracer
SRC = $(wildcard src/*/*.cc) src/main.cc
OBJ = $(SRC:src/%.cc=src/%.o)

HEADERS = $(wildcard src/*/*.hh)

INC_FLAGS = $(addprefix -I, $(sort $(dir $(HEADERS))))
CXXFLAGS += $(INC_FLAGS)

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $^ -o $@

src/%.o: src/%.cc $(HEADERS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(BIN) $(OBJ)
