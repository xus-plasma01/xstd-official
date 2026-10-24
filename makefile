CXX			:= zig c++
AR			:= zig ar

ARCH 	?= native
TARGET 	:= $(ARCH)

CXXFLAGS 	:= -target $(TARGET) -std=gnu++20 -Wall -Wextra -ffreestanding -nostdlib -static -fno-exceptions -fno-rtti -fno-sanitize=undefined -fno-stack-protector -T linker.ld

X86_64_ARCHSRC		:= $(wildcard xstdlib/external/arch/x86-64/*.cc)
I386_ARCHSRC		:= $(wildcard xstdlib/external/arch/i386/*.cc)

ifeq ($(ARCH),x86-64)
	ARCHSRC	:= $(X86_64_ARCHSRC)
	ARCHFLG := -m64
else ifeq ($(ARCH),i386)
	ARCHSRC := $(I386_ARCHSRC)
	ARCHFLG := -m32
else
	ARCHSRC := $(X86_64_ARCHSRC)
	ARCHFLG := -m64
endif

EXTERNAL_SRC		:= $(wildcard xstdlib/external/*.cc)
OTHER_SRC			:= $(wildcard xstdlib/src/*.cc)
SRC					:= $(EXTERNAL_SRC) $(OTHER_SRC) $(ARCHSRC)
OBJ					:= $(SRC:%.cc=build/%.o)
MAIN				?= examples/test.cc

EXEC				?= outfile
OBJTARGET			?= outfile.o

$(EXEC): $(MAIN) $(SRC)
	$(CXX) $(CXXFLAGS) $(ARCHFLG)  $(SRC) $(MAIN) -o $(EXEC)

static: build/xuslib.a

static_compile: build/xuslib.a main.cc
	$(CXX) $(CXXFLAGS) build/xuslib.a main.cc -o outfile

build/xuslib.a: $(OBJ)
	$(AR) rcs $@ $^

build/%.o: %.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

static:
	$(CXX) $(CXXFLAGS) -static $(ARCHSRC) $(SRC) -o $(TARGET)

run:
	./$(EXEC)

clean:
	rm -rf $(EXEC)
	rm -rf $(EXEC).o
	rm -rf $(EXEC).S
	rm -rf build
