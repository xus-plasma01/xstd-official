CXX			:= ../zig-0.16/zig c++
AR			:= ../zig-0.16/zig ar

CXXFLAGS 	:= -target x86_64-linux-none -ffreestanding -nostdlib -static -fno-exceptions -fno-rtti -fno-sanitize=undefined -fno-stack-protector -T linker.ld

X86_64_ARCHSRC		:= $(wildcard xstdlib/external/arch/x86-64/*.cc)
ARCHSRC				:= $(X86_64_ARCHSRC)
EXTERNAL_SRC		:= $(wildcard xstdlib/external/*.cc)
OTHER_SRC			:= $(wildcard xstdlib/src/*.cc)
SRC					:= $(EXTERNAL_SRC) $(OTHER_SRC) $(ARCHSRC)
OBJ					:= $(SRC:%.cc=build/%.o)

TARGET				:= outfile
OBJTARGET			:= outfile.o

$(TARGET): main.cc $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) main.cc -o $(TARGET)

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
	./$(TARGET)

clean:
	rm -rf $(TARGET)
	rm -rf $(TARGET).o
	rm -rf $(TARGET).S
	rm -rf build
