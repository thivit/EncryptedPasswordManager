# Build config
CXX      = g++
TARGET   = EncryptedPasswordManager
SRCS     = $(wildcard Source/*.cpp)
CXXFLAGS = -std=c++17 -Wall -Wextra -IInclude
QTFLAGS = $(shell pkg-config --cflags --libs Qt5Widgets)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(QTFLAGS)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
