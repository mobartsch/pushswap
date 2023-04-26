NAME ?= libft.a
BONUS_NAME ?= 

BUILD_DIR ?= ./obj
SRC_DIRS ?= ./src

LIB = 
LIBS = $(addprefix -L ,$(LIB))

SRCS := $(filter-out %_bonus.c, $(shell find $(SRC_DIRS) -name *.c))
OBJS := $(subst $(SRC_DIRS), $(BUILD_DIR), $(SRCS:.c=.o))

BONUS_SRCS := $(shell find $(SRC_DIRS) -name *_bonus.c)
BONUS_OBJS := $(subst $(SRC_DIRS), $(BUILD_DIR), $(BONUS_SRCS:.c=.o))

DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CC = cc
CFLAGS ?= $(INC_FLAGS) -Wall -Werror -Wextra -MMD -MP -g

LD = ar
LDFLAGS = $(LIBS)
LINKS = -rcs 

HIDE = @

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\nLinking:"
	@$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LINKS)
	@echo "..\n"

$(BUILD_DIR)/%.o: $(SRC_DIRS)/%.c
	$(HIDE) mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $< ..\n"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@echo "\nlinking bonus:"
	$(LD) $(LDFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LINKS)
	@echo "..\n"

$(BUILD_DIR)/%_bonus.o: $(SRC_DIRS)/%_bonus.c
	$(HIDE) mkdir -p $(@D)
	$(HIDE) $(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $< ...\n"


.PHONY: clean fclean re all bonus

clean:
	$(HIDE) $(RM) -r $(BUILD_DIR)
	@echo "removing obj/ ..\n"

fclean: clean
	$(HIDE) $(RM) $(NAME)
	$(HIDE) $(RM) $(BONUS_NAME)
	@echo "removing $(NAME) ..\n"

re: fclean all

-include $(DEPS)
