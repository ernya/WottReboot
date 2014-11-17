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
	UnixMutex.cpp\
	Window.cpp \
	Color.cpp \
	GeometryHandler.cpp\
	AObject.cpp \
	Rotation.cpp \
	Scale.cpp \
	Translation.cpp \
	Logging.cpp

OBJ=$(SRC:.cpp=.o)
CXXFLAGS= -W -Wall -g -std=c++11 -I/opt/X11/include -I/usr/local/include
LDFLAGS= -framework OpenGL -lGLEW -lglfw3 -framework Cocoa -framework IOKit -framework CoreVideo

$(NAME): $(OBJ)
	g++ $(OBJ) $(LDFLAGS) -o $(NAME)

all:$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all