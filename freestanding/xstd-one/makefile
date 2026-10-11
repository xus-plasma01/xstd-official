CXX             := zig c++
LLCXXFLAGS      := -std=gnu++20 -target x86_64-linux -ffreestanding -fno-sanitize=undefined -fno-stack-protector -nostdlib
LDFLAGS         := -Wl,-T,linker.ld
CXXFLAGS		:= -O2 -march=native

SRC             := main.cc
TARGET          := outfile

$(TARGET): $(SRC) linker.ld
	$(CXX) $(LLCXXFLAGS) $(LDFLAGS) $(SRC) -o $(TARGET)

asm:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SRC) -S -o $(TARGET).S

asmfreestand: 
	$(CXX) $(LLCXXFLAGS) $(LDFLAGS) $(SRC) -S -o $(TARGET).S

freestanding:
	$(CXX) $(LLCXXFLAGS) $(LDFLAGS) $(SRC) -o $(TARGET)

nolinker:
	$(CXX) -Ixstdlib -Isyscall $(CXXFLAGS) $(SRC) -o $(TARGET)

asmnolinker:
	$(CXX) $(CXXFLAGS) $(SRC) -S -o $(TARGET).S

run:
	./$(TARGET)

transfertotxt:
	./$(TARGET) > outputs.txt

clean:
	rm -rf $(TARGET)

asmclean:
	rm -rf $(TARGET).S
