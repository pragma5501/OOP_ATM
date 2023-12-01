ROOT_DIR = ./
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
UTL_DIR = ./src/utils

INC_DIR = \
	-I./src \
	-I./header\
	-I./ \


GCCFLAGS += -g -fsanitize=address $(INC_DIR)

OBJ_SRC = \
	$(SRC_DIR)/ATM.cpp \
	$(SRC_DIR)/bank.cpp \
	$(SRC_DIR)/user.cpp \
	$(SRC_DIR)/account.cpp \
	$(SRC_DIR)/card.cpp \
	$(SRC_DIR)/util.cpp \
	$(SRC_DIR)/handle_error.cpp \

TARGET_OBJ = \
	$(OBJ_DIR)/main.o \
	$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(OBJ_SRC))

all: my_atm

my_atm: $(TARGET_OBJ)
	@mkdir -p $(BIN_DIR)
	g++ -o $(BIN_DIR)/$@ $(GCCFLAGS) $^


$(OBJ_DIR)/main.o: $(ROOT_DIR)/main.cpp
	g++ -c $(GCCFLAGS) $< -o $@


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -c $(GCCFLAGS) $< -o $@



%.d: %.cpp
	g++ -M $(GCCFLAGS) $< -o $@

-include $(TARGET_OBJ:.o=.d)

clean:
	@rm -vf $(BIN_DIR)/*
	@rm -vf $(OBJ_DIR)/*.o


	