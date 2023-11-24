.PHONY: all clean 

LIB_SHARED_NAME := shared
LIB_STATIC_NAME := static


CUR_DIR := .
BIN_DIR := $(CUR_DIR)/bin
INC_DIR := $(CUR_DIR)/inc
OBJS_DIR := $(CUR_DIR)/objs
SRC_DIR	:= $(CUR_DIR)/src

LIB_DIR := $(CUR_DIR)/libs
LIB_STATIC := $(LIB_DIR)/static
LIB_SHARED := $(LIB_DIR)/shared

INC_FLAGS := -I $(INC_DIR)
CC := gcc

mk_objs:
	$(CC) -c $(CUR_DIR)/main.c -o $(OBJS_DIR)/main.o $(INC_FLAGS)
	$(CC) -c -fPIC $(SRC_DIR)/add.c -o $(OBJS_DIR)/add.o $(INC_FLAGS)
	$(CC) -c -fPIC $(SRC_DIR)/sub.c -o $(OBJS_DIR)/sub.o $(INC_FLAGS)

mk_stactic:
	ar rcs $(LIB_STATIC)/lib$(LIB_STATIC_NAME).a $(OBJS_DIR)/sub.o $(OBJS_DIR)/add.o	
mk_shared:
	$(CC) -shared $(OBJS_DIR)/add.o $(OBJS_DIR)/sub.o -o $(LIB_SHARED)/lib$(LIB_SHARED_NAME).so

install:
	cp -f $(LIB_STATIC)/lib$(LIB_STATIC_NAME).a /usr/lib
	cp -f $(LIB_SHARED)/lib$(LIB_SHARED_NAME).so /usr/lib
	
all: mk_objs mk_stactic mk_shared install
	$(CC) $(OBJS_DIR)/main.o -L$(LIB_STATIC) -l$(LIB_STATIC_NAME) -o $(BIN_DIR)/statically-linked
	$(CC) $(OBJS_DIR)/main.o -L$(LIB_SHARED) -l$(LIB_SHARED_NAME) -o $(BIN_DIR)/use-shared-library	
clean:
	rm -rf $(OBJS_DIR)/*
	rm -rf $(LIB_SHARED)/lib$(LIB_SHARED_NAME).so
	rm -rf $(BIN_DIR)/*
	rm -rf $(LIB_STATIC)/lib$(LIB_STATIC_NAME).a



