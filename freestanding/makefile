CXX			:= ../zig-0.16/zig c++
CXXFLAGS 	:= -target x86_64-linux-none -ffreestanding -nostdlib -static -fno-exceptions -fno-rtti -fno-sanitize=undefined -fno-stack-protector -T linker.ld

ARCHSRC			:= xstdlib/external/arch/x86-64/syscalls.cc
SRC				:= xstdlib/external/*.cc xstdlib/src/*.cc main.cc
TARGET			:= main

$(TARGET): $(ARCHSRC) $(SRC)
	$(CXX) $(CXXFLAGS) $(ARCHSRC) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -rf $(TARGET)
