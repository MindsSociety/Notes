CC = g++ 
MAIN = Main.cpp
SRC = Client.o LogFile.o
OUT = compiled
FLAGS = -O2
TARGET = $(addprefix $(OUT),/ex)

all: $(OUT) $(TARGET)

# $@ expands to the rule's target.
# $^ expands to the rule's dependencies,.
$(TARGET): $(SRC)
	$(CC) $(FLAGS) -o $(TARGET) $(MAIN) $(addprefix $(OUT)/,$(SRC))

# $@ for the pattern-matched target
# $< for the pattern-matched dependency
%.o: %.cpp
	$(CC) -o compiled/$@ -c $<

$(OUT):
	mkdir compiled

run: $(OUT) $(TARGET)
	./$(TARGET)

clean:
	rm -rf compiled
