NAME=libgnl.a
LIB_CFG=$(shell find ~/ -name "libs.mk" -type f)
GEN_PATH=$(shell find ~/ -name "gen.mk" -type f)
-include $(GEN_PATH)
SRC_DIR=srcs
export SRC_DIR
export NAME

make: $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "LIB MADE"