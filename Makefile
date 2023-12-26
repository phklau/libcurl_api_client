EXEC := api_client

BUILD_DIR := ./build
SRC_DIR := ./src

SRCS := GetRequest.cpp PostRequest.cpp main.cpp

OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

LDFLAGS := -lcurl

PYLINT := ../cpplint/cpplint.py

INC_DIRS := include

.PHONY: build
build: $(BUILD_DIR)/$(EXEC)

.PHONY: debug
debug: $(BUILD_DIR)/$(EXEC)

.PHONY: run
run: build
	$(BUILD_DIR)/$(EXEC)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

.PHONY: lint
lint:
	python3 $(PYLINT) *.cpp *.h

.PHONY: debug
debug:
	echo $(OBJS)

# Link
$(BUILD_DIR)/$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(BUILD_DIR)/$(EXEC) $(LDFLAGS)

# Compile
$(BUILD_DIR)/%.o: %.cpp
	mkdir -p build
	$(CXX) $(CPPFLAGS) -c $< -o $@

