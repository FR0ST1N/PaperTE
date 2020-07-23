CC = g++
CPP_STD = -std=c++17
CFLAGS = -Wall -Wextra
GTKMM=`pkg-config --cflags --libs gtkmm-3.0`
SOURCE_DIR = src
FILE_TYPE = *.cc
BUILD_DIR = build
TARGET = $(BUILD_DIR)/PaperTE

.PHONY: all lint open run clean

all: lint
	mkdir -p $(BUILD_DIR)
	$(CC) $(CPP_STD) $(CFLAGS) $(GTKMM) -o $(TARGET) $(SOURCE_DIR)/$(FILE_TYPE)

lint:
	python cpplint.py --recursive --filter=-build/include_subdir $(SOURCE_DIR)/*

open:
	@./$(TARGET)

run: all open

clean:
	rm -f $(TARGET)
