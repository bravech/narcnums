CXXFLAGS := -std=c++17 -Wall -lgmp -lgmpxx

# Set the includes for yourself
INC := -I/opt/homebrew/Cellar/gmp/6.2.1_1/include -L/opt/homebrew/Cellar/gmp/6.2.1_1/lib

SOURCEDIR := src
BUILDDIR := build
WARNING := -Wall -Wextra

ifeq (release,$(CONFIG))
CXXFLAGS += -O2
else
CXXFLAGS += -g
endif

SOURCES := $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))
DEPENDS := $(patsubst %.cpp,%.d,$(SOURCES))

CXXFLAGS += $(INC)

all: narcnums

narcnums: $(OBJECTS)
	$(CXX) $(WARNING) -o $@ $(CXXFLAGS) $^

-include $(DEPENDS)

%.o: %.cpp Makefile
	$(CXX) $(WARNING) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(DEPENDS) narcnums