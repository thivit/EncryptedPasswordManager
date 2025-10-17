.PHONY: all run clean

all: main

main: Source/Main.cpp Source/Cipher.cpp Source/FileManager.cpp
	@g++ -fPIC Source/Main.cpp Source/Cipher.cpp Source/FileManager.cpp -o EncryptedPasswordManager `pkg-config --cflags --libs Qt5Widgets`

run: all
	@./EncryptedPasswordManager

clean:
	@rm -f EncryptedPasswordManager
