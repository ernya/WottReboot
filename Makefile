NAME=WottReboot
SRC=	Input.cpp\
	main.cpp\
	SimpleFragmentShader.cpp\
	SimpleVertexShader.cpp\
	Triangle.cpp\
	VertexArray.cpp\
	VertexAttrib.cpp\
	VertexBuffer.cpp\
	VertexBufferData.cpp\
	VideoFlags.cpp\
	VideoMode.cpp\
	Window.cpp
OBJ=$(SRC:.cpp=.o)
CXXFLAGS= -W -Wall -g -std=c++11
LDFLAGS= -lGL -lGLU -lGLEW -lglfw

$(NAME): $(OBJ)
	g++ $(OBJ) $(LDFLAGS) -o $(NAME)

all:$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all