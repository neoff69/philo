.PHONY:     			all $(NAME) clear mkbuild minilibx clear clean fclean re

NAME					= philo_bonus

BUILD_DIR				= build/
	
HEADER_DIR				= header/
HEADER_FILE				= philo_bonus.h

DIR						= src/
SRC			 			= main.c \
						  set_up_struct.c \
						  ft_atoi.c \
						  process_declaration.c \
						  utils.c \
						  philo_routine.c \
						  check_if_finish.c \
							
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)

	
GCC						= cc
CFLAGS					= -Wall -Wextra -g3 -pthread -Werror

RM 						= rm -rf
CLEAR					= clear

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER_DIR)/$(HEADER_FILE) Makefile
						@mkdir -p $(@D)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

all: 					clear mkbuild $(HEADER_DIR) $(NAME) 
						
mkbuild:
						@mkdir -p build

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT)

sanitize :				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MAC) $(LINUX)

					
clean:					
						@${RM} $(OBJECTS)
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}

re:						fclean all
						$(MAKE) all
