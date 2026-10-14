CXX			:= ../zig-0.16/zig c++
<<<<<<< HEAD
CXXFLAGS 	:= -target x86_64-linux-none -ffreestanding -nostdlib -static -fno-exceptions -fno-rtti -fno-sanitize=undefined -fno-stack-protector -T linker.ld
=======
CXXFLAGS 	:= -target x86_64-linux-none -ffreestanding -nostdlib -fno-exceptions -fno-rtti -fno-sanitize=undefined -fno-stack-protector -T linker.ld
>>>>>>> 38a9dd99 ([commit 8] i put zig's drop-in c/c++ compilers in the repo or directory so you don't need to manually install compilers.)

ARCHSRC			:= xstdlib/external/arch/x86-64/syscalls.cc
SRC				:= xstdlib/external/*.cc xstdlib/src/*.cc main.cc
TARGET			:= xstd-freestanding

$(TARGET): $(ARCHSRC) $(SRC)
	$(CXX) $(CXXFLAGS) $(ARCHSRC) $(SRC) -o $(TARGET)

static:
	$(CXX) $(CXXFLAGS) -static $(ARCHSRC) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -rf $(TARGET)
