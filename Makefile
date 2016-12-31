TARGET = is_prime
source = $(TARGET).c

$(TARGET): $(source) Makefile
	gcc -Wall -o $@ $<
	mv $@.exe $@

clean:
	rm -fv $(TARGET) a.exe

vi:
	/usr/bin/vim $(source)

test: $(TARGET) Makefile
	@-./$(TARGET)
	@-./$(TARGET) 0
	@-./$(TARGET) -1
	@-./$(TARGET) x
	@./$(TARGET) 1
	@./$(TARGET) 2
	@./$(TARGET) 3
	@./$(TARGET) 4
	@./$(TARGET) 5
	@./$(TARGET) 6
	@./$(TARGET) 7
	@./$(TARGET) 8
	@./$(TARGET) 9
	@./$(TARGET) 10
	@./$(TARGET) 2017

