TARGET = is_prime
source = $(TARGET).c

$(TARGET): $(source) Makefile
	gcc -Wall -o $@ $<
	mv $@.exe $@

clean::
	rm -fv $(TARGET) a.exe core

vi:
	/usr/bin/vim $(source)

test: $(TARGET) Makefile
	@echo Testing failure cases...
	-./$(TARGET)
	-./$(TARGET) 0
	-./$(TARGET) -1
	-./$(TARGET) x
	@echo Testing hex and octal...
	./$(TARGET) 0x10
	./$(TARGET) 0x0777
	@echo The following tests ought all to succeed...
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
	@./$(TARGET) 100
	@./$(TARGET) 210
	@./$(TARGET) 2016
	@./$(TARGET) 2017
	@./$(TARGET) 2018
	@./$(TARGET) 2019
	@./$(TARGET) 2020
	@./$(TARGET) 2021
	@./$(TARGET) 2022
	@./$(TARGET) 2023
	@echo Some more weird tests...long int on this machine is 32 bits
	@./$(TARGET) 65536
	@./$(TARGET) 65537
	@./$(TARGET) 65538
	@./$(TARGET) 6553765537
	@./$(TARGET) 655376553765537
	@echo End of tests.

include common.mk

